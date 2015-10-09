#include "asuro.h"
#include "sound.h"

#define ONETONE_DURATION_MS 10

uint8_t Loudness=255;

void motrChirp(uint16_t startFreq_HZ, uint16_t stopFreq_HZ,uint16_t duration_ms)
{
  int16_t n;
  int16_t increment;
  increment=((int16_t)stopFreq_HZ-(int16_t)startFreq_HZ)*ONETONE_DURATION_MS/duration_ms;
  if(increment>0)
  {
    for(n=startFreq_HZ;n<stopFreq_HZ;n+=increment)
    {
      motorTone(n,ONETONE_DURATION_MS);
    }
  }else
  {
    for(n=startFreq_HZ;n>stopFreq_HZ;n+=increment)
    {
      motorTone(n,ONETONE_DURATION_MS);
    }
  }
}

void ringSound()
{
  uint8_t n;
  for(n=0;n<20;n++)
  {
    motorTone (1000, 10);
    delay(20);
  }
}

void chirp()
{
 motrChirp(1000,2000,100);
}

/*******************************************************************************
*   -c--date---version--nickname--------email---------------------------------
*
*   (c) 2015   V0.1     stochri         christoph(at)roboterclub-freiburg.de
*   (c) ..     V0.2     ...... ........ ( your name ) ........................
*
*******************************************************************************
*   This program is free software; you can redistribute it and/or modify      *
*   it under the terms of the GNU General Public License as published by      *
*   the Free Software Foundation version 2 of the License,                    *
*   If you want to use this software for commercial purposes and you          *
*   don't want to make it open source, please contact the authors for         *
*   licensing.                                                                *
*                                                                             *
*   IF YOU EXTEND THE PROGRAM PLEASE MAINTAIN THE LIST OF AUTHORS             *
*   ( which means adding copyright in the list above )                        *
*                                                                             *
*******************************************************************************/
