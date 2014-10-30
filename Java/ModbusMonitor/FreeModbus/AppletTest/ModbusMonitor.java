//******************************************************************************
// ModbusMonitor.java:	Applet
//
//******************************************************************************

package FreeModbus.AppletTest;


import java.applet.*;
import java.awt.*;
import FreeModbus.Util.*; //Modbus Class 
import FreeModbus.AppletTest.ModbusMonitorDlg;

//==============================================================================
// Main Class for applet ModbusMonitor
//
//==============================================================================
public class ModbusMonitor extends Applet implements Runnable
{
	long m_lNumErrors = 0;
	private long m_lNumPolls = 0;

	private boolean m_bPollActive = false;

	// THREAD SUPPORT:
	//		m_ModbusMonitor	is the Thread object for the applet
	//--------------------------------------------------------------------------
	Thread	 m_ModbusMonitor = null;

	private Modbus m_Modbus; //modbus Object 

	private ModbusMonitorDlg m_dlgMonitor; //dialog Window 

	//constants 
	private final static int FORCE_SINGLE_COIL=1;
	private final static int PRESET_SINGLE_REGISTER=0;

	//Static 
	private final static int LOOPBACK_TEST=0;
	private final static int READ_OUTPUT_REGISTERS=1;
	private final static int READ_INPUT_REGISTERS=2;
	private final static int READ_OUTPUT_STATUS=3;
	private final static int READ_INPUT_STATUS=4;


	// ModbusMonitor Class Constructor
	//--------------------------------------------------------------------------
	public ModbusMonitor()
	{
		// TODO: Add constructor code here
	}

	// APPLET INFO SUPPORT:
	//		The getAppletInfo() method returns a string describing the applet's
	// author, copyright date, or miscellaneous information.
    //--------------------------------------------------------------------------
	public String getAppletInfo()
	{
		return "Name: ModbusMonitor\r\n" +
		       "Author: Ricardo Saat \r\n" +
		       "Created with Microsoft Visual J++ Version 1.0";
	}


	// The init() method is called by the AWT when an applet is first loaded or
	// reloaded.  Override this method to perform whatever initialization your
	// applet needs, such as initializing data structures, loading images or
	// fonts, creating frame windows, setting the layout manager, or adding UI
	// components.
    //--------------------------------------------------------------------------
	public void init()
	{
        // If you use a ResourceWizard-generated "control creator" class to
        // arrange controls in your applet, you may want to call its
        // CreateControls() method from within this method. Remove the following
        // call to resize() before adding the call to CreateControls();
        // CreateControls() does its own resizing.
        //----------------------------------------------------------------------
		//resize(500, 300);
		//create control dialog 
		m_dlgMonitor= new ModbusMonitorDlg (this);
        m_dlgMonitor.CreateControls();

		//Modbus Initialization
		m_Modbus=new Modbus();
		m_Modbus.ReConnectOnEveryMessage(true);

		// TODO: Place additional initialization code here
		Initializecontrols();
		m_bPollActive=false;

		//Connect();
	
	}

	// Place additional applet clean up code here.  destroy() is called when
	// when you applet is terminating and being unloaded.
	//-------------------------------------------------------------------------
	public void destroy()
	{
		// TODO: Place applet cleanup code here
	}

	// ModbusMonitor Paint Handler
	//--------------------------------------------------------------------------
	public void paint(Graphics g)
	{
		// TODO: Place applet paint code here
		//g.drawString("Running: " + Math.random(), 10, 20);
	}

	//		The start() method is called when the page containing the applet
	// first appears on the screen. The AppletWizard's initial implementation
	// of this method starts execution of the applet's thread.
	//--------------------------------------------------------------------------
	public void start()
	{
		if (m_ModbusMonitor == null)
		{
			m_ModbusMonitor = new Thread(this);
			m_ModbusMonitor.start();
		}
		// TODO: Place additional applet start code here
		
		
	}
	
