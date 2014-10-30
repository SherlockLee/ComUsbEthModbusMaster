/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Sep 04 11:57:52 1999
 */
/* Compiler settings for ModbusServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "ModbusServer.h"

#define TYPE_FORMAT_STRING_SIZE   1029                              
#define PROC_FORMAT_STRING_SIZE   1717                              

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IModbusSrv, ver. 0.0,
   GUID={0xB3DE3CC1,0xC629,0x11D1,{0x8F,0xE9,0xE4,0xCD,0x05,0xC1,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IModbusSrv_ServerInfo;

#pragma code_seg(".orpc")
/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_Host_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ BSTR newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[922],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[922],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[922],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TcpPort_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[950],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[950],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[950],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_TcpPort_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[978],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[978],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[978],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_TxRxMessage_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ VARIANT vQuery,
    /* [in] */ short QueryLength,
    /* [out][in] */ VARIANT __RPC_FAR *vResponse,
    /* [in] */ short RespLength,
    /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
    /* [retval][out] */ long __RPC_FAR *plRetVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,plRetVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1006],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1006],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&vQuery,
                  ( unsigned char __RPC_FAR * )&QueryLength,
                  ( unsigned char __RPC_FAR * )&vResponse,
                  ( unsigned char __RPC_FAR * )&RespLength,
                  ( unsigned char __RPC_FAR * )&vNumOfBytesRead,
                  ( unsigned char __RPC_FAR * )&plRetVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1006],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TcpServer_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1064],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1064],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1064],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_CreateTCPServer_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1092],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1092],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1092],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_SilentInterval_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1120],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1120],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1120],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_SilentInterval_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1148],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1148],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1148],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TimeOut_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1176],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1176],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1176],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_TimeOut_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1204],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1204],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1204],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_StopBits_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1232],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1232],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1232],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_StopBits_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1260],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1260],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1260],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_TransmissionMode_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1288],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1288],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1288],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_TransmissionMode_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1316],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1316],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1316],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_ByteSize_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1344],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1344],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1344],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_ByteSize_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ short newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1372],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1372],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1372],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IModbusSrv_TxRxRawData_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ VARIANT vQuery,
    /* [in] */ short QueryLength,
    /* [out][in] */ VARIANT __RPC_FAR *vResponse,
    /* [in] */ short RespLength,
    /* [in] */ long Timeout,
    /* [optional][out][in] */ VARIANT __RPC_FAR *vNumOfBytesRead,
    /* [retval][out] */ long __RPC_FAR *plRetVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,plRetVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1400],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1400],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&vQuery,
                  ( unsigned char __RPC_FAR * )&QueryLength,
                  ( unsigned char __RPC_FAR * )&vResponse,
                  ( unsigned char __RPC_FAR * )&RespLength,
                  ( unsigned char __RPC_FAR * )&Timeout,
                  ( unsigned char __RPC_FAR * )&vNumOfBytesRead,
                  ( unsigned char __RPC_FAR * )&plRetVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1400],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IModbusSrv_get_Delay_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1464],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1464],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&pVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1464],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IModbusSrv_put_Delay_Proxy( 
    IModbusSrv __RPC_FAR * This,
    /* [in] */ long newVal)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,newVal);
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1492],
                  vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1492],
                  ( unsigned char __RPC_FAR * )&This,
                  ( unsigned char __RPC_FAR * )&newVal);
#else
    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[1492],
                  ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

static const unsigned short IModbusSrv_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    22,
    50,
    78,
    106,
    134,
    162,
    190,
    218,
    246,
    274,
    314,
    342,
    370,
    422,
    468,
    532,
    596,
    648,
    700,
    758,
    810,
    838,
    866,
    894,
    922,
    950,
    978,
    1006,
    1064,
    1092,
    1120,
    1148,
    1176,
    1204,
    1232,
    1260,
    1288,
    1316,
    1344,
    1372,
    1400,
    1464,
    1492
    };

