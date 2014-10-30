// CTCPIPServer.h : Declaration of the CCTCPIPServer

#ifndef __CTCPIPSERVER_H_
#define __CTCPIPSERVER_H_

#include "resource.h"       // main symbols

class CConnection;
#include "TcpServer.h"

/////////////////////////////////////////////////////////////////////////////
// CCTCPIPServer
class ATL_NO_VTABLE CCTCPIPServer : 
	public CComObjectRootEx<CComMultiThreadModel>,
	//public CComCoClass<CCTCPIPServer, &CLSID_CTCPIPServer>,
	public ISupportErrorInfo,
	public IDispatchImpl<ICTCPIPServer, &IID_ICTCPIPServer, &LIBID_MODBUSSERVERLib>
{
public:

	CCTCPIPServer()
	{
		m_pParentConnection=NULL;
	}

	


//DECLARE_REGISTRY_RESOURCEID(IDR_CTCPIPSERVER)

BEGIN_COM_MAP(CCTCPIPServer)
	COM_INTERFACE_ENTRY(ICTCPIPServer)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ICTCPIPServer
public:
	STDMETHOD(GetLocalHostIP)(/*[out,retval]*/ BSTR* pbstrVal);
	STDMETHOD(get_ServerActive)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	void FinalRelease( );
	void ParentConnection(CConnection* pParentConnection);
	ULONG InternalRelease();
	ULONG InternalAddRef();
	STDMETHOD(StopServer)(/*[out,retval]*/ VARIANT_BOOL* pbOk);
	STDMETHOD(StartServer)(/*[out,retval]*/ VARIANT_BOOL* pbOk);
	STDMETHOD(get_ServerPort)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ServerPort)(/*[in]*/ long newVal);
	STDMETHOD(get_ServerAddress)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_ServerAddress)(/*[in]*/ BSTR newVal);

protected:
	CConnection* m_pParentConnection;
	CTcpServer m_TcpServer;
};

#endif //__CTCPIPSERVER_H_
