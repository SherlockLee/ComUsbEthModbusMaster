VERSION 5.00
Begin VB.Form frmMainForm 
   Caption         =   "Visual Basic Sample "
   ClientHeight    =   5250
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6480
   LinkTopic       =   "Form1"
   ScaleHeight     =   5250
   ScaleWidth      =   6480
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdWrite 
      Caption         =   "WriteSample"
      Height          =   375
      Left            =   120
      TabIndex        =   20
      Top             =   2520
      Width           =   2415
   End
   Begin VB.CommandButton cmdHangUp 
      Caption         =   "Hang Up"
      Height          =   375
      Left            =   120
      TabIndex        =   18
      Top             =   4680
      Width           =   2175
   End
   Begin VB.CommandButton cmdInitializeModem 
      Caption         =   "Initialize Modem && Dial"
      Height          =   375
      Left            =   120
      TabIndex        =   17
      Top             =   4200
      Width           =   2175
   End
   Begin VB.ListBox lstErros 
      Height          =   840
      Left            =   2880
      TabIndex        =   16
      Top             =   1800
      Width           =   3255
   End
   Begin VB.CommandButton cmdStartServer 
      Caption         =   "Connect with Serial Device"
      Height          =   375
      Left            =   120
      TabIndex        =   15
      Top             =   120
      Width           =   2415
   End
   Begin VB.CommandButton cmdConnectWithTcpServer 
      Caption         =   "Connect with TCP Server"
      Height          =   375
      Left            =   120
      TabIndex        =   14
      Top             =   1080
      Width           =   2415
   End
   Begin VB.CommandButton cmdCustomfunc 
      Caption         =   "Custom Modbus Function"
      Height          =   375
      Left            =   120
      TabIndex        =   13
      Top             =   2040
      Width           =   2415
   End
   Begin VB.TextBox txtAddress 
      Height          =   285
      Left            =   3720
      MaxLength       =   5
      TabIndex        =   10
      Text            =   "0"
      Top             =   3120
      Width           =   975
   End
   Begin VB.TextBox txtQuantity 
      Height          =   285
      Left            =   5640
      MaxLength       =   2
      TabIndex        =   8
      Text            =   "10"
      Top             =   3120
      Width           =   495
   End
   Begin VB.ComboBox cboReadFunction 
      Height          =   315
      Left            =   4080
      Style           =   2  'Dropdown List
      TabIndex        =   6
      Top             =   2760
      Width           =   2055
   End
   Begin VB.TextBox txtDevice 
      Height          =   285
      Left            =   3600
      MaxLength       =   2
      TabIndex        =   5
      Text            =   "1"
      Top             =   2760
      Width           =   375
   End
   Begin VB.CommandButton cmdStartStopPoll 
      Caption         =   "&Start"
      Height          =   375
      Left            =   2760
      TabIndex        =   3
      Top             =   3600
      Width           =   3495
   End
   Begin VB.Timer trmPollDevice 
      Enabled         =   0   'False
      Interval        =   1500
      Left            =   2640
      Top             =   1440
   End
   Begin VB.ListBox lstValues 
      Height          =   1230
      Left            =   2880
      TabIndex        =   2
      Top             =   480
      Width           =   3255
   End
   Begin VB.CommandButton cmdNew 
      Caption         =   "New Form Instance"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   1560
      Width           =   2415
   End
   Begin VB.CheckBox chkEnableTCPInterface 
      Caption         =   "Enable TCP Server Interface"
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   600
      Width           =   2415
   End
   Begin VB.Label Label5 
      Caption         =   $"frmMainForm.frx":0000
      Height          =   975
      Left            =   2400
      TabIndex        =   19
      Top             =   4080
      Width           =   3855
   End
   Begin VB.Label lblStat 
      BorderStyle     =   1  'Fixed Single
      Height          =   255
      Left            =   2880
      TabIndex        =   12
      Top             =   120
      Width           =   3255
   End
   Begin VB.Label Label4 
      Caption         =   " See the functions ConnectWithSerialDevice() and ConnectUsingTCP_IP()  and change serial port or TCP/IP parameters"
      Height          =   1095
      Left            =   120
      TabIndex        =   11
      Top             =   3000
      Width           =   2415
   End
   Begin VB.Label Label3 
      Caption         =   "Start Addr."
      Height          =   255
      Left            =   2640
      TabIndex        =   9
      Top             =   3000
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "Quantity"
      Height          =   255
      Left            =   4800
      TabIndex        =   7
      Top             =   3120
      Width           =   615
   End
   Begin VB.Label Label1 
      Caption         =   "Poll Device"
      Height          =   255
      Left            =   2640
      TabIndex        =   4
      Top             =   2760
      Width           =   855
   End