	//		The stop() method is called when the page containing the applet is
	// no longer on the screen. The AppletWizard's initial implementation of
	// this method stops execution of the applet's thread.
	//--------------------------------------------------------------------------
	public void stop()
	{
		if (m_ModbusMonitor != null)
		{
			m_ModbusMonitor.stop();
			m_ModbusMonitor = null;
		}

		// TODO: Place additional applet stop code here

		//Stop Modbus 
		if (m_Modbus.IsConnected()){
			m_Modbus.closeConnection();
		}
		//m_Modbus=null;
	}

	// THREAD SUPPORT
	//		The run() method is called when the applet's thread is started. If
	// your applet performs any ongoing activities without waiting for user
	// input, the code for implementing that behavior typically goes here. For
	// example, for an applet that performs animation, the run() method controls
	// the display of images.
	//--------------------------------------------------------------------------
	public void run()
	{
		
		int iDelay;

		while (true)
		{
			try
			{
				//repaint();
				//SetStatusCom(" " + System.currentTimeMillis());
				// TODO:  Add additional thread-specific code here
				if (m_bPollActive) {
                    iDelay=atoi(m_dlgMonitor.txtDelay.getText());
					if ((iDelay>0)&&(iDelay<=5000)) {
						Thread.sleep(iDelay);
					}
					else {
						Thread.sleep(1000);
					}
                    ReadFuncion(m_dlgMonitor.cboReadFunction.getSelectedIndex());
					
				}
				else {
					Thread.sleep(1000);
				}
			}
			catch (InterruptedException e)
			{
				// TODO: Place exception-handling code here in case an
				//       InterruptedException is thrown by Thread.sleep(),
				//		 meaning that another thread has interrupted this one
				stop();
			}
		}
	}



	// TODO: Place additional applet code here
	
	private void Initializecontrols() 
	{

		//m_dlgMonitor.txtValues.disable();
		//initialize combo read 
		m_dlgMonitor.cboReadFunction.addItem("LoopBackTest");
		m_dlgMonitor.cboReadFunction.addItem("Read Output Registers");
		m_dlgMonitor.cboReadFunction.addItem("Read Input Registers");
		m_dlgMonitor.cboReadFunction.addItem("Read Output Status");
		m_dlgMonitor.cboReadFunction.addItem("Read Input Status");
		m_dlgMonitor.cboReadFunction.select(1);
		//initialize combo write 
		m_dlgMonitor.cboWriteFunction.addItem("Preset Single Register");
        m_dlgMonitor.cboWriteFunction.addItem("Force Single Coil");

		m_dlgMonitor.txtServerAddr.setText(getCodeBase().getHost());
		m_Modbus.Host(getCodeBase().getHost());
		//m_dlgMonitor.txtServerAddr.disable();
		m_dlgMonitor.txtPort.setText("502");
		m_Modbus.Port(502);
		m_dlgMonitor.txtDevice.setText("1");
        m_dlgMonitor.txtValue.setText("0");
		m_dlgMonitor.txtWriteAddr.setText("0");
        m_dlgMonitor.txtQuantity.setText("10");
		m_dlgMonitor.txtAddress.setText("0");
		m_dlgMonitor.txtDelay.setText("1000");

		m_dlgMonitor.cmdDisconnect.disable();

		//old Version Controls 

		//m_dlgMonitor.cmdDisconnect.hide();
		//m_dlgMonitor.cmdConnect.hide();
		m_dlgMonitor.lstValues.hide();

		EnableCancelPollButtons(false);

	}

	private void SetStatusCom(String sText) {
		m_dlgMonitor.lblComErrors.setText(sText);
	}

	private void SetStatusStat(String sText) {
		m_dlgMonitor.lblStat.setText(sText);
	}

