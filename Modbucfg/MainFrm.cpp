// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Modbucfg.h"

#include "MainFrm.h"

#include "Globals.h"

#include "CommParameters.h"

#include "DlgConnections.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

// Message ID used for tray notifications
#define WM_MY_TRAY_NOTIFICATION WM_USER+0


IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_MESSAGE(WM_MY_TRAY_NOTIFICATION, OnTrayNotification)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_OPTIONS_CONNECTIONS, OnOptionsConnections)
	ON_COMMAND(ID_TRAY_MAIN, OnTrayMain)
	ON_COMMAND(ID_TRAY_CONNECTIONS, OnTrayConnections)
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_COMMAND(ID_TRAY_EXIT, OnTrayExit)
	ON_WM_SIZE()
	ON_COMMAND(ID_OPTIONS_REGISTERTYPELIBRARY, OnOptionsRegistertypeLibrary)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame(): m_trayIcon(IDR_TRAY_ICON)
{
	m_bTeminate=FALSE;
	m_bConfiguringConnections=FALSE;
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);

	// Set up tray icon
	m_trayIcon.SetNotificationWnd(this, WM_MY_TRAY_NOTIFICATION);
	m_trayIcon.SetIcon(NULL);
	m_bTeminate=FALSE;

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnOptionsConnections() 
{
	CMDIChildWnd* pChildWnd=MDIGetActive();
	CDlgConnections	dlgConnections;
	
	if (pChildWnd!=NULL){
		ShowWindow(SW_SHOWNORMAL);
		AfxMessageBox("Close All documents before configuring connections");
		return;
	}
	
	m_bConfiguringConnections=TRUE;
	dlgConnections.DoModal();
	m_bConfiguringConnections=FALSE;	
}

// Handle notification from tray icon: display a message.
//
LRESULT CMainFrame::OnTrayNotification(WPARAM uID, LPARAM lEvent)
{

	// let tray icon do default stuff
	return m_trayIcon.OnTrayNotification(uID, lEvent);
}


void CMainFrame::OnTrayMain() 
{
	// The main window has been initialized, so show and update it.
	ShowWindow(SW_SHOWNORMAL);
	
}

void CMainFrame::OnTrayConnections() 
{

	if (m_bConfiguringConnections) {
		return;
	}

	OnOptionsConnections();

	
}

void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CMDIFrameWnd::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//ShowWindow(SW_HIDE);
	CMDIFrameWnd::OnClose();
}

void CMainFrame::OnTrayExit() 
{
	// TODO: Add your command handler code here
	CMDIFrameWnd::OnClose();
	
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	
	
	CMDIFrameWnd::OnSize(nType, cx, cy);

	if (SIZE_MINIMIZED==nType) {
		ShowWindow(SW_HIDE);
		m_trayIcon.SetIcon(IDR_TRAY_ICON);
	}
	else {
		m_trayIcon.SetIcon(NULL);
	}
	
	
		
}

void CMainFrame::OnOptionsRegistertypeLibrary() 
{

 CString sFilter;
	

 sFilter="Library Files (*.tlb)|*.tlb|All Files (*.*)|*.*||";

 CFileDialog  fileLib( TRUE, 
	                   NULL, 
					   NULL, 
					   OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
					   sFilter, 
					   (CWnd*)this);


 if (IDOK==fileLib.DoModal()) {
		
	 if (!RegTypeLib(fileLib.GetPathName())) {

          AfxMessageBox("Library registred failed");
	 }
	 else {
		 AfxMessageBox("Library registred");
	 }
 
 }


}
