// AutoModbus.cpp: implementation of the CAutoModbus class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"
#include "AutoModbus.h"
#include "OleSafeArrayEx.h"
#include <comdef.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define __IID_DEFINED__
#include "ModbusServer_i.c"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( CAutoModbus, CModbus)

CAutoModbus::CAutoModbus()
{
	m_pIModbusSrv=NULL;
	m_pITCPServer=NULL;

}

CAutoModbus::~CAutoModbus()
{
	Release();
}

HRESULT CAutoModbus::CreateInstance(LPCSTR szMachine, LPCSTR szConnectionName)
{
	CComBSTR sName;
	VARIANT_BOOL bOk;
	MULTI_QI    mq;
    COSERVERINFO csi, *pcsi=NULL;
	WCHAR wsz [MAX_PATH];
	REFIID riid=IID_IModbusSrv;
	DWORD dwClsCtx;
	LPDISPATCH pTCPServer;
	ICTCPIPServer* pITCPServer;
	
	if (0==strlen(szMachine)){
		dwClsCtx=CLSCTX_LOCAL_SERVER;
		pcsi=NULL;
	}
	else {
		
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szMachine , -1,
			wsz, MAX_PATH);
		memset(&csi, 0, sizeof(COSERVERINFO));
		csi.pwszName = wsz;
		pcsi = &csi;
		dwClsCtx=CLSCTX_REMOTE_SERVER;
	}
	
	mq.pIID = &IID_IModbusSrv;
    mq.pItf = NULL;
    mq.hr = S_OK;
	
	
	Release(); //Release Instance if created 

	m_sMachine.Empty();
	m_sConnectionName.Empty();


	HRESULT hRes = ::CoCreateInstanceEx(
		CLSID_ModbusSrv,             //CLSID of the object to be created
		NULL,        //If part of an aggregate, the 
		// controlling IUnknown
		dwClsCtx,   //CLSCTX values
		pcsi,			//Machine on which the object is to 
								// be instantiated
								1,                    //Number of MULTI_QI structures in 
								// rgmqResults
								&mq         //Array of MULTI_QI structures
								);
	
	//TRACE("E_NOINTERFACE = %x E_INVALIDARG= %x hRes= %x \n",E_NOINTERFACE,E_INVALIDARG , hRes);
	
	if FAILED(hRes){
		return hRes;
	}
	
	if FAILED(mq.hr){
		return mq.hr;
	}
	
	m_pIModbusSrv=(IModbusSrv*)mq.pItf;
	
	ASSERT(m_pIModbusSrv != NULL);
	
	if (m_pIModbusSrv != NULL) {
		mq.pItf->Release();
	}
	else {
		return mq.hr;
	}
	
	_ASSERTE(m_pIModbusSrv != NULL);
	
	sName=szConnectionName;
	
	if (!m_pIModbusSrv) {
		return mq.hr;
	}

	m_pIModbusSrv->OpenConnection(sName,mbLOCAL,&bOk);

	m_sMachine=szMachine;
	m_sConnectionName=szConnectionName;

	//GetTcp Sever 
	hRes = m_pIModbusSrv->get_TcpServer(&pTCPServer);

	if (hRes!=S_OK){
		return hRes;
	}

	hRes = pTCPServer->QueryInterface(IID_ICTCPIPServer,(void**)&pITCPServer);

	if (hRes!=S_OK){
		return hRes;
	}

	m_pITCPServer=pITCPServer;

	pITCPServer->Release();

	pTCPServer->Release();

	//m_pITCPServer

	return (S_OK);	
}


	//transmit a query to a modbus device and wait for a response
