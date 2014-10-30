#ifndef __DLL_EXPIMP_H__
#define __DLL_EXPIMP_H__


// O Define abaixo visa facilitar o uso:
// tanto no programa-cliente como na DLL-servidora
// as funcóes serão "EXPORT"

// (BASTA fazer um #define __DLL_EXPORT_IMPORT
// no .CPP da DLL)
// (e acrescentar #include <DLL_EXP.H>
// no .h de cada DLL)

#ifdef __EXTERN_C_NAO

	#ifdef __DLL_EXPORT_IMPORT
			#define  EXPORT_IMPORT  __declspec (dllexport)
	#else
			#define  EXPORT_IMPORT   __declspec (dllimport)
	#endif

#else

	#ifdef __DLL_EXPORT_IMPORT

		#ifdef __cplusplus
			#define  EXPORT_IMPORT  extern "C" __declspec (dllexport)
		#else
			#define  EXPORT_IMPORT  __declspec (dllexport)
		#endif 

	#else

		#ifdef __cplusplus
			#define  EXPORT_IMPORT  extern "C" __declspec (dllimport)
		#else
			#define  EXPORT_IMPORT   __declspec (dllimport)
		#endif
	#endif

#endif


#define CCONV _stdcall
#define NOMANGLE extern "C"

#endif //__DLL_EXPIMP_H__