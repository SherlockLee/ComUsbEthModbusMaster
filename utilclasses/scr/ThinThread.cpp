// ThinThread.cpp: implementation of the CThinThread class.
//
//////////////////////////////////////////////////////////////////////

#include "mbu.h"

#include "ThinThread.h"

#include <process.h> /* _beginthread, _endthread */

/////////////////////////////////////////////////////////////////////////////

// ThinThread

CThinThread::CThinThread()

: m_b2ndThread(FALSE)

{
	
	// Create a signaled, manual-reset event to synchronize destruction
	
	m_pExitEvent = new CEvent(TRUE, TRUE);
	
	ASSERT(m_pExitEvent);
	
	// Create a non-signaled, auto-reset event to wait on for work cycle
	
	m_pWorkEvent = new CEvent();
	
	ASSERT(m_pWorkEvent);

	m_dwSupendCount=0xFFFFFFFF;
	
}

BOOL CThinThread::CreateThread(DWORD dwCreateFlags, UINT nStackSize, 
							   
							   LPSECURITY_ATTRIBUTES lpSecurityAttrs, 
							   
							   UINT nMilliSecs)
							   
{
	
	m_b2ndThread = TRUE;
	
	m_bEndThread = FALSE;
	
	m_nCycleTime = nMilliSecs;
	
	m_dwSupendCount=0xFFFFFFFF;

	m_pExitEvent->ResetEvent(); // exit event is reset until we're done
	
	// Start second thread
	
	unsigned usThreadAddr;
	
	m_hThread2 = reinterpret_cast<HANDLE>
		
		(_beginthreadex(lpSecurityAttrs, nStackSize, Start,
		
		this, 1, &usThreadAddr));
	
	return reinterpret_cast<unsigned long> (m_hThread2);
	
}

CThinThread::~CThinThread()

{
	
	delete m_pWorkEvent;
	delete m_pExitEvent;
	
}

void CThinThread::KillThread2()

{
	
	// Start up the other thread so it can complete.
	
	// When it does, it will set the exit event and the object can
	
	// be destructed.
	
	m_bEndThread = TRUE;
	
	m_pWorkEvent->SetEvent();
	
	CSingleLock csl(m_pExitEvent);
	
	csl.Lock(); // wait for 2nd thread to finish
	
	csl.Unlock(); 
	
}

int CThinThread::Run()

{
	
	CSingleLock csl(m_pWorkEvent); // synch on the work event
	
	StartWork(); // do derived startup
	
	while (!m_bEndThread) // loop until we're done
		
	{
		
		csl.Lock(m_nCycleTime); // wait for event or timeout
		
		csl.Unlock(); 
		
		if (!m_bEndThread) DoWork(); // then do derived work
		
	}
	
	EndWork(); // do derived shutdown
	
	m_pExitEvent->SetEvent(); // set not waiting signal
	
	m_b2ndThread = FALSE;
	
	CloseHandle(m_hThread2);
	
	_endthreadex(0);
	
	return 0;
	
}

unsigned int __stdcall CThinThread::Start(void* pv)

{
	
	CThinThread* pMT = static_cast<CThinThread*> (pv);
	
	return pMT->Run();
	
}


BOOL CThinThread::SetThreadPriority(int nPriority)
{
	return ::SetThreadPriority(GetHandle(),nPriority);
}

int CThinThread::GetThreadPriority()
{

	return ::GetThreadPriority( GetHandle());

}


DWORD CThinThread::ResumeThread()
{
	if (!IsBusy()) {
		return 0;
	}

	if (m_dwSupendCount!=0xFFFFFFFF) {
	
		m_dwSupendCount = ::ResumeThread(GetHandle());
	}

	if (1==m_dwSupendCount) {
		m_dwSupendCount=0xFFFFFFFF;
	}
	return m_dwSupendCount;
}


DWORD CThinThread::SuspendThread()
{

	if (!IsBusy()) {
		return 0;
	}

	if (m_dwSupendCount!=0xFFFFFFFF) {
		return m_dwSupendCount;
	}
	m_dwSupendCount = ::SuspendThread(GetHandle());
	
	ASSERT(0xFFFFFFFF!=m_dwSupendCount);

	return m_dwSupendCount;
}

long CThinThread::test()
{
	AfxMessageBox("Test");
	return 0;
}

void CThinThread::DoEvents()
{
	MSG message;
	if (::PeekMessage(&message,NULL,0,0,PM_REMOVE)) {
		::TranslateMessage(&message);
		::DispatchMessage(&message);
	}
}
