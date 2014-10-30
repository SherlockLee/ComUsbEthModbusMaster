// CTCPIPServer.cpp : Implementation of CCTCPIPServer
#include "stdafx.h"
#include "ModbusServer.h"
#include "CTCPIPServer.h"
#include "Connection.h"
#include "Globals.h"
/////////////////////////////////////////////////////////////////////////////
// CCTCPIPServer


STDMETHODIMP CCTCPIPServer::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ICTCPIPServer,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CCTCPIPServer::get_ServerAddress(BSTR * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	*pVal=  (m_TcpServer.ServerAddr()).AllocSysString();
	return S_OK;
}

STDMETHODIMP CCTCPIPServer::put_ServerAddress(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	USES_CONVERSION;

	m_TcpServer.ServerAddr(W2A(newVal));

	return S_OK;
}

STDMETHODIMP CCTCPIPServer::get_ServerPort(long * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	*pVal = m_TcpServer.ServerPort();

	return S_OK;
}

STDMETHODIMP CCTCPIPServer::put_ServerPort(long newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	m_TcpServer.ServerPort(USHORT(newVal));

	return S_OK;
}

STDMETHODIMP CCTCPIPServer::StartServer(VARIANT_BOOL* pbOk)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	if (m_TcpServer.SeverStarted()){
		m_TcpServer.StopServer();
	}
	
	if (m_TcpServer.StartServer(m_TcpServer.ServerAddr(),
				m_TcpServer.ServerPort(),
				m_pParentConnection->m_pModbus)) {
		*pbOk=VARIANT_TRUE;
	}
	else {
		*pbOk=VARIANT_FALSE;
	}

	return S_OK;
}

STDMETHODIMP CCTCPIPServer::StopServer(VARIANT_BOOL * pbOk)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		if (m_TcpServer.StopServer()) {
		
			*pbOk=VARIANT_TRUE;
		}
		else {
			*pbOk=VARIANT_FALSE;
		}

	return S_OK;
}

ULONG CCTCPIPServer::InternalAddRef()
{
	ULONG l;
	ASSERT(m_pParentConnection);
	//TRACE("AddRef CCTCPIPServer\n");
	l=CComObjectRootEx<CComMultiThreadModel>::InternalAddRef();
	m_pParentConnection->Addref();

	return l;


}

ULONG CCTCPIPServer::InternalRelease()
{
	ULONG l;
	ASSERT(m_pParentConnection);
	//TRACE("Release CCTCPIPServer\n");
	l= CComObjectRootEx<CComMultiThreadModel>::InternalRelease();
	if (0==l) {
		if (m_TcpServer.SeverStarted()){
			m_TcpServer.StopServer();
		}
		
		m_pParentConnection->TCPIPServer(NULL);
	}

	gConnections.Remove(m_pParentConnection->Key());
	return l;
}

void CCTCPIPServer::ParentConnection(CConnection* pParentConnection)
{
	m_pParentConnection=pParentConnection;
}

void CCTCPIPServer::FinalRelease()
{


	
}


STDMETHODIMP CCTCPIPServer::get_ServerActive(VARIANT_BOOL * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	if (m_TcpServer.SeverStarted()) {
		
			*pVal=VARIANT_TRUE;
		}
		else {
			*pVal=VARIANT_FALSE;
		}

	return S_OK;
}

STDMETHODIMP CCTCPIPServer::GetLocalHostIP(BSTR* pbstrVal)
{

	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	try {
		*pbstrVal = (CBlockingSocket::GetHostIP()).AllocSysString();
	}
	catch(CBlockingSocketException* e) {
		e->Delete();
	}



	return S_OK;

}
