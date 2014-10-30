// StlUtils.h: interface for the CStlUtils class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STLUTILS_H__521BD2D7_1A97_11D3_92D0_000021C715ED__INCLUDED_)
#define AFX_STLUTILS_H__521BD2D7_1A97_11D3_92D0_000021C715ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include <iostream>       // for i/o functions

class CStlUtils  
{
public:
	CStlUtils();
	virtual ~CStlUtils();

};


template<class Derived>
class CRefCountImpl
{
public:

  CRefCountImpl() {
		m_lRefCount=0;
	
  }
 
  virtual ~CRefCountImpl() {

  }
  
  long  AddRef() { // non-virtual!
	  //std::cout << "AddRef " << m_lRefCount << std::endl;
	  return ::InterlockedIncrement(&m_lRefCount);

  }
  
  long  Release()
  {

	ULONG currentCount = ::InterlockedDecrement(&m_lRefCount);

	//std::cout << "Release " << m_lRefCount << std::endl;

	if (0 == currentCount)
	{
		delete (Derived*)this; //static_cast<Derived*>this<Derived>;
	}
	
	return currentCount;
    
  }


protected:

	long m_lRefCount;
};

template <class T>
class _STLUtil_NoAddRefReleaseOnCComPtr : public T
{
	private:
		virtual long  AddRef()=0;
		virtual long  Release()=0;
};


template<typename T>
class CRefCountPtr
{
public:
  
  CRefCountPtr() throw(): p(NULL) {}
  
  CRefCountPtr(T* ptr, bool fAddRef) throw() { 
    if ( (p = ptr) && fAddRef ) p->AddRef(); 
  }
  
  CRefCountPtr(T* ptr) throw() { 
    if ( (p = ptr) ) p->AddRef(); 
  }
  
  CRefCountPtr(const CRefCountPtr& ptr) throw() { 
    if ( (p = ptr.p) ) p->AddRef(); 
  }

  ~CRefCountPtr() throw() { 
	  if ( p ) p->Release(); 
  }

  operator T*() const throw() { return p; }
  
  //T& operator*() const throw() { _ASSERTE(p!=NULL); return *p; }
  
  //T** operator&() throw() { _ASSERTE(p==NULL); return &p; }
  

  _STLUtil_NoAddRefReleaseOnCComPtr<T>* operator->() const
  {
		_ASSERTE(p!=NULL);
		return (_STLUtil_NoAddRefReleaseOnCComPtr<T>*)p;
  }

  bool operator!() const throw() { return p == NULL; }

  T* operator=(T* ptr) throw() {
    if ( p ) p->Release();
    if ( (p = ptr) ) p->AddRef();
    return p;
  }

  T* operator =( const CRefCountPtr< T >& ptr ){
	if ( p ) p->Release();
    if ( (p = ptr) ) p->AddRef();
    return p;
  }
 
  void Attach(T* ptr) throw() { *this = ptr; }
  void Attach(T* ptr, bool fAddRef) throw() {
    if ( p ) p->Release();
    p = ptr;
    if ( fAddRef && p ) p->AddRef();
  }
  T* Detach() throw() { T* tmp = p; p = NULL; return tmp; }
  void Release() throw() { 
	  if ( p ) p->Release(); 
	  p = NULL;
  }

  
  //stl functions do nothing 
  bool operator< (const CRefCountPtr<T>& bw1){
	  return false;
  }

  bool operator== (const CRefCountPtr<T>& bw1){
	  return (bw1.p==p);
  }



public:
  T* p;
};


#endif // !defined(AFX_STLUTILS_H__521BD2D7_1A97_11D3_92D0_000021C715ED__INCLUDED_)
