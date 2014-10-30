// OleSafeArrayEx.cpp: implementation of the COleSafeArrayEx class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"
#include "OleSafeArrayEx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/*
enum VARENUM
    {	VT_EMPTY	= 0,
	VT_NULL	= 1,
	VT_I2	= 2,
	VT_I4	= 3,
	VT_R4	= 4,
	VT_R8	= 5,
	VT_CY	= 6,
	VT_DATE	= 7,
	VT_BSTR	= 8,
	VT_DISPATCH	= 9,
	VT_ERROR	= 10,
	VT_BOOL	= 11,
	VT_VARIANT	= 12,
	VT_UNKNOWN	= 13,
	VT_DECIMAL	= 14,
	VT_I1	= 16,
	VT_UI1	= 17,
	VT_UI2	= 18,
	VT_UI4	= 19,
	VT_I8	= 20,
	VT_UI8	= 21,
	VT_INT	= 22,
	VT_UINT	= 23,
	VT_VOID	= 24,
	VT_HRESULT	= 25,
	VT_PTR	= 26,
	VT_SAFEARRAY	= 27,
	VT_CARRAY	= 28,
	VT_USERDEFINED	= 29,
	VT_LPSTR	= 30,
	VT_LPWSTR	= 31,
	VT_RECORD	= 36,
	VT_FILETIME	= 64,
	VT_BLOB	= 65,
	VT_STREAM	= 66,
	VT_STORAGE	= 67,
	VT_STREAMED_OBJECT	= 68,
	VT_STORED_OBJECT	= 69,
	VT_BLOB_OBJECT	= 70,
	VT_CF	= 71,
	VT_CLSID	= 72,
	VT_BSTR_BLOB	= 0xfff,
	VT_VECTOR	= 0x1000,
	VT_ARRAY	= 0x2000,
	VT_BYREF	= 0x4000,
	VT_RESERVED	= 0x8000,
	VT_ILLEGAL	= 0xffff,
	VT_ILLEGALMASKED	= 0xfff,
	VT_TYPEMASK	= 0xfff
    };

*/


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COleSafeArrayEx::COleSafeArrayEx():COleSafeArray()
{

}

COleSafeArrayEx::~COleSafeArrayEx()
{

}

BOOL COleSafeArrayEx::ToWordArray(CWordArray& wordArray, const VARIANT* pvArray)
{
	
	WORD* pwData;
	LONG* plData;
	long lCount;
	long lLbound=0;
	long lUbound=0;
	
	
	const VARIANT* pvSrc= (pvArray==NULL) ? this : pvArray;    
	

	SAFEARRAY* psArray=NULL;

	//if array inside another variant 
	if ((VT_BYREF|VT_VARIANT)==pvSrc->vt) {
		pvSrc=pvSrc->pvarVal;
	}

	psArray=GetSfaPointerFromVariant(pvSrc);

	if (NULL==psArray) {

		return FALSE;
	}

	//Not array 
	if ((pvSrc->vt&VT_ARRAY)==0) {
		return FALSE;
	}
	
	//integer only 
	if (((pvSrc->vt&0x0FFF)!=VT_I2)&&((pvSrc->vt&0x0FFF)!=VT_I4)) {
		return FALSE;
	}
	
	//vectors only 
	if (::SafeArrayGetDim(psArray)!=1) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetLBound(psArray,1, &lLbound)) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetUBound(psArray, 1, &lUbound)) {
		return FALSE;
	}
	
	if ((pvSrc->vt&0x0FFF)==VT_I2) {
		
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pwData)) {
			return FALSE;
		}
	}
	else {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&plData)) {
			return FALSE;
		}
	}

	
	wordArray.SetSize(lUbound-lLbound+1);
	
	//integer 
	if ((pvSrc->vt&0x0FFF)==VT_I2) {
		::memcpy(wordArray.GetData(),pwData,(UINT)((lUbound-lLbound+1)*sizeof(WORD)));
	}
	else {
		for (lCount=0;lCount<=(lUbound-lLbound);lCount++) {
			wordArray[lCount]=(WORD)plData[lCount];
		}
	}
	
	::SafeArrayUnaccessData(psArray);
	return TRUE;
}