static const MIDL_SERVER_INFO IModbusSrv_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IModbusSrv_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IModbusSrv_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IModbusSrv_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(51) _IModbusSrvProxyVtbl = 
{
    &IModbusSrv_ProxyInfo,
    &IID_IModbusSrv,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IModbusSrv::CloseConnection */ ,
    (void *)-1 /* IModbusSrv::get_ComPort */ ,
    (void *)-1 /* IModbusSrv::put_ComPort */ ,
    (void *)-1 /* IModbusSrv::get_BaudRate */ ,
    (void *)-1 /* IModbusSrv::put_BaudRate */ ,
    (void *)-1 /* IModbusSrv::get_Parity */ ,
    (void *)-1 /* IModbusSrv::put_Parity */ ,
    (void *)-1 /* IModbusSrv::get_FlowControl */ ,
    (void *)-1 /* IModbusSrv::put_FlowControl */ ,
    (void *)-1 /* IModbusSrv::Connect */ ,
    (void *)-1 /* IModbusSrv::OpenConnection */ ,
    (void *)-1 /* IModbusSrv::get_RaiseError */ ,
    (void *)-1 /* IModbusSrv::put_RaiseError */ ,
    (void *)-1 /* IModbusSrv::PresetSingleRegister */ ,
    (void *)-1 /* IModbusSrv::ForceSingleCoil */ ,
    (void *)-1 /* IModbusSrv::ReadOutputRegisters */ ,
    (void *)-1 /* IModbusSrv::ReadInputRegisters */ ,
    (void *)-1 /* IModbusSrv::ReadOutputStatus */ ,
    (void *)-1 /* IModbusSrv::ReadInputStatus */ ,
    (void *)-1 /* IModbusSrv::PresetMultipleRegisters */ ,
    (void *)-1 /* IModbusSrv::ForceMultipleCoils */ ,
    (void *)-1 /* IModbusSrv::get_Retries */ ,
    (void *)-1 /* IModbusSrv::put_Retries */ ,
    (void *)-1 /* IModbusSrv::get_IsActive */ ,
    (void *)-1 /* IModbusSrv::get_Host */ ,
    IModbusSrv_put_Host_Proxy ,
    IModbusSrv_get_TcpPort_Proxy ,
    IModbusSrv_put_TcpPort_Proxy ,
    IModbusSrv_TxRxMessage_Proxy ,
    IModbusSrv_get_TcpServer_Proxy ,
    IModbusSrv_CreateTCPServer_Proxy ,
    IModbusSrv_get_SilentInterval_Proxy ,
    IModbusSrv_put_SilentInterval_Proxy ,
    IModbusSrv_get_TimeOut_Proxy ,
    IModbusSrv_put_TimeOut_Proxy ,
    IModbusSrv_get_StopBits_Proxy ,
    IModbusSrv_put_StopBits_Proxy ,
    IModbusSrv_get_TransmissionMode_Proxy ,
    IModbusSrv_put_TransmissionMode_Proxy ,
    IModbusSrv_get_ByteSize_Proxy ,
    IModbusSrv_put_ByteSize_Proxy ,
    IModbusSrv_TxRxRawData_Proxy ,
    IModbusSrv_get_Delay_Proxy ,
    IModbusSrv_put_Delay_Proxy
};


