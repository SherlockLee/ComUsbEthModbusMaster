// OleVariantEx.h: interface for the COleVariantEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEVARIANTEX_H__BE0C47A3_5B42_11D1_8FE9_CC451F13F87D__INCLUDED_)
#define AFX_OLEVARIANTEX_H__BE0C47A3_5B42_11D1_8FE9_CC451F13F87D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class COleVariantEx : public COleVariant  
{
public:
	VARTYPE VarType();
	float ToFloat();
	double ToDouble();
	int ToInt();
	BOOL IsSignedInt();
	BOOL IsString();
	WORD ToWord();
	BOOL IsMissing();
	CString ToString();
	COleVariantEx();
	COleVariantEx(const VARIANT& varSrc):COleVariant(varSrc){}
	COleVariantEx(const COleVariant& varSrc):COleVariant(varSrc){}
	COleVariantEx(CString& strSrc):COleVariant(strSrc){}

	virtual ~COleVariantEx();

};

#endif // !defined(AFX_OLEVARIANTEX_H__BE0C47A3_5B42_11D1_8FE9_CC451F13F87D__INCLUDED_)
