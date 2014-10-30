// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__A3BAD4AF_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
#define AFX_MAINFRM_H__A3BAD4AF_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "trayicon.h"

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

	CTrayIcon	m_trayIcon;		// my tray icon

// Generated message map functions
protected:
	afx_msg LRESULT OnTrayNotification(WPARAM wp, LPARAM lp);
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnOptionsConnections();
	afx_msg void OnTrayMain();
	afx_msg void OnTrayConnections();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
	afx_msg void OnTrayExit();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnOptionsRegistertypeLibrary();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bConfiguringConnections;
	BOOL m_bTeminate;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__A3BAD4AF_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
