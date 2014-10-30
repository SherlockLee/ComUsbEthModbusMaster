// CommParameters.cpp : implementation file
//

#include "stdafx.h"
#include "Modbucfg.h"
#include "CommParameters.h"
#include "OleFuncs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommParameters dialog


CCommParameters::CCommParameters(CWnd* pParent /*=NULL*/)
	: CDialog(CCommParameters::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommParameters)
	m_bDTRDSR = FALSE;
	m_bRTSCTS = FALSE;
	m_bXONXOFF = FALSE;
	//}}AFX_DATA_INIT

	m_pConnection=NULL;
	m_bModeNew=FALSE;

}


void CCommParameters::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommParameters)
	DDX_Control(pDX, IDC_EDIT_DELAY, m_edtDelay);
	DDX_Control(pDX, IDC_CHK_TCP_SERVER, m_chkTcpServer);
	DDX_Control(pDX, IDC_EDIT_DCOM_SERVER, m_edtDcomServer);
	DDX_Control(pDX, IDC_EDIT_PORT, m_edtServerPort);
	DDX_Control(pDX, IDC_EDIT_IP_ADDR, m_edtServerIP);
	DDX_Control(pDX, IDC_CHK_ACTIVE, m_chkActive);
	DDX_Control(pDX, IDC_EDIT_CHAR_INTERVAL, m_edtCharInterval);
	DDX_Control(pDX, IDC_EDIT_TIME_OUT, m_edtTimeOut);
	DDX_Control(pDX, IDC_CBO_BYTESIZE, m_cboByteSize);
	DDX_Control(pDX, IDC_CBO_STOPBITSCB, m_cboStopBits);
	DDX_Control(pDX, IDC_CBO_PARITY, m_cboParity);
	DDX_Control(pDX, IDC_CBO_COM_PORT, m_cboPorta);
	DDX_Control(pDX, IDC_CBO_BAUD_RATE, m_cboBaudRate);
	DDX_Check(pDX, IDC_CHK_DTRDSR, m_bDTRDSR);
	DDX_Check(pDX, IDC_CHK_RTSCTS, m_bRTSCTS);
	DDX_Check(pDX, IDC_CHK_XONXOFF, m_bXONXOFF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommParameters, CDialog)
	//{{AFX_MSG_MAP(CCommParameters)
	ON_BN_CLICKED(IDC_OK, OnOkey)
	ON_BN_CLICKED(IDC_BUTT_FIND_IP, OnButtFindIP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommParameters message handlers

void CCommParameters::LoadCombos()
{

	int nIndex=-1;
    CString str;
	
	//port 
	m_cboPorta.AddString("COM1"); 
	m_cboPorta.AddString("COM2");
	m_cboPorta.AddString("COM3");
	m_cboPorta.AddString("COM4");
	m_cboPorta.AddString("COM5"); 
	m_cboPorta.AddString("COM6");
	m_cboPorta.AddString("COM7");
	m_cboPorta.AddString("COM8");
	m_cboPorta.SetCurSel(0);

	//baudrate 
	/*CBR_110 	CBR_19200
    CBR_300 	CBR_38400
    CBR_600 	CBR_56000
	CBR_1200	CBR_57600
	CBR_2400	CBR_115200
	CBR_4800	CBR_128000
	CBR_9600	CBR_256000
	CBR_14400 */
	str.Format("%d", CBR_110);
    nIndex=m_cboBaudRate.AddString(str);
	m_cboBaudRate.SetItemData( nIndex,CBR_110);

	str.Format("%d", CBR_300);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_300);

	str.Format("%d", CBR_600);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_600);

	str.Format("%d", CBR_1200);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_1200);

	str.Format("%d", CBR_2400);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_2400);

	str.Format("%d", CBR_4800);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_4800);

	str.Format("%d", CBR_9600);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_9600);

	str.Format("%d", CBR_14400);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_14400);

	str.Format("%d", CBR_19200);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_19200);

	str.Format("%d", CBR_38400);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_38400);

	str.Format("%d", CBR_56000);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_56000);

	str.Format("%d", CBR_57600);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_57600);

	str.Format("%d", CBR_115200);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_115200);

	str.Format("%d", CBR_128000);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_128000);

	str.Format("%d", CBR_256000);
    nIndex=m_cboBaudRate.AddString(str);
    m_cboBaudRate.SetItemData( nIndex,CBR_256000);
	m_cboBaudRate.SetCurSel(0);

	//parity 
    str="Even";
	nIndex=m_cboParity.AddString(str);
    m_cboParity.SetItemData( nIndex,EVENPARITY);

	str="Mark";
    nIndex=m_cboParity.AddString(str);
    m_cboParity.SetItemData( nIndex,MARKPARITY);

   	str="No parity";
    nIndex=m_cboParity.AddString(str);
    m_cboParity.SetItemData( nIndex,NOPARITY);

	str="Odd";
    nIndex=m_cboParity.AddString(str);
    m_cboParity.SetItemData( nIndex,ODDPARITY);

	m_cboParity.SetCurSel(0);

	//stop bits 
	str="1";
	nIndex=m_cboStopBits.AddString(str);
	m_cboStopBits.SetItemData( nIndex,ONESTOPBIT); 
	str="1.5";
	nIndex=m_cboStopBits.AddString(str);
	m_cboStopBits.SetItemData( nIndex,ONE5STOPBITS);
	str="2";
	nIndex=m_cboStopBits.AddString(str);
	m_cboStopBits.SetItemData( nIndex,TWOSTOPBITS);
	m_cboStopBits.SetCurSel(0);

	//Byte Size 
	str="7";
	nIndex=m_cboByteSize.AddString(str);
	m_cboByteSize.SetItemData( nIndex,7);
	
	str="8";
	nIndex=m_cboByteSize.AddString(str);
	m_cboByteSize.SetItemData( nIndex,8); 
	m_cboByteSize.SetCurSel(0);


}

