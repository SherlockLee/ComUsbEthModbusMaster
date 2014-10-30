// ModbusSrv.cpp : Implementation of CModbusSrv
#include "stdafx.h"
#include "ModbusServer.h"
#include "ModbusSrv.h"


/////////////////////////////////////////////////////////////////////////////
// CModbusSrv

STDMETHODIMP CModbusSrv::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IModbusSrv,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CModbusSrv::CloseConnection()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	if (m_pConnection!=NULL) {
		gConnections.Remove(m_pConnection->Key());
	}

	m_pConnection=NULL;

	return S_OK;
}

void CModbusSrv::Init()
{
	m_pConnection=NULL;
	m_bRaiseError=FALSE;

}

void CModbusSrv::Terminate()
{
	CloseConnection();
}

STDMETHODIMP CModbusSrv::get_ComPort(short* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION
	*pVal = m_pConnection->m_pLocalModbus->ComPort();

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_ComPort(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
	VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->ComPort(BYTE(newVal));
		
	return S_OK;
}

STDMETHODIMP CModbusSrv::get_BaudRate(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_LOCAL_CONNECTION

	// TODO: Add your implementation code here
	*pVal=m_pConnection->m_pLocalModbus->BaudRate();
	return S_OK;
}

STDMETHODIMP CModbusSrv::put_BaudRate(long newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
	VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->BaudRate(DWORD(newVal));

	return S_OK;
}

STDMETHODIMP CModbusSrv::get_Parity(short* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
	VERIFY_LOCAL_CONNECTION

	// TODO: Add your implementation code here
	*pVal = m_pConnection->m_pLocalModbus->Parity();
	return S_OK;
}


STDMETHODIMP CModbusSrv::put_Parity(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->Parity(BYTE(newVal));

	return S_OK;
}


STDMETHODIMP CModbusSrv::get_FlowControl(short* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION

	*pVal=m_pConnection->m_pLocalModbus->FlowControl();

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_FlowControl(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	m_pConnection->m_pLocalModbus->FlowControl(BYTE(newVal));
	VERIFY_LOCAL_CONNECTION


	return S_OK;
}

STDMETHODIMP CModbusSrv::Connect(VARIANT_BOOL* pbConnected)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	if (m_pConnection!=NULL) {
		
		switch(m_pConnection->Type()) {
		case CConnection::LOCAL:
			*pbConnected =CBoolVb(m_pConnection->m_pLocalModbus->UpdateSerialConfig());
			break;
			
		case CConnection::REMOTE:
			*pbConnected = CBoolVb(m_pConnection->m_pRemoteModbus->openConnection());
			break;
		}
		
	}
	else {
		return Error(ERR_CONNECTION_NOT_OPENED,IDS_ATL_ERR_CONN_NOT_OPENDED);	
	}

	return S_OK;
}



STDMETHODIMP CModbusSrv::OpenConnection(BSTR Name, short Type , VARIANT_BOOL* pbOk)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
		
	// TODO: Add your implementation code here
		
	USES_CONVERSION;
	
	CloseConnection();
	
	CString sName(W2A(Name));
		
	switch(Type) {
	case CConnection::LOCAL:
		m_pConnection = gConnections.Add(sName,CConnection::LOCAL);
		*pbOk=VARIANT_TRUE;
		break;
	case CConnection::REMOTE:
		m_pConnection = gConnections.Add(sName,CConnection::REMOTE);
		*pbOk=VARIANT_TRUE;
		break;
	default:
		*pbOk=VARIANT_FALSE;
		break;

	}
	
	return S_OK;
}