static const PRPC_STUB_FUNCTION IModbusSrv_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IModbusSrvStubVtbl =
{
    &IID_IModbusSrv,
    &IModbusSrv_ServerInfo,
    51,
    &IModbusSrv_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ICTCPIPServer, ver. 0.0,
   GUID={0x47ADFAE1,0xD261,0x11D1,{0x8F,0xE9,0x6C,0xD5,0x04,0xC1,0xBC,0x01}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICTCPIPServer_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short ICTCPIPServer_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1520,
    1548,
    1576,
    1604,
    1632,
    134,
    1660,
    1688
    };

static const MIDL_SERVER_INFO ICTCPIPServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ICTCPIPServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICTCPIPServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ICTCPIPServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(15) _ICTCPIPServerProxyVtbl = 
{
    &ICTCPIPServer_ProxyInfo,
    &IID_ICTCPIPServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ICTCPIPServer::get_ServerAddress */ ,
    (void *)-1 /* ICTCPIPServer::put_ServerAddress */ ,
    (void *)-1 /* ICTCPIPServer::get_ServerPort */ ,
    (void *)-1 /* ICTCPIPServer::put_ServerPort */ ,
    (void *)-1 /* ICTCPIPServer::StartServer */ ,
    (void *)-1 /* ICTCPIPServer::StopServer */ ,
    (void *)-1 /* ICTCPIPServer::get_ServerActive */ ,
    (void *)-1 /* ICTCPIPServer::GetLocalHostIP */
};


static const PRPC_STUB_FUNCTION ICTCPIPServer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ICTCPIPServerStubVtbl =
{
    &IID_ICTCPIPServer,
    &ICTCPIPServer_ServerInfo,
    15,
    &ICTCPIPServer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure CloseConnection */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 16 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ComPort */

/* 22 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 24 */	NdrFcLong( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 30 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0xe ),	/* 14 */
/* 36 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 38 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 40 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 42 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 44 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 46 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 48 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ComPort */

/* 50 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 52 */	NdrFcLong( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 58 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 60 */	NdrFcShort( 0x6 ),	/* 6 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 66 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 70 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 72 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_BaudRate */

/* 78 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 80 */	NdrFcLong( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 86 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x10 ),	/* 16 */
/* 92 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 94 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 96 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 98 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 102 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_BaudRate */

/* 106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 114 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 120 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 122 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 124 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 130 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StopServer */


	/* Procedure get_Parity */

/* 134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 142 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xe ),	/* 14 */
/* 148 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pbOk */


	/* Parameter pVal */

/* 150 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 152 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 154 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 158 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Parity */

/* 162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 170 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 172 */	NdrFcShort( 0x6 ),	/* 6 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 178 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 180 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 182 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 186 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FlowControl */

/* 190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 198 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0xe ),	/* 14 */
/* 204 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 206 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 208 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 210 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 214 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FlowControl */

/* 218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 226 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 228 */	NdrFcShort( 0x6 ),	/* 6 */
/* 230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 232 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 236 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 238 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 242 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Connect */

/* 246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 254 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xe ),	/* 14 */
/* 260 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pbConnected */

/* 262 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 264 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 266 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 270 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenConnection */

/* 274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 282 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 284 */	NdrFcShort( 0x6 ),	/* 6 */
/* 286 */	NdrFcShort( 0xe ),	/* 14 */
/* 288 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter Name */

/* 290 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 292 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 294 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Parameter Type */

/* 296 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 298 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 300 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pbOk */

/* 302 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 304 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 306 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 310 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RaiseError */

/* 314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 322 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0xe ),	/* 14 */
/* 328 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 332 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 334 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 338 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RaiseError */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x13 ),	/* 19 */
#ifndef _ALPHA_
/* 350 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 352 */	NdrFcShort( 0x6 ),	/* 6 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 360 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 362 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 366 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PresetSingleRegister */

/* 370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 378 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
#else
			NdrFcShort( 0x38 ),	/* MIPS & PPC Stack size/offset = 56 */
#endif
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 380 */	NdrFcShort( 0xe ),	/* 14 */
/* 382 */	NdrFcShort( 0x10 ),	/* 16 */
/* 384 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter Addr */

/* 386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 388 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 390 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter Register */

/* 392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 394 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter RegValue */

/* 398 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 402 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter vRealType */

/* 404 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 406 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/* MIPS & PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 408 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter lRetval */

/* 410 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 412 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
#else
			NdrFcShort( 0x30 ),	/* MIPS & PPC Stack size/offset = 48 */
#endif
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 418 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
#else
			NdrFcShort( 0x34 ),	/* MIPS & PPC Stack size/offset = 52 */
#endif
#else
			NdrFcShort( 0x40 ),	/* Alpha Stack size/offset = 64 */
#endif
/* 420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ForceSingleCoil */

/* 422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x15 ),	/* 21 */
#ifndef _ALPHA_
/* 430 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 432 */	NdrFcShort( 0x14 ),	/* 20 */
/* 434 */	NdrFcShort( 0x10 ),	/* 16 */
/* 436 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter Addr */

/* 438 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 440 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 442 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter Register */

/* 444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 446 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter CoilValue */

/* 450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 452 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 454 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter plRetVal */

/* 456 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 458 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 464 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadOutputRegisters */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x16 ),	/* 22 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 476 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
#else
			NdrFcShort( 0x40 ),	/* MIPS & PPC Stack size/offset = 64 */
#endif
#else
			NdrFcShort( 0x58 ),	/* Alpha Stack size/offset = 88 */
#endif
/* 478 */	NdrFcShort( 0x14 ),	/* 20 */
/* 480 */	NdrFcShort( 0x10 ),	/* 16 */
/* 482 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x8,		/* 8 */

	/* Parameter Addr */

/* 484 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 486 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 488 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter DataStart */

/* 490 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 492 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Quantity */

/* 496 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 498 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 500 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vRegValues */

/* 502 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 504 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 506 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter vVarType */

/* 508 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 510 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 512 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter vRealType */

/* 514 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 516 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
#else
			NdrFcShort( 0x28 ),	/* MIPS & PPC Stack size/offset = 40 */
#endif
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 518 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter lpRetVal */

/* 520 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 522 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
#else
			NdrFcShort( 0x38 ),	/* MIPS & PPC Stack size/offset = 56 */
#endif
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 528 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
#else
			NdrFcShort( 0x3c ),	/* MIPS & PPC Stack size/offset = 60 */
#endif
#else
			NdrFcShort( 0x50 ),	/* Alpha Stack size/offset = 80 */
#endif
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadInputRegisters */

/* 532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x17 ),	/* 23 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 540 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
#else
			NdrFcShort( 0x40 ),	/* MIPS & PPC Stack size/offset = 64 */
#endif
#else
			NdrFcShort( 0x58 ),	/* Alpha Stack size/offset = 88 */
#endif
/* 542 */	NdrFcShort( 0x14 ),	/* 20 */
/* 544 */	NdrFcShort( 0x10 ),	/* 16 */
/* 546 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x8,		/* 8 */

	/* Parameter Addr */

/* 548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 550 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 552 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter DataStart */

/* 554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 556 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Quantity */

/* 560 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 562 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 564 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vRegValues */

/* 566 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 568 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 570 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter vVarType */

/* 572 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 574 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 576 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter vRealType */

/* 578 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 580 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
#else
			NdrFcShort( 0x28 ),	/* MIPS & PPC Stack size/offset = 40 */
#endif
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 582 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter plRetVal */

/* 584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 586 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
#else
			NdrFcShort( 0x38 ),	/* MIPS & PPC Stack size/offset = 56 */
#endif
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 592 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
#else
			NdrFcShort( 0x3c ),	/* MIPS & PPC Stack size/offset = 60 */
#endif
#else
			NdrFcShort( 0x50 ),	/* Alpha Stack size/offset = 80 */
#endif
/* 594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadOutputStatus */

/* 596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x18 ),	/* 24 */
#ifndef _ALPHA_
/* 604 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 606 */	NdrFcShort( 0x14 ),	/* 20 */
/* 608 */	NdrFcShort( 0x10 ),	/* 16 */
/* 610 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter Addr */

/* 612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 614 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 616 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter DataStart */

/* 618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 620 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Quantity */

/* 624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 626 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 628 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vCoilValues */

/* 630 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 632 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 634 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter plRetVal */

/* 636 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 638 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 644 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadInputStatus */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x19 ),	/* 25 */
#ifndef _ALPHA_
/* 656 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 658 */	NdrFcShort( 0x14 ),	/* 20 */
/* 660 */	NdrFcShort( 0x10 ),	/* 16 */
/* 662 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter Addr */

