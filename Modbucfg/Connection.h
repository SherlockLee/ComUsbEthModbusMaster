// Connection.h: interface for the CConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTION_H__E83D7142_F7E4_11D1_8FE9_6CD504C1BC01__INCLUDED_)
#define AFX_CONNECTION_H__E83D7142_F7E4_11D1_8FE9_6CD504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "RemoteModbus.h"
#include "AutoModbus.h"




class CConnection : public CObject  
{

	DECLARE_DYNAMIC(CConnection)

public:
	void Serialize(CArchive& archive);
	void DcomServer(LPCTSTR  szDcomServer);
	CString DcomServer();
	void Delete();
	CRemoteModbus* RemotePtr();
	CAutoModbus* AutoPtr();
	CConnection();
	virtual ~CConnection();
	void Key(CString& sKey);
	CString Key();
	CConnection(WORD wType , LPCTSTR sKey);
	CConnection(const CConnection& rConnection);
	WORD Type();
	

	enum _connection_type_ {
		NONE=0,
		AUTO=1,
		REMOTE=2
	};

	CModbus* m_pModbus; //local/dcom or remote/openmodbus

private:
	CString m_sKey;
	WORD m_wType;
	CString m_sDcomServer;

};

#endif // !defined(AFX_CONNECTION_H__E83D7142_F7E4_11D1_8FE9_6CD504C1BC01__INCLUDED_)
