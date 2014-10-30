	
// ModbusSrv.h : Declaration of the CModbusSrv

#ifndef __MODBUSSRV_H_
#define __MODBUSSRV_H_

#include "resource.h"       // main symbols

#include "globals.h"

#include "InterfaceConstants.h"

#include "OleVariantEx.h"
#include "OleSafeArrayEx.h"

/////////////////////////////////////////////////////////////////////////////
// CModbusSrv
class ATL_NO_VTABLE CModbusSrv : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CModbusSrv, &CLSID_ModbusSrv>,
	public ISupportErrorInfo,
	public IDispatchImpl<IModbusSrv, &IID_IModbusSrv, &LIBID_MODBUSSERVERLib>
{
public:
	CModbusSrv()
	{
//		m_pUnkMarshaler = NULL;
	}

	~CModbusSrv() {

	}

DECLARE_REGISTRY_RESOURCEID(IDR_MODBUSSRV)
/*FreThreadMarshall DECLARE_GET_CONTROLLING_UNKNOWN() */

BEGIN_COM_MAP(CModbusSrv)
	COM_INTERFACE_ENTRY(IModbusSrv)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
//	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

	HRESULT FinalConstruct()
	{
		Init();
		
		return S_OK;
		//return CoCreateFreeThreadedMarshaler(
		//	GetControllingUnknown(), &m_pUnkMarshaler.p);

	}

	void FinalRelease()
	{
		Terminate();
		//m_pUnkMarshaler.Release();
	}

	//CComPtr<IUnknown> m_pUnkMarshaler;

	enum _ModbusSrv_ {

		VB_TRUE=-1,
		VB_FALSE=0
	};

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IModbusSrv
public:
	STDMETHOD(get_Delay)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Delay)(/*[in]*/ long newVal);
	STDMETHOD(TxRxRawData)(/*[in]*/  VARIANT vQuery , /*[in]*/ short QueryLength , /*[out]*/  VARIANT* vResponse, /*[in]*/ short RespLength, /*[in]*/ long Timeout, /*[out,optional]*/ VARIANT* vNumOfBytesRead , /*[out,retval]*/ long* plRetVal);
	STDMETHOD(get_ByteSize)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_ByteSize)(/*[in]*/ short newVal);
	STDMETHOD(get_TransmissionMode)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_TransmissionMode)(/*[in]*/ short newVal);
	STDMETHOD(get_StopBits)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_StopBits)(/*[in]*/ short newVal);
	STDMETHOD(get_TimeOut)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_TimeOut)(/*[in]*/ long newVal);
	STDMETHOD(get_SilentInterval)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_SilentInterval)(/*[in]*/ long newVal);
	STDMETHOD(CreateTCPServer)(/*[out,retval]*/ LPDISPATCH* pVal);
	STDMETHOD(get_TcpServer)(/*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(TxRxMessage)(/*[in]*/  VARIANT vQuery , /*[in]*/ short QueryLength , /*[out]*/  VARIANT* vResponse, /*[in]*/ short RespLength, /*[out,optional]*/ VARIANT* vNumOfBytesRead , /*[out,retval]*/ long* plRetVal);
	STDMETHOD(get_TcpPort)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_TcpPort)(/*[in]*/ long newVal);
	STDMETHOD(get_Host)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Host)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_IsActive)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_Retries)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Retries)(/*[in]*/ short newVal);
	STDMETHOD(ForceMultipleCoils)(/*[in]*/ short Addr , /*[in]*/ long DataStart , /*[in]*/ short Quantity , /*[in]*/  VARIANT vCoilValues ,  /*[out,retval]*/ long* plRetVal);
	STDMETHOD(PresetMultipleRegisters)(/*[in]*/ short Addr , /*[in]*/ long DataStart , /*[in]*/ short Quantity , /*[in]*/  VARIANT vRegValues , VARIANT vRealType , /*[out,retval]*/ long* plRetVal);
	STDMETHOD(ReadInputStatus)(/*[in]*/ short Addr , /*[in]*/ long DataStart , /*[in]*/ short Quantity , /*[out]*/ VARIANT* vCoilValues , /*[out,retval]*/ long* plRetVal);
	STDMETHOD(ReadOutputStatus)(/*[in]*/ short Addr , /*[in]*/ long DataStart , /*[in]*/ short Quantity , /*[out]*/ VARIANT* vCoilValues ,  /*[out,retval]*/ long* plRetVal);
	STDMETHOD(ReadInputRegisters)(/*[in]*/ short Addr , /*[in]*/ long DataStart , /*[in]*/ short Quantity , /*[out]*/ VARIANT* vRegValues , /*[in,optional]*/ VARIANT vVarType ,/*[in,optional]*/ VARIANT vRealType ,   /*[out,retval]*/ long* plRetVal);
	STDMETHOD(ReadOutputRegisters)(/*[in]*/ short Addr , /*[in]*/ long DataStart , /*[in]*/ short Quantity , /*[in,out]*/ VARIANT* vRegValues , /*[in,optional]*/ VARIANT vVarType , /*[in,optional]*/ VARIANT vRealType  ,/*[out,retval]*/ long* lpRetVal);
	STDMETHOD(ForceSingleCoil)(/*[in]*/ short Addr , /*[in]*/ long Register , /*[in]*/ VARIANT_BOOL CoilValue , /*[out,retval]*/ long* plRetVal);
	STDMETHOD(PresetSingleRegister)(/*[in]*/ short Addr , /*[in]*/  long Register , /*[in]*/ VARIANT RegValue , VARIANT vRealType, /*[out,retval]*/  long*  lRetval);
	STDMETHOD(get_RaiseError)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_RaiseError)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(OpenConnection)(/*[in]*/ BSTR Name , /*[in]*/ short Type , /*[out,retval]*/  VARIANT_BOOL* pbOk);
	STDMETHOD(Connect)(/*[out,retval]*/ VARIANT_BOOL* pbConnected);
	STDMETHOD(get_FlowControl)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_FlowControl)(/*[in]*/ short newVal);
	STDMETHOD(get_Parity)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Parity)(/*[in]*/ short newVal);
	STDMETHOD(get_BaudRate)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_BaudRate)(/*[in]*/ long newVal);
	STDMETHOD(get_ComPort)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_ComPort)(/*[in]*/ short newVal);
	STDMETHOD(CloseConnection)();


	VARIANT_BOOL CBoolVb(BOOL bCondition);

