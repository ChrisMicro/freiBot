
/*************************************************************************

  Example:
  Read both line sensors. Detect light jump and escape. 
  Afterwards and turn to the light.

*************************************************************************/
#include "freiBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}

void loop()
{
  int n;
  if (isLightJump(1000)) 
  {
    BEEP; // check for a light jump for 1000ms
    Turn(180,250);
    Go(20,250);
    for(n=0;n<20;n++)
    {
      if(get_eyeValue(LEFT)>get_eyeValue(RIGHT)) Turn(10,250);
      else Turn(-10,250);
    }
  }
  
  setLed(EYE_LED_LEFT,  1);
  setLed(EYE_LED_RIGHT, 1);

  delay(50);
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