STDMETHODIMP CModbusSrv::get_RaiseError(VARIANT_BOOL * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	*pVal = CBoolVb(m_bRaiseError);

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_RaiseError(VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	m_bRaiseError=(newVal!=VARIANT_FALSE);

	return S_OK;
}



HRESULT CModbusSrv::ExceptionErrorCode(WORD wError)
{
	if (CModbus::ERR_OK!=wError) {
		return MAKE_HRESULT(SEVERITY_ERROR,FACILITY_ITF,ERR_OFFSET+wError);
	}
	else {
		return CModbus::ERR_OK;
	}

}


HRESULT CModbusSrv::Error(WORD wErrorCode, UINT nID)
{
	HRESULT hRes;

	if ( (wErrorCode>=FATAL_ERROR) || ((m_bRaiseError)&&(CModbus::ERR_OK!=wErrorCode)) ){
			hRes=ExceptionErrorCode(wErrorCode);
			return CComCoClass<CModbusSrv, &CLSID_ModbusSrv>::Error(nID,IID_IModbusSrv,hRes);
	}
	else {
			return S_OK;
	}
}

HRESULT CModbusSrv::Error(WORD wError, LPCTSTR lpstrErrMessage)
{

	USES_CONVERSION;

	HRESULT hRes;

	CString sMsg;

	if ( (wError>=FATAL_ERROR) || ((m_bRaiseError)&&(CModbus::ERR_OK!=wError)) ){
			hRes=ExceptionErrorCode(wError);
			if (NULL==lpstrErrMessage) {
				sMsg = m_pConnection->m_pModbus->ErrorMessage(wError);
			}
			return CComCoClass<CModbusSrv, &CLSID_ModbusSrv>::Error(A2OLE((LPCTSTR)sMsg), 
				IID_IModbusSrv, hRes);
	}
	else {
			return S_OK;
	}

}


VARIANT_BOOL CModbusSrv::CBoolVb(BOOL bCondition)
{

	if (FALSE==bCondition) {
		return VARIANT_FALSE;
	}
	else {
		return VARIANT_TRUE;
	}

}

STDMETHODIMP CModbusSrv::PresetSingleRegister(short Addr, long Register, VARIANT RegValue, VARIANT vRealType , long* lRetval)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
		
	WORD wError;
	WORD wRealType;
	
	COleVariantEx vRegValue(RegValue);
	
	COleVariantEx vR_Type(vRealType);
	
	// TODO: Add your implementation code here
	
	VERIFY_CONNECTION
		

    wRealType=CModbus::REAL_NORMAL;

	if (!vR_Type.IsMissing()) {
		
		if (CModbus::REAL_REVERSE==vR_Type.ToInt()){
				
				wRealType=CModbus::REAL_REVERSE;	
				
		}
		else {
				
				wRealType=CModbus::REAL_NORMAL;
				
		}	
	}
		
	switch (vRegValue.VarType()) {
		
		case VT_I2:
        case VT_I4:
			wError = m_pConnection->m_pModbus->PresetSingleRegister(WORD(Addr),WORD(Register),vRegValue.ToWord());
			break;
		case VT_R4:
			wError = m_pConnection->m_pModbus->PresetSingleRegister(WORD(Addr),WORD(Register),vRegValue.ToFloat(),wRealType); 
			break;
		case VT_R8:
			wError = m_pConnection->m_pModbus->PresetSingleRegister(WORD(Addr),WORD(Register),vRegValue.ToDouble(),wRealType);
			break;
		default:
			return Error(ERR_TYPE_MISMACTH,IDS_ERR_TYPE_MISMACTH);
	}
	
	*lRetval = ExceptionErrorCode(wError);
	
	return Error(wError);
	
}

STDMETHODIMP CModbusSrv::ForceSingleCoil(short Addr, long Register, VARIANT_BOOL CoilValue, long * plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())


	WORD wError;

	VERIFY_CONNECTION

	wError = m_pConnection->m_pModbus->ForceSingleCoil(WORD(Addr),WORD(Register),(VARIANT_TRUE==CoilValue));

	*plRetVal = ExceptionErrorCode(wError);

	return Error(wError);

}

