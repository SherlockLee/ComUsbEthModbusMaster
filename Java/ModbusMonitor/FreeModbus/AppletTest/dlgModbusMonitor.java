//------------------------------------------------------------------------------
// dlgModbusMonitor.java:
//		Implementation of "control creator" class dlgModbusMonitor
//------------------------------------------------------------------------------
import java.awt.*;
import DialogLayout;

public class dlgModbusMonitor
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
	TextField     txtValues;
	Label         lblServStatus;
	Label         lblComErrors;
	Label         lblStat;
	Choice        cboReadFunction;
	Label         lblServReadFunction;
	Button        cmdUpdateRead;
	Label         lblAddress;
	TextField     txtAddress;
	Label         lblQuantity;
	TextField     txtQuantity;


	// Constructor
	//--------------------------------------------------------------------------
	public dlgModbusMonitor (Container parent)
	{
		m_Parent = parent;
	}

	// Initialization.
	//--------------------------------------------------------------------------
	public boolean CreateControls()
	{
		// CreateControls should be called only once
		//----------------------------------------------------------------------
		if (m_fInitialized || m_Parent == null)
			return false;

		// m_Parent must be extended from the Container class
		//----------------------------------------------------------------------
		if (!(m_Parent instanceof Container))
			return false;

		// Since a given font may not be supported across all platforms, it
		// is safe to modify only the size of the font, not the typeface.
		//----------------------------------------------------------------------
	    Font OldFnt = m_Parent.getFont();
	    if (OldFnt != null)
	    {
			Font NewFnt = new Font(OldFnt.getName(), OldFnt.getStyle(), 8);

    		m_Parent.setFont(NewFnt);
	    }

		// All position and sizes are in dialog logical units, so we use a
		// DialogLayout as our layout manager.
		//----------------------------------------------------------------------
		m_Layout = new DialogLayout(m_Parent, 367, 165);
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
		m_Layout.setShape(cmdConnect, 104, 26, 50, 11);

		lblServAddress1 = new Label ("Server Address", Label.LEFT);
		m_Parent.add(lblServAddress1);
		m_Layout.setShape(lblServAddress1, 15, 14, 55, 10);

		lblServPort = new Label ("Port", Label.LEFT);
		m_Parent.add(lblServPort);
		m_Layout.setShape(lblServPort, 74, 14, 19, 9);

		txtServerAddr = new TextField ("");
		m_Parent.add(txtServerAddr);
		m_Layout.setShape(txtServerAddr, 15, 25, 48, 13);

		txtPort = new TextField ("");
		m_Parent.add(txtPort);
		m_Layout.setShape(txtPort, 71, 25, 28, 12);

		txtValues = new TextField ("");
		m_Parent.add(txtValues);
		m_Layout.setShape(txtValues, 200, 30, 145, 107);

		lblServStatus = new Label ("Status:", Label.LEFT);
		m_Parent.add(lblServStatus);
		m_Layout.setShape(lblServStatus, 171, 140, 26, 11);

		lblComErrors = new Label ("", Label.LEFT);
		m_Parent.add(lblComErrors);
		m_Layout.setShape(lblComErrors, 200, 141, 145, 11);

		lblStat = new Label ("", Label.LEFT);
		m_Parent.add(lblStat);
		m_Layout.setShape(lblStat, 199, 16, 145, 11);

		cboReadFunction = new Choice ();
		m_Parent.add(cboReadFunction);
		m_Layout.setShape(cboReadFunction, 15, 52, 78, 39);

		lblServReadFunction = new Label ("Read Function", Label.LEFT);
		m_Parent.add(lblServReadFunction);
		m_Layout.setShape(lblServReadFunction, 16, 41, 79, 10);

		cmdUpdateRead = new Button ("Update Data");
		m_Parent.add(cmdUpdateRead);
		m_Layout.setShape(cmdUpdateRead, 104, 53, 50, 11);

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
		m_Layout.setShape(txtQuantity, 117, 69, 34, 12);

		m_fInitialized = true;
		return true;
	}
}
