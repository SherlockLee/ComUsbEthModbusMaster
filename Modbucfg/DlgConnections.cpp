// DlgConnections.cpp : implementation file
//

#include "stdafx.h"
#include "Modbucfg.h"
#include "DlgConnections.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgConnections dialog


CDlgConnections::CDlgConnections(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgConnections::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgConnections)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgConnections::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgConnections)
	DDX_Control(pDX, IDC_LST_CONNECTIOS, m_lstConnections);
	DDX_Control(pDX, IDC_CMD_REMOVE, m_cmdRemove);
	DDX_Control(pDX, IDC_CMD_EDIT, m_cmdEdit);
	DDX_Control(pDX, IDC_CMD_ADD, m_cmdType);
	DDX_Control(pDX, IDC_CBO_TYPE, m_cboType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgConnections, CDialog)
	//{{AFX_MSG_MAP(CDlgConnections)
	ON_BN_CLICKED(IDC_CMD_ADD, OnCmdAdd)
	ON_BN_CLICKED(IDC_CMD_EDIT, OnCmdEdit)
	ON_BN_CLICKED(IDC_CMD_REMOVE, OnCmdRemove)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgConnections message handlers

void CDlgConnections::LoadControls()
{
	POSITION pos;
	//new connection type 
	m_cboType.ResetContent();
	m_cboType.AddString(_T("Local/DCom"));
	m_cboType.AddString(_T("Open Modbus"));
	m_cboType.SetCurSel(0);
	CString sKey;
	CConnection* pConnection;

	pos = gConnections.GetStartPosition();
	
	m_lstConnections.ResetContent();

	while (NULL!=pos) {
		gConnections.GetNextAssoc(pos,sKey,pConnection);
		m_lstConnections.AddString(sKey);
	}


}

BOOL CDlgConnections::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	LoadControls();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgConnections::OnCmdAdd() 
{
	int nIndex;
	
	CConnection* pConnection=NULL;
	CCommParameters dlgComParameters;
	CDlgRemoteParameters dlgRemoteParameters;
	
	nIndex = m_cboType.GetCurSel();

	switch (nIndex) {
	case 0: //Auto 
		
		dlgComParameters.m_bModeNew=TRUE;
		dlgComParameters.Connection(NULL);
		dlgComParameters.DoModal();
		pConnection = dlgComParameters.Connection();
		
		break;
		
	case 1: //Remote
		
		dlgRemoteParameters.m_bModeNew=TRUE;
		dlgRemoteParameters.Connection(NULL);
		dlgRemoteParameters.DoModal();
		pConnection = dlgRemoteParameters.Connection();
		
		break;
	}


	if (NULL!=pConnection) {
		
		m_lstConnections.AddString(pConnection->Key());
	}
	
}

void CDlgConnections::OnCmdEdit() 
{
	int nIndex;
	CString sKey;
	CConnection* pConnection =NULL;
	CCommParameters dlgComParameters;
	CDlgRemoteParameters dlgRemoteParameters;
	
	nIndex = m_lstConnections.GetCurSel();
	
	if (nIndex>=0) {
		m_lstConnections.GetText(nIndex,sKey);
		
		if (gConnections.Lookup(sKey,pConnection)) {
			
			switch (pConnection->Type()) {
				
			case CConnection::AUTO:
				dlgComParameters.m_bModeNew=FALSE;
				dlgComParameters.Connection(pConnection);
				dlgComParameters.DoModal();
				break; 
			case CConnection::REMOTE:
				dlgRemoteParameters.m_bModeNew=FALSE;
				dlgRemoteParameters.Connection(pConnection);
				dlgRemoteParameters.DoModal();
				break;
			default:
				ASSERT(FALSE);
				
			}
		}
		
	}
	
}

void CDlgConnections::OnCmdRemove() 
{
	int nIndex;
	CString sKey;
	int iResp;
		
	nIndex = m_lstConnections.GetCurSel();
	
	if (nIndex>=0) {
		m_lstConnections.GetText(nIndex,sKey);
		iResp=AfxMessageBox(_T("Remove connection ")+sKey,MB_YESNO);
		if (IDYES==iResp)  {
				gConnections.Remove(sKey);
				m_lstConnections.DeleteString(nIndex);
		}
		
	}
	
}

void CDlgConnections::OnButtonSave() 
{
	CFile fileCfg;
	
	if (fileCfg.Open("Modbu.cfg",CFile::modeCreate|CFile::modeWrite)){
		
		CArchive archConfig(&fileCfg,CArchive::store);
		gConnections.Serialize(archConfig);
		archConfig.Close();
		fileCfg.Close();
	}	
}

void CDlgConnections::OnButtonLoad() 
{

	CFile fileCfg;

	gConnections.RemoveAll();

	if (fileCfg.Open("Modbu.cfg",CFile::modeRead)){
		
		try {
			CArchive archConfig(&fileCfg,CArchive::load);
			gConnections.Serialize(archConfig);
			archConfig.Close();

			LoadControls();
		}
		
		catch( CException* e )
		{
			// Handle the exception here.
			// "e" contains information about the exception.
			e->Delete();
			
		}//end catch
		
		fileCfg.Close(); 
	}
}
