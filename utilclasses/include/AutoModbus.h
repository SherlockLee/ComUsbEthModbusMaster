// AutoModbus.h: interface for the CAutoModbus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOMODBUS_H__DA5B56E1_D64D_11D1_8FE9_6CD504C1BC01__INCLUDED_)
#define AFX_AUTOMODBUS_H__DA5B56E1_D64D_11D1_8FE9_6CD504C1BC01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "modbus.h"

#include "ModbusServer.h"

class CAutoModbus : public CModbus  
{
	DECLARE_DYNAMIC(CAutoModbus)
public:
	CString Machine();
	void Serialize(CArchive& archive);
	void ByteSize(WORD wSize);
	WORD ByteSize();
	void TransmissionMode(WORD wMode);
	WORD TransmissionMode();
	void StopBits(BYTE byStopBits);
	BYTE StopBits();
	BYTE FlowControl();
	void FlowControl(BYTE byFlow);
	BOOL Connect();
	void SilentInterval(DWORD dwSilentInterval);
	DWORD SilentInterval();
	void Timeout(DWORD dwTimeOut);
	DWORD Timeout();
	BYTE Parity();
	void Parity(BYTE byParity);
	void BaudRate(DWORD dwBaudRate);
	DWORD BaudRate();
	DWORD Delay();
    void Delay(DWORD dwDelay);
	BYTE ComPort();
	void ComPort(BYTE byPort);
	void Release( );
	HRESULT CreateInstance(LPCSTR szMachine,LPCSTR szConnectionName);
	CString ErrorMessage(WORD wErrorCode);
	CAutoModbus();
	virtual ~CAutoModbus();

	//transmit a query to a modbus device and wait for a response
//return ERR_XXX Code see Modbus.cpp file  
 WORD TxRxMessage(CByteArray& abyQuery, //modbus query without CRC
				  WORD wLengthQuery, //QueryLength without CRC
				  CByteArray& abyResponse, //modbus Response without CRC
				  WORD wLengthResponse, //wLengthResponse Response without CRC
				  WORD* pwNumOfBytesRead=NULL);
 BOOL IsActive(); //return  if the connection is open

 CComPtr<IModbusSrv>  m_pIModbusSrv;
 CComPtr<ICTCPIPServer>  m_pITCPServer;

 //Error Constants 
 enum _ERRROR_CODES_{
		ERR_AUTOMATION_ERROR=2000,
        ERR_BUILD_ARRAY_ERROR=2001
 };

private:
	CString m_sMachine;
	CString m_sConnectionName;

};

#endif // !defined(AFX_AUTOMODBUS_H__DA5B56E1_D64D_11D1_8FE9_6CD504C1BC01__INCLUDED_)
