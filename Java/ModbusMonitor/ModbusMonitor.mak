# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Java Virtual Machine Java Workspace" 0x0809

!IF "$(CFG)" == ""
CFG=ModbusMonitor - Java Virtual Machine Debug
!MESSAGE No configuration specified.  Defaulting to ModbusMonitor - Java\
 Virtual Machine Debug.
!ENDIF 

!IF "$(CFG)" != "ModbusMonitor - Java Virtual Machine Release" && "$(CFG)" !=\
 "ModbusMonitor - Java Virtual Machine Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ModbusMonitor.mak"\
 CFG="ModbusMonitor - Java Virtual Machine Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ModbusMonitor - Java Virtual Machine Release" (based on\
 "Java Virtual Machine Java Workspace")
!MESSAGE "ModbusMonitor - Java Virtual Machine Debug" (based on\
 "Java Virtual Machine Java Workspace")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "ModbusMonitor - Java Virtual Machine Debug"
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
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\ModbusMonitor.class" "$(OUTDIR)\Modbus.class"\
 "$(OUTDIR)\DialogLayout.class" "$(OUTDIR)\ModbusMonitorDlg.class"\
 "$(OUTDIR)\Thermometer.class"

CLEAN : 
	-@erase "$(INTDIR)\DialogLayout.class"
	-@erase "$(INTDIR)\Modbus.class"
	-@erase "$(INTDIR)\ModbusMonitor.class"
	-@erase "$(INTDIR)\ModbusMonitorDlg.class"
	-@erase "$(INTDIR)\Thermometer.class"

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
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\ModbusMonitor.class" "$(OUTDIR)\Modbus.class"\
 "$(OUTDIR)\DialogLayout.class" "$(OUTDIR)\ModbusMonitorDlg.class"\
 "$(OUTDIR)\Thermometer.class"

CLEAN : 
	-@erase "$(INTDIR)\DialogLayout.class"
	-@erase "$(INTDIR)\Modbus.class"
	-@erase "$(INTDIR)\ModbusMonitor.class"
	-@erase "$(INTDIR)\ModbusMonitorDlg.class"
	-@erase "$(INTDIR)\Thermometer.class"

# ADD BASE JAVA /g
# ADD JAVA /g

!ENDIF 

################################################################################
# Begin Target

# Name "ModbusMonitor - Java Virtual Machine Release"
# Name "ModbusMonitor - Java Virtual Machine Debug"

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"

!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ModbusMonitor.java

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"


"$(INTDIR)\ModbusMonitor.class" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"


"$(INTDIR)\ModbusMonitor.class" : $(SOURCE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ModbusMonitor.html

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"

!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\user\Ricardo\ModApp\Modbus.java

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"


"$(INTDIR)\Modbus.class" : $(SOURCE) "$(INTDIR)"
   $(JAVA) $(JAVA_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"


"$(INTDIR)\Modbus.class" : $(SOURCE) "$(INTDIR)"
   $(JAVA) $(JAVA_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DialogLayout.java

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"


"$(INTDIR)\DialogLayout.class" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"


"$(INTDIR)\DialogLayout.class" : $(SOURCE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ModbusMonitorDlg.java

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"


"$(INTDIR)\ModbusMonitorDlg.class" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"


"$(INTDIR)\ModbusMonitorDlg.class" : $(SOURCE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Thermometer.java

!IF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Release"


"$(INTDIR)\Thermometer.class" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ModbusMonitor - Java Virtual Machine Debug"


"$(INTDIR)\Thermometer.class" : $(SOURCE) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
