; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommParameters
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Modbucfg.h"
ODLFile=Modbucfg.odl
LastPage=0

ClassCount=10
Class1=CModbucfgApp
Class2=CModbucfgDoc
Class3=CModbucfgView
Class4=CMainFrame

ResourceCount=12
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_MODBUCTYPE
Resource7=IDD_ABOUTBOX (English (U.S.))
Resource4=IDD_MODBUCFG_FORM
Resource5=IDD_MODBUCFG_FORM (English (U.S.))
Resource6=IDR_MODBUCTYPE (English (U.S.))
Resource8=IDR_MAINFRAME (English (U.S.))
Class5=CAboutDlg
Class6=CChildFrame
Class7=CCommParameters
Resource9=IDD_MOD_LOCAL_COM_PARAM (English (U.S.))
Class8=CDlgConnections
Resource10=IDD_CONNECTIONS (English (U.S.))
Class9=CDlgRemoteParameters
Class10=CSplashWnd
Resource11=IDR_TRAY_ICON (English (U.S.))
Resource12=IDD_MOD_REM_PARAMETERS

[CLS:CModbucfgApp]
Type=0
HeaderFile=Modbucfg.h
ImplementationFile=Modbucfg.cpp
Filter=N
LastObject=ID_TRAY_EXIT

[CLS:CModbucfgDoc]
Type=0
HeaderFile=ModbucfgDoc.h
ImplementationFile=ModbucfgDoc.cpp
Filter=N
LastObject=CModbucfgDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CModbucfgView]
Type=0
HeaderFile=ModbucfgView.h
ImplementationFile=ModbucfgView.cpp
Filter=D
LastObject=CModbucfgView
BaseClass=CFormView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=ID_OPTIONS_REGISTERTYPELIBRARY


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M

[CLS:CAboutDlg]
Type=0
HeaderFile=Modbucfg.cpp
ImplementationFile=Modbucfg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7
Command3=ID_FILE_MRU_FILE1

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=8
Command8=ID_APP_ABOUT

[MNU:IDR_MODBUCTYPE]
Type=1
Class=CModbucfgView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_WINDOW_NEW
CommandCount=18
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command15=ID_WINDOW_CASCADE
Command16=ID_WINDOW_TILE_HORZ
Command17=ID_WINDOW_ARRANGE
Command18=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE

[DLG:IDD_MODBUCFG_FORM]
Type=1
Class=CModbucfgView

[DLG:IDD_MODBUCFG_FORM (English (U.S.))]
Type=1
Class=CModbucfgView
ControlCount=26
Control1=IDC_FRA_MOD_WRITE_FUNCTIONS,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_CBO_READ_FUNCTION,combobox,1344339971
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_DEVICE,edit,1350639744
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_ADDR,edit,1350639744
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_QUANT,edit,1350639744
Control10=IDC_STATIC,button,1342308359
Control11=IDC_CHK_Enable_Poll,button,1342242819
Control12=IDC_STAT_STATUS,static,1350696972
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_VALUE,edit,1350631552
Control15=IDC_CMD_WRITE,button,1342242816
Control16=IDC_CBO_WRITE_FUNCTION,combobox,1344339971
Control17=IDC_STAT_ERROR,static,1350696972
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_ADDR_WRI,edit,1350639744
Control20=IDC_LST_VALUES,listbox,1352728835
Control21=IDC_FRA_MOD_FUNCTIONS2,button,1342177287
Control22=IDC_CBO_CONNECTION,combobox,1344339971
Control23=IDC_STATIC,static,1342308352
Control24=IDC_EDIT_INTERVAL,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_CBO_DATA_TYPE,combobox,1344339971

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_APP_ABOUT
CommandCount=2

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_VIEW_TOOLBAR
Command4=ID_VIEW_STATUS_BAR
Command5=ID_OPTIONS_CONNECTIONS
Command6=ID_OPTIONS_REGISTERTYPELIBRARY
Command7=ID_APP_ABOUT
CommandCount=7

