#include "mcc_generated_files/mcc.h" 

#include "data.h"
#include "lm75.h"
#include "timer.h"
#include "rs485.h"

#define MAX_SENSORS 8


/*
  * Temperaturadapter - Dec 2017
 *
 * Key Characteristics:
 *
 * Bis zu 8 Sensoren können angeschlossen werden
 * Datentelegramme über RS485
 *
 * Das Protokoll
 *
 * xx - Stationsnummer
 * xx - Sensor1
 * xx - Sensor2
 * xx - Sensor3
 * xx - Sensor4
 * xx - Sensor5
 * xx - Sensor6
 * xx - Sensor7
 * xx - Sensor8
 * xx - checksum
 */

unsigned char bGatherAndSend; 
unsigned int  sensorCounter; 

unsigned char bGather; 
unsigned char bSend;


/*
 *forward declarations
 */

unsigned char getStation(void);
unsigned char getNumSensors(void);

DBLOCK data;



extern void testSend(void); 

unsigned int testdata; 


void main(void)  {
    
    unsigned char bCollision; 
    unsigned char cycle; 
    
    SYSTEM_Initialize(); 
    PIN_MANAGER_Initialize();
    
    STATION1_SetPullup(); 
    STATION2_SetPullup(); 
    
    NUMSENSORS1_SetPullup();
    NUMSENSORS2_SetPullup();
    NUMSENSORS4_SetPullup();
   
    SENDING_SetLow();
    COLLISIONDETECTED_SetLow(); 
    
    initTimer();
    initRS485(); 
    initSensors(); 
    
    bGather = 0; 
    bSend   = 0; 
    
    INTCONbits.GIEH = 1; 
    INTCONbits.GIEL = 1; 
    
    data.data.station    = getStation();  
    data.data.numSensors = getNumSensors();  
    
    for(;;)  {
        
        if (bTimerElapsed == 1)  {
            bTimerElapsed  = 0; 
            gatherData(&data);
            bCollision = sendData(&data);
        }    
        
        if (bCollision == 1)  {
            
            cycle = getStation() + 1;
            cycle *= 40;
            
            while ( cycle--)  {
              TMR1_Reload();   // ist jetzt mal ein Versuch
            }
            bCollision = 0; 
            
        }
        
        
    } // for
}




/*
 *  Gibt die Nummer der Station zurück konfiguriert über 2 Jümper
 *  RA0, RA1 - Pins 19,18
 */

/*
 * Gibt die Stationsnummer zurück.
 * Inverse Logik! 
 */

unsigned char getStation()  {
    
    unsigned char n = 0;   
    // Inverse Logik, ne!
    n |= STATION1_GetValue() != 0 ? 0 : 1; 
    n |= STATION2_GetValue() != 0 ? 0 : 2; 
  
    return n; 
}


unsigned char getNumSensors()  {
    
    unsigned char n = 0;   
    // Inverse Logik, ne!
    n |= NUMSENSORS1_GetValue() != 0 ? 0 : 1; 
    n |= NUMSENSORS2_GetValue() != 0 ? 0 : 2; 
    n |= NUMSENSORS4_GetValue() != 0 ? 0 : 4; 
    
    return n; 
}