	public boolean action (Event evt,Object obj){
		
		boolean bEvent;

		bEvent=false;
        
		if (evt.target.equals(m_dlgMonitor.cmdConnect)) {
			//connect 
			Connect();
		}
		
		else if (evt.target.equals(m_dlgMonitor.cmdDisconnect)) {
			
			//Stop Modbus 
			if (m_Modbus.IsConnected()){
				m_Modbus.closeConnection();
			}
			StopPoll();
			m_dlgMonitor.cmdDisconnect.disable();
			m_dlgMonitor.cmdConnect.enable();
			
		}
		else if (evt.target.equals(m_dlgMonitor.cmdStart)) {
		    StartPoll();
		}
		else if (evt.target.equals(m_dlgMonitor.cmdCancel)) {
		    StopPoll();
		}
		else if (evt.target.equals(m_dlgMonitor.cmdWrite)) {
		    WriteFunction();
		}
		else {
			return (super.action(evt,obj));
		}
		
		return (true); 
	}

	private void Connect() {
	
		String sServerAddr;
		int    iPort=0; 

		sServerAddr=m_dlgMonitor.txtServerAddr.getText(); //getCodeBase().getHost();

		try {
		
			iPort=(Integer.valueOf(m_dlgMonitor.txtPort.getText())).intValue();
		}
		catch (NumberFormatException e){
			SetStatusCom("Invalid Port Number");
			
		}
		if (!m_Modbus.openConnection(sServerAddr,iPort,5000)){
			SetStatusCom("openConnection Failed");
						
		}
		else {
			SetStatusCom("");
			m_dlgMonitor.cmdDisconnect.enable();
			m_dlgMonitor.cmdConnect.disable();
		}
		

	}

	//process write event 
	private void WriteFunction() {
		
		short nAddress;
		short nValue;
		short nError=0;
		short nDevice;
        
	//	if (!m_Modbus.IsConnected()){
	//		SetStatusCom("Not Connected");
	//		return;
	//	}

	
        nAddress=(short)atoi(m_dlgMonitor.txtWriteAddr.getText());
		nValue=(short)atoi(m_dlgMonitor.txtValue.getText());
        nDevice=(short)atoi(m_dlgMonitor.txtDevice.getText()); 

        switch (m_dlgMonitor.cboWriteFunction.getSelectedIndex()) {

		case PRESET_SINGLE_REGISTER:

			nError=m_Modbus.PresetSingleRegister(nDevice,(int)nAddress,nValue);
			break;
		case FORCE_SINGLE_COIL:

            nError=m_Modbus.ForceSingleCoil(nDevice,nAddress,(nValue!=0));
			break;
			
			
		}
		
	
		if (Modbus.ERR_OK !=nError) {
			SetStatusCom("Write Failed");
			  
		}
		else {
		    SetStatusCom("Ok"); 
		}
	
	}

	private int atoi(String sNumber) {
		int iNumber;
		
        try {
			iNumber=(Integer.valueOf(sNumber)).intValue();
		}
		catch (NumberFormatException e){
			
			iNumber=0;
		}

		return iNumber;
	}

    private void StartPoll() 
	{
		if ((!m_Modbus.IsConnected())&&(!m_Modbus.ReConnectOnEveryMessage())){
			SetStatusCom("Not Connected");
			return;
		}
		m_lNumPolls=0;
		m_lNumErrors=0;
        m_bPollActive=true;
		EnableCancelPollButtons(true);
	}

	private void StopPoll() 
	{
		EnableCancelPollButtons(false);
		m_bPollActive=false;

	}

	private void EnableCancelPollButtons(boolean bEnable) {
	    
		if (bEnable) {
			m_dlgMonitor.cmdCancel.enable();  
			m_dlgMonitor.cmdStart.disable();
		}
		else {
		   m_dlgMonitor.cmdCancel.disable();  
		   m_dlgMonitor.cmdStart.enable();
		}


	}