/* 664 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 666 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 668 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter DataStart */

/* 670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 672 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Quantity */

/* 676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 678 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 680 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vCoilValues */

/* 682 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 684 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 686 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter plRetVal */

/* 688 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 690 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 696 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PresetMultipleRegisters */

/* 700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x1a ),	/* 26 */
#ifndef _ALPHA_
/* 708 */	NdrFcShort( 0x38 ),	/* x86, MIPS, PPC Stack size/offset = 56 */
#else
			NdrFcShort( 0x50 ),	/* Alpha Stack size/offset = 80 */
#endif
/* 710 */	NdrFcShort( 0x14 ),	/* 20 */
/* 712 */	NdrFcShort( 0x10 ),	/* 16 */
/* 714 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter Addr */

/* 716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 718 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 720 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter DataStart */

/* 722 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 724 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Quantity */

/* 728 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 730 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 732 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vRegValues */

/* 734 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 736 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 738 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter vRealType */

/* 740 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 742 */	NdrFcShort( 0x20 ),	/* x86, MIPS, PPC Stack size/offset = 32 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 744 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter plRetVal */

/* 746 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 748 */	NdrFcShort( 0x30 ),	/* x86, MIPS, PPC Stack size/offset = 48 */
#else
			NdrFcShort( 0x40 ),	/* Alpha Stack size/offset = 64 */
#endif
/* 750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 754 */	NdrFcShort( 0x34 ),	/* x86, MIPS, PPC Stack size/offset = 52 */
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ForceMultipleCoils */

/* 758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x1b ),	/* 27 */
#ifndef _ALPHA_
/* 766 */	NdrFcShort( 0x28 ),	/* x86, MIPS, PPC Stack size/offset = 40 */
#else
			NdrFcShort( 0x40 ),	/* Alpha Stack size/offset = 64 */
#endif
/* 768 */	NdrFcShort( 0x14 ),	/* 20 */
/* 770 */	NdrFcShort( 0x10 ),	/* 16 */
/* 772 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter Addr */

/* 774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 776 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 778 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter DataStart */

/* 780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 782 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Quantity */

/* 786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 788 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 790 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vCoilValues */

/* 792 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 794 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 796 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter plRetVal */

/* 798 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 800 */	NdrFcShort( 0x20 ),	/* x86, MIPS, PPC Stack size/offset = 32 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 806 */	NdrFcShort( 0x24 ),	/* x86, MIPS, PPC Stack size/offset = 36 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Retries */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1c ),	/* 28 */
#ifndef _ALPHA_
/* 818 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0xe ),	/* 14 */
/* 824 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 826 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 828 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 830 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 834 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Retries */

/* 838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x1d ),	/* 29 */
#ifndef _ALPHA_
/* 846 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 848 */	NdrFcShort( 0x6 ),	/* 6 */
/* 850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 852 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 854 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 856 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 858 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 860 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 862 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsActive */

/* 866 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x1e ),	/* 30 */
#ifndef _ALPHA_
/* 874 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0xe ),	/* 14 */
/* 880 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 882 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 884 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 886 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 890 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Host */

/* 894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0x1f ),	/* 31 */
#ifndef _ALPHA_
/* 902 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 908 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 910 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 912 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 914 */	NdrFcShort( 0x3f6 ),	/* Type Offset=1014 */

	/* Return value */

/* 916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 918 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Host */

/* 922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x20 ),	/* 32 */
#ifndef _ALPHA_
/* 930 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 936 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 938 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 940 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 942 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Return value */

/* 944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 946 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TcpPort */

/* 950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x21 ),	/* 33 */
#ifndef _ALPHA_
/* 958 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x10 ),	/* 16 */
/* 964 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 966 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 968 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 974 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TcpPort */

/* 978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x22 ),	/* 34 */
#ifndef _ALPHA_
/* 986 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 992 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 994 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 996 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1000 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1002 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TxRxMessage */

/* 1006 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1008 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x23 ),	/* 35 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1014 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
#else
			NdrFcShort( 0x30 ),	/* MIPS & PPC Stack size/offset = 48 */
#endif
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 1016 */	NdrFcShort( 0xc ),	/* 12 */
/* 1018 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1020 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter vQuery */

/* 1022 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1024 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1026 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter QueryLength */

/* 1028 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1030 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1032 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vResponse */

/* 1034 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1036 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1038 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter RespLength */

/* 1040 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1042 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/* MIPS & PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1044 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vNumOfBytesRead */

/* 1046 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1048 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
#else
			NdrFcShort( 0x24 ),	/* MIPS & PPC Stack size/offset = 36 */
#endif
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1050 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter plRetVal */

/* 1052 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1054 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
#else
			NdrFcShort( 0x28 ),	/* MIPS & PPC Stack size/offset = 40 */
