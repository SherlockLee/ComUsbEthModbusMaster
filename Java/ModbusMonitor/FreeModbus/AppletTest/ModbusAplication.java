//
//
// ModbusAplication
//
//
package FreeModbus.AppletTest;

import FreeModbus.Util.*; //Modbus Class 

class ModbusAplication 
{


	

	public static void main(String args[]) {

	  int aiRegValues[];
	  boolean abCoils[];
	  short nErr;
	  short nQnt;
	  short nAddr;
	  int nDataStart;
	  int i;
	  String sServer; 
	  Modbus objModbus = new Modbus();
      
	  //Make a connection 
	  sServer = "127.0.0.1";
	  System.out.println("connecting with Server:"+ sServer );

	  if (!objModbus.openConnection(sServer,502,5000)){
			 System.out.println("openConnection Failed");
			return;
						
	   }
      
	  
	  //Preset Register double 
	  nErr = objModbus.PresetSingleRegister((short)1,(int)0,(double)0,Modbus.REAL_NORMAL);


	  //read Output Registers float - 64 
      nQnt=4;
	  nDataStart =0x0;
	  nAddr = 1;	
      double adRegs[] = new double[nQnt];
      
	  nErr = objModbus.ReadOutputRegisters(nAddr,nDataStart ,nQnt, adRegs,Modbus.REAL_NORMAL); 
	  
	  
	  if (nErr!=Modbus.ERR_OK) {
		  
		  System.out.println("Error Reading Output Registers"); 
		  
	  }
	  
	  for (i=0;i<nQnt;i++) {
		  System.out.println("["+(i+nDataStart)+"]="+adRegs[i]);
	  }



	  nErr = objModbus.PresetMultipleRegisters(nAddr,nDataStart ,nQnt ,adRegs,Modbus.REAL_NORMAL);
	  
	  if (nErr!=Modbus.ERR_OK) {
		  
		  System.out.println("Error Reading Output Registers"); 
		  
	  }


      //read Output Registers float - 32 
      nQnt=1;
	  nDataStart =0;
	  nAddr = 1;	
      float afRegs[] = new float[1];
      
	  nErr = objModbus.ReadOutputRegisters(nAddr,nDataStart ,nQnt, afRegs,Modbus.REAL_NORMAL); 
	  
	  
	  if (nErr!=Modbus.ERR_OK) {
		  
		  System.out.println("Error Reading Output Registers"); 
		  
	  }
	  
	  for (i=0;i<nQnt;i++) {
		  System.out.println("["+(i+nDataStart)+"]="+afRegs[i]);
	  }

	  nErr = objModbus.PresetMultipleRegisters(nAddr,nDataStart ,nQnt ,afRegs,Modbus.REAL_NORMAL);
	  
	  if (nErr!=Modbus.ERR_OK) {
		  
		  System.out.println("Error Reading Output Registers"); 
		  
	  }




	   //Read output Register Holding Registers 
	   nQnt=10;
	   aiRegValues = new int[nQnt];
	   nDataStart =0;
	   nAddr = 1;


	   System.out.println("Reading Output Registers ");
	   nErr = objModbus.ReadOutputRegisters(nAddr,nDataStart ,nQnt, aiRegValues);

       if (nErr!=Modbus.ERR_OK) {

		  System.out.println("Error Reading Output Registers"); 

	   }
	   
		for (i=0;i<nQnt;i++) {
               System.out.println("["+(i+nDataStart)+"]="+aiRegValues[i]);
		}
       
       


       //Read Input Regisgters 

	   System.out.println("Reading Input Registers ");
	   nErr = objModbus.ReadInputRegisters(nAddr,nDataStart ,nQnt, aiRegValues);

       if (nErr!=Modbus.ERR_OK) {

		  System.out.println("Error Reading input Registers"); 

	   }
	   
		for (i=0;i<nQnt;i++) {
               System.out.println("["+(i+nDataStart)+"]="+aiRegValues[i]);
		}
       

       //Read Output Status 
	   nQnt=10;
	   abCoils = new boolean[nQnt];
	   nDataStart =0;
	   nAddr = 1;

	   System.out.println("Reading Output Status ");
	   nErr = objModbus.ReadOutputStatus(nAddr,nDataStart ,nQnt, abCoils);

       if (nErr!=Modbus.ERR_OK) {

		  System.out.println("Error Reading Output status"); 

	   }
	   
	   for (i=0;i<nQnt;i++) {
               System.out.println("["+(i+nDataStart)+"]="+abCoils[i]);
	   }
       

	}
}

