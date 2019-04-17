#include "mcc_generated_files/mcc.h" 

#include "data.h"
#include "lm75.h"

void I2CWait(void);
void initLM75(unsigned char  address);
unsigned int readLM75(unsigned char  address);


void initSensors(void)  {
    
    TRISBbits.RB4 = 1; 
    TRISBbits.RB6 = 1; 
   
    SSPCON1bits.SSPEN = 1;
    SSPADD  = 0x08;   // das stimmt doch nicht, oder? 
    SSPCON1 = 0x28;
    SSPSTAT = 0x00;
    
}

unsigned char bI2CTimeout; 

int getSensor(unsigned char address)  {
   
    unsigned int ret; 
    
    bI2CTimeout = 0; 
    
    initLM75(address<<1);
    I2CWait(); 
    ret =  readLM75(address<<1);
    
    // KIch erkenne wie es scheint timeouts nicht auf diese weise. 
  /* 
     if (bI2CTimeout == 1 )  {

        return 0xFFFF; 
    }
    */
    return ret; 
}



void gatherData(DBLOCK *data)  {
    
    unsigned char i; 
    
    for ( i = 0; i < data -> data.numSensors; i++)  {
        data -> data.sensor[i] = getSensor(i); 
    }
} 


/*
 Von Microchip gemopst
 
 */

/*
Function: I2CStart
Return:
Arguments:
Description: Send a start condition on I2C Bus
*/
void I2CStart()  {

   SSPCON2bits.SEN = 1;   // Start condition enabled 
   while(SSPCON2bits.SEN) // automatically cleared by hardware 
       ;
}

/*
Function: I2CStop
Return:
Arguments:
Description: Send a stop condition on I2C Bus
*/
void I2CStop()   {
   SSPCON2bits.PEN = 1;  // Stop condition enabled 
   while(SSPCON2bits.PEN) // Wait for stop condition to finish 
       ;
   // muss das ?LATCbits.LATC0 = 1;    // PEN automatically cleared by hardware 
}

/*
Function: I2CRestart
Return:
Arguments:
Description: Sends a repeated start condition on I2C Bus
*/
void I2CRestart()   {
   SSPCON2bits.RSEN = 1; /* Repeated start enabled */
   while(SSPCON2bits.RSEN) /* wait for condition to finish */
      ;
}

/*
Function: I2CAck
Return:
Arguments:
Description: Generates acknowledge for a transfer
*/
void I2CAck()  {

   unsigned char timeout = 0xFFFF; 
    
   SSPCON2bits.ACKDT = 0; /* Acknowledge data bit, 0 = ACK */
   SSPCON2bits.ACKEN = 1; /* Ack data enabled */
   while(SSPCON2bits.ACKEN)   { /* wait for ack data to send on bus */
      if ( timeout-- == 0)  {
          bI2CTimeout = 1; 
          return; 
      }
   }
   
}

/*
Function: I2CNck
Return:
Arguments:
Description: Generates Not-acknowledge for a transfer
*/
void I2CNak()  {
    
   unsigned char timeout = 0xFFFF;  
    
   SSPCON2bits.ACKDT = 1; /* Acknowledge data bit, 1 = NAK */
   SSPCON2bits.ACKEN = 1; /* Ack data enabled */
  
   while(SSPCON2bits.ACKEN)   { /* wait for ack data to send on bus */
      if ( timeout-- == 0)  {
          bI2CTimeout = 1;
          return; 
      }
   }
}

/*
Function: I2CWait
Return:
Arguments:
Description: wait for transfer to finish
*/
void I2CWait()  {

     while ((SSPCON2 == 0x1F ) || ( SSPSTAT == 0x04 ) )
         ;
}

/*
Function: I2CSend
Return:
Arguments: dat - 8-bit data to be sent on bus
data can be either address/data byte
Description: Send 8-bit data on I2C bus
*/
void I2CSend(unsigned char dat)  {

   SSPBUF = dat; /* Move data to SSPBUF */
   while(BF) /* wait till complete data is sent from buffer */
      ; 
   I2CWait(); 
}

/*
Function: I2CRead
Return: 8-bit data read from I2C bus
Arguments:
Description: read 8-bit data from I2C bus
*/
unsigned char I2CRead(void)  {

    unsigned int timeout = 0xFFFF; 
    
    unsigned char temp;
                            /* Reception works if transfer is initiated in read mode */
    SSPCON2bits.RCEN = 1; /* Enable data reception */
    while(!SSPSTATbits.BF)  { /* wait for buffer full */
     
        if ( timeout-- == 0)  {
            bI2CTimeout = 1;
            return 0; 
        }
    }
    
    temp = SSPBUF;   /* Read serial buffer and store in temp register */
    I2CWait();       /* wait to check any pending transfer */
    return temp;     /* Return the read data from bus */
}

void initLM75(unsigned char address)  {
  
    SCL = 1;
    SDA = 1;

    I2CStart(); 
    I2CSend((0b10010000|address));
    I2CSend(0b00000001);
    I2CSend(0b00000000);
    I2CStop();
}

unsigned int readLM75(unsigned char address)  {

    unsigned int ret = 0; 
    
    I2CStart();
    I2CSend((0b10010000|address));
    I2CSend(0b00000000);
    I2CRestart();
    I2CSend((0b10010001|address));
 
    ret = ( I2CRead() << 8);
    I2CAck();
    ret |= I2CRead();

    I2CNak();
    I2CStop();

    return ret;
}



