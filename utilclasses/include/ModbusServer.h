/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Sep 04 11:57:52 1999
 */
/* Compiler settings for ModbusServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ModbusServer_h__
#define __ModbusServer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IModbusSrv_FWD_DEFINED__
#define __IModbusSrv_FWD_DEFINED__
typedef interface IModbusSrv IModbusSrv;
#endif 	/* __IModbusSrv_FWD_DEFINED__ */


#ifndef __ICTCPIPServer_FWD_DEFINED__
#define __ICTCPIPServer_FWD_DEFINED__
typedef interface ICTCPIPServer ICTCPIPServer;
#endif 	/* __ICTCPIPServer_FWD_DEFINED__ */


#ifndef __ModbusSrv_FWD_DEFINED__
#define __ModbusSrv_FWD_DEFINED__

#ifdef __cplusplus
typedef class ModbusSrv ModbusSrv;
#else
typedef struct ModbusSrv ModbusSrv;
#endif /* __cplusplus */

#endif 	/* __ModbusSrv_FWD_DEFINED__ */


#ifndef __CTCPIPServer_FWD_DEFINED__
#define __CTCPIPServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTCPIPServer CTCPIPServer;
#else
typedef struct CTCPIPServer CTCPIPServer;
#endif /* __cplusplus */

#endif 	/* __CTCPIPServer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "InterfaceConstants.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IModbusSrv_INTERFACE_DEFINED__
#define __IModbusSrv_INTERFACE_DEFINED__

