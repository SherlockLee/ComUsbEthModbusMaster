// ModbucfgView.cpp : implementation of the CModbucfgView class
//

#include "stdafx.h"
#include "Modbucfg.h"

#include "ModbucfgDoc.h"
#include "ModbucfgView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModbucfgView

IMPLEMENT_DYNCREATE(CModbucfgView, CFormView)

BEGIN_MESSAGE_MAP(CModbucfgView, CFormView)
	//{{AFX_MSG_MAP(CModbucfgView)
	ON_BN_CLICKED(IDC_CHK_Enable_Poll, OnchkEnablePoll)
	ON_EN_CHANGE(IDC_EDIT_INTERVAL, OnChangeEditInterval)
	ON_BN_CLICKED(IDC_CMD_WRITE, OnCmdWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModbucfgView construction/destruction

CModbucfgView::CModbucfgView()
	: CFormView(CModbucfgView::IDD)
{
	//{{AFX_DATA_INIT(CModbucfgView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CModbucfgView::~CModbucfgView()
{
}

void CModbucfgView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModbucfgView)
	DDX_Control(pDX, IDC_CBO_DATA_TYPE, m_cboDataType);
	DDX_Control(pDX, IDC_EDIT_INTERVAL, m_edtInterval);
	DDX_Control(pDX, IDC_CHK_Enable_Poll, m_butPollEnable);
	DDX_Control(pDX, IDC_STAT_STATUS, m_statStatus);
	DDX_Control(pDX, IDC_STAT_ERROR, m_staError);
	DDX_Control(pDX, IDC_LST_VALUES, m_lstValues);
	DDX_Control(pDX, IDC_CBO_WRITE_FUNCTION, m_cboWriteFunctions);
	DDX_Control(pDX, IDC_CBO_READ_FUNCTION, m_cboReadFunctions);
	DDX_Control(pDX, IDC_CBO_CONNECTION, m_cboConnections);
	DDX_Control(pDX, IDC_EDIT_VALUE, m_edtValue);
	DDX_Control(pDX, IDC_EDIT_QUANT, m_edtQuant);
	DDX_Control(pDX, IDC_EDIT_DEVICE, m_edtDevice);
	DDX_Control(pDX, IDC_EDIT_ADDR_WRI, m_edtWriteAddr);
	DDX_Control(pDX, IDC_EDIT_ADDR, m_edtReadAddr);
	DDX_Control(pDX, IDC_CMD_WRITE, m_cmdWrite);
	//}}AFX_DATA_MAP
}

BOOL CModbucfgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CModbucfgView diagnostics

#ifdef _DEBUG
void CModbucfgView::AssertValid() const
{
	CFormView::AssertValid();
}

void CModbucfgView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CModbucfgDoc* CModbucfgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModbucfgDoc)));
	return (CModbucfgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CModbucfgView message handlers

void CModbucfgView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	LoadControls();
	
}

void CModbucfgView::LoadControls()
{
	CString str;
	CString sKey;
	CConnection* pConnection;
	POSITION pos;

	//Read functions 
	m_cboReadFunctions.AddString(CString("LoopbackTest"));
	m_cboReadFunctions.AddString(CString("Read Output Registers"));
	m_cboReadFunctions.AddString(CString("Read Input Registers"));
	m_cboReadFunctions.AddString(CString("Read Ouput Status"));
	m_cboReadFunctions.AddString(CString("Read Input Status"));
	m_cboReadFunctions.SetCurSel(1);
	
	//Write Functions 
	m_cboWriteFunctions.AddString(CString("Preset Single Register"));
	m_cboWriteFunctions.AddString(CString("Force Single Coil"));
	m_cboWriteFunctions.SetCurSel(0);


	pos = gConnections.GetStartPosition();
	
	m_cboConnections.ResetContent();

	while (NULL!=pos) {
		gConnections.GetNextAssoc(pos,sKey,pConnection);
		m_cboConnections.AddString(sKey);
	}

	m_cboConnections.SetCurSel(0);


	//Default Values 
	str=_T("1");
    m_edtDevice.SetWindowText(str);
	
	str=_T("0");
	m_edtValue.SetWindowText(str);
	m_edtWriteAddr.SetWindowText(str);
	m_edtReadAddr.SetWindowText(str);

	str=_T("10");
	m_edtQuant.SetWindowText(str);

	str=_T("1000");
	m_edtInterval.SetWindowText(str);

	//Data Type 

	m_cboDataType.AddString(CString("char"));
	m_cboDataType.AddString(CString("signed - 16"));
	m_cboDataType.AddString(CString("unsigned - 16"));
	m_cboDataType.AddString(CString("float - 32"));
	m_cboDataType.AddString(CString("float - 32 reverse"));
	m_cboDataType.AddString(CString("double - 64"));
	m_cboDataType.AddString(CString("double - 64 reverse"));
	m_cboDataType.SetCurSel(1);

}