#endif
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 1056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1060 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
#else
			NdrFcShort( 0x2c ),	/* MIPS & PPC Stack size/offset = 44 */
#endif
#else
			NdrFcShort( 0x40 ),	/* Alpha Stack size/offset = 64 */
#endif
/* 1062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TcpServer */

/* 1064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0x24 ),	/* 36 */
#ifndef _ALPHA_
/* 1072 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1078 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1080 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 1082 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1084 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 1086 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1088 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTCPServer */

/* 1092 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x25 ),	/* 37 */
#ifndef _ALPHA_
/* 1100 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1106 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1108 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 1110 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1112 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 1114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1116 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SilentInterval */

/* 1120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x26 ),	/* 38 */
#ifndef _ALPHA_
/* 1128 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1134 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1136 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1138 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1144 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SilentInterval */

/* 1148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x27 ),	/* 39 */
#ifndef _ALPHA_
/* 1156 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1162 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1166 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1172 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TimeOut */

/* 1176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x28 ),	/* 40 */
#ifndef _ALPHA_
/* 1184 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1190 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1192 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1194 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1200 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TimeOut */

/* 1204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x29 ),	/* 41 */
#ifndef _ALPHA_
/* 1212 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1218 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1222 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1228 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StopBits */

/* 1232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x2a ),	/* 42 */
#ifndef _ALPHA_
/* 1240 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0xe ),	/* 14 */
/* 1246 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1248 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1250 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1252 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1256 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StopBits */

/* 1260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x2b ),	/* 43 */
#ifndef _ALPHA_
/* 1268 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1270 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1274 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1278 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1280 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1284 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TransmissionMode */

/* 1288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x2c ),	/* 44 */
#ifndef _ALPHA_
/* 1296 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0xe ),	/* 14 */
/* 1302 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1304 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1306 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1308 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1312 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TransmissionMode */

/* 1316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x2d ),	/* 45 */
#ifndef _ALPHA_
/* 1324 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1326 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1330 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1334 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1336 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1340 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ByteSize */

/* 1344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x2e ),	/* 46 */
#ifndef _ALPHA_
/* 1352 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0xe ),	/* 14 */
/* 1358 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1360 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1362 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1364 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1368 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ByteSize */

/* 1372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x2f ),	/* 47 */
#ifndef _ALPHA_
/* 1380 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1382 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1386 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1390 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1392 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1396 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TxRxRawData */

/* 1400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x30 ),	/* 48 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1408 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
#else
			NdrFcShort( 0x34 ),	/* MIPS & PPC Stack size/offset = 52 */
#endif
#else
			NdrFcShort( 0x50 ),	/* Alpha Stack size/offset = 80 */
#endif
/* 1410 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1412 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1414 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x8,		/* 8 */

	/* Parameter vQuery */

/* 1416 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1420 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Parameter QueryLength */

/* 1422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1424 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1426 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter vResponse */

/* 1428 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1430 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1432 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter RespLength */

/* 1434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1436 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/* MIPS & PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1438 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter Timeout */

/* 1440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1442 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
#else
			NdrFcShort( 0x24 ),	/* MIPS & PPC Stack size/offset = 36 */
#endif
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter vNumOfBytesRead */

/* 1446 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1448 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
#else
			NdrFcShort( 0x28 ),	/* MIPS & PPC Stack size/offset = 40 */
#endif
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 1450 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Parameter plRetVal */

/* 1452 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1454 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
#else
			NdrFcShort( 0x2c ),	/* MIPS & PPC Stack size/offset = 44 */
#endif
#else
			NdrFcShort( 0x40 ),	/* Alpha Stack size/offset = 64 */
#endif
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 1460 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
#else
			NdrFcShort( 0x30 ),	/* MIPS & PPC Stack size/offset = 48 */
#endif
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Delay */

/* 1464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x31 ),	/* 49 */
#ifndef _ALPHA_
/* 1472 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1478 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1480 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1482 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1488 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Delay */

/* 1492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x32 ),	/* 50 */
#ifndef _ALPHA_
/* 1500 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1506 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1510 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1516 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ServerAddress */

/* 1520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 1528 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1534 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1536 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1538 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1540 */	NdrFcShort( 0x3f6 ),	/* Type Offset=1014 */

	/* Return value */

/* 1542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1544 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ServerAddress */

/* 1548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1554 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 1556 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1562 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1564 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1566 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1568 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Return value */

/* 1570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1572 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ServerPort */

/* 1576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 1584 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1590 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1592 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1594 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1600 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ServerPort */

/* 1604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 1612 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1618 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1620 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1622 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1628 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartServer */

/* 1632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 1640 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1644 */	NdrFcShort( 0xe ),	/* 14 */
/* 1646 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pbOk */

/* 1648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1650 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1652 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1656 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ServerActive */

/* 1660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 1668 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0xe ),	/* 14 */
/* 1674 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1676 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1678 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1680 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1684 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLocalHostIP */

/* 1688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 1696 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1702 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pbstrVal */

/* 1704 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1706 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1708 */	NdrFcShort( 0x3f6 ),	/* Type Offset=1014 */

	/* Return value */

