// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__B3DE3CB8_C629_11D1_8FE9_E4CD05C10000__INCLUDED_)
#define AFX_STDAFX_H__B3DE3CB8_C629_11D1_8FE9_E4CD05C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define STRICT


#define _WIN32_WINNT 0x0400
#define _ATL_FREE_THREADED

#include "mbu.h"

#include <atlbase.h>


class CMyApp : public CWinApp      {     
public:
	void Test();
	
	virtual BOOL InitInstance();         
	virtual int ExitInstance();
};      

//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CExeModule : public CComModule
{
public:
	LONG Unlock();
	DWORD dwThreadID;
};
extern CExeModule _Module;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__B3DE3CB8_C629_11D1_8FE9_E4CD05C10000__INCLUDED)
