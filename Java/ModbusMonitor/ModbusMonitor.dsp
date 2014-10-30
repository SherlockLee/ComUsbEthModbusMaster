# Microsoft Developer Studio Project File - Name="ModbusMonitor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Java Virtual Machine Java Project" 0x0809

CFG=ModbusMonitor - Java Virtual Machine Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ModbusMonitor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ModbusMonitor.mak"\
 CFG="ModbusMonitor - Java Virtual Machine Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ModbusMonitor - Java Virtual Machine Release" (based on\
 "Java Virtual Machine Java Project")
!MESSAGE "ModbusMonitor - Java Virtual Machine Debug" (based on\
 "Java Virtual Machine Java Project")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
JAVA=jvc.exe

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ""
# PROP BASE Intermediate_Dir ""
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
# ADD BASE JAVA /O
# ADD JAVA /O

!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ""
# PROP BASE Intermediate_Dir ""
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
# ADD BASE JAVA /g
# ADD JAVA /g

!ENDIF 

# Begin Target

# Name "ModbusMonitor - Java Virtual Machine Release"
# Name "ModbusMonitor - Java Virtual Machine Debug"
# Begin Group "Source Files"

# PROP Default_Filter "java;html"
# Begin Group "util"

# PROP Default_Filter "*.java"
# Begin Source File

SOURCE=.\FreeModbus\Util\Modbus.java
# End Source File
# Begin Source File

SOURCE=.\FreeModbus\Util\ModbusException.java
# End Source File
# End Group
# Begin Source File

SOURCE=.\FreeModbus\AppletTest\DialogLayout.java
# End Source File
# Begin Source File

SOURCE=.\FreeModbus\AppletTest\ModbusAplication.java
# End Source File
# Begin Source File

SOURCE=.\ModbusMonitor.html
# End Source File
# Begin Source File

SOURCE=.\FreeModbus\AppletTest\ModbusMonitor.java
# End Source File
# Begin Source File

SOURCE=.\FreeModbus\AppletTest\ModbusMonitorDlg.java
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\ModbusMonitor.rct
# End Source File
# End Group
# Begin Group "certificate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\freemodbus.ddf
# End Source File
# Begin Source File

SOURCE=.\TrustModbus.ddf
# End Source File
# Begin Source File

SOURCE=.\TrustModbus.inf
# End Source File
# Begin Source File

SOURCE=.\wvtstoff.reg
# End Source File
# Begin Source File

SOURCE=.\wvtston.reg
# End Source File
# End Group
# End Target
# End Project
