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


IMPLEMENT_DYNAMIC( CConnections , CObject)


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConnections::CConnections()
{

}

CConnections::~CConnections()
{
	RemoveAll();
}

CConnection* CConnections::Add(LPCTSTR sKey, WORD wType)
{

	CConnection* pConnection=NULL;

	if (Lookup(sKey,pConnection)) {

		ASSERT(FALSE);
		return NULL;

	}

	pConnection = new CConnection(wType,sKey);

	SetAt(sKey,pConnection);

	return pConnection;
}

void CConnections::Remove(LPCTSTR sKey)
{
	CConnection* pConnection =NULL;
	
	if (Lookup(sKey,pConnection)) {

		pConnection->Delete();

		if (!RemoveKey(sKey)) {
				ASSERT(FALSE);
			}
	
	}


}

void CConnections::RemoveAll()
{

	POSITION pos;
	CString sKey;
	pos = GetStartPosition();
	CConnection* pConnection;
	
	while (NULL!=pos) {
		GetNextAssoc(pos,sKey,pConnection);
		Remove(sKey);
		pos = GetStartPosition();
	}

}

void CConnections::Serialize( CArchive& archive )
{
	int iCount=0;
	POSITION pos;
	CString sKey;
	CConnection* pConnection;
	WORD wType;
	int i=0;
	
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize( archive );
	
	
	// now do the stuff for our specific class
	if( archive.IsStoring() ){
		iCount=GetCount();
		archive <<iCount;
		
		pos = GetStartPosition();
		
		while (NULL!=pos) {
			GetNextAssoc(pos,sKey,pConnection);
			//Serialize each connection 
			archive <<sKey<< pConnection->Type();
			pConnection->Serialize(archive);
		}
		
	} 
	
	else {
		archive >>iCount;
		
		for (i=0;i<iCount;i++){
			archive >>sKey>>wType;
			pConnection= Add(sKey,wType);
			pConnection->Serialize(archive);
			if (CConnection::AUTO==pConnection->Type()) {
				if (!pConnection->AutoPtr()->m_pIModbusSrv) {
					Remove(sKey);
				}
			}
			
		}
	}
	
}