#if !defined(AFX_DLGCONNECTIONS_H__4D342E25_FE27_11D1_8FE9_68D504C1BC01__INCLUDED_)
#define AFX_DLGCONNECTIONS_H__4D342E25_FE27_11D1_8FE9_68D504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgConnections.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgConnections dialog

#include "globals.h"

#include "CommParameters.h"

#include "DlgRemoteParameters.h"

class CDlgConnections : public CDialog
{
// Construction
public:
	void LoadControls();
	CDlgConnections(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgConnections)
	enum { IDD = IDD_CONNECTIONS };
	CListBox	m_lstConnections;
	CButton	m_cmdRemove;
	CButton	m_cmdEdit;
	CButton	m_cmdType;
	CComboBox	m_cboType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgConnections)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	enum _General_DlgConnections_Constants_ {
		LOCAL_DCOM=0,
		OPEN_MODBUS=1	
	};
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgConnections)
	virtual BOOL OnInitDialog();
	afx_msg void OnCmdAdd();
	afx_msg void OnCmdEdit();
	afx_msg void OnCmdRemove();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONNECTIONS_H__4D342E25_FE27_11D1_8FE9_68D504C1BC01__INCLUDED_)
