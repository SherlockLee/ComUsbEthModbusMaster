// DlgRemoteParameters.cpp : implementation file
//

#include "stdafx.h"
#include "Modbucfg.h"
#include "DlgRemoteParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRemoteParameters dialog


CDlgRemoteParameters::CDlgRemoteParameters(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRemoteParameters::IDD, pParent)
{
	m_bModeNew=FALSE;
	m_pConnection=NULL;

	//{{AFX_DATA_INIT(CDlgRemoteParameters)
	//}}AFX_DATA_INIT
}


void CDlgRemoteParameters::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRemoteParameters)
	DDX_Control(pDX, IDC_EDIT_TIME_OUT, m_edtTimeOut);
	DDX_Control(pDX, IDC_EDIT_PORT, m_edtServerPort);
	DDX_Control(pDX, IDC_EDIT_IP_ADDR, m_edtServerAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRemoteParameters, CDialog)
	//{{AFX_MSG_MAP(CDlgRemoteParameters)
	ON_BN_CLICKED(IDOKey, OnOKey)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CDlgRemoteParameters::Connection(CConnection* pConnection)
{
	m_pConnection = pConnection;
}

CConnection* CDlgRemoteParameters::Connection(){
  
	return m_pConnection;
}



BOOL CDlgRemoteParameters::ShowParameters()
{
	
	ASSERT(m_pConnection);

	CRemoteModbus* pRemoteModbus = m_pConnection->RemotePtr();

	CString str;

	m_edtServerAddress.SetWindowText(pRemoteModbus->Host());

	str.Format("%d",pRemoteModbus->Port());

	m_edtServerPort.SetWindowText(str);

	str.Format("%d",pRemoteModbus->Timeout());

	m_edtTimeOut.SetWindowText(str);

	if (!m_bModeNew) {
		m_edtServerPort.EnableWindow(FALSE);
		m_edtServerAddress.EnableWindow(FALSE);
	}

	return TRUE;
}

BOOL CDlgRemoteParameters::SaveParameters()
{
	  
	DWORD dwTimeout;
	  
	  CString str;
	  CString sConnectionName;
	  CString sMachine;
	  
	  CRemoteModbus* pRemoteModbus=NULL;	
	 
	  UpdateData(TRUE);

	  
	  if (m_bModeNew) {
		  
		  m_edtServerPort.GetWindowText(str);
		  str.TrimLeft();
		  str.TrimRight();
		  
		  m_edtServerAddress.GetWindowText(sMachine);
		  
		  sMachine.TrimLeft();
		  sMachine.TrimRight();
		 		  
		  sConnectionName = sMachine + _T(":") + str;
		  
		  if (gConnections.Lookup(sConnectionName,m_pConnection)) {
				AfxMessageBox("Connection Alredy Exist");
				Connection(NULL);
				return FALSE;
		  }

		  
		  m_pConnection= gConnections.Add(sConnectionName, CConnection::REMOTE);
		  
		  if (NULL==m_pConnection) {
			   AfxMessageBox("Error Adding Connection");
			   return FALSE;
		  }

		  pRemoteModbus=m_pConnection->RemotePtr();
	
		  
	  }
	  else {

		  //edit connection 
		  ASSERT(m_pConnection);
		  pRemoteModbus= m_pConnection->RemotePtr();
	  
	  }
	  
	  
	  //timeout 
	  m_edtTimeOut.GetWindowText(str);
	  dwTimeout=(DWORD)atol(str);
	  if (0==dwTimeout) {
		  AfxMessageBox("Invalid timeout");
		  goto ParamError;
	  }
	  
	  pRemoteModbus->Timeout(dwTimeout);


	  //host
	  m_edtServerAddress.GetWindowText(str);
	  pRemoteModbus->Host(str);
	  
	  //port 	
	  m_edtServerPort.GetWindowText(str);
	  pRemoteModbus->Port((WORD)atol(str));

	  
	  pRemoteModbus->ReconnectOnEveryMessage(TRUE);

	  if (!pRemoteModbus->openConnection()) {
		  AfxMessageBox("Connection Error");
		  goto ParamError;
	  }

	  return (TRUE);

ParamError:
	if (m_bModeNew) {
		gConnections.Remove(sConnectionName); //Remove New Connection 
		Connection(NULL);
	}
	 return (FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgRemoteParameters message handlers



void CDlgRemoteParameters::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}



BOOL CDlgRemoteParameters::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	if (!m_bModeNew) {
		ShowParameters();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRemoteParameters::OnOKey() 
{
	if (SaveParameters()) {
		CDialog::OnOK();
	}
	
}
