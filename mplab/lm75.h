/* 
 * File:   massStorage.h
 * Author: marcus
 *
 * Created on 30. September 2014, 18:49
 */

#ifndef LM75_H
#define	LM75_H

extern void initSensors(void);  

extern int getSensor(unsigned char address);  

extern void gatherData(DBLOCK *data);  


#endif	/* LM75_H */

