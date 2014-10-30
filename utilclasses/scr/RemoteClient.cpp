// RemoteClient.cpp: implementation of the CRemoteClient class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"
#include "RemoteClient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Class CRemoteClient
IMPLEMENT_DYNAMIC(CRemoteClient, CObject)

CRemoteClient::CRemoteClient()
{
	psConnect=NULL;
	psaClient=NULL;
	
}

CRemoteClient::~CRemoteClient()
{

}

DWORD CRemoteClient::RxBytes()
{
	return m_dwRxBytes;
}

void CRemoteClient::AddRxBytes(DWORD dwBytes)
{
	m_dwRxBytes+=dwBytes;
}

DWORD CRemoteClient::TxBytes() 
{
	return m_dwTxBytes;
}

void CRemoteClient::AddTxBytes(DWORD dwBytes)
{
  m_dwTxBytes+=dwBytes;
}

void CRemoteClient::ResetTxRxCount()
{
  m_dwTxBytes=0;
  m_dwRxBytes=0;

}