BOOL COleSafeArrayEx::ToBoolByteArray(CByteArray& byteArray, const VARIANT* pvArray) {

	VARIANT_BOOL* pbData;
	short* piData;
	LONG* plData;
	long lCount;
	long lLbound=0;
	long lUbound=0;
	
	
	const VARIANT* pvSrc= (pvArray==NULL) ? this : pvArray;    

	SAFEARRAY* psArray=NULL;

	//if array inside another variant 
	if ((VT_BYREF|VT_VARIANT)==pvSrc->vt) {
		pvSrc=pvSrc->pvarVal;
	}

	psArray=GetSfaPointerFromVariant(pvSrc);

	if (NULL==psArray) {

		return FALSE;
	}

	//Not array 
	if ((pvSrc->vt&VT_ARRAY)==0) {
		return FALSE;
	}
	
	//integer only 
	if (((pvSrc->vt&0x0FFF)!=VT_I2)&&((pvSrc->vt&0x0FFF)!=VT_I4)&&((pvSrc->vt&0x0FFF)!=VT_BOOL)) {
		return FALSE;
	}
	//vectors only 
	if (::SafeArrayGetDim(psArray)!=1) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetLBound(psArray,1, &lLbound)) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetUBound(psArray, 1, &lUbound)) {
		return FALSE;
	}
	
	if ((pvSrc->vt&0x0FFF)==VT_I2) {
		
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&piData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_I4) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&plData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_BOOL) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pbData)) {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
	
	byteArray.SetSize(lUbound-lLbound+1);
	
	//integer 
	
	for (lCount=0;lCount<=(lUbound-lLbound);lCount++) {
		if ((pvSrc->vt&0x0FFF)==VT_I2) {
			byteArray[lCount]=(VARIANT_FALSE!=piData[lCount]);
		}
		else if ((pvSrc->vt&0x0FFF)==VT_I4) {
			byteArray[lCount]=(VARIANT_FALSE!=plData[lCount]);
		}
		else if ((pvSrc->vt&0x0FFF)==VT_BOOL) {
			byteArray[lCount]=(VARIANT_FALSE!=pbData[lCount]);
			
		}
	}

	::SafeArrayUnaccessData(psArray);

	return TRUE;

}

BOOL COleSafeArrayEx::ToByteArray(CByteArray& byteArray, const VARIANT* pvArray) {
	
	BYTE* pbyData;
	short* piData;
	LONG* plData;
	long lCount;
	long lLbound=0;
	long lUbound=0;
	
	
	const VARIANT* pvSrc= (pvArray==NULL) ? this : pvArray;  
	
	SAFEARRAY* psArray=NULL;

	//if array inside another variant 
	if ((VT_BYREF|VT_VARIANT)==pvSrc->vt) {
		pvSrc=pvSrc->pvarVal;
	}

	psArray=GetSfaPointerFromVariant(pvSrc);

	if (NULL==psArray) {

		return FALSE;
	}
	
	//integer only 
	if (((pvSrc->vt&0x0FFF)!=VT_I2)&&((pvSrc->vt&0x0FFF)!=VT_I4)&&((pvSrc->vt&0x0FFF)!=VT_UI1)) {
		return FALSE;
	}
	//vectors only 
	if (::SafeArrayGetDim(psArray)!=1) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetLBound(psArray,1, &lLbound)) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetUBound(psArray, 1, &lUbound)) {
		return FALSE;
	}
	
	if ((pvSrc->vt&0x0FFF)==VT_I2) {
		
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&piData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_I4) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&plData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_UI1) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pbyData)) {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
	
	byteArray.SetSize(lUbound-lLbound+1);
	
	//integer 
	
	for (lCount=0;lCount<=(lUbound-lLbound);lCount++) {
		if ((pvSrc->vt&0x0FFF)==VT_I2) {
			byteArray[lCount]=BYTE(piData[lCount]);
		}
		else if ((pvSrc->vt&0x0FFF)==VT_I4) {
			byteArray[lCount]=BYTE(plData[lCount]);
		}
		else if ((pvSrc->vt&0x0FFF)==VT_UI1) {
			byteArray[lCount]=BYTE(pbyData[lCount]);
			
		}
		
		//TRACE("BYTE[%d]=%d \n",lCount , byteArray[lCount]);
	}

	::SafeArrayUnaccessData(psArray);

	return TRUE;
}

