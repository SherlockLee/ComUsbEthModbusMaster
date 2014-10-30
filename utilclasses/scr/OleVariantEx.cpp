// OleVariantEx.cpp: implementation of the COleVariantEx class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"
#include "OleVariantEx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COleVariantEx::COleVariantEx():COleVariant()
{

}

COleVariantEx::~COleVariantEx()
{

}

CString COleVariantEx::ToString()
{

	
	if ((vt & 0x7F)==VT_BSTR){
		if ((vt & VT_BYREF)!=0){
			return CString(*(pbstrVal)); //byref
		}
		else {
		    return CString(bstrVal); //byval
		}
	}
	else {
		return CString("");
	}

}

BOOL COleVariantEx::IsMissing()
{
	return((vt==VT_ERROR)&&((scode & DISP_E_MEMBERNOTFOUND)!=0));
}

WORD COleVariantEx::ToWord()
{

	if (((vt & 0x7F)==VT_I2)){
		if ((vt & VT_BYREF)!=0){
			return WORD(*piVal); //byref
		}
		else {
		    return WORD(iVal); //byval
		}
	}
	else if (((vt & 0x7F)==VT_I4)){
		if ((vt & VT_BYREF)!=0){
			return WORD(*plVal); //byref
		}
		else {
		    return WORD(lVal); //byval
		}
	}
	else {
		ASSERT(0);
		return 0;
	}

}


BOOL COleVariantEx::IsString()
{
	return ((vt & 0x7F)==VT_BSTR);
}

BOOL COleVariantEx::IsSignedInt()
{
	return (((vt & 0x7F)==VT_I2)||((vt & 0x7F)==VT_I4));
}

int COleVariantEx::ToInt()
{
	
	if (((vt & 0x7F)==VT_I2)){
		if ((vt & VT_BYREF)!=0){
			return int(*piVal); //byref
		}
		else {
			return int(iVal); //byval
		}
	}
	else if (((vt & 0x7F)==VT_I4)){
		if ((vt & VT_BYREF)!=0){
			return int(*plVal); //byref
		}
		else {
			return int(lVal); //byval
		}
	}
	else {
		ASSERT(0);
		return 0;
	}
}

double COleVariantEx::ToDouble()
{
   ChangeType(VT_R8);
   return dblVal;
}

float COleVariantEx::ToFloat()
{
   ChangeType(VT_R4);
   return fltVal;
}

VARTYPE COleVariantEx::VarType()
{
	return (vt & 0x7F);
}
