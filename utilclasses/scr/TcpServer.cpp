#include "mbu.h"
#include "TcpServer.h"


//////////////////////////////////////////////////////////////////////
// CTcpServer Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTcpServer::CTcpServer()
{
	m_bWinsockStarted=StartWinsock();
	m_pModbus=NULL;
	
	m_sServerIP="127.0.0.1";
    m_unPort=DEFAULT_PORT;
	m_bSeverStarted=FALSE;
	m_dwTimeOut=5000; //Time out of 5 seconds 
	m_dwTxBufferSize=512;
	m_dwRxBufferSize=512;

	//Bounce Site 
	m_sBounceAddr="www.microsoft.com";
	m_wBouncePort=80;

	//Modbus Comm errors 
	m_byExceptionOffset=DEFAULT_COMM_EXCEPTION_OFFSET;
	m_bComExceptionEnabled=TRUE;
	m_lNumOfThreads=0;

}

CTcpServer::~CTcpServer()
{

	if (m_bWinsockStarted) {
	   StopWinsock();
	}
	

}

BOOL CTcpServer::StartServer(CString sServerIP,USHORT unPort ,CModbus* pModbus)
{
	
	try {

		//Try Dotted Decimal Format 
		CSockAddr saServer(sServerIP,unPort);
	
		if (INADDR_NONE==saServer.IPAddr()) {
		    saServer=CBlockingSocket::GetHostByName(sServerIP,unPort);
		}

		m_sListen.Create();
		m_sListen.Bind(saServer);
		m_sListen.Listen();
		m_pModbus=pModbus;
		CreateThread(); //create new thread object 
		m_bSeverStarted=TRUE;
		m_sServerIP=sServerIP;
		m_unPort=unPort;
		return TRUE;
	}
	catch(CBlockingSocketException* e) {
		m_sListen.Cleanup();
		e->Delete();
		return FALSE;
	}


}

BOOL CTcpServer::StopServer()
{

	//close all conneted clients 
	try {
		aClients.CloseAllClients();
		m_sListen.Close(); //stop listen socket
		while (m_lNumOfThreads>0){
			::Sleep(50);
		}
	}
	catch(CBlockingSocketException* e) {
		m_sListen.Cleanup();
		e->Delete();
	
	}
	m_bSeverStarted=FALSE;
	return TRUE;
}

BOOL CTcpServer::StartWinsock()
{
WORD wVersionRequested;
WSADATA wsaData;
int err;
 
wVersionRequested = MAKEWORD( 1, 1 );
 
err = WSAStartup( wVersionRequested, &wsaData );
if ( err != 0 ) {
    /* Tell the user that we couldn't find a usable */
    /* WinSock DLL.                                  */
    return FALSE;
}
 
/* Confirm that the WinSock DLL supports 1.1.*/
/* Note that if the DLL supports versions greater    */
/* than 1.0 in addition to 1.1, it will still return */
/* 1.1 in wVersion since that is the version we      */
/* requested.                                        */
 
if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) {
    /* Tell the user that we couldn't find a usable */
    /* WinSock DLL.                                  */
    StopWinsock();
    return FALSE; 
}

return TRUE;

}