BOOL COleSafeArrayEx::ToDoubleArray(CDoubleArray& doubleArray, const VARIANT* pvArray) {

	double* pdData;
	float* pfData;
	long lCount;
	long lLbound=0;
	long lUbound=0;
	
	
	const VARIANT* pvSrc= (pvArray==NULL) ? this : pvArray;    
	
    
	SAFEARRAY* psArray=NULL;

	//if array inside another variant 
	if ((VT_BYREF|VT_VARIANT)==pvSrc->vt) {
		pvSrc=pvSrc->pvarVal;
	}

	psArray=GetSfaPointerFromVariant(pvSrc);

	if (NULL==psArray) {

		return FALSE;
	}


	//Not array 
	if ((pvSrc->vt&VT_ARRAY)==0) {
		return FALSE;
	}
	
	//verify Type 
	if (((pvSrc->vt&0x0FFF)!=VT_R4)&&((pvSrc->vt&0x0FFF)!=VT_R8)) {
		return FALSE;
	}
	//vectors only 
	if (::SafeArrayGetDim(psArray)!=1) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetLBound(psArray,1, &lLbound)) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetUBound(psArray, 1, &lUbound)) {
		return FALSE;
	}
	
	if ((pvSrc->vt&0x0FFF)==VT_R4) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pfData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_R8) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pdData)) {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
	
	doubleArray.SetSize(lUbound-lLbound+1);
	
	for (lCount=0;lCount<=(lUbound-lLbound);lCount++) {
		if ((pvSrc->vt&0x0FFF)==VT_R4) {
			doubleArray[lCount]=pfData[lCount];
		}
		else if ((pvSrc->vt&0x0FFF)==VT_R8) {
			doubleArray[lCount]=pdData[lCount];
			
		}
	}

	::SafeArrayUnaccessData(psArray);

	return TRUE;


}

BOOL COleSafeArrayEx::ToDblArray(CDblArray& doubleArray, const VARIANT* pvArray) {

	double* pdData;
	float* pfData;
	long lCount;
	long lLbound=0;
	long lUbound=0;
	
	
	const VARIANT* pvSrc= (pvArray==NULL) ? this : pvArray;    
	

	SAFEARRAY* psArray=NULL;

	//if array inside another variant 
	if ((VT_BYREF|VT_VARIANT)==pvSrc->vt) {
		pvSrc=pvSrc->pvarVal;
	}

	psArray=GetSfaPointerFromVariant(pvSrc);

	if (NULL==psArray) {

		return FALSE;
	}

	//Not array 
	if ((pvSrc->vt&VT_ARRAY)==0) {
		return FALSE;
	}
	
	//verify Type 
	if (((pvSrc->vt&0x0FFF)!=VT_R4)&&((pvSrc->vt&0x0FFF)!=VT_R8)) {
		return FALSE;
	}
	//vectors only 
	if (::SafeArrayGetDim(psArray)!=1) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetLBound(psArray,1, &lLbound)) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetUBound(psArray, 1, &lUbound)) {
		return FALSE;
	}
	
	if ((pvSrc->vt&0x0FFF)==VT_R4) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pfData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_R8) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pdData)) {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
	
	doubleArray.SetSize(lUbound-lLbound+1);
	
	for (lCount=0;lCount<=(lUbound-lLbound);lCount++) {
		if ((pvSrc->vt&0x0FFF)==VT_R4) {
			doubleArray[lCount]=pfData[lCount];
		}
		else if ((pvSrc->vt&0x0FFF)==VT_R8) {
			doubleArray[lCount]=pdData[lCount];
			
		}
	}

	::SafeArrayUnaccessData(psArray);

	return TRUE;


}


