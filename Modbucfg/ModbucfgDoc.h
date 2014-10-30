// ModbucfgDoc.h : interface of the CModbucfgDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODBUCFGDOC_H__A3BAD4B3_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
#define AFX_MODBUCFGDOC_H__A3BAD4B3_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CModbucfgDoc : public CDocument
{
protected: // create from serialization only
	CModbucfgDoc();
	DECLARE_DYNCREATE(CModbucfgDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModbucfgDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CModbucfgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CModbucfgDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CModbucfgDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODBUCFGDOC_H__A3BAD4B3_F5AE_11D1_8FE9_6CD504C1BC01__INCLUDED_)
