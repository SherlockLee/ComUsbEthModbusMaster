// ClientArray.h: interface for the CClientArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTARRAY_H__89AA16E2_35EA_11D1_8FE8_F57DC398AE0E__INCLUDED_)
#define AFX_CLIENTARRAY_H__89AA16E2_35EA_11D1_8FE8_F57DC398AE0E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "RemoteClient.h"

//CArray definition 
#include <afxtempl.h>

//Critical Section 
#include <afxmt.h> 


//Define array of conneted remote clients 
class CClientArray : public CObject  
{
public:
	void CloseClient(int iElement);
	void CloseAllClients();
	void RemoveClient(int iElement);
	BOOL Unlock(); //lock object 
	BOOL Lock();   //unlock object 
	
    int CClientArray::AddClient(CBlockingSocket * psConnect, CSockAddr * psaClient);
     //AddClient add new client to Clients array 
	 //in : pointer of new client socket and new client address 
	 //return: position (0,5..) where cliets pointers was strend in clients array
	 //        or -1 if can't add new client 
	
	enum { MAX_CLIENTS=50
	};
	CClientArray();
	virtual ~CClientArray();
	CArray<CRemoteClient,CRemoteClient&> Clients; //clients array 

private:
	CCriticalSection m_csClients;
};

#endif // !defined(AFX_CLIENTARRAY_H__89AA16E2_35EA_11D1_8FE8_F57DC398AE0E__INCLUDED_)
