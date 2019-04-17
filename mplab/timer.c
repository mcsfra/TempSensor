#include "mcc_generated_files/mcc.h" 

#include "globals.h"
#include "timer.h"



volatile unsigned char bTimerElapsed; 
//unsigned int  timerCounter; 

void timerHandler(void);

void initTimer()   {
    
    bTimerElapsed = 0; 
  //  timerCounter  = TIMERCOUNT; 
    
    TMR1_SetInterruptHandler(timerHandler);
}


void timerHandler()  {
    bTimerElapsed = 1;
  //  SENDENABLE_Toggle();
}
/*
unsigned char testTimer()  {
    
    if (bTimerElapsed == 1)  {
            
        bTimerElapsed = 0; 
        if (--timerCounter == 0) {
            timerCounter = TIMERCOUNT; 
            return 1; 
        }     
    }
    return 0; 
}
*/
