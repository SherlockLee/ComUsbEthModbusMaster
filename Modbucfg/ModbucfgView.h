// ModbucfgView.h : interface of the CModbucfgView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODBUCFGVIEW_H__A3BAD4B5_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
#define AFX_MODBUCFGVIEW_H__A3BAD4B5_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "Globals.h"
#include "ThinThread.h"

class CModbucfgView : public CFormView,public CThinThread
{
protected: // create from serialization only
	CModbucfgView();
	DECLARE_DYNCREATE(CModbucfgView)

public:
	//{{AFX_DATA(CModbucfgView)
	enum { IDD = IDD_MODBUCFG_FORM };
	CComboBox	m_cboDataType;
	CEdit	m_edtInterval;
	CButton	m_butPollEnable;
	CStatic	m_statStatus;
	CStatic	m_staError;
	CListBox	m_lstValues;
	CComboBox	m_cboWriteFunctions;
	CComboBox	m_cboReadFunctions;
	CComboBox	m_cboConnections;
	CEdit	m_edtValue;
	CEdit	m_edtQuant;
	CEdit	m_edtDevice;
	CEdit	m_edtWriteAddr;
	CEdit	m_edtReadAddr;
	CButton	m_cmdWrite;
	//}}AFX_DATA

// Attributes
public:
	CModbucfgDoc* GetDocument();

	enum _Modbus_Functions_ {
	 LOOP_BACK_TEST=0,
	 READ_OUTPUT_REGISTERS=1,
	 READ_INPUT_REGISTERS=2,
	 READ_OUTPUT_STATUS=3,
	 READ_INPUT_STATUS=4,
	 PRESET_SINGLE_REGISTER=0,
	 FORCE_SINGLE_COIL=1
	};

	enum _Data_Types_ {
		DATA_CHAR =0 , 
        DATA_SIGNED_16=1,
		DATA_UNSIGNED_16=2,
		DATA_FLOAT=3,
		DATA_FLOAT_REVERSE=4,
		DATA_DOUBLE=5,
		DATA_DOUBLE_REVERSE=6,
	};

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModbucfgView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void EndWork();
	virtual ~CModbucfgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CModbus* GetConnection();
	WORD ExecuteReadFunction(int iFunction,DWORD& dwTime , CString& rErrorMessage);
	void DoWork();
	void StartWork();
	void LoadControls();
	//{{AFX_MSG(CModbucfgView)
	afx_msg void OnchkEnablePoll();
	afx_msg void OnChangeEditInterval();
	afx_msg void OnCmdWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	DWORD m_dwSum; //thread vars 
    DWORD m_dwCount; 
	DWORD m_dwErrors;

};

#ifndef _DEBUG  // debug version in ModbucfgView.cpp
inline CModbucfgDoc* CModbucfgView::GetDocument()
   { return (CModbucfgDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODBUCFGVIEW_H__A3BAD4B5_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
