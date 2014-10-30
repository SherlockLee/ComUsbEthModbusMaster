// OleSafeArrayEx.h: interface for the COleSafeArrayEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLESAFEARRAYEX_H__614A2AA4_5C73_11D1_8FE9_E72B9497FB7B__INCLUDED_)
#define AFX_OLESAFEARRAYEX_H__614A2AA4_5C73_11D1_8FE9_E72B9497FB7B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//CArray definition 
#include <afxtempl.h>

typedef CArray<double,double> CDoubleArray;

typedef CArray<double,double> CDblArray;

typedef CArray<float,float> CFloatArray;

//This class extend COleSafe Array Class
class COleSafeArrayEx : public COleSafeArray  
{
public:
	
	//Get SafeArray Pointer from a variant Variable 
	// return NULL if fail.
	SAFEARRAY* GetSfaPointerFromVariant(const VARIANT* vVar);
	
	/*insert word array into a variant integer array   
		in:	wordArray destination of data 
			pvArray Variant pointer , source of data or this object if 
			not supplied
		out:TRUE if success or FALSE if error
			
	*/	
	BOOL ToWordArray(CWordArray& wordArray, const VARIANT* pvArray=NULL);
	
	/*insert word array into variant integer array   
		in:	wordArray source of data 
			pvArray Variant pointer , destination of data. insert into 
					this objet if dest not suplied.
			vtDest - destination vartype VT_I4 or VT_I2
		out:TRUE if success or FALSE if error
			
	*/	
	BOOL ToVariantArray(const CWordArray& wArrayScr,VARIANT* pvarDest=NULL,VARTYPE vtDest=VT_I4);

	BOOL ToVariantArray(const CByteArray& byteArrayScr,VARIANT* pvarDest=NULL,VARTYPE vtDest=VT_UI1);
    
	BOOL ToVariantArray(const double* pdArrayScr,int iSize, VARIANT* pvarDest);

	BOOL ToVariantArray(const float* pfArrayScr,int iSize, VARIANT* pvarDest);

	BOOL ToVariantBoolArray(const CByteArray& byArrayScr,VARIANT* pvarDest=NULL);
	
	BOOL ToBoolByteArray(CByteArray& wordArray, const VARIANT* pvArray=NULL);

	BOOL ToByteArray(CByteArray& byteArray, const VARIANT* pvArray=NULL);

	BOOL ToDoubleArray(CDoubleArray& byteArray, const VARIANT* pvArray=NULL);

	BOOL ToDblArray(CDblArray& doubleArray, const VARIANT* pvArray=NULL);

	BOOL ToFloatArray(CFloatArray& doubleArray, const VARIANT* pvArray);
	
	//construction
	COleSafeArrayEx();
	COleSafeArrayEx( const VARIANT& varSrc ):COleSafeArray(varSrc){}
	virtual ~COleSafeArrayEx();

};

#endif // !defined(AFX_OLESAFEARRAYEX_H__614A2AA4_5C73_11D1_8FE9_E72B9497FB7B__INCLUDED_)