BOOL CCommParameters::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	LoadCombos();
	
	if (!m_bModeNew) {
		ShowParameters();
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CCommParameters::ShowParameters()
{
	int iIndex;
	CString str;
	CButton* pRadTransMode;
	BSTR bstrTCPServer=NULL;
	long lTcpPort=0;
	VARIANT_BOOL bVal;

	ASSERT(m_pConnection);

	CAutoModbus* m_pautoModbus = m_pConnection->AutoPtr();


	str.Format("COM%d",m_pautoModbus->ComPort());
	iIndex=m_cboPorta.FindString(-1, str);
	m_cboPorta.SetCurSel( iIndex );
	//baudrate 
	str.Format("%d",(m_pautoModbus->BaudRate()));
    iIndex=m_cboBaudRate.FindString(-1, str);
    m_cboBaudRate.SetCurSel( iIndex );

	//parity 
	switch (m_pautoModbus->Parity()) {
    case EVENPARITY:
		 str="Even"; 
		break;
    case MARKPARITY:
        str="Mark";
		break;
    case NOPARITY:
        str="No parity";
		break;
	case ODDPARITY:
		str="Odd";
		break;
    default:
		str="";
	}

	iIndex=m_cboParity.FindString(-1, str);
    m_cboParity.SetCurSel( iIndex );
    

	//StopBits 
	switch (m_pautoModbus->StopBits()) {
    case ONESTOPBIT:
		 str="1"; 
		break;
    case ONE5STOPBITS:
        str="1.5";
		break;
    case TWOSTOPBITS:
        str="2";
		break;
	default:
		str="2";
	}

	iIndex=m_cboStopBits.FindString(-1, str);
    m_cboStopBits.SetCurSel(iIndex);

	//ByteSize
	switch (m_pautoModbus->ByteSize()) {
	case 7:
		str="7";
		break;
	case 8:
		str="8";
		break;
	default:
		str="8";
		break;
	
	}

	iIndex=m_cboByteSize.FindString(-1, str);
    m_cboByteSize.SetCurSel(iIndex);


	//time-out 
    str.Format("%d",m_pautoModbus->Timeout());
    m_edtTimeOut.SetWindowText(str);
	//char interval 
    str.Format("%d",m_pautoModbus->SilentInterval());
    m_edtCharInterval.SetWindowText(str);
     
    //Delay 
	str.Format("%d",m_pautoModbus->Delay());
	m_edtDelay.SetWindowText(str);


	//active com port 
	m_chkActive.SetCheck(m_pautoModbus->IsActive());

	//flow control 

    m_bDTRDSR=(mbFC_DTRDSR&m_pautoModbus->FlowControl())!=0;
	m_bRTSCTS=(mbFC_RTSCTS&m_pautoModbus->FlowControl())!=0;
    m_bXONXOFF=(mbFC_XONXOFF&m_pautoModbus->FlowControl())!=0;

	//Transmission Mode 
	switch (m_pautoModbus->TransmissionMode()) {
	case mbMODE_RTU:
		pRadTransMode=(CButton*)GetDlgItem(IDC_RAD_RTU);
		break;
	
	case mbMODE_ASCII:
	
    default:
		pRadTransMode=(CButton*)GetDlgItem(IDC_RAD_ASCII);

	}
	
	 pRadTransMode->SetCheck(1);

	 //Show DCOM 
	m_edtDcomServer.SetWindowText(m_pautoModbus->Machine());

	//TCP Server 
	if (FAILED(m_pautoModbus->m_pITCPServer->get_ServerAddress(&bstrTCPServer))){
		ASSERT(FALSE);
	}
	else {
		str =bstrTCPServer;
		::SysFreeString(bstrTCPServer);
		m_edtServerIP.SetWindowText(str);
	}
	
	VERIFY(!FAILED(m_pautoModbus->m_pITCPServer->get_ServerPort(&lTcpPort)));
	str.Format("%d",lTcpPort);
	m_edtServerPort.SetWindowText(str);

	bVal=VARIANT_FALSE;
	VERIFY(!FAILED(m_pautoModbus->m_pITCPServer->get_ServerActive(&bVal)));

	if (VARIANT_TRUE==bVal){
		m_chkTcpServer.SetCheck(1);
	}
	else {
		m_chkTcpServer.SetCheck(0);
	}

	if (!m_bModeNew) {
		m_edtDcomServer.EnableWindow(FALSE);
		m_cboPorta.EnableWindow(FALSE);
	}

	UpdateData(FALSE);

	return TRUE;
}


BOOL CCommParameters::SaveParameters()
{
	  int nIndex;
	  DWORD dwBaudRate=0;
	  BYTE byParity=0;
	  DWORD dwTimeout;
	  DWORD dwSilentInterval;
	  CString str;
	  CString sAux;
	  CString sConnectionName;
	  CString sMachine;
	  BSTR bstr=NULL;
	  BYTE byFlowControl;
	  CButton* pRadTransMode;
	  CAutoModbus* m_pautoModbus=NULL;	
	  VARIANT_BOOL bValue=VARIANT_FALSE;
	  HRESULT hr;

	  CWaitCursor wait;    // display wait cursor


	  UpdateData(TRUE);

	  
	  if (m_bModeNew) {
		  //Create New Connection 
		  nIndex=m_cboPorta.GetCurSel();
		  sAux.Format("com%d",nIndex+1);
		  m_edtDcomServer.GetWindowText(sMachine);
		  sMachine.TrimLeft();
		  sMachine.TrimRight();
		  if (!sMachine.IsEmpty()) { 
			  str=sMachine+_T(":")+sAux;
		  }  
		  else{ 
			  str = sAux;
		  }
		  
		  sConnectionName= str; 
		  
		  if (gConnections.Lookup(sConnectionName,m_pConnection)) {
				AfxMessageBox("Connection Alredy Exist");
				Connection(NULL);
				return FALSE;
		  }

		  
		  m_pConnection= gConnections.Add(sConnectionName, CConnection::AUTO);
		  
		  if (NULL==m_pConnection) {
			   AfxMessageBox("Error Adding Connection");
			   return FALSE;
		  }

		  m_pautoModbus=m_pConnection->AutoPtr();
		
		  hr = m_pautoModbus->CreateInstance(sMachine,sAux);
		  
		  if(FAILED(hr)) {
			  
			  if (!GetErrorMsg(hr,sAux.GetBuffer(500),500)) {
				  sAux= _T("Can't Create Automation Object");			  
			  }

			  AfxMessageBox(sAux);
			  goto ParamError;
		  }

	  }
	  else {

		  //edit connection 
		  ASSERT(m_pConnection);
		  m_pautoModbus= m_pConnection->AutoPtr();
	  
	  }
	  
	  if (0==m_chkActive.GetCheck()) {  //0==unchecked
		  //if(!m_pautoModbus->CloseConnection()){
		//	  AfxMessageBox("Failed to close Connection");
		  //}
	  }

	  if (m_pautoModbus->IsActive()&&m_bModeNew) {
			if (IDYES==AfxMessageBox( _T("This connection is already opened by other app. Show current parameters?")
				,MB_YESNO)) {

				ShowParameters();
				goto ParamError;
			}
		
	  }

	  //com port 
	  nIndex=m_cboPorta.GetCurSel();
	 
	  if (nIndex<0) {
		  AfxMessageBox("Invalid com port");
		  goto ParamError;
	  }

	  m_pautoModbus->ComPort(BYTE(nIndex+1));
	  
	  //Baud Rate 

	  nIndex=m_cboBaudRate.GetCurSel();

	  if (nIndex<0) {
		  AfxMessageBox("Invalid Baud-Rate");
		  goto ParamError;
	  }
	  dwBaudRate=m_cboBaudRate.GetItemData(nIndex);

	  m_pautoModbus->BaudRate(dwBaudRate);
	  
	  //parity  
	  nIndex=m_cboParity.GetCurSel();
	  
	  if (nIndex<0) {
		  AfxMessageBox("Invalid Parity");
		  goto ParamError;
	  }	

	  byParity=BYTE(m_cboParity.GetItemData(nIndex));

	  m_pautoModbus->Parity(byParity);
	  	  
	  //Stop bits  
	  nIndex=m_cboStopBits.GetCurSel();
	  
	  if (nIndex<0) {
		  AfxMessageBox("Invalid Stop Bits");
		  goto ParamError;
	  }	
	  
	  m_pautoModbus->StopBits((BYTE)m_cboStopBits.GetItemData(nIndex));

	  
	  byFlowControl=mbFC_NONE; 
	  if (m_bDTRDSR) {
		  byFlowControl=byFlowControl|mbFC_DTRDSR;
	  }
	  
	  if (m_bRTSCTS) {
		  byFlowControl=byFlowControl|mbFC_RTSCTS;
	  }
	  
	  if (m_bXONXOFF) {
		  byFlowControl=byFlowControl|mbFC_XONXOFF;
	  }
	  m_pautoModbus->FlowControl(byFlowControl);

	  //timeout 
	  m_edtTimeOut.GetWindowText(str);
	  dwTimeout=(DWORD)atol(str);
	  if (0==dwTimeout) {
		  AfxMessageBox("Invalid timeout");
		  goto ParamError;
	  }
	  m_pautoModbus->Timeout(dwTimeout);

	  //silentinterval 
	  m_edtCharInterval.GetWindowText(str);
	  dwSilentInterval=(DWORD)atol(str);
	  if (0==dwSilentInterval) {
		  AfxMessageBox("Invalid Char Interval");
		  goto ParamError;
	  }
	  
	  m_pautoModbus->SilentInterval(dwSilentInterval);


	  //Delay 
      m_edtDelay.GetWindowText(str);
	  m_pautoModbus->Delay((DWORD)atol(str));

	  //Transmission Mode 
	  pRadTransMode=(CButton*)GetDlgItem(IDC_RAD_RTU);
	  
	  ASSERT(pRadTransMode);
	  
	  if (FALSE!=pRadTransMode->GetCheck()) {
		  m_pautoModbus->TransmissionMode(mbMODE_RTU);
	  }
	  else {
		  m_pautoModbus->TransmissionMode(mbMODE_ASCII);
		  
	  }


	  //Byte Size  
	  nIndex=m_cboByteSize.GetCurSel();
	  
	  if (nIndex<0) {
		  AfxMessageBox("Invalid Byte Size");
		  goto ParamError;
	  }	
	  
	  m_pautoModbus->ByteSize((BYTE)m_cboByteSize.GetItemData(nIndex));
	  
	  if (! m_pautoModbus->Connect()){
		  AfxMessageBox("Can't connect");
		  goto ParamError;
	  }
	  

	  //TCP Server 
	  if (1==m_chkTcpServer.GetCheck()) {//checked

		//address
		m_edtServerIP.GetWindowText(str);
		bstr= str.AllocSysString();
		m_pautoModbus->m_pITCPServer->put_ServerAddress(bstr);
		::SysFreeString(bstr);
		//port 
		m_edtServerPort.GetWindowText(str);
		m_pautoModbus->m_pITCPServer->put_ServerPort(WORD(atol(str)));
		m_pautoModbus->m_pITCPServer->StartServer(&bValue);
		if (VARIANT_FALSE==bValue){
			 AfxMessageBox("Error Starting Modbus TCP server");
			 goto ParamError;
		}

	  }
	  else {
		m_pautoModbus->m_pITCPServer->StopServer(&bValue);
		if (VARIANT_FALSE==bValue){
			 AfxMessageBox("Error Stoping Modbus TCP server");
			 goto ParamError;
		}
	  }
	  return (TRUE);

ParamError:
	if (m_bModeNew) {
		gConnections.Remove(sConnectionName); //Remove New Connection 
		Connection(NULL);
	}
	 return (FALSE);
}





void CCommParameters::Connection(CConnection* pConnection)
{
	m_pConnection = pConnection;
}

CConnection* CCommParameters::Connection(){
  
	return m_pConnection;
}


void CCommParameters::OnOkey() 
{
	
	if (SaveParameters()) {
		CDialog::OnOK();
	}	
}

void CCommParameters::OnCancel() 
{
	// TODO: Add extra cleanup here
	Connection(NULL);
	CDialog::OnCancel();
}

void CCommParameters::OnButtFindIP() 
{

	CWaitCursor wait;    // display wait cursor

	try {
		m_edtServerIP.SetWindowText(CBlockingSocket::GetHostIP());
	}
	catch(CBlockingSocketException* e) {
		e->Delete();
		AfxMessageBox("Failed finding local machine IP");
	}
	
}
