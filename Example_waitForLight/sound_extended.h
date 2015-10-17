#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __SOUND_EXTENDED__
  #define __SOUND_EXTENDED__

  #include "sound.h"
  
  void motrChirp(uint16_t startFreq_HZ, uint16_t stopFreq_HZ,uint16_t duration_ms);
  void ringSound();
  void chirp();

 
  #endif // __SOUND_EXTENDED__

#ifdef __cplusplus
}
#endif

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
