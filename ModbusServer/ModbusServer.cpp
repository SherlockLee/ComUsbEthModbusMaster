// ModbusServer.cpp : Implementation of WinMain


// Note: Proxy/Stub Information
//		To build a separate proxy/stub DLL, 
//		run nmake -f ModbusServerps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "ModbusServer.h"
#include "OleFuncs.h"

#include "Globals.h"


#include "ModbusServer_i.c"
#include "ModbusSrv.h"

#include "TcpServer.h"


LONG CExeModule::Unlock()
{
	DWORD dwCurrentThread = ::GetCurrentThreadId();

	LONG l = CComModule::Unlock();
	if (l == 0)
	{
#if _WIN32_WINNT >= 0x0400
		if (CoSuspendClassObjects() == S_OK)
			PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
#else
		PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
#endif
	}
	return l;
}

CExeModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_ModbusSrv, CModbusSrv)
END_OBJECT_MAP()

//OBJECT_ENTRY(CLSID_CTCPIPServer, CCTCPIPServer)

LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
	while (*p1 != NULL)
	{
		LPCTSTR p = p2;
		while (*p != NULL)
		{
			if (*p1 == *p++)
				return p1+1;
		}
		p1++;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////
//
//extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, 
//	HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int /*nShowCmd*/)
//{
//	lpCmdLine = GetCommandLine(); //this line necessary for _ATL_MIN_CRT
//	HRESULT hRes = CoInitialize(NULL);
//  If you are running on NT 4.0 or higher you can use the following call
//	instead to make the EXE free threaded.
//  This means that calls come in on a random RPC thread
//	HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
/*	_ASSERTE(SUCCEEDED(hRes));
	_Module.Init(ObjectMap, hInstance);
	_Module.dwThreadID = GetCurrentThreadId();
	TCHAR szTokens[] = _T("-/");

	int nRet = 0;
	BOOL bRun = TRUE;
	LPCTSTR lpszToken = FindOneOf(lpCmdLine, szTokens);
	while (lpszToken != NULL)
	{
		if (lstrcmpi(lpszToken, _T("UnregServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_ModbusServer, FALSE);
			nRet = _Module.UnregisterServer();
			bRun = FALSE;
			break;
		}
		if (lstrcmpi(lpszToken, _T("RegServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_ModbusServer, TRUE);
			nRet = _Module.RegisterServer(TRUE);
			bRun = FALSE;
			break;
		}
		lpszToken = FindOneOf(lpszToken, szTokens);
	}

	if (bRun)
	{
		hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
			REGCLS_MULTIPLEUSE);
		_ASSERTE(SUCCEEDED(hRes));

		MSG msg;
		while (GetMessage(&msg, 0, 0, 0))
			DispatchMessage(&msg);

		_Module.RevokeClassObjects();
	}

	CoUninitialize();
	return nRet;
}
*/


BOOL CMyApp::InitInstance()     {
	
	if (!DComOk()) {
		AfxMessageBox(_T("DCOM OLE Not supported"),MB_SYSTEMMODAL+MB_OK);
		return FALSE;       
	}      

	
	// Initialize OLE libraries       
	if (!AfxOleInit2())        {
		AfxMessageBox(_T("OLE Initialization Failed!"),MB_SYSTEMMODAL+MB_OK);
		return FALSE;       
	}        // Initialize the ATL Module

	_Module.Init(ObjectMap,m_hInstance); 
    _Module.dwThreadID = GetCurrentThreadId();

#ifdef _AFXDLL
		Enable3dControls(); // Call this when using MFC in a shared DLL
#else      
		Enable3dControlsStatic(); // Call this when linking
	// to MFC statically     
#endif

    //Reg UnregSever 
    TCHAR szTokens[] = _T("-/");
	int nRet = 0;
	BOOL bRun = TRUE;
	LPCTSTR lpszToken = FindOneOf(m_lpCmdLine, szTokens);

	while (lpszToken != NULL)
	{
		if (lstrcmpi(lpszToken, _T("UnregServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_ModbusServer, FALSE);
			nRet = _Module.UnregisterServer();
			nRet = UnRegisterTypeLib(
			   LIBID_MODBUSSERVERLib, 1, 0,
               LOCALE_NEUTRAL, SYS_WIN32);
			bRun = FALSE;
			break;
		}
		if (lstrcmpi(lpszToken, _T("RegServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_ModbusServer, TRUE);
			nRet = _Module.RegisterServer(TRUE);
			bRun = FALSE;
			// Update the System Registry
			COleObjectFactory::UpdateRegistryAll(); // MFC Classes
			if(!(SUCCEEDED(nRet))){
				AfxMessageBox("Register server Failed",MB_SYSTEMMODAL+MB_OK);
			}
			bRun=FALSE;
			break;
		}
		lpszToken = FindOneOf(lpszToken, szTokens);
	}
		
	// ATL Classes
	// Create the dialog box or other stuff here
	// Register OLE Class Factories
	// MFC ones are for multiple as specified
	// by the IMPLEMENT_OLECREATE() macro
	//COleObjectFactory::RegisterAll();
	// ATL ones specifically register with REGCLS_MULTIPLEUSE
	if (bRun) {
		if(!(SUCCEEDED(_Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER,
			REGCLS_MULTIPLEUSE)))){
				AfxMessageBox("RegisterClassObjects Failed",MB_SYSTEMMODAL+MB_OK);
		}
	}

	VERIFY(CTcpServer::StartWinsock());

	// Parse the command line to see if launched as OLE server
	if (RunEmbedded() || RunAutomated())        {
		// Application was run with /Embedding or /Automation.
		// Don't show the main window in this case. 
		//Test();
		return TRUE;
	}   
	
	return FALSE; // Nothing to do, so exit.    
	
}

int CMyApp::ExitInstance()     {

	DWORD dwStart = ::GetTickCount();
	MSG message;

	do {
	if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			::TranslateMessage(&message);
			::DispatchMessage(&message);
		}
	}while ((::GetTickCount()-dwStart)<3000);


	// MFC's class factories registration is
	// automatically revoked by MFC itself
	_Module.RevokeClassObjects(); // Revoke class factories for ATL
	_Module.Term();               // cleanup ATL Global Module
	
	
	
	VERIFY(CTcpServer::StopWinsock());

	return CWinApp::ExitInstance();  
}

void CMyApp::Test()
{
	

}

// Globals 

CMyApp theApp;
