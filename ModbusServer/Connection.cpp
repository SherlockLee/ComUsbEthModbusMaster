// Connection.cpp: implementation of the CConnection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Connection.h"
#include "CTCPIPServer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( CConnection , CObject)



CConnection::CConnection(WORD wType , LPCTSTR sKey)
{
	m_dwRef=1;
	m_sKey = sKey;
	m_wType = wType;
	m_pTCPServer=NULL;

	switch (wType) {

	case LOCAL:
		m_pModbus= new CLocalModbus();
		m_pLocalModbus=(CLocalModbus*)m_pModbus;
		break;
	case REMOTE:
		m_pModbus= new CRemoteModbus();
		m_pRemoteModbus=(CRemoteModbus*)m_pModbus;
		break;
	default:
		ASSERT(FALSE); //Type Error
	}

}

CConnection::CConnection(const CConnection& rConnection)
{
	m_pModbus = rConnection.m_pModbus;
	m_pLocalModbus=rConnection.m_pLocalModbus;
	m_pRemoteModbus=rConnection.m_pRemoteModbus;
	m_dwRef = rConnection.m_dwRef;
	m_sKey = rConnection.m_sKey;
	m_wType = rConnection.m_wType;

}

CConnection::CConnection() {
	m_dwRef=1;
	m_pModbus=NULL;
	m_wType=NONE;
	m_pLocalModbus=NULL;
	m_pRemoteModbus=NULL;
	


}

CConnection::~CConnection()
{
	
	if (m_pModbus!=NULL) {
		switch (m_wType) {
			
		case LOCAL:
			delete (CLocalModbus*)m_pModbus;
			break;
		case REMOTE:
			delete (CRemoteModbus*)m_pModbus;
			break;
		default:
			ASSERT(FALSE); //Type Error
		}
	}


}



LONG CConnection::Addref()
{
	LONG l=::InterlockedIncrement((LONG*)&m_dwRef);
	//TRACE("CConnection Addref\n");
	
	return m_dwRef;

}

LONG CConnection::Release()
{
	LONG l=::InterlockedDecrement((LONG*)&m_dwRef);
	//TRACE("CConnection Release\n");
	if (0==l) {
		delete this;
	}
	
	return l;
}

WORD CConnection::Type()
{
	return m_wType;
}


void CConnection::Key(CString& sKey)
{
	m_sKey=sKey;
}

CString CConnection::Key(){
	
	return m_sKey;

}




//m_pTCPServer= new CComObject<CCTCPIPServer>;
//		m_pTCPServer->AddRef();

LPDISPATCH CConnection::GetTcpDispatch()
{
	IDispatch* pDisp;

	if (NULL==m_pTCPServer) {
		m_pTCPServer= new CComObject<CCTCPIPServer>;
		m_pTCPServer->ParentConnection(this);
		TCPIPServer(m_pTCPServer);
	}

	m_pTCPServer->QueryInterface(IID_IDispatch, (void**)&pDisp);
	_ASSERTE(pDisp);

	return pDisp;

}

void CConnection::TCPIPServer(CComObject<CCTCPIPServer>* pTcpServer)
{
	m_pTCPServer=pTcpServer;
}