End
Attribute VB_Name = "frmMainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim m_ModbusServer As ModbusSrv 'Modbus Server Object
Dim m_TcpServer As CTCPIPServer 'TCP Server used for starting TCP/Serial port Interface
'Dim m_DcomUtil As DCOMLib
Dim m_bServerStarted As Boolean
Dim m_lErrors As Long
Dim m_lNumPolls As Long





Function ConnectUsingTCP_IP() As Boolean
 On Error GoTo ErrorConnectUsingTCP_IP
  
  'Set m_DcomUtil = New DCOMLib 'Initialize object to use DCOM
  
  'You can use normal Vb object creation
  'if you not try to instanciate on another machine
  Set m_ModbusServer = New ModbusSrv
  
   'Set m_ModbusServer = m_DcomUtil.CreateRemoteObject("{B3DE3CC2-C629-11D1-8FE9-E4CD05C10000}", "", False)

   'Set parameters as your hardware requirements
   m_ModbusServer.OpenConnection "127.0.0.1:502", mbREMOTE
   m_ModbusServer.Host = "127.0.0.1"
   m_ModbusServer.TcpPort = 502
   m_ModbusServer.TimeOut = 2000
   
   m_ModbusServer.RaiseError = True
     
   If Not m_ModbusServer.Connect Then
      ConnectUsingTCP_IP = False
      MsgBox "Error connecting with TCP/IP Server. Try to change TCP/IP parameters, see the Function ConnectUsingTCP_IP"
   Else
      End If
   
   
   
Exit Function

ErrorConnectUsingTCP_IP:
 MsgBox "Error:" & CStr(Err) & " " & Err.Description
 ConnectUsingTCP_IP = False
Exit Function
End Function

Sub LoadContols()

   Me.cboReadFunction.AddItem "Read Output Registers"
   Me.cboReadFunction.AddItem "Read Input Registers"
   Me.cboReadFunction.AddItem "Read Output Status (Coils)"
   Me.cboReadFunction.AddItem "Read Input Status (Coils)"
   
   cboReadFunction.ListIndex = 0
End Sub