/* 1710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1712 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x12, 0x0,	/* FC_UP */
/* 12 */	NdrFcShort( 0xc ),	/* Offset= 12 (24) */
/* 14 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 16 */	NdrFcShort( 0x2 ),	/* 2 */
/* 18 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 22 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 24 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
/* 28 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (14) */
/* 30 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 32 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 34 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x4 ),	/* 4 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (10) */
/* 44 */	
			0x12, 0x0,	/* FC_UP */
/* 46 */	NdrFcShort( 0x390 ),	/* Offset= 912 (958) */
/* 48 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 50 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 52 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 54 */	NdrFcShort( 0x2 ),	/* Offset= 2 (56) */
/* 56 */	NdrFcShort( 0x10 ),	/* 16 */
/* 58 */	NdrFcShort( 0x2b ),	/* 43 */
/* 60 */	NdrFcLong( 0x3 ),	/* 3 */
/* 64 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 66 */	NdrFcLong( 0x11 ),	/* 17 */
/* 70 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 72 */	NdrFcLong( 0x2 ),	/* 2 */
/* 76 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 78 */	NdrFcLong( 0x4 ),	/* 4 */
/* 82 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 84 */	NdrFcLong( 0x5 ),	/* 5 */
/* 88 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 90 */	NdrFcLong( 0xb ),	/* 11 */
/* 94 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 96 */	NdrFcLong( 0xa ),	/* 10 */
/* 100 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 102 */	NdrFcLong( 0x6 ),	/* 6 */
/* 106 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (320) */
/* 108 */	NdrFcLong( 0x7 ),	/* 7 */
/* 112 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 114 */	NdrFcLong( 0x8 ),	/* 8 */
/* 118 */	NdrFcShort( 0xffffff94 ),	/* Offset= -108 (10) */
/* 120 */	NdrFcLong( 0xd ),	/* 13 */
/* 124 */	NdrFcShort( 0xca ),	/* Offset= 202 (326) */
/* 126 */	NdrFcLong( 0x9 ),	/* 9 */
/* 130 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (344) */
/* 132 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 136 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (362) */
/* 138 */	NdrFcLong( 0x24 ),	/* 36 */
/* 142 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (890) */
/* 144 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 148 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (890) */
/* 150 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 154 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (894) */
/* 156 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 160 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (898) */
/* 162 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 166 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (902) */
/* 168 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 172 */	NdrFcShort( 0x2de ),	/* Offset= 734 (906) */
/* 174 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 178 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (910) */
/* 180 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 184 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (898) */
/* 186 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 190 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (902) */
/* 192 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 196 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (914) */
/* 198 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 202 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (910) */
/* 204 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 208 */	NdrFcShort( 0x2c6 ),	/* Offset= 710 (918) */
/* 210 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 214 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (922) */
/* 216 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 220 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (926) */
/* 222 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 226 */	NdrFcShort( 0x2c0 ),	/* Offset= 704 (930) */
/* 228 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 232 */	NdrFcShort( 0x2be ),	/* Offset= 702 (934) */
/* 234 */	NdrFcLong( 0x10 ),	/* 16 */
/* 238 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 240 */	NdrFcLong( 0x12 ),	/* 18 */
/* 244 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 246 */	NdrFcLong( 0x13 ),	/* 19 */
/* 250 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 252 */	NdrFcLong( 0x16 ),	/* 22 */
/* 256 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 258 */	NdrFcLong( 0x17 ),	/* 23 */
/* 262 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 264 */	NdrFcLong( 0xe ),	/* 14 */
/* 268 */	NdrFcShort( 0x2a2 ),	/* Offset= 674 (942) */
/* 270 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 274 */	NdrFcShort( 0x2a8 ),	/* Offset= 680 (954) */
/* 276 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 280 */	NdrFcShort( 0x266 ),	/* Offset= 614 (894) */
/* 282 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 286 */	NdrFcShort( 0x264 ),	/* Offset= 612 (898) */
/* 288 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 292 */	NdrFcShort( 0x262 ),	/* Offset= 610 (902) */
/* 294 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 298 */	NdrFcShort( 0x25c ),	/* Offset= 604 (902) */
/* 300 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 304 */	NdrFcShort( 0x256 ),	/* Offset= 598 (902) */
/* 306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* Offset= 0 (310) */
/* 312 */	NdrFcLong( 0x1 ),	/* 1 */
/* 316 */	NdrFcShort( 0x0 ),	/* Offset= 0 (316) */
/* 318 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (317) */
/* 320 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 324 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 326 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 338 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 340 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 342 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 344 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 346 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 356 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 358 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 360 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 362 */	
			0x12, 0x0,	/* FC_UP */
