// RemoteClient.h: interface for the CRemoteClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REMOTECLIENT_H__89AA16E1_35EA_11D1_8FE8_F57DC398AE0E__INCLUDED_)
#define AFX_REMOTECLIENT_H__89AA16E1_35EA_11D1_8FE8_F57DC398AE0E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "blocksock.h"

class CRemoteClient:public CObject  
{
	DECLARE_DYNAMIC(CRemoteClient)
public:
	void ResetTxRxCount();
	void AddTxBytes(DWORD dwBytes);
	DWORD TxBytes();
	void AddRxBytes(DWORD dwBytes);
	DWORD RxBytes();
	CBlockingSocket* psConnect;
	CSockAddr* psaClient;
	CRemoteClient();
	BOOL IsEmpty() { //this element is empty
		return (NULL==psConnect)&&(NULL==psaClient);
	}
	virtual ~CRemoteClient(); //999-127.000.000.001

private:
	DWORD m_dwTxBytes;
	DWORD m_dwRxBytes;
};

#endif // !defined(AFX_REMOTECLIENT_H__89AA16E1_35EA_11D1_8FE8_F57DC398AE0E__INCLUDED_)
