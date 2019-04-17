/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC18F14K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set NUMSENSORS1 aliases
#define NUMSENSORS1_TRIS               TRISAbits.TRISA0
#define NUMSENSORS1_LAT                LATAbits.LATA0
#define NUMSENSORS1_PORT               PORTAbits.RA0
#define NUMSENSORS1_WPU                WPUAbits.WPUA0
#define NUMSENSORS1_ANS                ANSELbits.ANS0
#define NUMSENSORS1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define NUMSENSORS1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define NUMSENSORS1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define NUMSENSORS1_GetValue()           PORTAbits.RA0
#define NUMSENSORS1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define NUMSENSORS1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define NUMSENSORS1_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define NUMSENSORS1_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define NUMSENSORS1_SetAnalogMode()  do { ANSELbits.ANS0 = 1; } while(0)
#define NUMSENSORS1_SetDigitalMode() do { ANSELbits.ANS0 = 0; } while(0)

// get/set NUMSENSORS2 aliases
#define NUMSENSORS2_TRIS               TRISAbits.TRISA1
#define NUMSENSORS2_LAT                LATAbits.LATA1
#define NUMSENSORS2_PORT               PORTAbits.RA1
#define NUMSENSORS2_WPU                WPUAbits.WPUA1
#define NUMSENSORS2_ANS                ANSELbits.ANS1
#define NUMSENSORS2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define NUMSENSORS2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define NUMSENSORS2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define NUMSENSORS2_GetValue()           PORTAbits.RA1
#define NUMSENSORS2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define NUMSENSORS2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define NUMSENSORS2_SetPullup()      do { WPUAbits.WPUA1 = 1; } while(0)
#define NUMSENSORS2_ResetPullup()    do { WPUAbits.WPUA1 = 0; } while(0)
#define NUMSENSORS2_SetAnalogMode()  do { ANSELbits.ANS1 = 1; } while(0)
#define NUMSENSORS2_SetDigitalMode() do { ANSELbits.ANS1 = 0; } while(0)

// get/set NUMSENSORS4 aliases
#define NUMSENSORS4_TRIS               TRISAbits.TRISA2
#define NUMSENSORS4_LAT                LATAbits.LATA2
#define NUMSENSORS4_PORT               PORTAbits.RA2
#define NUMSENSORS4_WPU                WPUAbits.WPUA2
#define NUMSENSORS4_ANS                ANSELbits.ANS2
#define NUMSENSORS4_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define NUMSENSORS4_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define NUMSENSORS4_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define NUMSENSORS4_GetValue()           PORTAbits.RA2
#define NUMSENSORS4_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define NUMSENSORS4_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define NUMSENSORS4_SetPullup()      do { WPUAbits.WPUA2 = 1; } while(0)
#define NUMSENSORS4_ResetPullup()    do { WPUAbits.WPUA2 = 0; } while(0)
#define NUMSENSORS4_SetAnalogMode()  do { ANSELbits.ANS2 = 1; } while(0)
#define NUMSENSORS4_SetDigitalMode() do { ANSELbits.ANS2 = 0; } while(0)

// get/set STATION1 aliases
#define STATION1_TRIS               TRISAbits.TRISA4
#define STATION1_LAT                LATAbits.LATA4
#define STATION1_PORT               PORTAbits.RA4
#define STATION1_WPU                WPUAbits.WPUA4
#define STATION1_ANS                ANSELbits.ANS3
#define STATION1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define STATION1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define STATION1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define STATION1_GetValue()           PORTAbits.RA4
#define STATION1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define STATION1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define STATION1_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define STATION1_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define STATION1_SetAnalogMode()  do { ANSELbits.ANS3 = 1; } while(0)
#define STATION1_SetDigitalMode() do { ANSELbits.ANS3 = 0; } while(0)

