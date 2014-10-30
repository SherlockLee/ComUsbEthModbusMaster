//
//Modbus class to ccomunicate with modbus server 
//
package FreeModbus.Util;

import java.io.*;
import java.net.*;
import java.lang.Exception;
import FreeModbus.Util.ModbusException;



public  class Modbus 

{
	
	private Socket m_connection;
	private DataInputStream m_istream; //input buffer 
	private DataOutputStream m_ostream; //output buffer 
	private final int OUTPUT_BUFFER_SIZE=512; 
	private int m_iTimeOut=10000;      //Max Time out
	private boolean m_bIsConnected=false;
	private boolean m_bReConnectOnEveryMessage=false;
	private int m_iRetries=1;
	private boolean m_bThrowCommException=false;

	//internet frame 
	private final int MBAP_HEADER_SIZE=6;
	private final int OFFSET_MODBUS_MESS=6;

	//Modbus Functions 
	private static final  byte READ_OUTPUT_REGISTERS=3; 
	private static final  byte READ_INPUT_REGISTERS=4;
	private static final byte READ_OUTPUT_STATUS=1;
	private static final byte READ_INPUT_STATUS=2;
	private static final byte PRESET_MULTIPLE_REGISTERS=16;
	private static final byte PRESET_SINGLE_REGISTER=6;
	private static final byte LOOP_BACK_TEST=8;
	private static final byte FORCE_SINGLE_COIL=5;
	private static final byte FORCE_MULTIPLE_COILS=15;
	
	//Errors 
	
	public static final short  ERR_OK = 0; //No Error
	public static final short  ERR_TIMEOUT = 1;
	public static final short  ERR_EXECPTION=9000;
	public static final short  ERR_INVALID_RESPONSE=12;
	public static final short  ERR_MODBUS_EXCPTION=8000; //Excption 1->8001 , 2->8002...
    
	//General Constants 
	
	public static final int REAL_NORMAL=0;
    public static final int REAL_REVERSE=1;
	
	/*  TCP/IP settings. */
	private String m_sAddress="127.0.0.1"; //
	private int m_iPort=502;
	
	
		
	//constructor
	public Modbus(){
		m_iRetries=1;
	}
	

	public int Retries() {

		return m_iRetries;
	}

	public void Retries(int iRetries) {

		m_iRetries=iRetries;
	}

	public boolean ThrowCommException() {
		return m_bThrowCommException;
	}
	
	public void ThrowCommException(boolean bThrow) {
		m_bThrowCommException = bThrow;
	}

	
	public String ErrorMessage(int iErrorNumber) {
		String sMsg="";

		sMsg = sMsg + " #" + iErrorNumber;
		return sMsg;
	}

	private void ThrowException (int iNumber) {
		
		if (m_bThrowCommException && (iNumber!=ERR_OK)) {
			throw  new ModbusException(ErrorMessage(iNumber), iNumber);			
		}
	}

	public boolean ReConnectOnEveryMessage() {

		return m_bReConnectOnEveryMessage;
	}



	public void ReConnectOnEveryMessage(boolean bReConnectOnEveryMessage) {

		m_bReConnectOnEveryMessage=bReConnectOnEveryMessage;

	}

    public void Host(String sHost) {
		
        m_sAddress = sHost;
	}

	public String Host() {
		
        return m_sAddress;
	}

	public int Port() {

       return m_iPort;
	}

	public void Port(int iPort) {

      m_iPort = iPort;
	}

