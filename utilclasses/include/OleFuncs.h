

#ifndef _OleFuncs_h_
#define _OleFuncs_h_

//changed AfxOleInit replacing ::OleInitialize(NULL); whith 
//	::CoInitializeEx(NULL,COINIT_MULTITHREADED);
BOOL AFXAPI AfxOleInit2();


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
       UINT uiSize);


/*
Check for presence of the function CoCreateInstanceEx() in the operating

system DLL Ole32.dll. If not found, then the free threading model is

not supported. Inform user and exit.

*/

BOOL DComOk();

#endif