/* interface IModbusSrv */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IModbusSrv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B3DE3CC1-C629-11D1-8FE9-E4CD05C10000")
    IModbusSrv : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseConnection( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ComPort( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ComPort( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaudRate( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BaudRate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parity( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parity( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FlowControl( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FlowControl( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenConnection( 
            /* [in] */ BSTR Name,
            /* [in] */ short Type,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RaiseError( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RaiseError( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PresetSingleRegister( 
            /* [in] */ short Addr,
            /* [in] */ long Register,
            /* [in] */ VARIANT RegValue,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *lRetval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ForceSingleCoil( 
            /* [in] */ short Addr,
            /* [in] */ long Register,
            /* [in] */ VARIANT_BOOL CoilValue,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadOutputRegisters( 
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vRegValues,
            /* [optional][in] */ VARIANT vVarType,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *lpRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadInputRegisters( 
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vRegValues,
            /* [optional][in] */ VARIANT vVarType,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadOutputStatus( 
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vCoilValues,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadInputStatus( 
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vCoilValues,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PresetMultipleRegisters( 
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [in] */ VARIANT vRegValues,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ForceMultipleCoils( 
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [in] */ VARIANT vCoilValues,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Retries( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Retries( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Host( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Host( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TcpPort( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TcpPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TxRxMessage( 
            /* [in] */ VARIANT vQuery,
            /* [in] */ short QueryLength,
            /* [out][in] */ VARIANT __RPC_FAR *vResponse,
            /* [in] */ short RespLength,
            /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TcpServer( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateTCPServer( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SilentInterval( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SilentInterval( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StopBits( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StopBits( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TransmissionMode( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TransmissionMode( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ByteSize( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ByteSize( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TxRxRawData( 
            /* [in] */ VARIANT vQuery,
            /* [in] */ short QueryLength,
            /* [out][in] */ VARIANT __RPC_FAR *vResponse,
            /* [in] */ short RespLength,
            /* [in] */ long Timeout,
            /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
            /* [retval][out] */ long __RPC_FAR *plRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Delay( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Delay( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IModbusSrvVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IModbusSrv __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IModbusSrv __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IModbusSrv __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseConnection )( 
            IModbusSrv __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ComPort )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ComPort )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BaudRate )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BaudRate )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Parity )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Parity )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FlowControl )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FlowControl )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbConnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenConnection )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ short Type,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RaiseError )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RaiseError )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PresetSingleRegister )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long Register,
            /* [in] */ VARIANT RegValue,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *lRetval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceSingleCoil )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long Register,
            /* [in] */ VARIANT_BOOL CoilValue,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadOutputRegisters )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vRegValues,
            /* [optional][in] */ VARIANT vVarType,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *lpRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadInputRegisters )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vRegValues,
            /* [optional][in] */ VARIANT vVarType,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadOutputStatus )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vCoilValues,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadInputStatus )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [out][in] */ VARIANT __RPC_FAR *vCoilValues,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PresetMultipleRegisters )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [in] */ VARIANT vRegValues,
            /* [optional][in] */ VARIANT vRealType,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceMultipleCoils )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short Addr,
            /* [in] */ long DataStart,
            /* [in] */ short Quantity,
            /* [in] */ VARIANT vCoilValues,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Retries )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Retries )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsActive )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Host )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Host )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TcpPort )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TcpPort )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TxRxMessage )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ VARIANT vQuery,
            /* [in] */ short QueryLength,
            /* [out][in] */ VARIANT __RPC_FAR *vResponse,
            /* [in] */ short RespLength,
            /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TcpServer )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTCPServer )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SilentInterval )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SilentInterval )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TimeOut )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TimeOut )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StopBits )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StopBits )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TransmissionMode )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TransmissionMode )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ByteSize )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ByteSize )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TxRxRawData )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ VARIANT vQuery,
            /* [in] */ short QueryLength,
            /* [out][in] */ VARIANT __RPC_FAR *vResponse,
            /* [in] */ short RespLength,
            /* [in] */ long Timeout,
            /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
            /* [retval][out] */ long __RPC_FAR *plRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Delay )( 
            IModbusSrv __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Delay )( 
            IModbusSrv __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IModbusSrvVtbl;

    interface IModbusSrv
    {
        CONST_VTBL struct IModbusSrvVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IModbusSrv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IModbusSrv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IModbusSrv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IModbusSrv_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IModbusSrv_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IModbusSrv_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IModbusSrv_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IModbusSrv_CloseConnection(This)	\
    (This)->lpVtbl -> CloseConnection(This)

#define IModbusSrv_get_ComPort(This,pVal)	\
    (This)->lpVtbl -> get_ComPort(This,pVal)

#define IModbusSrv_put_ComPort(This,newVal)	\
    (This)->lpVtbl -> put_ComPort(This,newVal)

#define IModbusSrv_get_BaudRate(This,pVal)	\
    (This)->lpVtbl -> get_BaudRate(This,pVal)

#define IModbusSrv_put_BaudRate(This,newVal)	\
    (This)->lpVtbl -> put_BaudRate(This,newVal)

#define IModbusSrv_get_Parity(This,pVal)	\
    (This)->lpVtbl -> get_Parity(This,pVal)

#define IModbusSrv_put_Parity(This,newVal)	\
    (This)->lpVtbl -> put_Parity(This,newVal)

#define IModbusSrv_get_FlowControl(This,pVal)	\
    (This)->lpVtbl -> get_FlowControl(This,pVal)

#define IModbusSrv_put_FlowControl(This,newVal)	\
    (This)->lpVtbl -> put_FlowControl(This,newVal)

#define IModbusSrv_Connect(This,pbConnected)	\
    (This)->lpVtbl -> Connect(This,pbConnected)

#define IModbusSrv_OpenConnection(This,Name,Type,pbOk)	\
    (This)->lpVtbl -> OpenConnection(This,Name,Type,pbOk)

#define IModbusSrv_get_RaiseError(This,pVal)	\
    (This)->lpVtbl -> get_RaiseError(This,pVal)

#define IModbusSrv_put_RaiseError(This,newVal)	\
    (This)->lpVtbl -> put_RaiseError(This,newVal)

#define IModbusSrv_PresetSingleRegister(This,Addr,Register,RegValue,vRealType,lRetval)	\
    (This)->lpVtbl -> PresetSingleRegister(This,Addr,Register,RegValue,vRealType,lRetval)

#define IModbusSrv_ForceSingleCoil(This,Addr,Register,CoilValue,plRetVal)	\
    (This)->lpVtbl -> ForceSingleCoil(This,Addr,Register,CoilValue,plRetVal)

#define IModbusSrv_ReadOutputRegisters(This,Addr,DataStart,Quantity,vRegValues,vVarType,vRealType,lpRetVal)	\
    (This)->lpVtbl -> ReadOutputRegisters(This,Addr,DataStart,Quantity,vRegValues,vVarType,vRealType,lpRetVal)

#define IModbusSrv_ReadInputRegisters(This,Addr,DataStart,Quantity,vRegValues,vVarType,vRealType,plRetVal)	\
    (This)->lpVtbl -> ReadInputRegisters(This,Addr,DataStart,Quantity,vRegValues,vVarType,vRealType,plRetVal)

#define IModbusSrv_ReadOutputStatus(This,Addr,DataStart,Quantity,vCoilValues,plRetVal)	\
    (This)->lpVtbl -> ReadOutputStatus(This,Addr,DataStart,Quantity,vCoilValues,plRetVal)

#define IModbusSrv_ReadInputStatus(This,Addr,DataStart,Quantity,vCoilValues,plRetVal)	\
    (This)->lpVtbl -> ReadInputStatus(This,Addr,DataStart,Quantity,vCoilValues,plRetVal)

#define IModbusSrv_PresetMultipleRegisters(This,Addr,DataStart,Quantity,vRegValues,vRealType,plRetVal)	\
    (This)->lpVtbl -> PresetMultipleRegisters(This,Addr,DataStart,Quantity,vRegValues,vRealType,plRetVal)

#define IModbusSrv_ForceMultipleCoils(This,Addr,DataStart,Quantity,vCoilValues,plRetVal)	\
    (This)->lpVtbl -> ForceMultipleCoils(This,Addr,DataStart,Quantity,vCoilValues,plRetVal)

#define IModbusSrv_get_Retries(This,pVal)	\
    (This)->lpVtbl -> get_Retries(This,pVal)

#define IModbusSrv_put_Retries(This,newVal)	\
    (This)->lpVtbl -> put_Retries(This,newVal)

#define IModbusSrv_get_IsActive(This,pVal)	\
    (This)->lpVtbl -> get_IsActive(This,pVal)

#define IModbusSrv_get_Host(This,pVal)	\
    (This)->lpVtbl -> get_Host(This,pVal)

#define IModbusSrv_put_Host(This,newVal)	\
    (This)->lpVtbl -> put_Host(This,newVal)

#define IModbusSrv_get_TcpPort(This,pVal)	\
    (This)->lpVtbl -> get_TcpPort(This,pVal)

#define IModbusSrv_put_TcpPort(This,newVal)	\
    (This)->lpVtbl -> put_TcpPort(This,newVal)

#define IModbusSrv_TxRxMessage(This,vQuery,QueryLength,vResponse,RespLength,vNumOfBytesRead,plRetVal)	\
    (This)->lpVtbl -> TxRxMessage(This,vQuery,QueryLength,vResponse,RespLength,vNumOfBytesRead,plRetVal)

#define IModbusSrv_get_TcpServer(This,pVal)	\
    (This)->lpVtbl -> get_TcpServer(This,pVal)

#define IModbusSrv_CreateTCPServer(This,pVal)	\
    (This)->lpVtbl -> CreateTCPServer(This,pVal)

#define IModbusSrv_get_SilentInterval(This,pVal)	\
    (This)->lpVtbl -> get_SilentInterval(This,pVal)

#define IModbusSrv_put_SilentInterval(This,newVal)	\
    (This)->lpVtbl -> put_SilentInterval(This,newVal)

#define IModbusSrv_get_TimeOut(This,pVal)	\
    (This)->lpVtbl -> get_TimeOut(This,pVal)

#define IModbusSrv_put_TimeOut(This,newVal)	\
    (This)->lpVtbl -> put_TimeOut(This,newVal)

#define IModbusSrv_get_StopBits(This,pVal)	\
    (This)->lpVtbl -> get_StopBits(This,pVal)

#define IModbusSrv_put_StopBits(This,newVal)	\
    (This)->lpVtbl -> put_StopBits(This,newVal)

#define IModbusSrv_get_TransmissionMode(This,pVal)	\
    (This)->lpVtbl -> get_TransmissionMode(This,pVal)

#define IModbusSrv_put_TransmissionMode(This,newVal)	\
    (This)->lpVtbl -> put_TransmissionMode(This,newVal)

#define IModbusSrv_get_ByteSize(This,pVal)	\
    (This)->lpVtbl -> get_ByteSize(This,pVal)

#define IModbusSrv_put_ByteSize(This,newVal)	\
    (This)->lpVtbl -> put_ByteSize(This,newVal)

#define IModbusSrv_TxRxRawData(This,vQuery,QueryLength,vResponse,RespLength,Timeout,vNumOfBytesRead,plRetVal)	\
    (This)->lpVtbl -> TxRxRawData(This,vQuery,QueryLength,vResponse,RespLength,Timeout,vNumOfBytesRead,plRetVal)

#define IModbusSrv_get_Delay(This,pVal)	\
    (This)->lpVtbl -> get_Delay(This,pVal)

#define IModbusSrv_put_Delay(This,newVal)	\
    (This)->lpVtbl -> put_Delay(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_CloseConnection_Proxy( 
    IModbusSrv __RPC_FAR * This);


void __RPC_STUB IModbusSrv_CloseConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_ComPort_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_ComPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_ComPort_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_ComPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_BaudRate_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_BaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_BaudRate_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IModbusSrv_put_BaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_Parity_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_Parity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_Parity_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_Parity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_FlowControl_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_FlowControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_FlowControl_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_FlowControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_Connect_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbConnected);


void __RPC_STUB IModbusSrv_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_OpenConnection_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ short Type,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk);


void __RPC_STUB IModbusSrv_OpenConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_RaiseError_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_RaiseError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_RaiseError_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IModbusSrv_put_RaiseError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_PresetSingleRegister_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long Register,
    /* [in] */ VARIANT RegValue,
    /* [optional][in] */ VARIANT vRealType,
    /* [retval][out] */ long __RPC_FAR *lRetval);


