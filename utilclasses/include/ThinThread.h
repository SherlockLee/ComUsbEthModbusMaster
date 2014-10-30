// ThinThread.h : header file
// Copyright (C) 1997 by The Windward Group, All Rights Reserved

#ifndef THINTHREAD_H

#define THINTHREAD_H

#ifndef __AFXWIN_H__

#error include 'stdafx.h' before including this file for PCH

#endif

#include <afxmt.h>

/////////////////////////////////////////////////////////////////////////////

class CThinThread

{
	
public:
	static void DoEvents();
	DWORD SuspendThread();
	DWORD ResumeThread();
	int GetThreadPriority();
	BOOL SetThreadPriority(int nPriority);
	
	CThinThread();
	
	virtual ~CThinThread();
	
	BOOL CreateThread(DWORD dwCreateFlags = 0,
		
		UINT nStackSize = 0,
		
		LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL,
		
		UINT nMilliSecs = INFINITE); // upper time limit to wait
	
	HANDLE GetHandle() {return m_hThread2;}
	
	BOOL IsBusy() {return m_b2ndThread;}
	
	void Stop() {m_bEndThread = TRUE;}
	
protected:
	long test();
	
	CEvent* m_pWorkEvent; // do work event
	
	CEvent* m_pExitEvent; // used to synchronize destruction
	
	int m_nCycleTime; // do work cycle time
	
	BOOL m_bEndThread; // end the thread ?
	
	BOOL m_b2ndThread; // 2nd thread active?
	
	HANDLE m_hThread2; // 2nd thread handle
	
	virtual void StartWork() {} // override to do startup
	
	virtual void DoWork() = 0; // override to do work
	
	virtual void EndWork() {} // override to do shutdown
	
	CEvent* GetEvent() const {return m_pWorkEvent;} // cycle control event
	
	int GetCycleTime() const {return m_nCycleTime;}
	
	void KillThread2();
	
	int Run();
	
	void SetCycleTime(int nMilliSecs) {m_nCycleTime = nMilliSecs;}
	
	static unsigned int __stdcall Start(void* pv);
	
private:
	DWORD m_dwSupendCount;
};

#endif