Sub ReadFunction()
  
  On Error GoTo ReadFunctionError
  
  Dim vValues As Variant
  Dim iDevice As Integer
  Dim iDataStart As Long
  Dim iQnt As Integer
  Dim i As Integer
 
  
  iDevice = Val(Me.txtDevice.Text)
  iDataStart = Val(Me.txtAddress.Text)
  iQnt = Val(Me.txtQuantity.Text)
  
  lblStat.Caption = CStr(m_lNumPolls) & " Errors = " & CStr(m_lErrors)
  Me.Caption = lblStat.Caption
  m_lNumPolls = m_lNumPolls + 1
  
  
  If iQnt > 0 Then
  
      Select Case Me.cboReadFunction.ListIndex
       
       Case 0
             m_ModbusServer.ReadOutputRegisters iDevice, iDataStart, iQnt, vValues, vbLong
            
            'Example reading Modbus Registers using floating point support
            'Note that when reading 1 float number is equivalent to read 2 registers
            'because you need 2 WORDS (Registers) to store a floating point number
            'double floating point number requires 4 Registers.
            
            'constants  mbREAL_NORMAL and mbREAL_REVERSE indicates if most significant part of
            'the real number is at the first register or the last register.
            
            'Read float
            'm_ModbusServer.ReadOutputRegisters iDevice, iDataStart, iQnt, vValues, vbSingle, mbREAL_NORMAL
            
            'Read float reversed
            'm_ModbusServer.ReadOutputRegisters iDevice, iDataStart, iQnt, vValues, vbSingle, mbREAL_REVERSE
            
            'Read double
            'm_ModbusServer.ReadOutputRegisters iDevice, iDataStart, iQnt, vValues, vbDouble, mbREAL_NORMAL
            
            'Read double reversed
            'm_ModbusServer.ReadOutputRegisters iDevice, iDataStart, iQnt, vValues, vbDouble, mbREAL_REVERSE
    
       
       Case 1
            m_ModbusServer.ReadInputRegisters iDevice, iDataStart, iQnt, vValues, vbLong
       
       Case 2
            m_ModbusServer.ReadOutputStatus iDevice, iDataStart, iQnt, vValues
       Case 3
            m_ModbusServer.ReadInputStatus iDevice, iDataStart, iQnt, vValues
       
      End Select
      
  End If
  
  If iQnt < Me.lstValues.ListCount Then
       
    For i = 1 To (lstValues.ListCount - iQnt)
      lstValues.RemoveItem 0
    Next i
  End If
  
  For i = 0 To iQnt - 1
    If i > lstValues.ListCount - 1 Then
      lstValues.AddItem ""
    End If
    lstValues.List(i) = "[" & CStr(i + iDataStart) & "]=" & CStr(vValues(i))
  Next i
  
  
  Exit Sub
  
ReadFunctionError:
 m_lErrors = m_lErrors + 1
'lstValues.Clear
'lstValues.AddItem "Error:0x" & Hex$(Err.Number) & " " & Err.Description
lstErros.AddItem CStr(m_lErrors) & "-Error:0x" & Hex$(Err.Number) & " " & Err.Description
Err.Clear

Exit Sub

End Sub

Sub WriteFunction()

 On Error GoTo WriteFunctionError
  
  Dim vValues As Variant
  Dim iDevice As Integer
  Dim iDataStart As Long
  Dim iQnt As Integer
  Dim i As Integer
 
  
  iDevice = Val(Me.txtDevice.Text)
   
  'GoTo CoilsWrite
  
  'preset a single register
  iDataStart = 0
  m_ModbusServer.PresetSingleRegister iDevice, iDataStart, CInt(10)

  'preset multiple registers
   Dim regValues() As Integer
   
   'Dim regValues() As Long 'send as 16 unsigned integer 0 to 65535
   'Dim regValues() As Single  'send as float number
   'Dim regValues() As Double  'send as double  number
   
   ReDim regValues(0 To 2)
   regValues(0) = 0
   regValues(1) = 1
   regValues(2) = 2
   iDataStart = 2 'index is 0 based
   iQnt = UBound(regValues) - LBound(regValues)
   'set values
   m_ModbusServer.PresetMultipleRegisters iDevice, iDataStart, iQnt, regValues
      
CoilsWrite:

  'force single coil
  iDataStart = 3 ' address is 0 based
  m_ModbusServer.ForceSingleCoil iDevice, iDataStart, True
  
  'force multiple coils
  Dim aCoils() As Boolean
  ReDim aCoils(0 To 2)
  aCoils(0) = False
  aCoils(1) = True
  aCoils(2) = True
  iDataStart = 0 ' address is 0 based
  iQnt = UBound(aCoils) - LBound(aCoils)
  m_ModbusServer.ForceMultipleCoils iDevice, iDataStart, iQnt, aCoils
  
Exit Sub
WriteFunctionError:
 m_lErrors = m_lErrors + 1