/* 364 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (872) */
/* 366 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 368 */	NdrFcShort( 0x18 ),	/* 24 */
/* 370 */	NdrFcShort( 0xa ),	/* 10 */
/* 372 */	NdrFcLong( 0x8 ),	/* 8 */
/* 376 */	NdrFcShort( 0x58 ),	/* Offset= 88 (464) */
/* 378 */	NdrFcLong( 0xd ),	/* 13 */
/* 382 */	NdrFcShort( 0x78 ),	/* Offset= 120 (502) */
/* 384 */	NdrFcLong( 0x9 ),	/* 9 */
/* 388 */	NdrFcShort( 0x94 ),	/* Offset= 148 (536) */
/* 390 */	NdrFcLong( 0xc ),	/* 12 */
/* 394 */	NdrFcShort( 0xbc ),	/* Offset= 188 (582) */
/* 396 */	NdrFcLong( 0x24 ),	/* 36 */
/* 400 */	NdrFcShort( 0x114 ),	/* Offset= 276 (676) */
/* 402 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 406 */	NdrFcShort( 0x130 ),	/* Offset= 304 (710) */
/* 408 */	NdrFcLong( 0x10 ),	/* 16 */
/* 412 */	NdrFcShort( 0x148 ),	/* Offset= 328 (740) */
/* 414 */	NdrFcLong( 0x2 ),	/* 2 */
/* 418 */	NdrFcShort( 0x160 ),	/* Offset= 352 (770) */
/* 420 */	NdrFcLong( 0x3 ),	/* 3 */
/* 424 */	NdrFcShort( 0x178 ),	/* Offset= 376 (800) */
/* 426 */	NdrFcLong( 0x14 ),	/* 20 */
/* 430 */	NdrFcShort( 0x190 ),	/* Offset= 400 (830) */
/* 432 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (431) */
/* 434 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 436 */	NdrFcShort( 0x4 ),	/* 4 */
/* 438 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 442 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 444 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 446 */	NdrFcShort( 0x4 ),	/* 4 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x1 ),	/* 1 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	0x12, 0x0,	/* FC_UP */
/* 458 */	NdrFcShort( 0xfffffe4e ),	/* Offset= -434 (24) */
/* 460 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 462 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 464 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 468 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 470 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 472 */	NdrFcShort( 0x4 ),	/* 4 */
/* 474 */	NdrFcShort( 0x4 ),	/* 4 */
/* 476 */	0x11, 0x0,	/* FC_RP */
/* 478 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (434) */
/* 480 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 482 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 484 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 496 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 498 */	NdrFcShort( 0xffffff54 ),	/* Offset= -172 (326) */
/* 500 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 502 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x6 ),	/* Offset= 6 (514) */
/* 510 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 512 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 514 */	
			0x11, 0x0,	/* FC_RP */
/* 516 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (484) */
/* 518 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 530 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 532 */	NdrFcShort( 0xffffff44 ),	/* Offset= -188 (344) */
/* 534 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 536 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x6 ),	/* Offset= 6 (548) */
/* 544 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 546 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 548 */	
			0x11, 0x0,	/* FC_RP */
/* 550 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (518) */
/* 552 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 554 */	NdrFcShort( 0x4 ),	/* 4 */
/* 556 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 562 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 564 */	NdrFcShort( 0x4 ),	/* 4 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x1 ),	/* 1 */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	0x12, 0x0,	/* FC_UP */
/* 576 */	NdrFcShort( 0x17e ),	/* Offset= 382 (958) */
/* 578 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 580 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 582 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x6 ),	/* Offset= 6 (594) */
/* 590 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 592 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 594 */	
			0x11, 0x0,	/* FC_RP */
/* 596 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (552) */
/* 598 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 600 */	NdrFcLong( 0x2f ),	/* 47 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 610 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 612 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 614 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 616 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 618 */	NdrFcShort( 0x1 ),	/* 1 */
/* 620 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 622 */	NdrFcShort( 0x4 ),	/* 4 */
/* 624 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 626 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 628 */	NdrFcShort( 0x10 ),	/* 16 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0xa ),	/* Offset= 10 (642) */
/* 634 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 636 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 638 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (598) */
/* 640 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 642 */	
			0x12, 0x0,	/* FC_UP */
/* 644 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (616) */
/* 646 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 648 */	NdrFcShort( 0x4 ),	/* 4 */
/* 650 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 656 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 658 */	NdrFcShort( 0x4 ),	/* 4 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x1 ),	/* 1 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	0x12, 0x0,	/* FC_UP */
/* 670 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (626) */
/* 672 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 674 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 676 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x6 ),	/* Offset= 6 (688) */
/* 684 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 686 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 688 */	
			0x11, 0x0,	/* FC_RP */
/* 690 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (646) */
/* 692 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 696 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 698 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 700 */	NdrFcShort( 0x10 ),	/* 16 */
/* 702 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 704 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 706 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (692) */
			0x5b,		/* FC_END */
/* 710 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 712 */	NdrFcShort( 0x18 ),	/* 24 */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0xa ),	/* Offset= 10 (726) */
/* 718 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 720 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 722 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (698) */
/* 724 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 726 */	
			0x11, 0x0,	/* FC_RP */