	private void ReadFuncionOld(int iFunction) {
		
		short nError=0;
		short nDevice;
		short nQuantity;
		int nAddress;
		short anRegValues[];
		boolean abCoilValues[];
		String sStat;
		String sValues="";
		String sText="";
		int i;
        long  lInitialTime;
		long  lDuration=0; 
		char cValue;
		int iListCount; 
		int iSelectedItem=-1;

		nAddress=atoi(m_dlgMonitor.txtAddress.getText());
		nQuantity=(short)atoi(m_dlgMonitor.txtQuantity.getText());
        nDevice=(short)atoi(m_dlgMonitor.txtDevice.getText()); 
        anRegValues=new short[0];
		abCoilValues=new boolean[0];

		iListCount=m_dlgMonitor.lstValues.countItems();
	
		if (nQuantity>iListCount) {
			for(i=1;i<=(nQuantity-iListCount);i++){
				m_dlgMonitor.lstValues.addItem(" ");
			}
		}

		if (nQuantity<iListCount) {
			m_dlgMonitor.lstValues.delItems(nQuantity,iListCount-1);
		} 

		m_Modbus.ThrowCommException(false);

		switch (iFunction) {
				
		case LOOPBACK_TEST:
            lInitialTime=System.currentTimeMillis();
			try{
				nError=m_Modbus.LoopbackTest(nDevice);
			}
			catch (ModbusException mbExcetion) {
				nError=(short)mbExcetion.ErrorNumber();
				
			}
			lDuration=System.currentTimeMillis()-lInitialTime;
			anRegValues=new short[0];
			abCoilValues=new boolean[0];
            break;
		case READ_OUTPUT_REGISTERS:
			lInitialTime=System.currentTimeMillis();
			anRegValues=new short[nQuantity];
			abCoilValues=new boolean[0];
			nError=m_Modbus.ReadOutputRegisters(nDevice,  (short)nAddress , nQuantity , anRegValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
		case READ_INPUT_REGISTERS:
			lInitialTime=System.currentTimeMillis();
			anRegValues=new short[nQuantity];
			abCoilValues=new boolean[0];
			nError=m_Modbus.ReadInputRegisters(nDevice,  (short)nAddress , nQuantity , anRegValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
		case READ_OUTPUT_STATUS:
			lInitialTime=System.currentTimeMillis();
			abCoilValues=new boolean[nQuantity];
            anRegValues=new short[0];;
			nError=m_Modbus.ReadOutputStatus(nDevice,  (short)nAddress , nQuantity , abCoilValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
		case READ_INPUT_STATUS:
			lInitialTime=System.currentTimeMillis();
			abCoilValues=new boolean[nQuantity];
            anRegValues=new short[0];
			nError=m_Modbus.ReadInputStatus(nDevice,  (short)nAddress , nQuantity , abCoilValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
			
			
		}

		m_lNumPolls++;
		if (Modbus.ERR_OK!=nError) {
			m_lNumErrors++;
		}

		if (anRegValues.length!=0) {
			
			iSelectedItem=m_dlgMonitor.lstValues.getSelectedIndex();
			
			for (i=0;i<anRegValues.length;i++){
				sValues="["+(nAddress+i)+"]="
						  + anRegValues[i]  //short 
					      + " " + (int)(char)anRegValues[i]  //unsigned short  
						  + " 0x"+Integer.toHexString((char)anRegValues[i]); //hex 
			
				cValue=(char)anRegValues[i];
				if (cValue!=0) {
					sValues+= " " + cValue;  //unsigned short 
				}
				m_dlgMonitor.lstValues.replaceItem(sValues,i);
				
			}

			if (iSelectedItem>=0) {
				m_dlgMonitor.lstValues.select(iSelectedItem);
			}
			
		
		
		}
	
		if (abCoilValues.length!=0) {
			
			iSelectedItem=m_dlgMonitor.lstValues.getSelectedIndex();

			for (i=0;i<abCoilValues.length;i++){
				sValues="["+(nAddress+i)+"]="+abCoilValues[i];
				m_dlgMonitor.lstValues.replaceItem(sValues,i);
			}

			if (iSelectedItem>=0) {
				m_dlgMonitor.lstValues.select(iSelectedItem);
			}
			
		
		}


		SetStatusStat(m_lNumPolls+" Errors="+m_lNumErrors + " "+lDuration + "(ms)");
	
	}

	private void ReadFuncion(int iFunction) {
		
		short nError=0;
		short nDevice;
		short nQuantity;
		int nAddress;
		short anRegValues[];
		boolean abCoilValues[];
		String sStat;
		String sValues="";
		String sText="";
		int i;
        long  lInitialTime;
		long  lDuration=0; 
		char cValue;
		

		nAddress=atoi(m_dlgMonitor.txtAddress.getText());
		nQuantity=(short)atoi(m_dlgMonitor.txtQuantity.getText());
        nDevice=(short)atoi(m_dlgMonitor.txtDevice.getText()); 
        anRegValues=new short[0];
		abCoilValues=new boolean[0];

	
		m_Modbus.ThrowCommException(false);

		switch (iFunction) {
				
		case LOOPBACK_TEST:
            lInitialTime=System.currentTimeMillis();
			try{
				nError=m_Modbus.LoopbackTest(nDevice);
			}
			catch (ModbusException mbExcetion) {
				nError=(short)mbExcetion.ErrorNumber();
				
			}
			lDuration=System.currentTimeMillis()-lInitialTime;
			anRegValues=new short[0];
			abCoilValues=new boolean[0];
            break;
		case READ_OUTPUT_REGISTERS:
			lInitialTime=System.currentTimeMillis();
			anRegValues=new short[nQuantity];
			abCoilValues=new boolean[0];
			nError=m_Modbus.ReadOutputRegisters(nDevice,  (short)nAddress , nQuantity , anRegValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
		case READ_INPUT_REGISTERS:
			lInitialTime=System.currentTimeMillis();
			anRegValues=new short[nQuantity];
			abCoilValues=new boolean[0];
			nError=m_Modbus.ReadInputRegisters(nDevice,  (short)nAddress , nQuantity , anRegValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
		case READ_OUTPUT_STATUS:
			lInitialTime=System.currentTimeMillis();
			abCoilValues=new boolean[nQuantity];
            anRegValues=new short[0];;
			nError=m_Modbus.ReadOutputStatus(nDevice,  (short)nAddress , nQuantity , abCoilValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
		case READ_INPUT_STATUS:
			lInitialTime=System.currentTimeMillis();
			abCoilValues=new boolean[nQuantity];
            anRegValues=new short[0];
			nError=m_Modbus.ReadInputStatus(nDevice,  (short)nAddress , nQuantity , abCoilValues);
			lDuration=System.currentTimeMillis()-lInitialTime;
			break;
			
			
		}

		m_lNumPolls++;
		if (Modbus.ERR_OK!=nError) {
			m_lNumErrors++;
		}

		if (anRegValues.length!=0) {
			
			for (i=0;i<anRegValues.length;i++){
				sValues="["+(nAddress+i)+"]="
						  + anRegValues[i]  //short 
					      + " " + (int)(char)anRegValues[i]  //unsigned short  
						  + " 0x"+Integer.toHexString((char)anRegValues[i]); //hex 
			
				cValue=(char)anRegValues[i];
				if (cValue!=0) {
					sValues+= " " + cValue;  //unsigned short 
				}
				sText+="\n"+sValues;
				
			}

			
		
		
		}
	
		if (abCoilValues.length!=0) {
			
			for (i=0;i<abCoilValues.length;i++){
				sValues="["+(nAddress+i)+"]="+abCoilValues[i];
				sText+="\n"+sValues;
			}

					
		}

        
		m_dlgMonitor.txtValues. setText(sText);

		SetStatusStat(m_lNumPolls+" Errors="+m_lNumErrors + " "+lDuration + "(ms)");
	
	}


}
