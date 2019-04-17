
/******************************************************************************************
** Fifo zur Pufferung eingehener Kommandos
** [[ ToDo: BufferOverflows werden nicht geblockt und auch niocht erkannt.
******************************************************************************************/

#include "fifo.h"

/*
** Ringpuffer
*/
unsigned char fifo[FIFO_SIZE];

/*
** Index der schreibposition
*/
volatile unsigned char fifoIn;

/*
** index der Leseposition
*/
volatile unsigned char fifoOut;

/******************************************************************************************
** Fifo initialisieren.
** Schreib und lesepointer auf 0
*/
void fifoInit()  {

   fifoIn  = 0;
   fifoOut = 0;
}


/******************************************************************************************
** Ein zeichen aus dem Ringpuffer holen.
** Achtung ! Vorher prüfen, ( mit fifoEmpty() )
** ob es zeichen zur Abholung gibt.
*/
unsigned char fifoGet()  {

    unsigned char v = fifo[fifoOut];


    return fifo[fifoOut++ & FIFO_MASK];
}

/******************************************************************************************
** Ein zeichen in dem Ringpuffer legen.
** es wird nicht geprüft, ob der Puffer voll ist; ggf. wird
** das Älteste Zeichen überschrieben
*/
void fifoPut(unsigned char in)  {

    fifo[fifoIn++ & FIFO_MASK] = in;
}

/******************************************************************************************
** testet, ob der Ringbuffer leer ist.
*/
unsigned char fifoEmpty()  {

  return (fifoIn & FIFO_MASK) == (fifoOut & FIFO_MASK);

}