	// Method to close the network connection.
	public void closeConnection()
	{
		try {
			m_istream.close();
			m_ostream.close();
			m_connection.close();
			m_bIsConnected=false;
		}
		catch(IOException e) { 
			System.err.println("Connection close with Modbus server failed.");
		}
	} // End closeConnection().
	
	
	// Method for connecting to the Modbus Server. 
	public boolean openConnection(String host, int port, int iTimeOut)
	{

		if (IsConnected()) {
			closeConnection();
		}

		try
		{
			m_sAddress=host;
			m_iPort=port;
			m_iTimeOut=iTimeOut;

			m_connection = new Socket(host, port);
			

			//Input buffer 
			m_istream = new DataInputStream(new
				BufferedInputStream(m_connection.getInputStream()));
			
			//output buffer 
			m_ostream = new DataOutputStream(new
				BufferedOutputStream(m_connection.getOutputStream(),OUTPUT_BUFFER_SIZE));
			
			m_iTimeOut=iTimeOut;
			m_bIsConnected=true;
			return(true);
		}
		catch (IOException e) {
			System.err.println("Could not open connection to Modbus server.");
			m_bIsConnected=false;
			return(false);
		}
	}//end open connection 
	
	public boolean IsConnected(){
		return(m_bIsConnected);
	}
	
	public  short ReadOutputRegisters(short nAddr,  int nDataStart , short nQtd , short anRegValues[]) {
		
		short QUERY_LENGHT=6;
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(3 + 2 * nQtd);
		int  aiReply[]  = new int[nReplyLength+MBAP_HEADER_SIZE];
		short nError;
		short nByte;
		short nRespByte;
		int iRetry;
			
		//Query 
		InsertMBAPHeader(abyQuery ,QUERY_LENGHT);
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=READ_OUTPUT_REGISTERS; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nQtd);
		

		iRetry=0;
		
		do {
			
			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			if (nError==ERR_OK) {
				if (((byte)aiReply[0]!=abyQuery[OFFSET_MODBUS_MESS+0])||((byte)aiReply[1]!=abyQuery[OFFSET_MODBUS_MESS+1])) {
					nError=ERR_INVALID_RESPONSE;
				}
				else {
					nByte=0;//return array 
					for(nRespByte=3;nRespByte<nReplyLength;nRespByte=(short)(nRespByte+2)){
						anRegValues[nByte] = (short)(aiReply[nRespByte]);
						anRegValues[nByte]=(short)((anRegValues[nByte]<<8)|(aiReply[nRespByte+1]));
						nByte++;
					}
					
				}
				
				
			}//nerror=ERR_OK
			iRetry++;
			
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);

