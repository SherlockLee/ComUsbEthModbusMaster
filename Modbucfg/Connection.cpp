// Connection.cpp: implementation of the CConnection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Connection.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( CConnection , CObject)


CConnection::CConnection()
{
	m_pModbus=NULL;
}

CConnection::~CConnection()
{

	
}


CConnection::CConnection(WORD wType , LPCTSTR sKey)
{
	m_sKey = sKey;
	m_wType = wType;
	
	switch (wType) {

	case AUTO:
		m_pModbus= new CAutoModbus();
		break;
	case REMOTE:
		m_pModbus= new CRemoteModbus();
		break;
	default:
		ASSERT(FALSE); //Type Error
	}

}

CConnection::CConnection(const CConnection& rConnection)
{
	m_pModbus = rConnection.m_pModbus;
	m_sKey = rConnection.m_sKey;
	m_wType = rConnection.m_wType;

}


CAutoModbus* CConnection::AutoPtr()
{
	if (AUTO==m_wType) {
		return (CAutoModbus*)m_pModbus;
	}
	else {
		ASSERT(FALSE);//Type Error 
		return NULL;
	}
}

CRemoteModbus* CConnection::RemotePtr()
{
	if (REMOTE==m_wType) {
		return (CRemoteModbus*)m_pModbus;
	}
	else {
		ASSERT(FALSE);//Type Error 
		return NULL;
	}

}

void CConnection::Delete()
{

	if (m_pModbus!=NULL) {
		switch (m_wType) {
			
		case AUTO:
			delete AutoPtr();
			break;
		case REMOTE:
			delete RemotePtr();
			break;
		default:
			ASSERT(FALSE); //Type Error
		}
	}

	delete this;
}


CString CConnection::DcomServer()
{
	return m_sDcomServer;
}

void CConnection::DcomServer(LPCTSTR szDcomServer)
{
	m_sDcomServer=szDcomServer;
}

CString CConnection::Key() {
	return m_sKey;
}

WORD CConnection::Type() {

	return m_wType;

}


 void CConnection::Serialize( CArchive& archive )
  {
	  // call base class function first
	  // base class is CObject in this case
	  CObject::Serialize( archive );
	  

	  // now do the stuff for our specific class
	  if( archive.IsStoring() ){
		 archive <<m_sDcomServer;
      } 
	  else {
		 archive >>m_sDcomServer;
      }
	  
	  switch(Type()) {
	  case AUTO:
		  AutoPtr()->Serialize(archive);
		  break;
	  case REMOTE:
		  RemotePtr()->Serialize(archive);
		  break;
	  }

  }