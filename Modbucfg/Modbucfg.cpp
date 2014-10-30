// Modbucfg.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Modbucfg.h"
#include "OleFuncs.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "ModbucfgDoc.h"
#include "ModbucfgView.h"
#include "AutoModbus.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CComModule _Module;

/////////////////////////////////////////////////////////////////////////////
// CModbucfgApp

BEGIN_MESSAGE_MAP(CModbucfgApp, CWinApp)
	//{{AFX_MSG_MAP(CModbucfgApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModbucfgApp construction

CModbucfgApp::CModbucfgApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CModbucfgApp object

CModbucfgApp theApp;

// This identifier was generated to be statistically unique for your app.
// You may change it if you prefer to choose a specific identifier.

// {A3BAD4A5-F5AE-11D1-8FE9-6CD504C1BC01}
static const CLSID clsid =
{ 0xa3bad4a5, 0xf5ae, 0x11d1, { 0x8f, 0xe9, 0x6c, 0xd5, 0x4, 0xc1, 0xbc, 0x1 } };

/////////////////////////////////////////////////////////////////////////////
// CModbucfgApp initialization

BOOL CModbucfgApp::InitInstance()
{

	if (!DComOk()) {
		AfxMessageBox(_T("DCOM OLE Not supported"),MB_SYSTEMMODAL+MB_OK);
		return FALSE;       
	}

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Initialize OLE libraries
	if (!AfxOleInit2())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	//SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_MODBUCTYPE,
		RUNTIME_CLASS(CModbucfgDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CModbucfgView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
	
	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// DON'T display a new MDI child window during startup!!!
    cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CModbucfgApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CModbucfgApp commands

void CModbucfgApp::Test()
{
	
	CAutoModbus autoModbus;
	
	autoModbus.CreateInstance("","com3");
	
	autoModbus.ComPort(3);
	autoModbus.BaudRate(1200);
	autoModbus.Parity(mbNOPARITY);
	autoModbus.Timeout(500);
	autoModbus.TransmissionMode(mbMODE_RTU);
	
	
	
	autoModbus.m_pIModbusSrv->put_RaiseError(VARIANT_TRUE);
	
	if (!autoModbus.Connect()) {
		return;
		
	}
	
	if (!autoModbus.LoopbackTest(1)){
	}
	
	
}


BOOL CModbucfgApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
	if (CSplashWnd::PreTranslateAppMessage(pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}


BOOL RegTypeLib(LPCSTR szTypeLibName) {

	WCHAR* pwsz = new WCHAR[MAX_PATH];
	BOOL bResp=FALSE;
	HRESULT hRes;
	ITypeLib* pITypeLib;
	
	::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szTypeLibName , -1,
			pwsz, MAX_PATH);

	hRes= ::LoadTypeLib((OLECHAR FAR*)pwsz,&pITypeLib);
	
	if FAILED(hRes){
		bResp=FALSE;
	}
	else {
		hRes = ::RegisterTypeLib((ITypeLib FAR*)pITypeLib,pwsz,NULL);   
		bResp=(S_OK==hRes);
		pITypeLib->Release();
	}
    
	delete[]pwsz;
	
	return bResp;
}


