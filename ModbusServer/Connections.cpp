// Connections.cpp: implementation of the CConnections class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Connections.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConnections::CConnections()
{

}

CConnections::~CConnections()
{

}

CConnection* CConnections::Add(LPCTSTR sKey, WORD wType)
{

	CConnection* pConnection=NULL;

	if (Lookup(sKey,pConnection)) {

		pConnection->Addref();

		return pConnection;

	}

	pConnection = new CConnection(wType,sKey);

	SetAt(sKey,pConnection);

	return pConnection;
}

void CConnections::Remove(LPCTSTR sKey)
{
	CConnection* pConnection =NULL;
	LONG lRef;

	if (Lookup(sKey,pConnection)) {

		lRef=pConnection->Release();
		
		if (0==lRef) {
			if (!RemoveKey(sKey)) {
				ASSERT(FALSE);
			}
		}

	}


}