//server worker thread 
UINT CTcpServer::ServerThreadProc(LPVOID pParam) {
	
	
	CTcpServer* pTCPServer=(CTcpServer*)pParam;
	
	pTCPServer->IncrementThreadCount();

	WORD nRecived=0;
	int iReciveCount;
	WORD nQueryLength;
	WORD nResponseLength=0;
    CByteArray byRecived;
	CByteArray byResponse;
	CByteArray byMbapHeadeader;
	BOOL bConnected=FALSE;
	int iElement=-1;
    WORD nError;
	byRecived.SetSize(pTCPServer->RxBufferSize());
	byResponse.SetSize(pTCPServer->TxBufferSize());
	BOOL bAceppted=FALSE;
	
	BYTE byTransac_id_hi;
	BYTE byTransac_id_lo;
	BYTE byModbusFunction;
	BYTE byUnit_Id;

	
    CSockAddr* psaClient = new CSockAddr;
	CBlockingSocket* psConnect = new CBlockingSocket;
	
	try {
		if (!pTCPServer->m_sListen.Accept(*psConnect,*psaClient)){
			delete psConnect;
			delete psaClient;
			pTCPServer->DecrementThreadCount();
			return 0;
		}
		
		pTCPServer->CreateThread();
		
		bAceppted=TRUE;
		iElement=pTCPServer->aClients.AddClient(psConnect,psaClient);
		iReciveCount=0;
		pTCPServer->aClients.Clients[iElement].ResetTxRxCount();
		
		while (TRUE) {
			
			nRecived=psConnect->Receive((char*)byRecived.GetData(),MBAP_HEADER_LENGHT,0); 
			if (0==nRecived){
				break;		
			}
			iReciveCount+=nRecived;
			
			if (iReciveCount>=MBAP_HEADER_LENGHT) {
				//process TCP header
				byTransac_id_hi=byRecived[0];
				byTransac_id_lo=byRecived[1];
				nQueryLength=(byRecived[4]<<8)|byRecived[5];
               	
				//recive modbus query 
				::ZeroMemory(byRecived.GetData(),byRecived.GetSize());
				nRecived=psConnect->Receive((char*)byRecived.GetData(),nQueryLength,pTCPServer->TimeOut()/1000); //4 bytes query and response length
				
				if (nRecived!=nQueryLength){
					//error close socket 
					break;		
				}
				
				if ((pTCPServer->RxBufferSize()<nQueryLength)) {
					break;
				}
				
				byUnit_Id=byRecived[0];
				
				byModbusFunction=byRecived[1];
				
				//send query to modbus device 
				::ZeroMemory(byResponse.GetData(),byResponse.GetSize());
				
				pTCPServer->aClients.Clients[iElement].AddRxBytes(nQueryLength);
				
				nError=pTCPServer->m_pModbus->TxRxMessage(byRecived,nQueryLength,byResponse,0,&nResponseLength);
				
				byMbapHeadeader.SetSize(MBAP_HEADER_LENGHT);
				byMbapHeadeader[0]=byTransac_id_hi;
				byMbapHeadeader[1]=byTransac_id_lo;
				byMbapHeadeader[2]=HIBYTE(MODBUS_ENCODING);
				byMbapHeadeader[3]=LOBYTE(MODBUS_ENCODING);
				
				if (CModbus::ERR_OK!=nError) {
					nResponseLength=3;
					byResponse.SetSize(nResponseLength);
					byMbapHeadeader[4]=HIBYTE(nResponseLength);
					byMbapHeadeader[5]=LOBYTE(nResponseLength);
					
					byResponse[0]=byUnit_Id;
					
					if (nError>=CModbus::ERR_EXCPTION_CODE)
					{
						byResponse[1]=0x80+byModbusFunction;
						byResponse[2]=BYTE(nError-CModbus::ERR_EXCPTION_CODE);
					}
					else {
						byResponse[1]=0x80+byModbusFunction;
						
						if (pTCPServer->ComExceptionEnabled()) {
							byResponse[2]=BYTE(pTCPServer->CommExceptionOffset()+nError);
						}
						else {
							
							byResponse[2]=BYTE(GENERAL_COMM_ERROR);
						}
					}
					
                }
				else {
					byResponse.SetSize(nResponseLength); 
					byMbapHeadeader[4]=HIBYTE(nResponseLength);
					byMbapHeadeader[5]=LOBYTE(nResponseLength);
					
				}
				
				byResponse.InsertAt(0,&byMbapHeadeader);
				
				//return response to remote client 
				if (byResponse.GetSize()!=(int)psConnect->Write((char*)byResponse.GetData(),byResponse.GetSize(),pTCPServer->TimeOut()/1000)) {
					break;
				}
				pTCPServer->aClients.Clients[iElement].AddTxBytes(nResponseLength);
				iReciveCount=0;				
				
			}
			
			
		}//while (TRUE)
		
		psConnect->Close();
	}
	catch (CBlockingSocketException* e){
		e->Delete();
		if (bAceppted) {
			psConnect->Cleanup();
		}
	}
	
	if (iElement>=0) {
		pTCPServer->aClients.RemoveClient(iElement);
	}
	delete psConnect;
	delete psaClient;
    
	pTCPServer->DecrementThreadCount();
	return 0;
}

