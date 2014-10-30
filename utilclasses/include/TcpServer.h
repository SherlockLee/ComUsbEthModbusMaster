// TcpServer.h: interface for the CTcpServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPSERVER_H__7FE93B61_36BF_11D1_8FE8_B5E573E0D20E__INCLUDED_)
#define AFX_TCPSERVER_H__7FE93B61_36BF_11D1_8FE8_B5E573E0D20E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ClientArray.h" 

#include "LocalModbus.h" 

class CTcpServer : public CObject  
{
public:
	BOOL ServerActive();
	LONG DecrementThreadCount();
	LONG IncrementThreadCount();
	void ServerPort(USHORT usAddr);
	CString ServerAddr();
	void ServerAddr(LPCSTR szServerAddr);
	BOOL ComExceptionEnabled();
	void ComExceptionEnabled(BOOL bEnabled);
	void CommExceptionOffset(BYTE byOffset);
	BYTE CommExceptionOffset();
	WORD BouncePort();
	void BouncePort(WORD wPort);
	CString BounceAddr();
	void BounceAddr(CString sAddr);
	void RxBufferSize(DWORD dwRxSize);
	DWORD RxBufferSize();
	void TxBufferSize(DWORD dwTxSize);
	DWORD TxBufferSize();
	void TimeOut(DWORD dwTimeOut);
	DWORD TimeOut();
	USHORT ServerPort();
	CString ServerIP();
	BYTE ComPort();
	BOOL StopServer();
	BOOL StartServer(CString sServerIP,USHORT unPort,CModbus* pModbus);
	BOOL SeverStarted();
	static BOOL StartWinsock();
	static BOOL  StopWinsock();

	CTcpServer();
	virtual ~CTcpServer();

	CClientArray aClients; 
	enum {
		DEFAULT_PORT=502,
		MBAP_HEADER_LENGHT=6,
		MODBUS_ENCODING=0,
		DEFAULT_COMM_EXCEPTION_OFFSET=0x80,
		GENERAL_COMM_ERROR=4
	};


private:
	BOOL m_bComExceptionEnabled;
	BYTE m_byExceptionOffset;
	WORD m_wBouncePort;
	CString m_sBounceAddr;
	DWORD m_dwTxBufferSize;
	DWORD m_dwRxBufferSize;
	DWORD m_dwTimeOut;
	BOOL m_bSeverStarted;
	USHORT m_unPort;
	CString m_sServerIP;
	CModbus* m_pModbus;
	BOOL m_bWinsockStarted;
	CBlockingSocket m_sListen; //listen socket
	static UINT ServerThreadProc(LPVOID pParam);

protected:
	LONG m_lNumOfThreads;
	void CreateThread();
};

#endif // !defined(AFX_TCPSERVER_H__7FE93B61_36BF_11D1_8FE8_B5E573E0D20E__INCLUDED_)
