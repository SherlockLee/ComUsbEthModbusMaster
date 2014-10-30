# Microsoft Developer Studio Project File - Name="ModbuLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ModbuLib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ModbuLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ModbuLib.mak" CFG="ModbuLib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ModbuLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ModbuLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ModbuLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\UtilClasses\Include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MAKING_MBU_LIB_" /D "_AFXDLL" /YX /FD /c
# ADD BASE RSC /l 0x416
# ADD RSC /l 0x416
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"ReleaseModbuLib.lib"

!ELSEIF  "$(CFG)" == "ModbuLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GR /GX /Z7 /Od /I "..\UtilClasses\Include" /D "_DEBUG" /D "_AFXDLL" /D "_MAKING_MBU_LIB_" /D "WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x416
# ADD RSC /l 0x416
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"DebugModbuLib.lib"

!ENDIF 

# Begin Target

# Name "ModbuLib - Win32 Release"
# Name "ModbuLib - Win32 Debug"
# Begin Source File

SOURCE=..\UtilClasses\scr\AutoModbus.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\AutoModbus.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\blocksock.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\blocksock.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\ClientArray.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\ClientArray.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\crc16.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\InterfaceConstants.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\LocalModbus.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\LocalModbus.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\mbu.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\MMTimer.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\MMTimer.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\modbus.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\modbus.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\ModbusMessages.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\ModbusServer.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\OleFuncs.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\OleFuncs.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\OleSafeArrayEx.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\OleSafeArrayEx.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\OleVariantEx.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\OleVariantEx.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\PerformanceCounter.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\PerformanceCounter.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\RemoteClient.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\RemoteClient.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\RemoteModbus.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\RemoteModbus.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\SyncAccess.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\SyncAccess.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\TcpServer.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\TcpServer.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\ThinThread.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\ThinThread.h
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\scr\Trayicon.cpp
# End Source File
# Begin Source File

SOURCE=..\UtilClasses\include\Trayicon.h
# End Source File
# End Target
# End Project
