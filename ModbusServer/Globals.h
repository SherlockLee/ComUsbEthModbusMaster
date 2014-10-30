// Globals.h: interface for the CGlobals class.
//
//////////////////////////////////////////////////////////////////////

#include "Connections.h"

#if !defined(AFX_GLOBALS_H__6DE30687_C724_11D1_8FE9_E4CD05C10000__INCLUDED_)
#define AFX_GLOBALS_H__6DE30687_C724_11D1_8FE9_E4CD05C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CGlobals  
{
public:
	CGlobals();
	virtual ~CGlobals();

};


extern CConnections gConnections; //Collection with all connectiosn local or remore


#endif // !defined(AFX_GLOBALS_H__6DE30687_C724_11D1_8FE9_E4CD05C10000__INCLUDED_)
