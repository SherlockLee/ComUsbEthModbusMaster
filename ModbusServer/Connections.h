// Connections.h: interface for the CConnections class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTIONS_H__6DE30686_C724_11D1_8FE9_E4CD05C10000__INCLUDED_)
#define AFX_CONNECTIONS_H__6DE30686_C724_11D1_8FE9_E4CD05C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Connection.h"


class CConnections : public CMap<CString,LPCSTR ,CConnection*,CConnection*>  
{
public:
	void Remove(LPCTSTR sKey);
	CConnection* Add(LPCTSTR sKey, WORD wType);
	CConnections();
	virtual ~CConnections();
	
};

#endif // !defined(AFX_CONNECTIONS_H__6DE30686_C724_11D1_8FE9_E4CD05C10000__INCLUDED_)
