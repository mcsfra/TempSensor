/* 
 * File:   rs485.h
 * Author: marcus
 *
 * Created Dec 2017
 */

#ifndef __RS485_H__
#define	__RS485_H__

extern void          initRS485(void);
/*
extern unsigned char testBus(void);
extern void          sendTelegram(unsigned char station, unsigned char *data, unsigned char bufLen);
extern void          sendByte(unsigned char data );
*/

//extern void txHandler(void); 

extern void rxHandler(void); 

extern unsigned char sendData(DBLOCK *data); 

extern unsigned char loNibble(unsigned char b); 
extern unsigned char hiNibble(unsigned char b); 
extern unsigned char sendByteComplex(unsigned char b ); 

extern void sendTest(void);


#endif	/* RS485_H */