void CModbucfgView::StartWork()
{
	SCODE sc = ::CoInitializeEx(NULL,COINIT_MULTITHREADED);
	//SCODE sc = ::CoInitializeEx(NULL,COINIT_APARTMENTTHREADED); 

	if (FAILED(sc))
	{
		// warn about non-NULL success codes
		TRACE1("Warning: OleInitialize returned scode = %x",sc);
	}

	m_dwCount=0;
	m_dwSum=0;
	m_dwErrors=0;
}

void CModbucfgView::DoWork()
{
	ldiv_t div_result;
    float fUpdateSpeed;
	DWORD dwTime;
	CString str;
	WORD nError;
    
	int iNumLoops=10;
	
	
	fUpdateSpeed=0.0;
	
	if ((m_cboReadFunctions.GetCurSel()>=LOOP_BACK_TEST)&&
		(m_cboReadFunctions.GetCurSel()<=READ_INPUT_STATUS)){
		
		m_dwCount++;
		nError=ExecuteReadFunction(m_cboReadFunctions.GetCurSel(),dwTime,str);
		m_dwSum +=dwTime;  
		
		div_result = ldiv(m_dwCount,iNumLoops);
		
		if (CModbus::ERR_OK!=nError){
			m_dwErrors++;
		}
		
		if (0==div_result.rem){
			fUpdateSpeed=(float)(iNumLoops*1000)/(float)m_dwSum;
			m_dwSum=0; 
		}
		else {
			fUpdateSpeed=(float)(1*1000)/(float)dwTime;
		}

		m_staError.SetWindowText(str);
		str.Format("%d Errors=%d  %4.2f(Up./s) ",m_dwCount,m_dwErrors,fUpdateSpeed);  
		m_statStatus.SetWindowText(str);
	}
	
			
}

void CModbucfgView::EndWork()
{
	::CoUninitialize();
}

void CModbucfgView::OnchkEnablePoll() 
{
	CString sText;
	DWORD dwInterval=0;

	m_edtInterval.GetWindowText(sText);
	dwInterval=DWORD(atol(sText));
	
	if (dwInterval>10000) {
		AfxMessageBox("Max. Interval is 10000 ms");
		dwInterval=10000;
		sText.Format("%d",dwInterval);
		m_edtInterval.SetWindowText(sText);
		return;
	}

	if (0!=m_butPollEnable.GetCheck()) {

		if (!IsBusy()) {
			CreateThread(0,0,NULL,dwInterval);
		}
		m_butPollEnable.SetCheck(1);

	}
	else {
		Stop();

	}
	
}



