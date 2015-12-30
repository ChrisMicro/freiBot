#include "Arduino.h"
#include "sound_extended.h"
#include "stdint.h"
#include "pin_defintions.h"

/************************************************************************************

	driver definitions

        Functions for compatibility to the ASURO robot

************************************************************************************/
// ASRURO Motor states
#define FREE    0                    // motor free runing
#define BREAK   1                    // break motor
#define FWD     2                    // motor forward
#define RWD     3                    // motor backward

#define LEFT	1
#define RIGHT   2

//#define Sleep(x) delayMicroseconds(x)

#ifdef __cplusplus
extern "C"
{
#endif
  void Msleep(uint32_t time_ms);
  void Sleep(uint32_t time_us);
  void MotorSpeed(uint8_t left, uint8_t right);
  void MotorDir(uint8_t left, uint8_t right);
  void Go   ( int16_t distance, uint8_t speed ); 
  void Turn ( int16_t degree  , uint8_t speed );
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

