#include "mcc_generated_files/mcc.h" 

#include "data.h"
#include "rs485.h"


void sendTest(void);

void initRS485(void)  {
    
    EUSART_Initialize();
}


unsigned char sendData(DBLOCK *data)  { 
 
    /*
     *  Calculate Checksum
     */
    
    unsigned char sumCheck = 0; 
    unsigned char i;
    unsigned char received;
    
    for ( i = 0; i < sizeof(DBLOCK) - 1; i++)  {
        sumCheck ^= data -> stream[i];
    }
    data -> data.sumcheck = sumCheck;   
    
    /*
     * Versenden
     */
    
    COLLISIONDETECTED_SetLow(); 
       
    SENDENABLE_SetHigh(); 
    
    if ( !sendByteComplex('*'))  {
            return 1; 
    }
    
    for ( i = 0; i < sizeof(DBLOCK); i++)  {
        
        if ( !sendByteComplex(data -> stream[i]))  {
            return 1; 
        }
    }
    SENDENABLE_SetLow();
        
    return 0;      
}

unsigned char loNibble(unsigned char b)  {
    
    unsigned char nib = b & 0x0f;
    return  nib < 0x0A ? '0' + nib : 'A' + (nib-10); 
}

unsigned char hiNibble(unsigned char b)  {
    
    unsigned char nib = ( b >> 4 ) & 0x0f;
    return  nib < 0x0A ? '0' + nib : 'A' + (nib-10);
}



/*
 * Versendet ein Byte und checkt auch auf Kollision
 *    return : 0 --> mist. Kollision
 *             1 --> alles Güt
 */

unsigned char sendByteComplex(unsigned char b)  {

    unsigned char received; 
    
    if ( EUSART_is_rx_ready())  {
        EUSART_Read();
    }
       
    SENDING_SetHigh();
    EUSART_Write(b);
    SENDING_SetLow(); 
   
    // Zurücklesen 
    received = EUSART_Read();
        
    if ( received != b )  {
        COLLISIONDETECTED_SetHigh(); 
        SENDENABLE_SetLow();
        return 0; 
    }
    
    return 1;    
}

unsigned char msg[] = "Weltherrschaft!\n";

void testSend(void)  {
    
    unsigned char i = 0; 
    
    for (;;)  {
        
        if ( i == 16)
            i = 0; 
        
        EUSART_Write(msg[i]);
        i++;
    }
    
}


unsigned char message[] = "Weltherrschaft.\n";

void sendTest()  { 
    
    unsigned char i; 
    
    COLLISIONDETECTED_SetLow(); 
       
    SENDENABLE_SetHigh(); 
   
    for ( i = 0; i < 16; i++)  {
 
        sendByteComplex(message[i]);
    }
    SENDENABLE_SetLow();
}


