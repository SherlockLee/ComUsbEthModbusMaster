// SyncAccess.h: interface for the CSyncAccess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYNCACCESS_H__6078B328_6200_11D1_8FE9_85545834CF7D__INCLUDED_)
#define AFX_SYNCACCESS_H__6078B328_6200_11D1_8FE9_85545834CF7D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxmt.h>

class CSyncAccess  
{
public:
	DWORD NumOfUnlocks();
	DWORD NumOfLocks();
	DWORD LockTimeOut();
	void LockTimeOut(DWORD dwTimeOut);
	BOOL Unlock();
	BOOL Lock();
	CString sName;
	CCriticalSection m_cs;
	CMutex* m_pMutex;
	CSingleLock* m_psLock;
	CSyncAccess();
	CSyncAccess(const CString& sName);
	virtual ~CSyncAccess();

protected:
	CString m_sName;
private:
	DWORD m_dwNumOfLocks;
	DWORD m_dwNumOfUnlocks;
	enum _CSyncAccess_ {
		DEFAULT_TIME_OUT=1000//1 second 
	};
	DWORD m_dwLockTimeOut;
};

#endif // !defined(AFX_SYNCACCESS_H__6078B328_6200_11D1_8FE9_85545834CF7D__INCLUDED_)