//return ERR_XXX Code see Modbus.cpp file  
WORD CAutoModbus::TxRxMessage(CByteArray& abyQuery, //modbus query without CRC
							  WORD wLengthQuery, //QueryLength without CRC
							  CByteArray& abyResponse, //modbus Response without CRC
							  WORD wLengthResponse, //wLengthResponse Response without CRC
							  WORD* pwNumOfBytesRead){
	
	
	COleSafeArrayEx vQuery;
	COleSafeArrayEx vResponse;
	COleVariant vNumOfBytesRead;
	long lError=S_OK;
	WORD wError;

	HRESULT hRes;
	
	
	if (pwNumOfBytesRead!=NULL){
		vNumOfBytesRead.ChangeType(VT_I2);
	}

	if (!vQuery.ToVariantArray(abyQuery)){
			return ERR_BUILD_ARRAY_ERROR;
	}
    
	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return ERR_AUTOMATION_ERROR;
	}



	
	hRes = m_pIModbusSrv->TxRxMessage(vQuery, 
		short(wLengthQuery), 
		(VARIANT*)(&vResponse), 
		short(wLengthResponse), 
		(VARIANT*)&vNumOfBytesRead, 
		&lError);

	if FAILED(hRes) {
		return ERR_AUTOMATION_ERROR;
	}

	if(!vResponse.ToByteArray(abyResponse)){
	
		return ERR_BUILD_ARRAY_ERROR;
	}

	if (lError==S_OK) {
		wError= ERR_OK;
	}
	else {
		if (FACILITY_ITF==SCODE_FACILITY(lError)){
			wError=SCODE_CODE(lError);
			wError=wError-WORD(mbErrOffset); 
		}
		else {
			ASSERT(FALSE);
			TRACE("Automation Error Err=%x =\n",lError);
			wError = ERR_AUTOMATION_ERROR;
		
		}
	}

	return wError;
	
}


 BOOL CAutoModbus::IsActive() {

	VARIANT_BOOL bIsActive;
	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_IsActive(&bIsActive);

	return (VARIANT_TRUE==bIsActive);
 }

void CAutoModbus::Release()
{
	m_pITCPServer=NULL;
	m_pIModbusSrv=NULL;
		
}


CString CAutoModbus::ErrorMessage(WORD wErrorCode){
	CString sRetValue("");
    CString sAux;
	if(ERR_AUTOMATION_ERROR==wErrorCode) {
		sRetValue=MSG_AUTO_MODBUS_ERR_AUTOMATION_ERROR;
	}
	else if (ERR_BUILD_ARRAY_ERROR==wErrorCode) {
		sRetValue=MSG_AUTO_MODBUS_ERR_BUILD_ARRAY_ERROR;
	}
	else {
	   sRetValue=CModbus::ErrorMessage(wErrorCode);
	}

	return sRetValue;
 }

void CAutoModbus::ComPort(BYTE byPort)
{
	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_ComPort(byPort);
}

BYTE CAutoModbus::ComPort()
{
	short iComPort=0;
	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_ComPort(&iComPort);

	return (BYTE(iComPort));
}

DWORD CAutoModbus::BaudRate()
{
	long lBaudRate=0;
	
	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}
	
	m_pIModbusSrv->get_BaudRate(&lBaudRate);

	return DWORD(lBaudRate);
	
}

void CAutoModbus::BaudRate(DWORD dwBaudRate)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_BaudRate(long(dwBaudRate));
}

void CAutoModbus::Parity(BYTE byParity)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_Parity(byParity);


}

BYTE CAutoModbus::Parity()
{

	short iParity;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_Parity(&iParity);

	return BYTE(iParity);
}

DWORD CAutoModbus::Timeout()
{
	long lTimeOut;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_TimeOut(&lTimeOut);

	return DWORD(lTimeOut);

}

void CAutoModbus::Timeout(DWORD dwTimeOut)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_TimeOut(long(dwTimeOut));

	return;

}

DWORD CAutoModbus::SilentInterval()
{

	long lSilentInterval;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_SilentInterval(&lSilentInterval);

	return DWORD(lSilentInterval);

}

void CAutoModbus::SilentInterval(DWORD dwSilentInterval)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return ;
	}

	m_pIModbusSrv->put_SilentInterval(long(dwSilentInterval));

}

BOOL CAutoModbus::Connect()
{
	
	VARIANT_BOOL bResp;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return FALSE;
	}

	m_pIModbusSrv->Connect(&bResp);

	return (VARIANT_TRUE==bResp);


}

void CAutoModbus::FlowControl(BYTE byFlow)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return ;
	}
	m_pIModbusSrv->put_FlowControl(short(byFlow));

}

BYTE CAutoModbus::FlowControl()
{
	short iFlow=0;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return FALSE;
	}

	m_pIModbusSrv->get_FlowControl(&iFlow);

	return BYTE(iFlow);

}

BYTE CAutoModbus::StopBits()
{
	short iStopBits;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return FALSE;
	}

	m_pIModbusSrv->get_StopBits(&iStopBits);

	return BYTE(iStopBits);

}

void CAutoModbus::StopBits(BYTE byStopBits)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_StopBits(short(byStopBits));


}