'lstValues.Clear
'lstValues.AddItem "Error:0x" & Hex$(Err.Number) & " " & Err.Description
lstErros.AddItem CStr(m_lErrors) & "-Error:0x" & Hex$(Err.Number) & " " & Err.Description
Err.Clear

End Sub

Private Sub cmdConnectWithTcpServer_Click()
   
  Screen.MousePointer = vbHourglass
  m_bServerStarted = ConnectUsingTCP_IP()
  Screen.MousePointer = vbDefault
    
End Sub


Private Sub cmdCustomfunc_Click()
   
  On Error GoTo CommError
  
  'Implementing a  diagnostic function
  LoopbackTest 1  'Test if device with address 1 is working
  
  
  Exit Sub
  
CommError:
 MsgBox "&H" & Hex$(Err.Number) & "  " & Err.Description
Exit Sub
End Sub

Private Sub cmdHangUp_Click()
  
  Dim sRecived As String 'Text Returned by modem
  Dim lTimeout As Long 'Time to wait a message in ms
  Dim sTelNumber As String
  
  'escape sequence
  lTimeout = 1000
  sRecived = SendCommand("+++", lTimeout)
  Debug.Print sRecived
  sRecived = SendCommand("ATH0", lTimeout)
  Debug.Print sRecived
  
  
End Sub

Private Sub cmdInitializeModem_Click()
     
  Dim sRecived As String 'Text Returned by modem
  Dim lTimeout As Long 'Time to wait a message in ms
  Dim sTelNumber As String
  
  'put your modem intialization string
  lTimeout = 1000
  sRecived = SendCommand("AT&F1", lTimeout)
  Debug.Print sRecived
  
  
  'dial to your plc
  lTimeout = 10000 'wait 10 seconds
                   'the program with be stoped for 10 seconds
                   'waiting for response
  sTelNumber = "30688777"
  sRecived = SendCommand("ATDT" & sTelNumber, lTimeout) '
  Debug.Print sRecived
  
     
End Sub

Private Sub cmdNew_Click()
   Dim f As frmMainForm
   
   Set f = New frmMainForm
   
   f.Show
   
   Set f = Nothing
   
End Sub

Private Sub cmdStartServer_Click()
  
  Screen.MousePointer = vbHourglass
  m_bServerStarted = ConnectWithSerialDevice()
  Screen.MousePointer = vbDefault
  
End Sub

Private Sub cmdStartStopPoll_Click()
    
    If trmPollDevice.Enabled Then
      trmPollDevice.Enabled = False
      cmdStartStopPoll.Caption = "&Start"
    Else
      m_lErrors = 0
      m_lNumPolls = 0
      trmPollDevice.Enabled = True
      cmdStartStopPoll.Caption = "&Stop"
    End If
      
      
End Sub

Private Sub Command1_Click()

End Sub

Private Sub cmdWrite_Click()
      
  MsgBox "See the procedure WriteFunction to verify how to preset single/ multiple register and coils. THIS CAN DISCONFIGURE YOUR INSTRUMENT! "
      
  Exit Sub
      
  WriteFunction
      
End Sub

Private Sub Form_Load()

   LoadContols
   m_bServerStarted = False

End Sub

Function SendCommand(ByVal sCommand As String, ByVal lTimeout As Long) As String

Dim vResp As Variant
Dim vNumOfBytesRead As Variant
   Dim abyData() As Byte
   Dim i As Integer
   
   sCommand = sCommand & vbCrLf
   ReDim abyData(0 To Len(sCommand) - 1)
   
   For i = 0 To Len(sCommand) - 1
     abyData(i) = Asc(Mid$(sCommand, i + 1, 1))
   Next i
   
   m_ModbusServer.TxRxRawData CVar(abyData), Len(sCommand), vResp, 0, lTimeout, vNumOfBytesRead


  For i = 0 To vNumOfBytesRead - 1
     SendCommand = SendCommand & Chr$(vResp(i))
   Next i