protected:
	void Init();
	void Terminate();

private:
	HRESULT ExceptionErrorCode(WORD wError);
	BOOL m_bRaiseError;
	HRESULT Error(WORD wErrorCode, UINT nID);
	HRESULT Error(WORD wError, LPCTSTR lpstrErrMessage=NULL);
	CConnection* m_pConnection;

};


#define VERIFY_LOCAL_CONNECTION if (NULL==m_pConnection) { \
			return Error(ERR_CONNECTION_NOT_OPENED,IDS_ATL_ERR_CONN_NOT_OPENDED);} \
			if (CConnection::LOCAL!=m_pConnection->Type()) { \
				return Error(ERR_LOCAL_CALL_ERR,IDS_LOCAL_CALL_ERR); }  \

#define VERIFY_CONNECTION if (NULL==m_pConnection) { \
	return Error(ERR_CONNECTION_NOT_OPENED,IDS_ATL_ERR_CONN_NOT_OPENDED);} \

#define VERIFY_REMOTE_CONNECTION if (NULL==m_pConnection) { \
			return Error(ERR_CONNECTION_NOT_OPENED,IDS_ATL_ERR_CONN_NOT_OPENDED);} \
			if (CConnection::REMOTE!=m_pConnection->Type()) { \
				return Error(ERR_REMOTE_CALL_ERR,IDS_REMOTE_CALL_ERR); }  \


#endif //__MODBUSSRV_H_
