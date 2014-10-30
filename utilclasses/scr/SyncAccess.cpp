// SyncAccess.cpp: implementation of the CSyncAccess class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"
#include "SyncAccess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSyncAccess::CSyncAccess()
{
	m_pMutex=NULL;
	m_psLock=NULL;
	m_dwLockTimeOut=DEFAULT_TIME_OUT;
	m_dwNumOfLocks=0;
	m_dwNumOfUnlocks=0;
	
}

CSyncAccess::CSyncAccess(const CString& sName) {
	m_pMutex = new CMutex(FALSE,sName,NULL);
	m_psLock = new CSingleLock( m_pMutex,FALSE);
}

CSyncAccess::~CSyncAccess()
{
	if (m_psLock!=NULL) {
		delete m_psLock;
	}
	
	if (m_pMutex!=NULL) {
		delete m_pMutex;
	}

}





BOOL CSyncAccess::Lock()
{
	BOOL bRet;
	m_dwNumOfLocks++;
	if (m_psLock!=NULL) {
		return m_psLock->Lock(m_dwLockTimeOut);
	}
	else {
		bRet = m_cs.Lock();
		ASSERT(bRet);
		return bRet;
	}

}

BOOL CSyncAccess::Unlock()
{

	BOOL bRet;
	m_dwNumOfUnlocks++;
	if (m_psLock!=NULL) {
		return m_psLock->Unlock(1);
	}
	else {
		bRet=m_cs.Unlock();
		ASSERT(bRet);
		return bRet;
	}

}

void CSyncAccess::LockTimeOut(DWORD dwTimeOut)
{
	m_dwLockTimeOut=dwTimeOut;

}

DWORD CSyncAccess::LockTimeOut()
{
	return m_dwLockTimeOut;
}

DWORD CSyncAccess::NumOfLocks()
{
	return m_dwNumOfLocks;
}

DWORD CSyncAccess::NumOfUnlocks()
{
	return m_dwNumOfUnlocks;
}


