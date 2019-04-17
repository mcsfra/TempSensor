
#ifndef DATA_H
#define	DATA_H

typedef struct data  {
    
       unsigned char station; 
       unsigned char numSensors;
       int sensor[8];
       unsigned char sumcheck;
} DATA;



typedef union udata  {

    DATA data;
    unsigned char stream[19];
            
    
} DBLOCK;  



#endif	/* DATA_H */

