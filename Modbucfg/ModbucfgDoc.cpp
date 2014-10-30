// ModbucfgDoc.cpp : implementation of the CModbucfgDoc class
//

#include "stdafx.h"
#include "Modbucfg.h"

#include "ModbucfgDoc.h"
#include "ModbucfgView.h"

#include "globals.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModbucfgDoc

IMPLEMENT_DYNCREATE(CModbucfgDoc, CDocument)

BEGIN_MESSAGE_MAP(CModbucfgDoc, CDocument)
	//{{AFX_MSG_MAP(CModbucfgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CModbucfgDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CModbucfgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IModbucfg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {A3BAD4A7-F5AE-11D1-8FE9-6CD504C1BC01}
static const IID IID_IModbucfg =
{ 0xa3bad4a7, 0xf5ae, 0x11d1, { 0x8f, 0xe9, 0x6c, 0xd5, 0x4, 0xc1, 0xbc, 0x1 } };

BEGIN_INTERFACE_MAP(CModbucfgDoc, CDocument)
	INTERFACE_PART(CModbucfgDoc, IID_IModbucfg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModbucfgDoc construction/destruction

CModbucfgDoc::CModbucfgDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CModbucfgDoc::~CModbucfgDoc()
{
	AfxOleUnlockApp();
}

BOOL CModbucfgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if (gConnections.GetCount()<1) {
		AfxMessageBox(_T("There are no connections to open new document"));
		return FALSE;
	}

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CModbucfgDoc serialization

void CModbucfgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CModbucfgDoc diagnostics

#ifdef _DEBUG
void CModbucfgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CModbucfgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CModbucfgDoc commands

void CModbucfgDoc::OnCloseDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
	CWaitCursor wait;    // display wait cursor
	POSITION pos = GetFirstViewPosition();  
	while (pos != NULL)   {
      CModbucfgView* pModbucfgView = (CModbucfgView*)GetNextView(pos);   
	  pModbucfgView->Stop();
	  while (pModbucfgView->IsBusy()) {
		  CThinThread::DoEvents();
	  }
	}   
	CDocument::OnCloseDocument();
}
