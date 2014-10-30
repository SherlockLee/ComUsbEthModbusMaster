#if !defined(AFX_DLGREMOTEPARAMETERS_H__2283C162_0041_11D2_8FE9_68D504C1BC01__INCLUDED_)
#define AFX_DLGREMOTEPARAMETERS_H__2283C162_0041_11D2_8FE9_68D504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgRemoteParameters.h : header file

//

#include "Globals.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgRemoteParameters dialog

class CDlgRemoteParameters : public CDialog
{
// Construction
public:
	CDlgRemoteParameters(CWnd* pParent = NULL);   // standard constructor

	BOOL SaveParameters();
	void Connection(CConnection* pConnection);
	CConnection* Connection();
	BOOL ShowParameters();
	CCommParameters(CWnd* pParent = NULL);   // standard constructor

	BOOL m_bModeNew;

// Dialog Data
	//{{AFX_DATA(CDlgRemoteParameters)
	enum { IDD = IDD_MOD_REM_PARAMETERS };
	CEdit	m_edtTimeOut;
	CEdit	m_edtServerPort;
	CEdit	m_edtServerAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRemoteParameters)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRemoteParameters)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnOKey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CConnection* m_pConnection;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGREMOTEPARAMETERS_H__2283C162_0041_11D2_8FE9_68D504C1BC01__INCLUDED_)
