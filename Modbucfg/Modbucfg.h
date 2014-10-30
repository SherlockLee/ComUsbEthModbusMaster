// Modbucfg.h : main header file for the MODBUCFG application
//

#if !defined(AFX_MODBUCFG_H__A3BAD4AA_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
#define AFX_MODBUCFG_H__A3BAD4AA_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CModbucfgApp:
// See Modbucfg.cpp for the implementation of this class
//

class CModbucfgApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void Test();
	CModbucfgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModbucfgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//COleTemplateServer m_server;
		// Server object for document creation

	//{{AFX_MSG(CModbucfgApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BOOL RegTypeLib(LPCSTR szTypeLibName);

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODBUCFG_H__A3BAD4AA_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