[MNU:IDR_MODBUCTYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_CLOSE
Command3=ID_APP_EXIT
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_WINDOW_NEW
Command7=ID_WINDOW_CASCADE
Command8=ID_WINDOW_TILE_HORZ
Command9=ID_WINDOW_ARRANGE
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MOD_LOCAL_COM_PARAM (English (U.S.))]
Type=1
Class=CCommParameters
ControlCount=36
Control1=IDCANCEL,button,1342242816
Control2=IDC_CBO_BAUD_RATE,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CBO_PARITY,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_TIME_OUT,edit,1350631552
Control9=IDC_EDIT_CHAR_INTERVAL,edit,1350631552
Control10=IDC_OK,button,1342242816
Control11=IDC_CHK_ACTIVE,button,1342242819
Control12=IDC_STATIC,static,1342177282
Control13=IDC_CHK_DTRDSR,button,1342242819
Control14=IDC_CHK_RTSCTS,button,1342177283
Control15=IDC_CHK_XONXOFF,button,1342177283
Control16=IDC_STATIC,static,1342177282
Control17=IDC_CBO_STOPBITSCB,combobox,1344340483
Control18=IDC_STATIC,button,1342177287
Control19=IDC_RAD_RTU,button,1342177289
Control20=IDC_RAD_ASCII,button,1342177289
Control21=IDC_STATIC,static,1342177282
Control22=IDC_CBO_BYTESIZE,combobox,1344340483
Control23=IDC_EDIT_DCOM_SERVER,edit,1350631552
Control24=IDC_STATIC,button,1342177287
Control25=IDC_STATIC,static,1342308352
Control26=IDC_CBO_COM_PORT,combobox,1344340227
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,button,1342177287
Control29=IDC_EDIT_IP_ADDR,edit,1350631552
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_EDIT_PORT,edit,1350639744
Control33=IDC_CHK_TCP_SERVER,button,1342242819
Control34=IDC_BUTT_FIND_IP,button,1342242816
Control35=IDC_STATIC,static,1342308352
Control36=IDC_EDIT_DELAY,edit,1350631552

[CLS:CCommParameters]
Type=0
HeaderFile=CommParameters.h
ImplementationFile=CommParameters.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCommParameters

[DLG:IDD_CONNECTIONS (English (U.S.))]
Type=1
Class=CDlgConnections
ControlCount=8
Control1=IDCANCEL,button,1342242816
Control2=IDC_LST_CONNECTIOS,listbox,1352728835
Control3=IDC_CMD_ADD,button,1342242816
Control4=IDC_CMD_EDIT,button,1342242816
Control5=IDC_CMD_REMOVE,button,1342242816
Control6=IDC_CBO_TYPE,combobox,1344339971
Control7=IDC_BUTTON_SAVE,button,1342242816
Control8=IDC_BUTTON_LOAD,button,1342242816

[CLS:CDlgConnections]
Type=0
HeaderFile=DlgConnections.h
ImplementationFile=DlgConnections.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgConnections
VirtualFilter=dWC

[DLG:IDD_MOD_REM_PARAMETERS]
Type=1
Class=CDlgRemoteParameters
ControlCount=9
Control1=IDOKey,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT_IP_ADDR,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_PORT,edit,1350639744
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_TIME_OUT,edit,1350631552

[CLS:CDlgRemoteParameters]
Type=0
HeaderFile=DlgRemoteParameters.h
ImplementationFile=DlgRemoteParameters.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOKey
VirtualFilter=dWC

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd
LastObject=CSplashWnd

[MNU:IDR_TRAY_ICON (English (U.S.))]
Type=1
Class=?
Command1=ID_TRAY_MAIN
Command2=ID_TRAY_CONNECTIONS
Command3=ID_TRAY_EXIT
Command4=ID_APP_ABOUT
CommandCount=4

