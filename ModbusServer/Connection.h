// Connection.h: interface for the CConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTION_H__6DE30685_C724_11D1_8FE9_E4CD05C10000__INCLUDED_)
#define AFX_CONNECTION_H__6DE30685_C724_11D1_8FE9_E4CD05C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "LocalModbus.h"
#include "RemoteModbus.h"
#include "ModbusServer.h"

class CCTCPIPServer;


class CConnection : public CObject   
{
	DECLARE_DYNAMIC(CConnection)

public:
	void TCPIPServer(CComObject<CCTCPIPServer>* pTcpServer);
	LPDISPATCH GetTcpDispatch();
	
	CConnection(const CConnection& rConnection);
	void Key(CString& sKey);
	CString Key();
	WORD Type();
	LONG Release();
	LONG Addref();
	CConnection();
	CConnection(WORD wType , LPCTSTR sKey);
	virtual ~CConnection();
	
	CModbus* m_pModbus;
	CLocalModbus* m_pLocalModbus;
	CRemoteModbus* m_pRemoteModbus;
	CComObject<CCTCPIPServer>* m_pTCPServer;

	LONG m_dwRef;
	
	enum _connection_type_ {
		NONE=0,
		LOCAL=1,
		REMOTE=2
	};

private:
	CString m_sKey;
	WORD m_wType;
protected:
	
};

#endif // !defined(AFX_CONNECTION_H__6DE30685_C724_11D1_8FE9_E4CD05C10000__INCLUDED_)