BOOL COleSafeArrayEx::ToFloatArray(CFloatArray& floatArray, const VARIANT* pvArray) {

	double* pdData;
	float* pfData;
	long lCount;
	long lLbound=0;
	long lUbound=0;
	
	
	const VARIANT* pvSrc= (pvArray==NULL) ? this : pvArray;    
	

	
	SAFEARRAY* psArray=NULL;

	//if array inside another variant 
	if ((VT_BYREF|VT_VARIANT)==pvSrc->vt) {
		pvSrc=pvSrc->pvarVal;
	}

	psArray=GetSfaPointerFromVariant(pvSrc);

	if (NULL==psArray) {

		return FALSE;
	}

	//Not array 
	if ((pvSrc->vt&VT_ARRAY)==0) {
		return FALSE;
	}
	
	//verify Type 
	if (((pvSrc->vt&0x0FFF)!=VT_R4)&&((pvSrc->vt&0x0FFF)!=VT_R8)) {
		return FALSE;
	}
	//vectors only 
	if (::SafeArrayGetDim(psArray)!=1) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetLBound(psArray,1, &lLbound)) {
		return FALSE;
	}
	
	if FAILED(::SafeArrayGetUBound(psArray, 1, &lUbound)) {
		return FALSE;
	}
	
	if ((pvSrc->vt&0x0FFF)==VT_R4) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pfData)) {
			return FALSE;
		}
	}
	else if ((pvSrc->vt&0x0FFF)==VT_R8) {
		if FAILED(::SafeArrayAccessData(psArray,(void HUGEP* FAR*)&pdData)) {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
	
	floatArray.SetSize(lUbound-lLbound+1);
	
	for (lCount=0;lCount<=(lUbound-lLbound);lCount++) {
		if ((pvSrc->vt&0x0FFF)==VT_R4) {
			floatArray[lCount]=pfData[lCount];
		}
		else if ((pvSrc->vt&0x0FFF)==VT_R8) {
			floatArray[lCount]=float(pdData[lCount]);
			
		}
	}

	::SafeArrayUnaccessData(psArray);

	return TRUE;


}


BOOL COleSafeArrayEx::ToVariantArray(const CWordArray& wArrayScr,VARIANT* pvarDest,VARTYPE vtDest){

	WORD* pwData;
	LONG* plData;
	long lCount;
	
	VARIANT* pvDest= (pvarDest==NULL) ? this : pvarDest;   

	if FAILED(::VariantClear(pvDest)) {
		return FALSE;
	}

	pvDest->vt=(VT_ARRAY|vtDest);
	pvDest->parray=::SafeArrayCreateVector(vtDest,0,wArrayScr.GetSize());
	
	if (NULL==pvDest->parray) {
		return FALSE;
	}
	
	if ((pvDest->vt&0x0FFF)==VT_I2) {
		
		if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&pwData)) {
			return FALSE;
		}
	}
	else {
		if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&plData)) {
			return FALSE;
		}
	}

	//integer 
	if ((pvDest->vt&0x0FFF)==VT_I2) {
		::memcpy(pwData,wArrayScr.GetData(),(UINT)((wArrayScr.GetSize())*sizeof(WORD)));
	}
	else {
		for (lCount=0;lCount<wArrayScr.GetSize();lCount++) {

			 plData[lCount]=wArrayScr[lCount];
		}
	}

    ::SafeArrayUnaccessData(pvDest->parray);
	return TRUE;

}


BOOL COleSafeArrayEx::ToVariantArray(const CByteArray& byteArrayScr,VARIANT* pvarDest,VARTYPE vtDest){
	
	WORD* pwData;
	LONG* plData;
	BYTE* pbyData;

	long lCount;
	
	VARIANT* pvDest= (pvarDest==NULL) ? this : pvarDest;   

	if FAILED(::VariantClear(pvDest)) {
		return FALSE;
	}

	pvDest->vt=(VT_ARRAY|vtDest);
	pvDest->parray=::SafeArrayCreateVector(vtDest,0,byteArrayScr.GetSize());
	
	if (NULL==pvDest->parray) {
		return FALSE;
	}
	
	if ((pvDest->vt&0x0FFF)==VT_I2) {
		
		if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&pwData)) {
			return FALSE;
		}
	}
	else if ((pvDest->vt&0x0FFF)==VT_I4){
		if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&plData)) {
			return FALSE;
		}
	}
	else if ((pvDest->vt&0x0FFF)==VT_UI1){
		if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&pbyData)) {
			return FALSE;
		}
	}

	for (lCount=0;lCount<byteArrayScr.GetSize();lCount++) {
		
		if ((pvDest->vt&0x0FFF)==VT_I2) {
			pwData[lCount] = byteArrayScr[lCount];
		}
		else if ((pvDest->vt&0x0FFF)==VT_I4) {

			plData[lCount] = byteArrayScr[lCount];

		}
		else if ((pvDest->vt&0x0FFF)==VT_UI1) {

			pbyData[lCount] = byteArrayScr[lCount];
			
		}
	}
	
	
    ::SafeArrayUnaccessData(pvDest->parray);
	
	return TRUE;

}



