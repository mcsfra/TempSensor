/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc.h"
#include "i2c_driver.h"

#pragma warning disable 520        

inline void i2c_driver_close(void)
{
    SSPCON1bits.SSPEN = 0;
}

/* Interrupt Control */
inline void mssp_enableIRQ(void)
{
    PIE1bits.SSPIE = 1;
}

inline bit mssp_IRQisEnabled(void)
{
    return PIE1bits.SSPIE;
}

inline void mssp_disableIRQ(void)
{
    PIE1bits.SSPIE = 0;
}

inline void mssp_clearIRQ(void)
{
    PIR1bits.SSPIF = 0;
}

inline void mssp_setIRQ(void)
{
    PIR1bits.SSPIF = 1;
}

inline bit mssp_IRQisSet(void)
{
    return PIR1bits.SSPIF;
}

inline void mssp_waitForEvent(uint16_t *timeout)
{
    //uint16_t to = (timeout!=NULL)?*timeout:100;
    //to <<= 8;

    if(PIR1bits.SSPIF == 0)
    {
        while(1)// to--)
        {
            if(PIR1bits.SSPIF) break;
            __delay_us(100);
        }
    }
}

bit i2c_driver_open(void)
{
    if(!SSPCON1bits.SSPEN)
    {
        SSPSTAT = 0x00;
        SSPCON1 = 0x28;
        SSPCON2 = 0x00;
        SSPADD = 0x9;
        return true;
    }
    else
        return false;
}

bit i2c_driver_initSlaveHardware(void)
{
    if(!SSPCON1bits.SSPEN)
    {
/* NOTE on AHEN:
 * If multiple slaves are to be emulated, then AHEN must be set.  It must be set
 * because the driver needs to selectively ACK/NACK the address depending on its
 * ability to handle the address.
*/

/* NOTE on DHEN:
 * DHEN must be set so that the data is not automatically NACK'ed if it is not read
 * from the SSPBUF.  This driver will ALWAYS read the SSPBUF so that it can pass
 * the value to the appropriate slave handler.  Because the data is ALWAYS read
 * the data will always be ACK'd if DHEN is cleared.  If the slave does not want
 * the data byte from the master then it will return false and a NACK will be returned.
 */

/* NOTE on SEN:
 * SEN will be set enabling clock stretching.  This is because we don't know how
 * long the user will take to process data bytes in their callbacks.  If they are fast,
 * we may not need to stretch the clock.  If they are slow, we need to stretch the clock.
 * If we ALWAYS stretch the clock, we will release the clock when the ISR is complete.
 */

/* NOTE on PCIE:
 * PCIE will be set to enable interrupts on STOP.  This will allow us know when
 * the master is finished
 */
        
/* NOTE on SCIE:
 * SCIE will be set to enable interrupts on START.  This will allow us to detect
 * both a START and a RESTART event and prepare to restart communications.
 */
        SSPCON1 |= 0x06; //setup I2C Slave (7-bit Addressing)
        SSPSTAT = 0x00;
        SSPCON2 = 0x00;
        
        SSPCON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

inline void i2c_driver_resetBus(void)
{
    
}

inline void i2c_driver_start(void)
{
    SSPCON2bits.SEN = 1;
}

inline void i2c_driver_restart(void)
{
    SSPCON2bits.RSEN = 1;
}

inline void i2c_driver_stop(void)
{
    SSPCON2bits.PEN = 1;
}

inline bit i2c_driver_isNACK(void)
{
    return SSPCON2bits.ACKSTAT = 1;
}

inline void i2c_driver_startRX(void)
{
    SSPCON2bits.RCEN = 1;
}

inline char i2c_driver_getRXData(void)
{
    return SSPBUF;
}

inline void i2c_driver_setAddr(char addr)
{
    SSPADD = addr;
}

inline void i2c_driver_setMask(char mask)
{
    SSPMSK = mask;
}

inline void i2c_driver_TXData(char d)
{
    SSPBUF = d;
}

inline char i2c_driver_getAddr(void)
{
    return SSPADD;
}

inline void i2c_driver_sendACK(void)
{
    SSPCON2bits.ACKDT = 0;
    SSPCON2bits.ACKEN = 1; // start the ACK/NACK
}

inline void i2c_driver_sendNACK(void)
{
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1; // start the ACK/NACK
}

inline void i2c_driver_releaseClock(void)
{
    SSPCON1bits.CKP = 1;
}

inline bit i2c_driver_isBufferFull(void)
{
    return SSPSTATbits.BF;
}

inline bit i2c_driver_isStart(void)
{
    return SSPSTATbits.S;
}

inline bit i2c_driver_isAddress(void)
{
    return !SSPSTATbits.D_nA;
}

inline bit i2c_driver_isStop(void)
{
    return SSPSTATbits.P;
}

inline bit i2c_driver_isData(void)
{
    return SSPSTATbits.D_nA;
}

inline bit i2c_driver_isRead(void)
{
    return SSPSTATbits.R_nW;
}

inline bit i2c_driver_isWriteCollision(void)
{
    return SSPCON1bits.WCOL;
}

inline bit i2c_driver_isReceiveOverflow(void)
{
    return SSPCON1bits.SSPOV;
}

inline void i2c_driver_clearBusCollision(void)
{
    PIR2bits.BCLIF = 0; // clear the bus collision.
}

inline void i2c_driver_setBusCollisionISR(void *f){
    i2c_driver_busCollisionISR = f;
}

inline void i2c_driver_setI2cISR(void *f){
    i2c_driver_i2cISR = f;
}
