//------------------------------------------------------------------------------
// ModbusMonitorDlg.java:
//		Implementation for container control initialization class ModbusMonitorDlg
//
// WARNING: Do not modify this file.  This file is recreated each time its
//          associated .rct/.res file is sent through the Java Resource Wizard!
//
// This class can be use to create controls within any container, however, the
// following describes how to use this class with an Applet.  For addtional
// information on using Java Resource Wizard generated classes, refer to the
// Visual J++ 1.1 documention.
//
// 1) Import this class in the .java file for the Applet that will use it:
//
//      import ModbusMonitorDlg;
//
// 2) Create an instance of this class in your Applet's 'init' member, and call
//    CreateControls() through this object:
//
//      ModbusMonitorDlg ctrls = new ModbusMonitorDlg (this);
//      ctrls.CreateControls();
//
// 3) To process events generated from user action on these controls, implement
//    the 'handleEvent' member for your applet:
//
//      public boolean handleEvent (Event evt)
//      {
//
//      }
//
//------------------------------------------------------------------------------
package FreeModbus.AppletTest;

import java.awt.*;
import FreeModbus.AppletTest.DialogLayout;

public class ModbusMonitorDlg
{
	Container    m_Parent       = null;
	boolean      m_fInitialized = false;
	DialogLayout m_Layout;

	// Control definitions
	//--------------------------------------------------------------------------
	Button        cmdConnect;
	Label         lblServAddress1;
	Label         lblServPort;
	TextField     txtServerAddr;
	TextField     txtPort;
	Label         lblServStatus;
	Label         lblComErrors;
	Label         lblStat;
	Choice        cboReadFunction;
	Label         lblServReadFunction;
	Label         lblAddress;
	TextField     txtAddress;
	Label         lblQuantity;
	TextField     txtQuantity;
	Choice        cboWriteFunction;
	Label         lblServWriteFunction;
	Button        cmdWrite;
	Label         lblAddress2;
	TextField     txtWriteAddr;
	Label         lblValue;
	TextField     txtValue;
	Button        cmdStart;
	Button        cmdCancel;
	Button        cmdDisconnect;
	Label         lblDevice;
	TextField     txtDevice;
	TextField     txtDelay;
	Label         lblDelay;
	List          lstValues;
	TextArea      txtValues;


	// Constructor
	//--------------------------------------------------------------------------
	public ModbusMonitorDlg (Container parent)
	{
		m_Parent = parent;
	}