void __RPC_STUB IModbusSrv_PresetSingleRegister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_ForceSingleCoil_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long Register,
    /* [in] */ VARIANT_BOOL CoilValue,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_ForceSingleCoil_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_ReadOutputRegisters_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long DataStart,
    /* [in] */ short Quantity,
    /* [out][in] */ VARIANT __RPC_FAR *vRegValues,
    /* [optional][in] */ VARIANT vVarType,
    /* [optional][in] */ VARIANT vRealType,
    /* [retval][out] */ long __RPC_FAR *lpRetVal);


void __RPC_STUB IModbusSrv_ReadOutputRegisters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_ReadInputRegisters_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long DataStart,
    /* [in] */ short Quantity,
    /* [out][in] */ VARIANT __RPC_FAR *vRegValues,
    /* [optional][in] */ VARIANT vVarType,
    /* [optional][in] */ VARIANT vRealType,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_ReadInputRegisters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_ReadOutputStatus_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long DataStart,
    /* [in] */ short Quantity,
    /* [out][in] */ VARIANT __RPC_FAR *vCoilValues,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_ReadOutputStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_ReadInputStatus_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long DataStart,
    /* [in] */ short Quantity,
    /* [out][in] */ VARIANT __RPC_FAR *vCoilValues,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_ReadInputStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_PresetMultipleRegisters_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long DataStart,
    /* [in] */ short Quantity,
    /* [in] */ VARIANT vRegValues,
    /* [optional][in] */ VARIANT vRealType,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_PresetMultipleRegisters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_ForceMultipleCoils_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short Addr,
    /* [in] */ long DataStart,
    /* [in] */ short Quantity,
    /* [in] */ VARIANT vCoilValues,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_ForceMultipleCoils_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_Retries_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_Retries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_Retries_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_Retries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_IsActive_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_Host_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_Host_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_Host_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IModbusSrv_put_Host_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TcpPort_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_TcpPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_TcpPort_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IModbusSrv_put_TcpPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_TxRxMessage_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ VARIANT vQuery,
    /* [in] */ short QueryLength,
    /* [out][in] */ VARIANT __RPC_FAR *vResponse,
    /* [in] */ short RespLength,
    /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_TxRxMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TcpServer_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_TcpServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_CreateTCPServer_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_CreateTCPServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_SilentInterval_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_SilentInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_SilentInterval_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IModbusSrv_put_SilentInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TimeOut_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_TimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_TimeOut_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IModbusSrv_put_TimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_StopBits_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_StopBits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_StopBits_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_StopBits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TransmissionMode_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_TransmissionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_TransmissionMode_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_TransmissionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_ByteSize_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_ByteSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_ByteSize_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IModbusSrv_put_ByteSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_TxRxRawData_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ VARIANT vQuery,
    /* [in] */ short QueryLength,
    /* [out][in] */ VARIANT __RPC_FAR *vResponse,
    /* [in] */ short RespLength,
    /* [in] */ long Timeout,
    /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
    /* [retval][out] */ long __RPC_FAR *plRetVal);


