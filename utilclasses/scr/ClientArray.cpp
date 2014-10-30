// ClientArray.cpp: implementation of the CClientArray class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"
#include "ClientArray.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientArray::CClientArray()
{

	Clients.SetSize(MAX_CLIENTS);
	
}

CClientArray::~CClientArray()
{

}

int CClientArray::AddClient(CBlockingSocket * psConnect, CSockAddr * psaClient)
{
	int i;
	int iElement=-1;
	Lock();
	for (i=0;i<(Clients.GetSize()-1);++i){
		if (Clients[i].IsEmpty()) {
		   Clients[i].psConnect=psConnect;
		   Clients[i].psaClient=psaClient;
		   iElement=i;
		   break;
		}

	}
	Unlock();
	return iElement;
}

BOOL CClientArray::Lock()
{
	return m_csClients.Lock();
}

BOOL CClientArray::Unlock()
{
	return m_csClients.Unlock();
}

void CClientArray::RemoveClient(int iElement)
{

	Lock();
	if ((iElement>=0)&&(iElement<Clients.GetSize())&&(!Clients[iElement].IsEmpty())) {
		
		Clients[iElement].psConnect=NULL;
		Clients[iElement].psaClient=NULL;
				
	}
	Unlock();
}

void CClientArray::CloseAllClients()
{
	int i;
	Lock();
	for (i=0;i<(Clients.GetSize()-1);++i){
		if (!Clients[i].IsEmpty()) {		
			CloseClient(i); //close conection with client 
			
		}
		
	}
	
	
	Unlock();
	
}

void CClientArray::CloseClient(int iElement)
{
	Lock();
	if ((iElement>=0)&&(iElement<Clients.GetSize())&&(!Clients[iElement].IsEmpty())) {
		Clients[iElement].psConnect->Cleanup(); //close conection with client 
	}
    Unlock();
}
