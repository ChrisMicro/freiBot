
/*************************************************************************
  
  Experimental: sied walk like a crab
  
*************************************************************************/
#include "freiBot.h"

void setup()
{
  initRobotHardware();
}

void loop()
{
  int maxSpeed=100;
  int n;
  int dist=800;
  
  delay(5000); 
    MotorSpeed(maxSpeed, maxSpeed);
    MotorDir( FWD,FWD);
    delay(1000); 

  
  for(n=0;n<5;n++)
  {
    MotorSpeed(maxSpeed, maxSpeed);
    MotorDir( FWD,FREE);
    delay(dist); 
    MotorSpeed(maxSpeed, maxSpeed);
    MotorDir(FREE, RWD);
    delay(dist);
  } 
    MotorDir(BREAK, BREAK);
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