End Function
'
'Example how to create new modbus function
'
Function LoopbackTest(nAddr As Integer) As Long

    Const QUERY_LENGHT = 6
    Const nReplyLength = 0
    Dim abyQuery() As Byte
    Dim vReply As Variant
    Dim vQuery As Variant
    Dim vNumOfBytes As Variant
    Dim nError As Long
    Dim iReg As Integer
    Dim iRetry As Integer

    ReDim abyQuery(0 To QUERY_LENGHT)
 
    'new modbus message see modbus protcol on www.modicon.com
    abyQuery(0) = nAddr 'ADDR
    abyQuery(1) = 8 'Function
    abyQuery(2) = 0 'diag. code=0
    abyQuery(3) = 0
    abyQuery(4) = &HA5
    abyQuery(5) = &H37
    
    vQuery = abyQuery

    Do
        nError = m_ModbusServer.TxRxMessage(vQuery, QUERY_LENGHT, vReply, nReplyLength, vNumOfBytes) 'send message to device
        If (nError = mbErrOk) Then 'interpret response ,
            For iReg = 0 To QUERY_LENGHT - 1
                If (abyQuery(iReg) <> vReply(iReg)) Then
                    nError = mbErrInvResp
                    Exit For
                End If
            Next iReg


        End If

        iRetry = iRetry + iRetry

    Loop While ((iRetry < m_ModbusServer.Retries) And (mbErrOk <> nError))

    LoopbackTest = nError


       
End Function 'end LoopBackTest

Function ConnectWithSerialDevice() As Boolean

  On Error GoTo ErrorConnectWithSerialDevice
  
  'Set m_DcomUtil = New DCOMLib 'Initialize object to use DCOM
  
  'You can use normal Vb object creation
  'if you not try to instanciate on another machine
  Set m_ModbusServer = New ModbusSrv
  
   'Set m_ModbusServer = m_DcomUtil.CreateRemoteObject("{B3DE3CC2-C629-11D1-8FE9-E4CD05C10000}", "", False)

   'Set m_ModbusServer = m_DcomUtil.CreateRemoteObject("ModbusSrv.ModbusSrv.1", "", False)

   'Set parameters as your hardware requirements
   m_ModbusServer.OpenConnection "com2", mbLOCAL 'change com port
   m_ModbusServer.ComPort = 2 'change com port
   m_ModbusServer.BaudRate = 9600
   m_ModbusServer.Parity = mbNOPARITY
   
   m_ModbusServer.FlowControl = mbFC_NONE
   
   m_ModbusServer.SilentInterval = 20
   m_ModbusServer.TimeOut = 500
   
   m_ModbusServer.TransmissionMode = mbMODE_RTU
   m_ModbusServer.ByteSize = 8
   m_ModbusServer.StopBits = mbONESTOPBIT
   
   m_ModbusServer.RaiseError = True
     
   If Not m_ModbusServer.Connect Then
      ConnectWithSerialDevice = False
      MsgBox "Error connecting with serial port Try Change Parameters of serial port , see the Function ConnectWithSerialDevice"
   Else
   
      If chkEnableTCPInterface.Value Then
        Set m_TcpServer = m_ModbusServer.CreateTCPServer

        'change this address
        m_TcpServer.ServerAddress = "127.0.0.1"
        m_TcpServer.ServerPort = 502

        If Not m_TcpServer.StartServer Then
          MsgBox "Error Starting TCP Serial Port Interface Try. to change server address at Sub ConnectWithSerialDevice"
        End If
      Else
       Set m_TcpServer = Nothing
      End If
      
      ConnectWithSerialDevice = True
   End If
   
   
   
Exit Function

ErrorConnectWithSerialDevice:
 MsgBox "Error:" & CStr(Err) & " " & Err.Description
 ConnectWithSerialDevice = False
Exit Function

End Function


Private Sub trmPollDevice_Timer()
    
    ReadFunction
    
End Sub