void __RPC_STUB IModbusSrv_TxRxRawData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_Delay_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IModbusSrv_get_Delay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_Delay_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IModbusSrv_put_Delay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IModbusSrv_INTERFACE_DEFINED__ */


#ifndef __ICTCPIPServer_INTERFACE_DEFINED__
#define __ICTCPIPServer_INTERFACE_DEFINED__

/* interface ICTCPIPServer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICTCPIPServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47ADFAE1-D261-11D1-8FE9-6CD504C1BC01")
    ICTCPIPServer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServerAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerPort( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServerPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartServer( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopServer( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerActive( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLocalHostIP( 
            /* [retval][out] */ BSTR __RPC_FAR *pbstrVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICTCPIPServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICTCPIPServer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICTCPIPServer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerAddress )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ServerAddress )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerPort )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ServerPort )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartServer )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopServer )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServerActive )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocalHostIP )( 
            ICTCPIPServer __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pbstrVal);
        
        END_INTERFACE
    } ICTCPIPServerVtbl;

    interface ICTCPIPServer
    {
        CONST_VTBL struct ICTCPIPServerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICTCPIPServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICTCPIPServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICTCPIPServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICTCPIPServer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICTCPIPServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICTCPIPServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICTCPIPServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICTCPIPServer_get_ServerAddress(This,pVal)	\
    (This)->lpVtbl -> get_ServerAddress(This,pVal)

#define ICTCPIPServer_put_ServerAddress(This,newVal)	\
    (This)->lpVtbl -> put_ServerAddress(This,newVal)

#define ICTCPIPServer_get_ServerPort(This,pVal)	\
    (This)->lpVtbl -> get_ServerPort(This,pVal)

#define ICTCPIPServer_put_ServerPort(This,newVal)	\
    (This)->lpVtbl -> put_ServerPort(This,newVal)

#define ICTCPIPServer_StartServer(This,pbOk)	\
    (This)->lpVtbl -> StartServer(This,pbOk)

#define ICTCPIPServer_StopServer(This,pbOk)	\
    (This)->lpVtbl -> StopServer(This,pbOk)

#define ICTCPIPServer_get_ServerActive(This,pVal)	\
    (This)->lpVtbl -> get_ServerActive(This,pVal)

#define ICTCPIPServer_GetLocalHostIP(This,pbstrVal)	\
    (This)->lpVtbl -> GetLocalHostIP(This,pbstrVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_get_ServerAddress_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ICTCPIPServer_get_ServerAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_put_ServerAddress_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ICTCPIPServer_put_ServerAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_get_ServerPort_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ICTCPIPServer_get_ServerPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_put_ServerPort_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ICTCPIPServer_put_ServerPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_StartServer_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk);


void __RPC_STUB ICTCPIPServer_StartServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_StopServer_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbOk);