BYTE CTcpServer::ComPort()
{

	if (m_pModbus!=NULL) {
	
	 return ((CLocalModbus*)m_pModbus)->ComPort();
	}
	else {
	 return 0;
	}

}

CString CTcpServer::ServerIP()
{

	return (m_sServerIP);
}

USHORT CTcpServer::ServerPort()
{

	return (m_unPort);
}

void CTcpServer::ServerPort(USHORT usAddr){

	m_unPort = usAddr;

}

BOOL CTcpServer::SeverStarted()

{
	return m_bSeverStarted;
}

DWORD CTcpServer::TimeOut()
{
   return m_dwTimeOut;
}

void CTcpServer::TimeOut(DWORD dwTimeOut)
{
   m_dwTimeOut=dwTimeOut;
}

DWORD CTcpServer::RxBufferSize()
{
	return m_dwRxBufferSize;

}

void CTcpServer::RxBufferSize(DWORD dwRxSize) {
     m_dwRxBufferSize=dwRxSize;
}

DWORD CTcpServer::TxBufferSize()
{
	return m_dwTxBufferSize;

}

void CTcpServer::TxBufferSize(DWORD dwTxSize) {
     m_dwTxBufferSize=dwTxSize;
}

void CTcpServer::BounceAddr(CString sAddr)
{
   m_sBounceAddr = sAddr;
}

CString CTcpServer::BounceAddr()
{
   return m_sBounceAddr;
}

void CTcpServer::BouncePort(WORD wPort)
{
  m_wBouncePort=wPort;
}

WORD CTcpServer::BouncePort()
{
   return m_wBouncePort;
}

BYTE CTcpServer::CommExceptionOffset()
{
	return m_byExceptionOffset;
}

void CTcpServer::CommExceptionOffset(BYTE byOffset)
{
	m_byExceptionOffset=byOffset;
}

void CTcpServer::ComExceptionEnabled(BOOL bEnabled)
{
	m_bComExceptionEnabled=bEnabled;
}

BOOL CTcpServer::ComExceptionEnabled()
{
	return m_bComExceptionEnabled;
}

BOOL CTcpServer::StopWinsock()
{
	int iResp= WSACleanup();
	return (0==iResp);
}

void CTcpServer::ServerAddr(LPCSTR szServerAddr)
{
	m_sServerIP = szServerAddr;
}

CString CTcpServer::ServerAddr()
{
	return m_sServerIP;
}

void CTcpServer::CreateThread()
{
	DWORD dwThreadId;
	HANDLE hThread;
	
	hThread = ::CreateThread(NULL, // pointer to thread security attributes
		0,      // initial thread stack size, in bytes
		(LPTHREAD_START_ROUTINE)ServerThreadProc,
		// pointer to thread function
		(LPVOID)this,     // argument for new thread
		0,  // creation flags
		&dwThreadId      // pointer to returned thread identifier
		);
	
	ASSERT(hThread);
	
	VERIFY(::CloseHandle(hThread));
}



LONG CTcpServer::IncrementThreadCount()
{
	return ::InterlockedIncrement(&m_lNumOfThreads);
}

LONG CTcpServer::DecrementThreadCount()
{
	return ::InterlockedDecrement(&m_lNumOfThreads);
}

BOOL CTcpServer::ServerActive()
{
	return m_bSeverStarted;
}