WORD CModbucfgView::ExecuteReadFunction(int iFunction,DWORD& dwTime, CString& rErrorMessage)
{
	CModbus* pModbus;
	CShortArray aValues;
	CByteArray abCoilValues;
	
	CFloatArray afValues;
	CDblArray adValues;

    CString str;
	CString sAux;
    WORD nError;
	int i;
	BOOL bRegisters;
	DWORD dwStart;
	CString sKey;
	CConnection* pConnection =NULL;
	BYTE byDevice;
	WORD wQuant;
	WORD wAddr;
	int nIndex;
	int nPreviusCount;
	int iDataType;
    
	i=m_cboConnections.GetCurSel();

	iDataType= m_cboDataType.GetCurSel();

	if (i<0) {
		return 0;
	}
	else {
		m_cboConnections.GetLBText(i,sKey);
		
		if (gConnections.Lookup(sKey,pConnection)) {
		
			pModbus=pConnection->m_pModbus;
		}
		else {
			ASSERT(FALSE);
			return 0;
		}
	}

	m_edtDevice.GetWindowText(str);
	
	byDevice=BYTE(atoi(str));

	m_edtQuant.GetWindowText(str);
	wQuant=BYTE(atoi(str));

	m_edtReadAddr.GetWindowText(str);
	wAddr=WORD(atoi(str));

	switch (iFunction) {

	case LOOP_BACK_TEST:
		dwStart=::timeGetTime();
		nError=pModbus->LoopbackTest(byDevice);
		dwTime=::timeGetTime()-dwStart;
		str="";
		bRegisters=FALSE;
		break;
	
	case READ_OUTPUT_REGISTERS:
		
		dwStart=::timeGetTime();
		switch (iDataType) {
			
		case DATA_CHAR:
		case DATA_SIGNED_16:
		case DATA_UNSIGNED_16:
			aValues.SetSize(wQuant);
			nError=pModbus->ReadOutputRegisters(byDevice,wAddr,wQuant, aValues);
			break;
		case DATA_FLOAT:
			afValues.SetSize(wQuant);
			nError=pModbus->ReadOutputRegisters(byDevice,wAddr,wQuant, afValues);
			break;
		case DATA_FLOAT_REVERSE:
			afValues.SetSize(wQuant);
			nError=pModbus->ReadOutputRegisters(byDevice,wAddr,wQuant, afValues,CModbus::REAL_REVERSE);
			break;
		case DATA_DOUBLE:
			adValues.SetSize(wQuant);
			nError=pModbus->ReadOutputRegisters(byDevice,wAddr,wQuant, adValues);
			break;
		case DATA_DOUBLE_REVERSE:
			adValues.SetSize(wQuant);
			nError=pModbus->ReadOutputRegisters(byDevice,wAddr,wQuant, adValues,CModbus::REAL_REVERSE);
			break;
		}
		
		dwTime=::timeGetTime()-dwStart;
		bRegisters=TRUE;	
		break;
		case READ_INPUT_REGISTERS:
	
			dwStart=::timeGetTime();
			switch (iDataType) {
				
			case DATA_CHAR:
			case DATA_SIGNED_16:
			case DATA_UNSIGNED_16:
				aValues.SetSize(wQuant);
				nError=pModbus->ReadInputRegisters(byDevice,wAddr,wQuant, aValues);
				break;
			case DATA_FLOAT:
				afValues.SetSize(wQuant);
				nError=pModbus->ReadInputRegisters(byDevice,wAddr,wQuant, afValues);
				break;
			case DATA_FLOAT_REVERSE:
				afValues.SetSize(wQuant);
				nError=pModbus->ReadInputRegisters(byDevice,wAddr,wQuant, afValues,CModbus::REAL_REVERSE);
				break;
			case DATA_DOUBLE:
				adValues.SetSize(wQuant);
				nError=pModbus->ReadInputRegisters(byDevice,wAddr,wQuant, adValues);
				break;
			case DATA_DOUBLE_REVERSE:
				adValues.SetSize(wQuant);
				nError=pModbus->ReadInputRegisters(byDevice,wAddr,wQuant, adValues,CModbus::REAL_REVERSE);
				break;
			}
			dwTime=::timeGetTime()-dwStart;
			bRegisters=TRUE;
			break;
			
			case READ_OUTPUT_STATUS:
				dwStart=::timeGetTime();
				abCoilValues.SetSize(wQuant);
				nError=pModbus->ReadOutputStatus(byDevice,wAddr,wQuant, abCoilValues);
				dwTime=::timeGetTime()-dwStart;
				bRegisters=FALSE;
				break;
				
			case READ_INPUT_STATUS:
				dwStart=::timeGetTime();
				abCoilValues.SetSize(wQuant);
				nError=pModbus->ReadInputStatus(byDevice,wAddr,wQuant, abCoilValues); 
				dwTime=::timeGetTime()-dwStart;
				bRegisters=FALSE;
				break;
				
	}


	nIndex=m_lstValues.GetCurSel();
	nPreviusCount=m_lstValues.GetCount();

	m_lstValues.SetRedraw(FALSE);
	
	if (bRegisters) {

		for(i=0;i<wQuant;++i) {
			
			switch (iDataType) {
			case DATA_CHAR:
				sAux.Format("[%u]=%c 0x%x",wAddr+i,(char)aValues[i],(WORD)aValues[i]);
			    break;
            case DATA_SIGNED_16:
				sAux.Format("[%u]=%d 0x%x",wAddr+i,aValues[i],(WORD)aValues[i]);
				break;
			case DATA_UNSIGNED_16:
				sAux.Format("[%u]=%d 0x%x",wAddr+i,(WORD)aValues[i],(WORD)aValues[i]);
				break;
            case DATA_FLOAT:
			case DATA_FLOAT_REVERSE:
				sAux.Format("[%u]=%g ",wAddr+2*i,afValues[i]);
				break;
			case DATA_DOUBLE:
			case DATA_DOUBLE_REVERSE:
				sAux.Format("[%u]=%g ",wAddr+4*i,adValues[i]);
				break;
			}

			
			//sAux.Format("[%u]=%d  %d  0x%x  ",wAddr+i,aValues[i],(WORD)aValues[i],(WORD)aValues[i]);
			
			m_lstValues.DeleteString(i);
			m_lstValues.InsertString(i,sAux);
		}
	
	}
	else {
		
		for(i=0;i<abCoilValues.GetSize();++i) {
			sAux.Format("[%u]=%d ",wAddr+i,abCoilValues[i]);
			m_lstValues.DeleteString(i);
			m_lstValues.InsertString(i,sAux);
		}
	}

	if (nPreviusCount>wQuant) {

		for (i=wQuant;i<nPreviusCount;i++){
			m_lstValues.DeleteString(wQuant);
		}
	}
	
	if ((nIndex>0)&&(nIndex<m_lstValues.GetCount())) {
		m_lstValues.SetCurSel(nIndex);
	}

	m_lstValues.SetRedraw(TRUE);
	m_lstValues.Invalidate(FALSE);

		
	rErrorMessage=pModbus->ErrorMessage(nError);
	return nError;
}
void CModbucfgView::OnChangeEditInterval() 
{

	CString sText;
	DWORD dwInterval=0;

	m_edtInterval.GetWindowText(sText);
	dwInterval=DWORD(atol(sText));
	
	if (dwInterval>10000) {
		AfxMessageBox("Max. Interval is 10000 ms");
		dwInterval=10000;
		sText.Format("%d",dwInterval);
		m_edtInterval.SetWindowText(sText);
		return;
	}

	SetCycleTime(int(dwInterval));

	
}