void __RPC_STUB ICTCPIPServer_StopServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_get_ServerActive_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB ICTCPIPServer_get_ServerActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICTCPIPServer_GetLocalHostIP_Proxy( 
    ICTCPIPServer __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pbstrVal);


void __RPC_STUB ICTCPIPServer_GetLocalHostIP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICTCPIPServer_INTERFACE_DEFINED__ */



#ifndef __MODBUSSERVERLib_LIBRARY_DEFINED__
#define __MODBUSSERVERLib_LIBRARY_DEFINED__

/* library MODBUSSERVERLib */
/* [helpstring][version][uuid] */ 

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_ModbusServer_0211_0001
    {	mbErrOk	= ERR_OK,
	mbErrTimeOut	= _ERR_TIMEOUT_,
	mbErrInvResp	= _ERR_INV_RESP_,
	mbErrCRC	= _ERR_CRC_,
	mbErrWrPort	= _ERR_WR_PORT_,
	mbErrRdPort	= _ERR_RD_PORT_,
	mbErrNotInit	= _ERR_NOT_INT_,
	mbErrExceptionCode	= _ERR_EXCPTION_CODE_,
	mbErrOffset	= ERR_OFFSET,
	mbErrBufferOverflow	= _ERR_BUFFER_OVERFLOW_,
	mbErrSocketError	= _ERR_SOCKET_ERROR_,
	mbErrWriteSockError	= _ERR_WR_SOCK_ERROR_,
	mbErrReadSockError	= _ERR_RD_SOCK_ERROR_,
	mbErrSockNotConnected	= _ERR_SOCK_NOT_CONNECTED_
    }	ErrorConstants;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_ModbusServer_0211_0002
    {	mbNOPARITY	= 0,
	mbODDPARITY	= 1,
	mbEVENPARITY	= 2,
	mbMARKPARITY	= 3,
	mbSPACEPARITY	= 4,
	mbONESTOPBIT	= 0,
	mbONE5STOPBITS	= 1,
	mbTWOSTOPBITS	= 2,
	mbFC_NONE	= 0,
	mbFC_DTRDSR	= 0x1,
	mbFC_RTSCTS	= 0x2,
	mbFC_XONXOFF	= 0x4,
	mbLOCAL	= 1,
	mbREMOTE	= 2,
	mbMODE_RTU	= 0,
	mbMODE_ASCII	= 1,
	mbREAL_NORMAL	= 0,
	mbREAL_REVERSE	= 1
    }	GeneralConstants;


EXTERN_C const IID LIBID_MODBUSSERVERLib;

EXTERN_C const CLSID CLSID_ModbusSrv;

#ifdef __cplusplus

class DECLSPEC_UUID("B3DE3CC2-C629-11D1-8FE9-E4CD05C10000")
ModbusSrv;
#endif

EXTERN_C const CLSID CLSID_CTCPIPServer;

#ifdef __cplusplus

class DECLSPEC_UUID("47ADFAE2-D261-11D1-8FE9-6CD504C1BC01")
CTCPIPServer;
#endif
#endif /* __MODBUSSERVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
