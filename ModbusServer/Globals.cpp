// Globals.cpp: implementation of the CGlobals class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Globals.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGlobals::CGlobals()
{

}

CGlobals::~CGlobals()
{

}

CConnections gConnections; //Collection with all connectiosn local or remote