void CModbucfgView::OnCmdWrite() 
{
	BYTE byDevice=0;
	WORD wValue=0;
	WORD wAddr=0;
	CModbus* pModbus=GetConnection();
	WORD nError=CModbus::ERR_OK;
	CString strValue;
	CString sVal;
	CWaitCursor WaitCursor;
	double dValue=0.0;

	if (NULL==pModbus) {
		return;
	}

	m_edtValue.GetWindowText(strValue);
	sVal= strValue;
	wValue = (WORD)atoi(strValue);

	m_edtDevice.GetWindowText(strValue);
	byDevice = (BYTE)atoi(strValue);

	m_edtWriteAddr.GetWindowText(strValue);
	wAddr = (WORD)atoi(strValue);

	switch (m_cboWriteFunctions.GetCurSel()) {
		
	case PRESET_SINGLE_REGISTER:

		switch(m_cboDataType.GetCurSel()) {
			
		case DATA_CHAR:
			sVal.TrimLeft();
			if (sVal.GetLength()>0) { 
				nError=pModbus->PresetSingleRegister(byDevice,wAddr,WORD(sVal[0]));
			}
			break;
		case DATA_SIGNED_16:
			
		case DATA_UNSIGNED_16:
			if (sVal.GetLength()>0) { 
				nError=pModbus->PresetSingleRegister(byDevice,wAddr,WORD(atoi(sVal)));
			}
			break;
		case DATA_FLOAT:
			nError=pModbus->PresetSingleRegister(byDevice,wAddr,float(atof(sVal)));
			break;
		case DATA_FLOAT_REVERSE:
			nError=pModbus->PresetSingleRegister(byDevice,wAddr,float(atof(sVal)),CModbus::REAL_REVERSE);
			break;
		case DATA_DOUBLE:
			nError=pModbus->PresetSingleRegister(byDevice,wAddr,double(atof(sVal)));
		
			break;
		case DATA_DOUBLE_REVERSE:
			nError=pModbus->PresetSingleRegister(byDevice,wAddr,double(atof(sVal)),CModbus::REAL_REVERSE);
			break;
		}
		
		
		
		if(nError!=CModbus::ERR_OK){
			WaitCursor.Restore();
			AfxMessageBox(pModbus->ErrorMessage(nError));
		}
		break;
	case FORCE_SINGLE_COIL:
		nError=pModbus->ForceSingleCoil(byDevice,wAddr,(BOOL)wValue);
		if(nError!=CModbus::ERR_OK){
			WaitCursor.Restore();  
			AfxMessageBox(pModbus->ErrorMessage(nError));
		}
		break;
		
	}
	
}

CModbus* CModbucfgView::GetConnection()
{

	int i;
	CModbus* pModbus=NULL;
	CConnection* pConnection=NULL;
	CString sKey;

	i=m_cboConnections.GetCurSel();
	
	if (i<0) {
		ASSERT(FALSE);
		pModbus=NULL;
	}
	else {
		m_cboConnections.GetLBText(i,sKey);
		
		if (gConnections.Lookup(sKey,pConnection)) {
		
			pModbus=pConnection->m_pModbus;
		}
		else {
			ASSERT(FALSE);
			pModbus=NULL;
		}
	}
	
	return pModbus;
}
