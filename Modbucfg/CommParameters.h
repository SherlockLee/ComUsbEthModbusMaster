#if !defined(AFX_COMMPARAMETERS_H__598A7320_F984_11D1_9E7B_08C003C10000__INCLUDED_)
#define AFX_COMMPARAMETERS_H__598A7320_F984_11D1_9E7B_08C003C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CommParameters.h : header file
//

#include "Globals.h"

/////////////////////////////////////////////////////////////////////////////
// CCommParameters dialog

class CCommParameters : public CDialog
{
// Construction
public:
	BOOL SaveParameters();
	void Connection(CConnection* pConnection);
	CConnection* Connection();
	BOOL ShowParameters();
	void LoadCombos();
	CCommParameters(CWnd* pParent = NULL);   // standard constructor

	BOOL m_bModeNew;

// Dialog Data
	//{{AFX_DATA(CCommParameters)
	enum { IDD = IDD_MOD_LOCAL_COM_PARAM };
	CEdit	m_edtDelay;
	CButton	m_chkTcpServer;
	CEdit	m_edtDcomServer;
	CEdit	m_edtServerPort;
	CEdit	m_edtServerIP;
	CButton	m_chkActive;
	CEdit	m_edtCharInterval;
	CEdit	m_edtTimeOut;
	CComboBox	m_cboByteSize;
	CComboBox	m_cboStopBits;
	CComboBox	m_cboParity;
	CComboBox	m_cboPorta;
	CComboBox	m_cboBaudRate;
	BOOL	m_bDTRDSR;
	BOOL	m_bRTSCTS;
	BOOL	m_bXONXOFF;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommParameters)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommParameters)
	virtual BOOL OnInitDialog();
	afx_msg void OnOkey();
	virtual void OnCancel();
	afx_msg void OnButtFindIP();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CConnection* m_pConnection;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMPARAMETERS_H__598A7320_F984_11D1_9E7B_08C003C10000__INCLUDED_)
