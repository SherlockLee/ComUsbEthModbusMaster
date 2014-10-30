#include "mbu.h"
#include <Afxole.h>
#include "OleFuncs.h"

//changed AfxOleInit replacing ::OleInitialize(NULL); whith 
//	::CoInitializeEx(NULL,COINIT_MULTITHREADED);

BOOL AFXAPI AfxOleInit2()
{
	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	ASSERT(!pState->m_bNeedTerm);    // calling it twice?

	// Special case DLL context to assume that the calling app initializes OLE.
	// For DLLs where this is not the case, those DLLs will need to initialize
	// OLE for themselves via OleInitialize.  This is done since MFC cannot provide
	// automatic uninitialize for DLLs because it is not valid to shutdown OLE
	// during a DLL_PROCESS_DETACH.
	if (afxContextIsDLL)
	{
		pState->m_bNeedTerm = -1;  // -1 is a special flag
		return TRUE;
	}

	// first, initialize OLE
	//SCODE sc = ::OleInitialize(NULL);
	SCODE sc = ::CoInitializeEx(NULL,COINIT_MULTITHREADED);
	//SCODE sc = ::CoInitializeEx(NULL,COINIT_APARTMENTTHREADED); 

	if (FAILED(sc))
	{
		// warn about non-NULL success codes
		TRACE1("Warning: OleInitialize returned scode = %s.\n",
			AfxGetFullScodeString(sc));
		goto InitFailed;
	}
	// termination required when OleInitialize does not fail
	pState->m_bNeedTerm = TRUE;

	// hook idle time and exit time for required OLE cleanup
	CWinThread* pThread; pThread = AfxGetThread();
	pThread->m_lpfnOleTermOrFreeLib = AfxOleTermOrFreeLib;

	// allocate and initialize default message filter
	if (pThread->m_pMessageFilter == NULL)
	{
		pThread->m_pMessageFilter = new COleMessageFilter;
		ASSERT(AfxOleGetMessageFilter() != NULL);
		AfxOleGetMessageFilter()->Register();
	}

#ifdef _MAC
	CWinApp* pApp; pApp = AfxGetApp();
#ifndef _WINDLL
	// Mac MFC uses a static version of ole2ui which must be initialized
	if (pState->m_bNeedTerm && !::OleUIInitialize(pApp->m_hInstance,
			pApp->m_hPrevInstance, SZCLASSICONBOX, SZCLASSRESULTIMAGE))
		goto InitFailed;
#endif

	_afxPfnOleAuto = NewAEEventHandlerProc(_AfxOleAutoHandler);
	if (_afxPfnOleAuto != NULL)
	{
		AEInstallEventHandler('OLE2', 'AUTO', _afxPfnOleAuto, (long) pApp, false);
	}
#endif

	return TRUE;

InitFailed:
	AfxOleTerm();
	return FALSE;
}



/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: GetErrorMsg

  Summary:  Accepts a Win32 error code and retrieves a human readable
            system message for it.

  Args:     HRESULT hr
              SCODE error code.
            LPTSTR pszMsg
              Pointer string where message will be placed.
            UINT uiSize
              Max size of the msg string.

  Returns:  BOOL
              TRUE if hr was error; FALSE if not.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL GetErrorMsg(
       HRESULT hr,
       LPTSTR pszMsg,
       UINT uiSize)
{
  BOOL bErr = FAILED(hr);
  DWORD dwSize;

  if (bErr)
  {
    memset(pszMsg, 0, uiSize * sizeof(TCHAR));

    if (HRESULT_FACILITY(hr) == FACILITY_WINDOWS)
      hr = HRESULT_CODE(hr);

    dwSize = FormatMessage(
      FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
      NULL,
      hr,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
      pszMsg,
      uiSize,
      NULL);
    if (dwSize>2)
    {
      // Take out the trailing CRLF.
      pszMsg[--dwSize] = 0;
      pszMsg[--dwSize] = 0;
    }
  }

  return bErr;
}

/*

Check for presence of the function CoCreateInstanceEx() in the operating

system DLL Ole32.dll. If not found, then the free threading model is

not supported. Inform user and exit.

*/

BOOL DComOk() {
	HMODULE hMod = ::GetModuleHandle (_T("ole32.dll")) ;

	FARPROC fp = ::GetProcAddress (hMod, _T("CoCreateInstanceEx")) ;

	return  !(fp == NULL);
}