WORD CAutoModbus::TransmissionMode()
{
	short iTransmitionMode;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_TransmissionMode(&iTransmitionMode);

	return WORD(iTransmitionMode);

}

void CAutoModbus::TransmissionMode(WORD wMode)
{

	
	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_TransmissionMode(short(wMode));

}

WORD CAutoModbus::ByteSize()
{
	short iValue;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_ByteSize(&iValue);

	return WORD(iValue);

}

void CAutoModbus::ByteSize(WORD wSize)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_ByteSize(short(wSize));
}


DWORD CAutoModbus::Delay()
{
	long lValue;

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return 0;
	}

	m_pIModbusSrv->get_Delay(&lValue);

	return DWORD(lValue);

}

void CAutoModbus::Delay(DWORD dwDelay)
{

	if (!m_pIModbusSrv) {
		ASSERT(FALSE);
		return;
	}

	m_pIModbusSrv->put_Delay(long(dwDelay));
}


void CAutoModbus::Serialize(CArchive& archive)
{
	
	CModbus::Serialize( archive );
	
	long lAux;
	VARIANT_BOOL bValue;
	CString str;
	BSTR bstr;
	long lPorta=0;
	
	
	// now do the stuff for our specific class
	if( archive.IsStoring() ){
		
		if (!m_pIModbusSrv) {
			ASSERT(FALSE);
		}
		
		archive	<< m_sMachine
			<< m_sConnectionName
			<<  long(ComPort())
			<<	long(ByteSize())
			<<  long(TransmissionMode())
			<<  long(StopBits())
			<<  long (FlowControl())
			<<  long(SilentInterval())
			<<  long(Timeout())
			<<  long(Parity())
			<<  long(BaudRate())
			<<  long(Delay()); 
		
		
		
	} 
	else {
		archive	>> m_sMachine
			>> m_sConnectionName;
		archive	>>	lPorta;
		str.Format("com%d",lPorta);
		if(FAILED(CreateInstance(m_sMachine,str))){
			archive	>>	lAux //ByteSize
				>>  lAux  //TransmissionMode
				>>  lAux  //StopBits
				>>  lAux	//FlowControl
				>>  lAux  //SilentInterval
				>>  lAux	//Timeout
				>>  lAux	//Parity
				>>  lAux	//BaudRate
				>>  lAux;	//Delay
				
		}
		else {
			archive	>>	lAux; //ByteSize
			ByteSize((WORD)lAux);
			archive	>>  lAux;  //TransmissionMode
			TransmissionMode((WORD)lAux);
			archive	>>  lAux;  //StopBits
			StopBits(BYTE(lAux));
			archive	>>  lAux;	//FlowControl
			FlowControl(BYTE(lAux));
			archive	>>  lAux;  //SilentInterval
			SilentInterval(DWORD(lAux));
			archive	>>  lAux;	//Timeout
			Timeout(DWORD(lAux));
			archive	>>  lAux;	//Parity
			Parity(BYTE(lAux));
			archive	>>  lAux;	//BaudRate
			BaudRate(DWORD(lAux));
			archive	>>  lAux;	//Delay
			Delay(lAux);

		
			ComPort(BYTE(lPorta));
			
			if (!Connect()) {
				ASSERT(FALSE);
			}
			
		}
		
	}

	
	//TCP Server 
	if( archive.IsStoring() ){
		
		bValue=VARIANT_FALSE;
		str.Empty();
		lAux=0;
		
		if (!m_pITCPServer) {
			ASSERT(FALSE);
			archive << bValue<<str<<lAux;
		}
		else {
			m_pITCPServer->get_ServerActive(&bValue);
			archive << bValue;
			m_pITCPServer->get_ServerAddress(&bstr);
			str = bstr;
			::SysFreeString(bstr);
			archive << str;
			m_pITCPServer->get_ServerPort(&lAux);
			archive << lAux;
		}
	}
	else {
		archive >> bValue;
		archive >> str;
		bstr = str.AllocSysString(); 
		archive >> lAux;
		
		if (!m_pITCPServer) {
			ASSERT(FALSE);
		}
		else {
			m_pITCPServer->put_ServerPort(lAux);
			m_pITCPServer->put_ServerAddress(bstr);
			if (VARIANT_TRUE==bValue){
				m_pITCPServer->StartServer(&bValue);
			}
		}
		::SysFreeString(bstr);
	}
}

CString CAutoModbus::Machine()
{
	return m_sMachine;
}