		return(nError);
		
	}//end ReadOutRegisters 
	
	
	public  short ReadOutputRegisters(short nAddr,  int nDataStart , short nQtd , int aiRegValues[]) {
		
		
		short anRegValues[];
		short nError ;
		
		anRegValues=new short[aiRegValues.length];
		nError = ReadOutputRegisters(nAddr,nDataStart ,nQtd ,anRegValues);
		ShortToIntArray(anRegValues,aiRegValues);
		return nError;
		
		
	}

	public short ReadOutputRegisters(short nAddr,  int nDataStart , short nQtd , float afRegValues[], int nRealType ) {
	
		
	 short anValues[];
	 short nError;

	 anValues = new short[2*afRegValues.length];
	 
	 nError =ReadOutputRegisters(nAddr,nDataStart,(short)(2*nQtd),anValues);
	 ShortToFloatArray(anValues,afRegValues,nRealType);
	
	 return nError;
	
	}

	public short ReadOutputRegisters(short nAddr,  int nDataStart , short nQtd , double adRegValues[], int nRealType ) {
	
		
	 short anValues[];
	 short nError;

	 anValues = new short[4*adRegValues.length];
	 
	 nError =ReadOutputRegisters(nAddr,nDataStart,(short)(4*nQtd),anValues);
	 ShortToDoubleArray(anValues,adRegValues,nRealType);
	 return nError;
	
	}
	
	
	public short ReadInputRegisters(short nAddr,  int nDataStart , short nQtd , short anRegValues[]) {
		
		byte abyQuery[]= new byte[6+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(3 + 2 * nQtd);
		int  aiReply[]  = new int[nReplyLength+MBAP_HEADER_SIZE];
		short nError;
		short nByte;
		short nRespByte;
		short QUERY_LENGHT=6;
		int iRetry;
		
		
		//Query 
		InsertMBAPHeader(abyQuery,QUERY_LENGHT);
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=READ_INPUT_REGISTERS; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nQtd);
		

		iRetry=0;
		
		do {
			
			nError=TxRxMessage(abyQuery,(short)(6+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			if (nError==ERR_OK) {
				if (((byte)aiReply[0]!=abyQuery[OFFSET_MODBUS_MESS+0])||((byte)aiReply[1]!=abyQuery[OFFSET_MODBUS_MESS+1])) {
					nError=ERR_INVALID_RESPONSE;
				}
				else {
					nByte=0;//return array 
					for(nRespByte=3;nRespByte<nReplyLength;nRespByte=(short)(nRespByte+2)){
						anRegValues[nByte] = (short)(aiReply[nRespByte]);
						anRegValues[nByte]=(short)((anRegValues[nByte]<<8)|(aiReply[nRespByte+1]));
						nByte++;
					}
					
				}
				
				
			}//nerror=ERR_OK
			
			iRetry++;

		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);

		return(nError);
		
	}//end ReadInputRegisters 
	
	
	public short ReadInputRegisters(short nAddr,  int nDataStart , short nQtd , int aiRegValues[]) {
		
		
		short anRegValues[];
		short nError ;
		
		anRegValues=new short[aiRegValues.length];
		nError = ReadInputRegisters(nAddr,nDataStart ,nQtd ,anRegValues);
		ShortToIntArray(anRegValues,aiRegValues);
		return nError;
		
		
	}

	public short ReadInputRegisters(short nAddr,  int nDataStart , short nQtd , float afRegValues[], int nRealType ) {
	
		
	 short anValues[];
	 short nError;

	 anValues = new short[2*afRegValues.length];
	 
	 nError =ReadInputRegisters(nAddr,nDataStart,(short)(2*nQtd),anValues);
	 ShortToFloatArray(anValues,afRegValues,nRealType);
	
	 return nError;
	
	}

	public short ReadInputRegisters(short nAddr,  int nDataStart , short nQtd , double adRegValues[], int nRealType ) {
	
		
	 short anValues[];
	 short nError;

	 anValues = new short[4*adRegValues.length];
	 
	 nError =ReadInputRegisters(nAddr,nDataStart,(short)(4*nQtd),anValues);
	 ShortToDoubleArray(anValues,adRegValues,nRealType);
	 return nError;
	
	}
	
	public short ReadOutputStatus(short nAddr,  int nDataStart , short nQtd , boolean abCoilValues[]) {
		
		short QUERY_LENGHT=6;
		
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(3 + (nQtd + 7) / 8);
		int  aiReply[]  = new int[nReplyLength+MBAP_HEADER_SIZE];
		short nError;
		short nRespByte;
		int iCoil;
		int iBit;
		int iRetry;
		
		
		//Query 
		InsertMBAPHeader(abyQuery,QUERY_LENGHT);
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=READ_OUTPUT_STATUS; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nQtd);

		
		iRetry=0;
		
		do {
			
			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			if (nError==ERR_OK) {
				if (((byte)aiReply[0]!=abyQuery[OFFSET_MODBUS_MESS+0])||((byte)aiReply[1]!=abyQuery[OFFSET_MODBUS_MESS+1])) {
					nError=ERR_INVALID_RESPONSE;
				}
				else {
					iBit=0;
					nRespByte=3;		
					for(iCoil=0;iCoil<nQtd;iCoil++){
						
						if (iBit>7){
							iBit=0;
							nRespByte++;
						}
						
						if ((aiReply[nRespByte] & (0x01<<iBit))>0){
							abCoilValues[iCoil]= true; 
						}
						else {
							abCoilValues[iCoil]= false; 
						}
						iBit++; //next bit 
						
					}// end for 
					
				}// else 
				
				
			}//nerror=ERR_OK
			iRetry++;
			
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);

		return(nError);
		
	}//end ReadOutStatus 
	
	
	public short ReadInputStatus(short nAddr,  int nDataStart , short nQtd , boolean abCoilValues[]) {
		
		short QUERY_LENGHT=6;
		
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(3 + (nQtd + 7) / 8);
		int  aiReply[]  = new int[nReplyLength+MBAP_HEADER_SIZE];
		short nError;
		short nRespByte;
		int iCoil;
		int iBit;
		int iRetry;
		
		
		//Query 
		InsertMBAPHeader(abyQuery,QUERY_LENGHT);


		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=READ_INPUT_STATUS; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nQtd);
		

		iRetry=0;
		
		do {
			
			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			if (nError==ERR_OK) {
				if (((byte)aiReply[0]!=abyQuery[OFFSET_MODBUS_MESS+0])||((byte)aiReply[1]!=abyQuery[OFFSET_MODBUS_MESS+1])) {
					nError=ERR_INVALID_RESPONSE;
				}
				else {
					iBit=0;
					nRespByte=3;		
					for(iCoil=0;iCoil<nQtd;iCoil++){
						
						if (iBit>7){
							iBit=0;
							nRespByte++;
						}
						
						if ((aiReply[nRespByte] & (0x01<<iBit))>0){
							abCoilValues[iCoil]= true; 
						}
						else {
							abCoilValues[iCoil]= false; 
						}
						iBit++; //next bit 
						
					}// end for 
					
				}// else 
				
				
			}//nerror=ERR_OK
			iRetry++;
			
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);
		
		return(nError);
		
	}//end ReadOutStatus 
	
	
	
	public short PresetMultipleRegisters(short nAddr,  int nDataStart , short nQtd , short anRegValues[]) {
		
		
		short QUERY_LENGHT=(short)(7+2*nQtd);
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(6);
		int  aiReply[]  = new int[nReplyLength];
		short nError;
		short nByte;
		short nRespByte;
		int	  iReg; 	
		
		int iRetry;
		
		
		//Query 
		InsertMBAPHeader(abyQuery,QUERY_LENGHT);
				
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=PRESET_MULTIPLE_REGISTERS; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+6]=(byte)(2*nQtd);
		
		for (iReg=0;iReg<(nQtd);iReg++){
			abyQuery[OFFSET_MODBUS_MESS+7+iReg*2]=HiByte(anRegValues[iReg]);
			abyQuery[OFFSET_MODBUS_MESS+7+iReg*2+1]=LoByte(anRegValues[iReg]);
		}
		
		
		iRetry=0;

		do {

			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply,nReplyLength);
			
			
			if (nError==ERR_OK) {
				
				for (iReg=0;iReg<6;iReg++){
					if ((byte)aiReply[iReg]!=abyQuery[OFFSET_MODBUS_MESS+iReg]) {
						nError=ERR_INVALID_RESPONSE;
						break;
					}
				}
				
			}//nerror=ERR_OK

			iRetry++;
			
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));
		
		ThrowException(nError);

		return(nError);
		
	}//end ReadOutRegisters 
	
	
	
	public short PresetMultipleRegisters(short nAddr,  int nDataStart , short nQtd , int aiRegValues[]) {
		
		short anRegValues[];
		short nError;
		
		anRegValues=new short[aiRegValues.length];
		IntToShortArray(aiRegValues,anRegValues);
		return PresetMultipleRegisters(nAddr,nDataStart ,nQtd ,anRegValues);
		
	}

	public short PresetMultipleRegisters(short nAddr,  int nDataStart , short nQtd , float afRegValues[],int nRealType) {
		
		short anRegValues[];
		short nError;
		
		anRegValues=new short[nQtd*2];
		FloatToShortArray(afRegValues,anRegValues,nRealType);
		return PresetMultipleRegisters(nAddr,nDataStart ,(short)(nQtd*2) ,anRegValues);
		
	}

	
	public short PresetMultipleRegisters(short nAddr,  int nDataStart , short nQtd , double adRegValues[],int nRealType) {
		
		short anRegValues[];
		short nError;
		
		anRegValues=new short[nQtd*4];
		DoubleToShortArray(adRegValues,anRegValues,nRealType);
		return PresetMultipleRegisters(nAddr,nDataStart ,(short)(nQtd*4) ,anRegValues);
		
	}
	
	
	public short PresetSingleRegister(short nAddr,  int nRegister , short nRegValue) {
		
		
		short QUERY_LENGHT=(short)(6);
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(6);
		int  aiReply[]  = new int[nReplyLength+MBAP_HEADER_SIZE];
		short nError;
		short nByte;
		short nRespByte;
		int	  iReg; 	
		int iRetry;
		
		
		//Query 
		InsertMBAPHeader(abyQuery,QUERY_LENGHT);
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=PRESET_SINGLE_REGISTER; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nRegister);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nRegister);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nRegValue);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nRegValue);
		
		iRetry=0;
		
		do {
			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			
			if (nError==ERR_OK) {
				
				for (iReg=0;iReg<QUERY_LENGHT;iReg++){
					if ((byte)aiReply[iReg]!=abyQuery[OFFSET_MODBUS_MESS+iReg]) {
						nError=ERR_INVALID_RESPONSE;
						break;
					}
				}
				
			}//nerror=ERR_OK
			iRetry++;
			
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);

		return(nError);
		
	}//end PresetSingleRegister
	
	public short PresetSingleRegister(short nAddr,  int nRegister , int iRegValue) {
	
		return PresetSingleRegister(nAddr,nRegister ,(short)iRegValue);
	
	}

	public short PresetSingleRegister(short nAddr,  int nRegister ,float fRegValue,int nRealType) {
		
	    float afRegs[] = new float[1];
	
		afRegs[0] = fRegValue;

		return PresetMultipleRegisters(nAddr,nRegister ,(short)(1) ,afRegs,nRealType);
		
	}

	public short PresetSingleRegister(short nAddr,  int nRegister ,double dRegValue,int nRealType) {
		
	    double adRegs[] = new double[1];
	
		adRegs[0] = dRegValue;

		return PresetMultipleRegisters(nAddr,nRegister ,(short)(1) ,adRegs,nRealType);
		
	}

	public short LoopbackTest(short nAddr) throws ModbusException {
		
		
		short QUERY_LENGHT=(short)(6);
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(6+MBAP_HEADER_SIZE);
		int  aiReply[]  = new int[nReplyLength];
		short nError;
		int	  iReg; 	
		short nQueryLenght = (short)(QUERY_LENGHT+MBAP_HEADER_SIZE);
		int iRetry;
		
		iReg=0;
	
		//Query 
		InsertMBAPHeader(abyQuery ,QUERY_LENGHT);
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=LOOP_BACK_TEST; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte((short)0); //diag. code=0
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte((short)0);
		abyQuery[OFFSET_MODBUS_MESS+4]=(byte)System.currentTimeMillis();
		abyQuery[OFFSET_MODBUS_MESS+5]=(byte)System.currentTimeMillis();
		
		iRetry=0;

		do {
			nError=TxRxMessage(abyQuery,nQueryLenght,aiReply, nReplyLength);
			
			
			if (nError==ERR_OK) {
				
				for (iReg=0;iReg<QUERY_LENGHT;iReg++){
					if ((byte)aiReply[iReg]!=abyQuery[OFFSET_MODBUS_MESS+iReg]) {
						nError=ERR_INVALID_RESPONSE;
						break;
					}
				}
				
			}//nerror=ERR_OK
			
			iRetry++;

		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);

		return(nError);
		
	}//end LoopBackTest
	
	
	public short ForceSingleCoil(short nAddr, int nRegister, boolean bCoilValue) {
		
		
		short QUERY_LENGHT=(short)(6);
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(6);
		int  aiReply[]  = new int[nReplyLength+MBAP_HEADER_SIZE];
		short nError;
		int	  iReg; 	
		
		int iRetry;
		
		
		//Query 
		InsertMBAPHeader(abyQuery,QUERY_LENGHT);
		
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=FORCE_SINGLE_COIL; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nRegister); //diag. code=0
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nRegister);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(CmodBool(bCoilValue));
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(CmodBool(bCoilValue));
		
		
		iRetry=0;
		
		do {
			
			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			
			if (nError==ERR_OK) {
				
				for (iReg=0;iReg<QUERY_LENGHT;iReg++){
					if ((byte)aiReply[iReg]!=abyQuery[OFFSET_MODBUS_MESS+iReg]) {
						nError=ERR_INVALID_RESPONSE;
						break;
					}
				}
				
			}//nerror=ERR_OK
			iRetry++;
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));


		ThrowException(nError);

		return(nError);
		
	}//end ForceSingleCoil 
	
	
	public short ForceMultipleCoils(short nAddr,  int nDataStart , short nQtd , boolean abCoilValues[]) {
		
		
		short QUERY_LENGHT=(short)(7+(nQtd + 7)/8);
		byte abyQuery[]= new byte[QUERY_LENGHT+MBAP_HEADER_SIZE];
		short nReplyLength=(short)(6);
		int  aiReply[]  = new int[nReplyLength];
		short nError;
		short nByte;
		short nQueryByte;
		int	  iCoil; 
		int   iBit;
		int   iReg;
		int iRetry;
		
		
		
		
		//Query 
		InsertMBAPHeader(abyQuery ,QUERY_LENGHT);
		
		//modbus message 
		abyQuery[OFFSET_MODBUS_MESS+0]=(byte)nAddr; //ADDR	
		abyQuery[OFFSET_MODBUS_MESS+1]=FORCE_MULTIPLE_COILS; //Function 
		abyQuery[OFFSET_MODBUS_MESS+2]=HiByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+3]=LoByte(nDataStart);
		abyQuery[OFFSET_MODBUS_MESS+4]=HiByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+5]=LoByte(nQtd);
		abyQuery[OFFSET_MODBUS_MESS+6]=(byte)((nQtd + 7)/8);
		nQueryByte=OFFSET_MODBUS_MESS+7;
		iBit=0;

		for (iCoil=0;iCoil<(nQtd);iCoil++){
			if (iBit>7){
				iBit=0;
				nQueryByte++;
			}
			
			if (abCoilValues[iCoil]) {
				abyQuery[nQueryByte]=(byte)(abyQuery[nQueryByte] | (0x01<<iBit));
			}
			iBit++;
			
		}
		
		
		iRetry=0;
		
		do {
			
			nError=TxRxMessage(abyQuery,(short)(QUERY_LENGHT+MBAP_HEADER_SIZE),aiReply, nReplyLength);
			
			
			if (nError==ERR_OK) {
				
				for (iReg=0;iReg<6;iReg++){
					if ((byte)aiReply[iReg]!=abyQuery[OFFSET_MODBUS_MESS+iReg]) {
						nError=ERR_INVALID_RESPONSE;
						break;
					}
				}
				
			}//nerror=ERR_OK
			
			iRetry++;
		} while ((iRetry<m_iRetries)&&(nError!=ERR_OK));

		ThrowException(nError);
		
		return(nError);
		
	}//end ForceMultipleCoils 
	
	
	public synchronized  short TxRxMessage(byte abyQuery[] , short nQueryLength, int aiReply[], short nReplyLenght) {
		
		long lInitialTime;
		boolean bTimeout=false; 
		int iByteRecived;
		long lCurrentTime;
		short  iRespSize=0;
		
		
		if (m_bReConnectOnEveryMessage) {
			if (!openConnection(m_sAddress,m_iPort,m_iTimeOut)){	
				return(ERR_EXECPTION);
			}
		}
		
			
		try	{
			m_ostream.flush();	
			m_ostream.flush();	
			m_istream.skip(m_istream.available()); //discard any value in the buffer 
			//send question 
			m_ostream.write(abyQuery, 0, nQueryLength); //offset=0 
			m_ostream.flush(); 
			
			lInitialTime=System.currentTimeMillis(); 
			bTimeout=false; 
			
			while (!bTimeout){
				if (this.m_istream.available()<MBAP_HEADER_SIZE){
					if ((System.currentTimeMillis()-lInitialTime)>m_iTimeOut){
						lCurrentTime=(System.currentTimeMillis()-lInitialTime);
						lCurrentTime=System.currentTimeMillis();
						bTimeout=true;
					} 
					
				}
				else {
					break;
				} 
				
			}	
			
			if (!bTimeout){
				
				for (iByteRecived=0;iByteRecived<MBAP_HEADER_SIZE;iByteRecived++){	
					aiReply[iByteRecived]=m_istream.readUnsignedByte();
				}
				
				iRespSize = (short)(aiReply[MBAP_HEADER_SIZE-2]);
				iRespSize = (short)((iRespSize<<8)|(aiReply[MBAP_HEADER_SIZE-1]));
				
				while (!bTimeout){
					if (this.m_istream.available()<(iRespSize)){
						if ((System.currentTimeMillis()-lInitialTime)>m_iTimeOut){
							lCurrentTime=(System.currentTimeMillis()-lInitialTime);
							lCurrentTime=System.currentTimeMillis();
							bTimeout=true;
						} 
						
					}
					else {
						break;
					} 
					
					
					
				}
			}
			
			if (!bTimeout){
				
				for (iByteRecived=0;iByteRecived<iRespSize;iByteRecived++){	
					aiReply[iByteRecived]=m_istream.readUnsignedByte();
				}
				
				//verify modbus exception 
				if (aiReply[1]>0x80){
					return (short)(ERR_MODBUS_EXCPTION+aiReply[2]);
				}
										
			}
			else {
				return(ERR_TIMEOUT);
			}
			
			
			if (m_bReConnectOnEveryMessage) {
				closeConnection();
			}
			
			
		}//end try
		
		catch(IOException ioe) { 
			System.err.println("Could not read data from Modbus server."); 
			return(ERR_EXECPTION);
		}

		return(ERR_OK);	
		
	}//end TxRxMessage 
	
	
	public void InsertMBAPHeader(byte abQuery[] , short nqueryLenght ){

		if (abQuery.length<6) {
			return;
		}

		abQuery[0]=0; //identifier
		abQuery[1]=0;
		abQuery[2]=0;//protocol identifier 
		abQuery[3]=0;
		abQuery[4]=HiByte(nqueryLenght);//length field (upper byte) 
		abQuery[5]=LoByte(nqueryLenght);
	
	}


	private byte HiByte(int iNumber) {
		return( (byte)((iNumber>>8) & (int)0x000000FF));
	}
	
	
	private byte LoByte(int iNumber) {
		return( (byte)((iNumber) & 0xFF));
	}

	private short HiWord(int iNumber) {
		return( (short)((iNumber>>16) & (int)0x0000FFFF));
	}

	private short LoWord(int iNumber) {
		return( (short)((iNumber) & (int)0x0000FFFF));
	}

	//java boolean to modbus boolean 
	private short CmodBool(boolean bCoil) {
		if (bCoil) {
			return((short)0xFF00);
		}
		else {
			return((short)0x0000);
		}
		
	}
	
	private void ShortToIntArray(short nArray[] , int iArray[]) {
		
		int i;
		int iTest;
		for (i=0;i<nArray.length;i++){
			
			iArray[i]=(int)((char)nArray[i]);
			iTest=iArray[i];
		}
		
	}
	
	private void IntToShortArray(int iArray[] , short nArray[]) {
		
		int i;
		short nTest;
		for (i=0;i<nArray.length;i++){
			
			nArray[i]=(short)iArray[i];
			nTest=nArray[i];
		}
		
	}

    private void ShortToFloatArray(short anArray[] , float afArray[] , int nRealTye) {
		
		int i;
        float fValue;
		
		if (anArray.length!=(2*afArray.length)) {
	
			System.err.println("ShortToFloat Error");
			return;
		}

        
        for (i=0;i<afArray.length;++i){
		
			if (REAL_NORMAL==nRealTye) {
				afArray[i]= Float.intBitsToFloat(HiLoWord2Int (anArray[2*i+1],anArray[2*i+0]));
			}
			else {
				afArray[i]= Float.intBitsToFloat(HiLoWord2Int (anArray[2*i+0],anArray[2*i+1]));
			}
		}

	}

	
	private void FloatToShortArray(float afArray[] ,short anArray[], int nRealTye) {
		
		int i;
        int iValue;
		
		if (anArray.length!=(2*afArray.length)) {
			
			System.err.println("ShortToFloat Error");
			return;
		}
		
		for (i=0;i<afArray.length;++i){
		
			iValue  = Float.floatToIntBits(afArray[i]);
			
			
			if (REAL_NORMAL==nRealTye) {
				anArray[2*i+1]=HiWord(iValue);
				anArray[2*i+0]=LoWord(iValue);
			
			}
			else {
				anArray[2*i+0]=HiWord(iValue);
				anArray[2*i+1]=LoWord(iValue);
			}

			
		}
		
		
	}



	private void ShortToDoubleArray(short anArray[] , double adArray[] , int nRealTye) {
		
		int i;
        float fValue;
		
		if (anArray.length!=(4*adArray.length)) {
	
			System.err.println("ShortToFloat Error");
			return;
		}

        
        for (i=0;i<adArray.length;++i){
		
			if (REAL_NORMAL==nRealTye) {
				adArray[i]= Double.longBitsToDouble(Words2Long(anArray[4*i+3],anArray[4*i+2],anArray[4*i+1],anArray[4*i+0]));
			}
			else {
				adArray[i]= Double.longBitsToDouble(Words2Long(anArray[4*i+0],anArray[4*i+1],anArray[4*i+2],anArray[4*i+3]));
			}
		}

	}


	private void DoubleToShortArray(double adArray[] ,short anArray[], int nRealTye) {
		
		int i;
        long lValue;
		
		if (anArray.length!=(4*adArray.length)) {
			
			System.err.println("DoubleToShortArray Error");
			return;
		}
		
		for (i=0;i<adArray.length;++i){
		
			lValue  = Double.doubleToLongBits(adArray[i]);
			
			
			if (REAL_NORMAL==nRealTye) {
				
				anArray[4*i+3]=GetWord(3,lValue);
				anArray[4*i+2]=GetWord(2,lValue);
				anArray[4*i+1]=GetWord(1,lValue);
				anArray[4*i+0]=GetWord(0,lValue);
			
			}
			else {
				anArray[4*i+0]=GetWord(3,lValue);
				anArray[4*i+1]=GetWord(2,lValue);
				anArray[4*i+2]=GetWord(1,lValue);
				anArray[4*i+3]=GetWord(0,lValue);
			}

			
		}
		
		
	}



	private int HiLoWord2Int(short iHi , short iLo) {
		int iRet=0;
		int iHiPart=0;
		int iLoPart=0;
        iHiPart = ((int)0xFFFF & iHi);
        iHiPart = (iHiPart<<16);
		iRet = iHiPart|((int)0xFFFF & iLo);
		return( iRet)  ; //(byte)((iNumber>>8) & (int)0x000000FF));
	}

	private long Words2Long(short w3 , short w2,short w1 , short w0) {
		
		long lRel=0;
		long lTemp=0;
		        
		lTemp = ((long)0xFFFF & w3);
        lTemp = lTemp<<(3*16);
		lRel = lRel | lTemp;

		lTemp = ((long)0xFFFF & w2);
        lTemp = lTemp<<(2*16);
		lRel = lRel | lTemp;
		

		lTemp = ((long)0xFFFF & w1);
        lTemp = lTemp<<(1*16);
		lRel = lRel | lTemp;

		lTemp = ((long)0xFFFF & w0);
        lTemp = lTemp<<(0*16);
		lRel = lRel | lTemp;

		return lRel;
        
	}

	private short GetWord(int iPart, long lValue) {
		
		long lTemp=0;
		
		lTemp =lValue;
        lTemp = lTemp>>(iPart*16);
		lTemp = ((long)0xFFFF & lTemp);
		
		return (short)lTemp;
        

	}

}//end Modbus Class 