	// Initialization.
	//--------------------------------------------------------------------------
	public boolean CreateControls()
	{
		// Can only init controls once
		//----------------------------------------------------------------------
		if (m_fInitialized || m_Parent == null)
			return false;

		// Parent must be a derivation of the Container class
		//----------------------------------------------------------------------
		if (!(m_Parent instanceof Container))
			return false;

		// Since there is no way to know if a given font is supported from
		// platform to platform, we only change the size of the font, and not
		// type face name.  And, we only change the font if the dialog resource
		// specified a font.
		//----------------------------------------------------------------------
		Font OldFnt = m_Parent.getFont();
		
		if (OldFnt != null)
		{
			Font NewFnt = new Font(OldFnt.getName(), OldFnt.getStyle(), 8);

			m_Parent.setFont(NewFnt);
		}

		// All position and sizes are in Dialog Units, so, we use the
		// DialogLayout manager.
		//----------------------------------------------------------------------
		m_Layout = new DialogLayout(m_Parent, 355, 186);
		m_Parent.setLayout(m_Layout);
		m_Parent.addNotify();

		Dimension size   = m_Layout.getDialogSize();
		Insets    insets = m_Parent.insets();
		
		m_Parent.resize(insets.left + size.width  + insets.right,
                        insets.top  + size.height + insets.bottom);

		// Control creation
		//----------------------------------------------------------------------
		cmdConnect = new Button ("Connect");
		m_Parent.add(cmdConnect);
		m_Layout.setShape(cmdConnect, 85, 28, 50, 11);

		lblServAddress1 = new Label ("Serv. Addr.", Label.LEFT);
		m_Parent.add(lblServAddress1);
		m_Layout.setShape(lblServAddress1, 13, 15, 37, 10);

		lblServPort = new Label ("Port", Label.LEFT);
		m_Parent.add(lblServPort);
		m_Layout.setShape(lblServPort, 28, 28, 19, 9);

		txtServerAddr = new TextField ("");
		m_Parent.add(txtServerAddr);
		m_Layout.setShape(txtServerAddr, 51, 14, 141, 13);

		txtPort = new TextField ("");
		m_Parent.add(txtPort);
		m_Layout.setShape(txtPort, 51, 27, 28, 12);

		lblServStatus = new Label ("Status:", Label.LEFT);
		m_Parent.add(lblServStatus);
		m_Layout.setShape(lblServStatus, 183, 142, 22, 8);

		lblComErrors = new Label ("", Label.LEFT);
		m_Parent.add(lblComErrors);
		m_Layout.setShape(lblComErrors, 225, 141, 93, 11);

		lblStat = new Label ("", Label.LEFT);
		m_Parent.add(lblStat);
		m_Layout.setShape(lblStat, 214, 15, 104, 11);

		cboReadFunction = new Choice ();
		m_Parent.add(cboReadFunction);
		m_Layout.setShape(cboReadFunction, 87, 52, 103, 39);

		lblServReadFunction = new Label ("Read Function", Label.LEFT);
		m_Parent.add(lblServReadFunction);
		m_Layout.setShape(lblServReadFunction, 88, 41, 79, 10);

		lblAddress = new Label ("Address:", Label.LEFT);
		m_Parent.add(lblAddress);
		m_Layout.setShape(lblAddress, 15, 71, 29, 9);

		txtAddress = new TextField ("");
		m_Parent.add(txtAddress);
		m_Layout.setShape(txtAddress, 45, 70, 36, 12);

		lblQuantity = new Label ("Quantity:", Label.LEFT);
		m_Parent.add(lblQuantity);
		m_Layout.setShape(lblQuantity, 87, 71, 31, 9);

		txtQuantity = new TextField ("");
		m_Parent.add(txtQuantity);
		m_Layout.setShape(txtQuantity, 123, 69, 34, 12);

		cboWriteFunction = new Choice ();
		m_Parent.add(cboWriteFunction);
		m_Layout.setShape(cboWriteFunction, 14, 97, 106, 39);

		lblServWriteFunction = new Label ("Write Function", Label.LEFT);
		m_Parent.add(lblServWriteFunction);
		m_Layout.setShape(lblServWriteFunction, 15, 86, 79, 10);

		cmdWrite = new Button ("Write");
		m_Parent.add(cmdWrite);
		m_Layout.setShape(cmdWrite, 129, 97, 50, 11);

		lblAddress2 = new Label ("Address:", Label.LEFT);
		m_Parent.add(lblAddress2);
		m_Layout.setShape(lblAddress2, 14, 116, 29, 9);

		txtWriteAddr = new TextField ("");
		m_Parent.add(txtWriteAddr);
		m_Layout.setShape(txtWriteAddr, 44, 115, 36, 12);

		lblValue = new Label ("Value:", Label.LEFT);
		m_Parent.add(lblValue);
		m_Layout.setShape(lblValue, 91, 116, 22, 9);

		txtValue = new TextField ("");
		m_Parent.add(txtValue);
		m_Layout.setShape(txtValue, 116, 114, 34, 12);

		cmdStart = new Button ("Start");
		m_Parent.add(cmdStart);
		m_Layout.setShape(cmdStart, 13, 138, 38, 10);

		cmdCancel = new Button ("Cancel");
		m_Parent.add(cmdCancel);
		m_Layout.setShape(cmdCancel, 53, 138, 35, 10);

		cmdDisconnect = new Button ("Disconnect");
		m_Parent.add(cmdDisconnect);
		m_Layout.setShape(cmdDisconnect, 141, 28, 50, 11);

		lblDevice = new Label ("Device", Label.LEFT);
		m_Parent.add(lblDevice);
		m_Layout.setShape(lblDevice, 15, 54, 25, 9);

		txtDevice = new TextField ("");
		m_Parent.add(txtDevice);
		m_Layout.setShape(txtDevice, 43, 52, 35, 13);

		txtDelay = new TextField ("");
		m_Parent.add(txtDelay);
		m_Layout.setShape(txtDelay, 145, 138, 28, 14);

		lblDelay = new Label ("Delay (ms)", Label.LEFT);
		m_Parent.add(lblDelay);
		m_Layout.setShape(lblDelay, 101, 141, 34, 10);

		lstValues = new List (1, false);
		m_Parent.add(lstValues);
		m_Layout.setShape(lstValues, 297, 67, 43, 14);

		txtValues = new TextArea ("");
		m_Parent.add(txtValues);
		m_Layout.setShape(txtValues, 215, 37, 103, 94);

		m_fInitialized = true;
		return true;
	}
}
