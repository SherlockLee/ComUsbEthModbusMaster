package FreeModbus.Util;

import java.lang.Exception;

//
//
// ModbusException
//
//


public class ModbusException extends RuntimeException
{
	
	public ModbusException() { 
		super(); 
	}
	
	
	public ModbusException(String s, int iErrorNumber) { 

		super(s); 
		m_iErrorNumber = iErrorNumber;
	}

	public int ErrorNumber() {
		return m_iErrorNumber;
	}

	private int m_iErrorNumber;
	
}

