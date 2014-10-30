/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Sep 04 11:57:52 1999
 */
/* Compiler settings for ModbusServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IModbusSrv = {0xB3DE3CC1,0xC629,0x11D1,{0x8F,0xE9,0xE4,0xCD,0x05,0xC1,0x00,0x00}};


const IID IID_ICTCPIPServer = {0x47ADFAE1,0xD261,0x11D1,{0x8F,0xE9,0x6C,0xD5,0x04,0xC1,0xBC,0x01}};


const IID LIBID_MODBUSSERVERLib = {0xB3DE3CB4,0xC629,0x11D1,{0x8F,0xE9,0xE4,0xCD,0x05,0xC1,0x00,0x00}};


const CLSID CLSID_ModbusSrv = {0xB3DE3CC2,0xC629,0x11D1,{0x8F,0xE9,0xE4,0xCD,0x05,0xC1,0x00,0x00}};


const CLSID CLSID_CTCPIPServer = {0x47ADFAE2,0xD261,0x11D1,{0x8F,0xE9,0x6C,0xD5,0x04,0xC1,0xBC,0x01}};


#ifdef __cplusplus
}
#endif