// get/set STATION2 aliases
#define STATION2_TRIS               TRISAbits.TRISA5
#define STATION2_LAT                LATAbits.LATA5
#define STATION2_PORT               PORTAbits.RA5
#define STATION2_WPU                WPUAbits.WPUA5
#define STATION2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define STATION2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define STATION2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define STATION2_GetValue()           PORTAbits.RA5
#define STATION2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define STATION2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define STATION2_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define STATION2_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS               TRISBbits.TRISB4
#define SDA_LAT                LATBbits.LATB4
#define SDA_PORT               PORTBbits.RB4
#define SDA_WPU                WPUBbits.WPUB4
#define SDA_ANS                ANSELHbits.ANS10
#define SDA_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDA_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDA_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDA_GetValue()           PORTBbits.RB4
#define SDA_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDA_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define SDA_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define SDA_SetAnalogMode()  do { ANSELHbits.ANS10 = 1; } while(0)
#define SDA_SetDigitalMode() do { ANSELHbits.ANS10 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()    do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()   do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()   do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()         PORTBbits.RB5
#define RB5_SetDigitalInput()   do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()  do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()     do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()   do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode() do { ANSELHbits.ANS11 = 1; } while(0)
#define RB5_SetDigitalMode()do { ANSELHbits.ANS11 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS               TRISBbits.TRISB6
#define SCL_LAT                LATBbits.LATB6
#define SCL_PORT               PORTBbits.RB6
#define SCL_WPU                WPUBbits.WPUB6
#define SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL_GetValue()           PORTBbits.RB6
#define SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()    do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()   do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()   do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()         PORTBbits.RB7
#define RB7_SetDigitalInput()   do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()  do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()     do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()   do { WPUBbits.WPUB7 = 0; } while(0)

// get/set SENDING aliases
#define SENDING_TRIS               TRISCbits.TRISC3
#define SENDING_LAT                LATCbits.LATC3
#define SENDING_PORT               PORTCbits.RC3
#define SENDING_ANS                ANSELbits.ANS7
#define SENDING_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SENDING_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SENDING_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SENDING_GetValue()           PORTCbits.RC3
#define SENDING_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SENDING_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SENDING_SetAnalogMode()  do { ANSELbits.ANS7 = 1; } while(0)
#define SENDING_SetDigitalMode() do { ANSELbits.ANS7 = 0; } while(0)

// get/set STATUS2 aliases
#define STATUS2_TRIS               TRISCbits.TRISC4
#define STATUS2_LAT                LATCbits.LATC4
#define STATUS2_PORT               PORTCbits.RC4
#define STATUS2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define STATUS2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define STATUS2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define STATUS2_GetValue()           PORTCbits.RC4
#define STATUS2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define STATUS2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set SENDENABLE aliases
#define SENDENABLE_TRIS               TRISCbits.TRISC6
#define SENDENABLE_LAT                LATCbits.LATC6
#define SENDENABLE_PORT               PORTCbits.RC6
#define SENDENABLE_ANS                ANSELHbits.ANS8
#define SENDENABLE_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SENDENABLE_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SENDENABLE_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SENDENABLE_GetValue()           PORTCbits.RC6
#define SENDENABLE_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SENDENABLE_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SENDENABLE_SetAnalogMode()  do { ANSELHbits.ANS8 = 1; } while(0)
#define SENDENABLE_SetDigitalMode() do { ANSELHbits.ANS8 = 0; } while(0)

// get/set COLLISIONDETECTED aliases
#define COLLISIONDETECTED_TRIS               TRISCbits.TRISC7
#define COLLISIONDETECTED_LAT                LATCbits.LATC7
#define COLLISIONDETECTED_PORT               PORTCbits.RC7
#define COLLISIONDETECTED_ANS                ANSELHbits.ANS9
#define COLLISIONDETECTED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define COLLISIONDETECTED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define COLLISIONDETECTED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define COLLISIONDETECTED_GetValue()           PORTCbits.RC7
#define COLLISIONDETECTED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define COLLISIONDETECTED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define COLLISIONDETECTED_SetAnalogMode()  do { ANSELHbits.ANS9 = 1; } while(0)
#define COLLISIONDETECTED_SetDigitalMode() do { ANSELHbits.ANS9 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/