BOOL COleSafeArrayEx::ToVariantArray(const double* pdArrayScr,int iSize, VARIANT* pvarDest){
	
	double* pdData;
	long lCount;
	
	VARIANT* pvDest= (pvarDest==NULL) ? this : pvarDest;   

	if FAILED(::VariantClear(pvDest)) {
		return FALSE;
	}

	pvDest->vt=(VT_ARRAY|VT_R8);
	pvDest->parray=::SafeArrayCreateVector(VT_R8,0,iSize);
	
	if (NULL==pvDest->parray) {
		return FALSE;
	}
	
	
	if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&pdData)) {
		return FALSE;
	}
	

	for (lCount=0;lCount<iSize;lCount++) {
			pdData[lCount] = pdArrayScr[lCount];
	}
	
    ::SafeArrayUnaccessData(pvDest->parray);
	
	return TRUE;

}

BOOL COleSafeArrayEx::ToVariantArray(const float* pfArrayScr,int iSize, VARIANT* pvarDest){
	
	float* pfData;
	long lCount;
	
	VARIANT* pvDest= (pvarDest==NULL) ? this : pvarDest;   

	if FAILED(::VariantClear(pvDest)) {
		return FALSE;
	}

	pvDest->vt=(VT_ARRAY|VT_R4);
	pvDest->parray=::SafeArrayCreateVector(VT_R4,0,iSize);
	
	if (NULL==pvDest->parray) {
		return FALSE;
	}
	
	
	if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&pfData)) {
		return FALSE;
	}
	

	for (lCount=0;lCount<iSize;lCount++) {
			pfData[lCount] = pfArrayScr[lCount];
	}
	
    ::SafeArrayUnaccessData(pvDest->parray);
	
	return TRUE;

}



BOOL COleSafeArrayEx::ToVariantBoolArray(const CByteArray& byArrayScr,VARIANT* pvarDest) {

	VARIANT_BOOL* pvbData;
	long lCount;
	
	VARIANT* pvDest= (pvarDest==NULL) ? this : pvarDest;   

	if FAILED(::VariantClear(pvDest)) {
		return FALSE;
	}

	pvDest->vt=(VT_ARRAY|VT_BOOL);
	pvDest->parray=::SafeArrayCreateVector(VT_BOOL,0,byArrayScr.GetSize());
	
	if (NULL==pvDest->parray) {
		return FALSE;
	}
	
	
	if FAILED(::SafeArrayAccessData(pvDest->parray,(void HUGEP* FAR*)&pvbData)) {
		return FALSE;
	}


	for (lCount=0;lCount<byArrayScr.GetSize();lCount++) {
		if (FALSE==byArrayScr[lCount]) {
			 pvbData[lCount]=VARIANT_FALSE;
		}
		else {
			pvbData[lCount]=VARIANT_TRUE;
		}
	}
	

    ::SafeArrayUnaccessData(pvDest->parray);
	return TRUE;

}

SAFEARRAY* COleSafeArrayEx::GetSfaPointerFromVariant(const VARIANT* vVar)
{


	const VARIANT* pVariant;

	//if array inside another variant 
	// DELPHI can use this kind of array 
	if ((VT_BYREF|VT_VARIANT)==vVar->vt) {
		pVariant=vVar->pvarVal;
	}
	else {
		pVariant=vVar;

	}
		
	//Not an array 
	if ((pVariant->vt&VT_ARRAY)==0) {
		return NULL;
	}


	if ((pVariant->vt&VT_BYREF)==0) {
		return pVariant->parray;
	}
	else {
		return (*(pVariant->pparray));
	}

}