STDMETHODIMP CModbusSrv::ReadOutputRegisters(short Addr, long DataStart, short Quantity, VARIANT* vRegValues , VARIANT vVarType,VARIANT vRealType , long* lpRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	WORD wError;
	WORD wRealType;

	VERIFY_CONNECTION

    VARTYPE vtDest;

	COleSafeArrayEx vRegs;
	COleVariantEx vDataType(vVarType);
	COleVariantEx vR_Type(vRealType);

	CWordArray anRegValues;
	CFloatArray afRegValues;
	CDblArray adRegValues;


	//clear in,out parameters 
    HRESULT hr;

	hr=::VariantClear(vRegValues);

	if (S_OK!=hr) {
		return hr;
	}

	if (vDataType.IsMissing()){
		vtDest=VT_I4;
	}
	else {
		if ((vDataType.ToInt()>=VT_I2) && (vDataType.ToInt()<=VT_R8)){
			vtDest=vDataType.ToInt();
		}
		else {
			vtDest=VT_I4;
		}

	}

	if (vR_Type.IsMissing()){
		wRealType=CModbus::REAL_NORMAL;
	}
	else {
		if (CModbus::REAL_REVERSE==vR_Type.ToInt()){
			wRealType=CModbus::REAL_REVERSE;	
		}
		else {
			wRealType=CModbus::REAL_NORMAL;
		}
		
	}

	switch (vtDest) {
	case VT_I2:
    case VT_I4:
		
		anRegValues.SetSize(Quantity);
		wError = m_pConnection->m_pModbus->ReadOutputRegisters(WORD(Addr),  //address of modbus device
			WORD(DataStart) , //start address, first address is 0 "ZERO" Ex: 30005 -> nDaStart=4 
			WORD(Quantity) , //number of reg. to read 
			anRegValues); //read values if does not occur an error
		
		if (!vRegs.ToVariantArray(anRegValues,vRegValues,vtDest)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		break;
		
	case VT_R4: 
		
		afRegValues.SetSize(Quantity);
		wError = m_pConnection->m_pModbus->ReadOutputRegisters(WORD(Addr),  //address of modbus device
			WORD(DataStart) , //start address, first address is 0 "ZERO" Ex: 30005 -> nDaStart=4 
			WORD(Quantity) , //number of reg. to read 
			afRegValues,
			wRealType); //read values if does not occur an error
		
		if (!vRegs.ToVariantArray(afRegValues.GetData(),afRegValues.GetSize(),vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		
		break;
		
	case VT_R8: 
		
		adRegValues.SetSize(Quantity);
		wError = m_pConnection->m_pModbus->ReadOutputRegisters(WORD(Addr),  //address of modbus device
			WORD(DataStart) , //start address, first address is 0 "ZERO" Ex: 30005 -> nDaStart=4 
			WORD(Quantity) , //number of reg. to read 
			adRegValues,
			wRealType); //read values if does not occur an error
		
		if (!vRegs.ToVariantArray(adRegValues.GetData(),adRegValues.GetSize(),vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		
		break;
		
	}

	*lpRetVal = ExceptionErrorCode(wError);

	return Error(wError);
}

STDMETHODIMP CModbusSrv::ReadInputRegisters(short Addr, long DataStart, short Quantity, VARIANT * vRegValues, VARIANT vVarType,VARIANT vRealType, long * plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	WORD wError;
	WORD wRealType;

	VERIFY_CONNECTION

    VARTYPE vtDest;

	COleSafeArrayEx vRegs;
	COleVariantEx vDataType(vVarType);
	COleVariantEx vR_Type(vRealType);
	

	CWordArray anRegValues;
	CFloatArray afRegValues;
	CDblArray adRegValues;

	//clear in,out parameters 
	HRESULT hr;

	hr=::VariantClear(vRegValues);

	if (S_OK!=hr) {
		return hr;
	}

	if (vDataType.IsMissing()){
		vtDest=VT_I4;
	}
	else {
		if ((vDataType.ToInt()>=VT_I2) && (vDataType.ToInt()<=VT_R8)){
			vtDest=vDataType.ToInt();
		}
		else {
			vtDest=VT_I4;
		}

	}

	if (vR_Type.IsMissing()){
		wRealType=CModbus::REAL_NORMAL;
	}
	else {
		if (CModbus::REAL_REVERSE==vR_Type.ToInt()){
			wRealType=CModbus::REAL_REVERSE;	
		}
		else {
			wRealType=CModbus::REAL_NORMAL;
		}
		
	}

	switch (vtDest) {
	case VT_I2:
    case VT_I4:
		
		anRegValues.SetSize(Quantity);
		wError = m_pConnection->m_pModbus->ReadInputRegisters(WORD(Addr),  //address of modbus device
			WORD(DataStart) , //start address, first address is 0 "ZERO" Ex: 30005 -> nDaStart=4 
			WORD(Quantity) , //number of reg. to read 
			anRegValues); //read values if does not occur an error
		
		if (!vRegs.ToVariantArray(anRegValues,vRegValues,vtDest)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		break;
		
	case VT_R4: 
		
		afRegValues.SetSize(Quantity);
		wError = m_pConnection->m_pModbus->ReadInputRegisters(WORD(Addr),  //address of modbus device
			WORD(DataStart) , //start address, first address is 0 "ZERO" Ex: 30005 -> nDaStart=4 
			WORD(Quantity) , //number of reg. to read 
			afRegValues,
			wRealType); //read values if does not occur an error
		
		if (!vRegs.ToVariantArray(afRegValues.GetData(),afRegValues.GetSize(),vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		
		break;
		
	case VT_R8: 
		
		adRegValues.SetSize(Quantity);
		wError = m_pConnection->m_pModbus->ReadInputRegisters(WORD(Addr),  //address of modbus device
			WORD(DataStart) , //start address, first address is 0 "ZERO" Ex: 30005 -> nDaStart=4 
			WORD(Quantity) , //number of reg. to read 
			adRegValues,
			wRealType); //read values if does not occur an error
		
		if (!vRegs.ToVariantArray(adRegValues.GetData(),adRegValues.GetSize(),vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		
		break;
		
	}

	*plRetVal = ExceptionErrorCode(wError);

	return Error(wError);

}

STDMETHODIMP CModbusSrv::ReadOutputStatus(short Addr, long DataStart, short Quantity, VARIANT* vCoilValues, long* plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	WORD wError;
	
	VERIFY_CONNECTION
		

	CByteArray abCoilValues;
	COleSafeArrayEx vCoils;
	

	abCoilValues.SetSize(Quantity);

	//clear in out parameters 
	HRESULT hr;

	hr=::VariantClear(vCoilValues);

	if (S_OK!=hr) {
		return hr;
	}
	
	wError = m_pConnection->m_pModbus->ReadOutputStatus(WORD(Addr), 
						  WORD(DataStart) , 
						  WORD(Quantity) , 
						  abCoilValues); 
	
	
	if (!vCoils.ToVariantBoolArray(abCoilValues,vCoilValues)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
	}
	
	*plRetVal = ExceptionErrorCode(wError);
	
	return Error(wError);


}

STDMETHODIMP CModbusSrv::ReadInputStatus(short Addr, long DataStart, short Quantity, VARIANT * vCoilValues, long * plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		WORD wError;
	
	VERIFY_CONNECTION
		

	CByteArray abCoilValues;
	COleSafeArrayEx vCoils;
	

	abCoilValues.SetSize(Quantity);

	//clear in out parameters 
	HRESULT hr;

	hr=::VariantClear(vCoilValues);

	if (S_OK!=hr) {
		return hr;
	}
	
	wError = m_pConnection->m_pModbus->ReadInputStatus(WORD(Addr), 
						  WORD(DataStart) , 
						  WORD(Quantity) , 
						  abCoilValues); 
	
	
	if (!vCoils.ToVariantBoolArray(abCoilValues,vCoilValues)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
	}
	
	*plRetVal = ExceptionErrorCode(wError);
	
	return Error(wError);
}

STDMETHODIMP CModbusSrv::PresetMultipleRegisters(short Addr, long DataStart, short Quantity, VARIANT vRegValues, VARIANT vRealType , long * plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	WORD wError;
	
	VERIFY_CONNECTION
		
	
	CWordArray anRegValues;
	CFloatArray afRegValues;
	CDblArray adRegValues;

	COleSafeArrayEx vRegs;

	WORD wRealType;
	COleVariantEx vR_Type(vRealType);

	if (!vR_Type.IsMissing()) {

		if (CModbus::REAL_REVERSE==vR_Type.ToInt()){
			
			wRealType=CModbus::REAL_REVERSE;	
			
		}
		
		else {
			
			wRealType=CModbus::REAL_NORMAL;
			
		}	

	}
	else {
		   wRealType=CModbus::REAL_NORMAL;
	}


		
	switch ((vRegValues.vt & 0xF7)) {
		
	case VT_I2:
	case VT_I4:
		anRegValues.SetSize(Quantity);
	
		if (!vRegs.ToWordArray(anRegValues,&vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}
		
		wError = m_pConnection->m_pModbus->PresetMultipleRegisters(WORD(Addr),  
			WORD(DataStart) , 
			WORD(Quantity) , 
			anRegValues); 
		
		break;
	case VT_R4:  
		
		afRegValues.SetSize(Quantity);

		if (!vRegs.ToFloatArray(afRegValues,&vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}

		wError = m_pConnection->m_pModbus->PresetMultipleRegisters(WORD(Addr),  
			WORD(DataStart) , 
			WORD(Quantity) , 
			afRegValues,
			wRealType); 
		break;

	case VT_R8:
		adRegValues.SetSize(Quantity);

		if (!vRegs.ToDblArray(adRegValues,&vRegValues)){
			return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
		}

		wError = m_pConnection->m_pModbus->PresetMultipleRegisters(WORD(Addr),  
			WORD(DataStart) , 
			WORD(Quantity) , 
			adRegValues,
			wRealType); 
		break;
	default:
		return Error(ERR_TYPE_MISMACTH,IDS_ERR_TYPE_MISMACTH);
	}
	
	*plRetVal = ExceptionErrorCode(wError);
	
	return Error(wError);
}

STDMETHODIMP CModbusSrv::ForceMultipleCoils(short Addr, long DataStart, short Quantity, VARIANT vCoilValues, long * plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	WORD wError;
	
	VERIFY_CONNECTION
		
	CByteArray abCoilValues;
	COleSafeArrayEx vCoils;

	
	abCoilValues.SetSize(Quantity);

		
	if (!vCoils.ToBoolByteArray(abCoilValues,&vCoilValues)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
	}
	
	wError = m_pConnection->m_pModbus->ForceMultipleCoils(WORD(Addr),  
						  WORD(DataStart) , 
						  WORD(Quantity) , 
						  abCoilValues); 
	
	
	*plRetVal = ExceptionErrorCode(wError);
	
	return Error(wError);
}

STDMETHODIMP CModbusSrv::get_Retries(short* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_CONNECTION

	*pVal=short(m_pConnection->m_pModbus->Retries());

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_Retries(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())


	VERIFY_CONNECTION

	m_pConnection->m_pModbus->Retries(WORD(newVal));

	return S_OK;
}

STDMETHODIMP CModbusSrv::get_IsActive(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_CONNECTION

	*pVal = CBoolVb(m_pConnection->m_pModbus->IsActive());

	return S_OK;
}

STDMETHODIMP CModbusSrv::get_Host(BSTR* pVal)
{

	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_REMOTE_CONNECTION

	*pVal = m_pConnection->m_pRemoteModbus->Host().AllocSysString();

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_Host(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	USES_CONVERSION;

	CString sHost(W2A(newVal));

	VERIFY_REMOTE_CONNECTION

	m_pConnection->m_pRemoteModbus->Host(sHost);

	return S_OK;
}

STDMETHODIMP CModbusSrv::get_TcpPort(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_REMOTE_CONNECTION

    *pVal=m_pConnection->m_pRemoteModbus->Port();

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_TcpPort(long newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_REMOTE_CONNECTION

    m_pConnection->m_pRemoteModbus->Port(WORD(newVal));

	return S_OK;
}

STDMETHODIMP CModbusSrv::TxRxMessage(VARIANT vQuery, short QueryLength, VARIANT* vResponse, short RespLength, VARIANT* vNumOfBytesRead, long* plRetVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

    VERIFY_CONNECTION
	
	WORD wError;
	COleSafeArrayEx vBytes;
	CByteArray abyQuery;
	CByteArray abyResponse;
	WORD wNumOfBytesRead;
	COleVariantEx vNumReadBytes(vNumOfBytesRead);


	abyQuery.SetSize(QueryLength);

	HRESULT hr;


	hr=::VariantClear(vResponse);

	if (S_OK!=hr) {
		return hr;
	}


	if(RespLength>0){
		abyResponse.SetSize(RespLength);
	}
	else {
		abyResponse.SetSize(512);
	}

	
	if (!vBytes.ToByteArray(abyQuery,&vQuery)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
	}

	wError = m_pConnection->m_pModbus->TxRxMessage(abyQuery, //modbus query without CRC
				  WORD(QueryLength), //QueryLength without CRC
				  abyResponse, //modbus Response without CRC
				  WORD(RespLength), //wLengthResponse Response without CRC
				  &wNumOfBytesRead);

	if (!vBytes.ToVariantArray(abyResponse,vResponse)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);		
	}


	if (!vNumReadBytes.IsMissing()) {
		VERIFY(S_OK==::VariantClear(vNumOfBytesRead));
		vNumOfBytesRead->vt=VT_I4;
		vNumOfBytesRead->lVal=wNumOfBytesRead;
	}
	
	*plRetVal = ExceptionErrorCode(wError);

	return Error(wError);

}

STDMETHODIMP CModbusSrv::get_TcpServer(LPDISPATCH* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	VERIFY_LOCAL_CONNECTION

	// TODO: Add your implementation code here
	*pVal = m_pConnection->GetTcpDispatch();
	return S_OK;
}

STDMETHODIMP CModbusSrv::CreateTCPServer(LPDISPATCH* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION

	// TODO: Add your implementation code here
	*pVal = m_pConnection->GetTcpDispatch();

	return S_OK;
}

STDMETHODIMP CModbusSrv::get_SilentInterval(long * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
    VERIFY_LOCAL_CONNECTION

	// TODO: Add your implementation code here
	*pVal = long( m_pConnection->m_pLocalModbus->SilentInterval() );
	return S_OK;
}

STDMETHODIMP CModbusSrv::put_SilentInterval(long newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->SilentInterval(DWORD(newVal));

	return S_OK;
}

STDMETHODIMP CModbusSrv::get_TimeOut(long * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_CONNECTION
	// TODO: Add your implementation code here
	switch(m_pConnection->Type()) {
	
	case CConnection::LOCAL:
		*pVal = (long)m_pConnection->m_pLocalModbus->Timeout(); 
		break;
	case CConnection::REMOTE:
		*pVal = (long)m_pConnection->m_pRemoteModbus->Timeout(); 
		break;
	default:
		ASSERT(FALSE);
		break;

	}

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_TimeOut(long newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_CONNECTION
	// TODO: Add your implementation code here
	switch(m_pConnection->Type()) {
	
	case CConnection::LOCAL:
		m_pConnection->m_pLocalModbus->Timeout(DWORD(newVal)); 
		break;
	case CConnection::REMOTE:
		m_pConnection->m_pRemoteModbus->Timeout(DWORD(newVal)); 
		break;
	default:
		ASSERT(FALSE);
		break;

	}
	
	return S_OK;
}

STDMETHODIMP CModbusSrv::get_StopBits(short * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_LOCAL_CONNECTION

	*pVal = m_pConnection->m_pLocalModbus->StopBits();

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_StopBits(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->StopBits(BYTE(newVal));

	return S_OK;
}


STDMETHODIMP CModbusSrv::get_TransmissionMode(short * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here
	VERIFY_LOCAL_CONNECTION

	*pVal = m_pConnection->m_pLocalModbus->TransmissionMode();

	return S_OK;

}

STDMETHODIMP CModbusSrv::put_TransmissionMode(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->TransmissionMode(WORD(newVal));


	return S_OK;
}

STDMETHODIMP CModbusSrv::get_ByteSize(short * pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_LOCAL_CONNECTION

	*pVal = m_pConnection->m_pLocalModbus->ByteSize();

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_ByteSize(short newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

    VERIFY_LOCAL_CONNECTION

	m_pConnection->m_pLocalModbus->ByteSize(newVal);

	return S_OK;
}


STDMETHODIMP CModbusSrv::TxRxRawData(VARIANT vQuery, short QueryLength, VARIANT * vResponse, short RespLength, long Timeout, VARIANT * vNumOfBytesRead, long * plRetVal)
{

	AFX_MANAGE_STATE(AfxGetStaticModuleState())

    WORD wError;
	COleSafeArrayEx vBytes;
	CByteArray abyQuery;
	CByteArray abyResponse;
	WORD wNumOfBytesRead;
	WORD wResp;
	COleVariantEx vNumReadBytes(vNumOfBytesRead);

	abyQuery.SetSize(QueryLength);
	
	VERIFY_LOCAL_CONNECTION

	HRESULT hr;

	hr=::VariantClear(vResponse);

	if (S_OK!=hr) {
		return hr;
	}
	

	if(RespLength>0){
		abyResponse.SetSize(RespLength);
		wResp=RespLength;
	}
	else {
		wResp=512;
		abyResponse.SetSize(512);
	}

	if (!vBytes.ToByteArray(abyQuery,&vQuery)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);
	}

	wError = m_pConnection->m_pLocalModbus->TxRxRawData(abyQuery.GetData(), //modbus query without CRC
				  WORD(QueryLength), //QueryLength without CRC
				  abyResponse.GetData(), //modbus Response without CRC
				  WORD(wResp), //wLengthResponse Response without CRC
				  wNumOfBytesRead,
				  DWORD(Timeout));



	abyResponse.SetSize(wNumOfBytesRead);

	if (!vBytes.ToVariantArray(abyResponse,vResponse)){
		return Error(ERR_BUILDING_ARRAY,IDS_ERR_CONVERT_ARRAY);		
	}


	if (!vNumReadBytes.IsMissing()) {
		VERIFY(S_OK==::VariantClear(vNumOfBytesRead));
		vNumOfBytesRead->vt=VT_I4;
		vNumOfBytesRead->lVal=wNumOfBytesRead;
	}
	
	*plRetVal = ExceptionErrorCode(wError);

	return Error(wError);
}

STDMETHODIMP CModbusSrv::get_Delay(long *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_CONNECTION

	*pVal=long(m_pConnection->m_pModbus->Delay());

	return S_OK;
}

STDMETHODIMP CModbusSrv::put_Delay(long newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VERIFY_CONNECTION

	m_pConnection->m_pModbus->Delay(DWORD(newVal));

	return S_OK;
}