/* 728 */	NdrFcShort( 0xffffff0c ),	/* Offset= -244 (484) */
/* 730 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 740 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 744 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 746 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 748 */	NdrFcShort( 0x4 ),	/* 4 */
/* 750 */	NdrFcShort( 0x4 ),	/* 4 */
/* 752 */	0x12, 0x0,	/* FC_UP */
/* 754 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (730) */
/* 756 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 758 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 760 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 762 */	NdrFcShort( 0x2 ),	/* 2 */
/* 764 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 770 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 776 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 778 */	NdrFcShort( 0x4 ),	/* 4 */
/* 780 */	NdrFcShort( 0x4 ),	/* 4 */
/* 782 */	0x12, 0x0,	/* FC_UP */
/* 784 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (760) */
/* 786 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 788 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 790 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 792 */	NdrFcShort( 0x4 ),	/* 4 */
/* 794 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 800 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 802 */	NdrFcShort( 0x8 ),	/* 8 */
/* 804 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 806 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 808 */	NdrFcShort( 0x4 ),	/* 4 */
/* 810 */	NdrFcShort( 0x4 ),	/* 4 */
/* 812 */	0x12, 0x0,	/* FC_UP */
/* 814 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (790) */
/* 816 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 818 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 820 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 828 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 830 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 834 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 836 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 838 */	NdrFcShort( 0x4 ),	/* 4 */
/* 840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 842 */	0x12, 0x0,	/* FC_UP */
/* 844 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (820) */
/* 846 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 848 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 850 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 856 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 858 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 862 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 864 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 866 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 868 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (850) */
/* 870 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 872 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x28 ),	/* 40 */
/* 876 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (858) */
/* 878 */	NdrFcShort( 0x0 ),	/* Offset= 0 (878) */
/* 880 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 882 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 884 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 886 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffdf7 ),	/* Offset= -521 (366) */
			0x5b,		/* FC_END */
/* 890 */	
			0x12, 0x0,	/* FC_UP */
/* 892 */	NdrFcShort( 0xfffffef6 ),	/* Offset= -266 (626) */
/* 894 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 896 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 898 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 900 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 902 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 904 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 906 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 908 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 910 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 912 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 914 */	
			0x12, 0x0,	/* FC_UP */
/* 916 */	NdrFcShort( 0xfffffdac ),	/* Offset= -596 (320) */
/* 918 */	
			0x12, 0x10,	/* FC_UP */
/* 920 */	NdrFcShort( 0xfffffc72 ),	/* Offset= -910 (10) */
/* 922 */	
			0x12, 0x10,	/* FC_UP */
/* 924 */	NdrFcShort( 0xfffffdaa ),	/* Offset= -598 (326) */
/* 926 */	
			0x12, 0x10,	/* FC_UP */
/* 928 */	NdrFcShort( 0xfffffdb8 ),	/* Offset= -584 (344) */
/* 930 */	
			0x12, 0x10,	/* FC_UP */
/* 932 */	NdrFcShort( 0xfffffdc6 ),	/* Offset= -570 (362) */
/* 934 */	
			0x12, 0x10,	/* FC_UP */
/* 936 */	NdrFcShort( 0x2 ),	/* Offset= 2 (938) */
/* 938 */	
			0x12, 0x0,	/* FC_UP */
/* 940 */	NdrFcShort( 0xfffffc54 ),	/* Offset= -940 (0) */
/* 942 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 944 */	NdrFcShort( 0x10 ),	/* 16 */
/* 946 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 948 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 950 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 952 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 954 */	
			0x12, 0x0,	/* FC_UP */
/* 956 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (942) */
/* 958 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 960 */	NdrFcShort( 0x20 ),	/* 32 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* Offset= 0 (964) */
/* 966 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 968 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 970 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 972 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 974 */	NdrFcShort( 0xfffffc62 ),	/* Offset= -926 (48) */
/* 976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 978 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 980 */	NdrFcShort( 0x1 ),	/* 1 */
/* 982 */	NdrFcShort( 0x10 ),	/* 16 */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0xfffffc52 ),	/* Offset= -942 (44) */
/* 988 */	
			0x11, 0x0,	/* FC_RP */
/* 990 */	NdrFcShort( 0x6 ),	/* Offset= 6 (996) */
/* 992 */	
			0x13, 0x0,	/* FC_OP */
/* 994 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (958) */
/* 996 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 998 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1000 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (992) */
/* 1006 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1008 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1014) */
/* 1010 */	
			0x13, 0x0,	/* FC_OP */
/* 1012 */	NdrFcShort( 0xfffffc24 ),	/* Offset= -988 (24) */
/* 1014 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1010) */
/* 1024 */	
			0x11, 0x10,	/* FC_RP */
/* 1026 */	NdrFcShort( 0xfffffd56 ),	/* Offset= -682 (344) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _ModbusServer_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IModbusSrvProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICTCPIPServerProxyVtbl,
    0
};

const CInterfaceStubVtbl * _ModbusServer_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IModbusSrvStubVtbl,
    ( CInterfaceStubVtbl *) &_ICTCPIPServerStubVtbl,
    0
};

PCInterfaceName const _ModbusServer_InterfaceNamesList[] = 
{
    "IModbusSrv",
    "ICTCPIPServer",
    0
};

const IID *  _ModbusServer_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _ModbusServer_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ModbusServer, pIID, n)

int __stdcall _ModbusServer_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _ModbusServer, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _ModbusServer, 2, *pIndex )
    
}

const ExtendedProxyFileInfo ModbusServer_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ModbusServer_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ModbusServer_StubVtblList,
    (const PCInterfaceName * ) & _ModbusServer_InterfaceNamesList,
    (const IID ** ) & _ModbusServer_BaseIIDList,
    & _ModbusServer_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
