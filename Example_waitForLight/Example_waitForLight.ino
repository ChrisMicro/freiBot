

/*************************************************************************
  
  Example:
  Read the LED-light sensors and react on a sudden increase of 
  light.
    
*************************************************************************/
#include "freiBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}

#define LIGHTJUMPTRIGGERLEVEL 20
// wait for a sudden increasing light and exit
// or exit after timeout
uint8_t isLightJump(uint32_t timeOut_ms)
{
  int16_t oldValue = 0x7FFF;
  int16_t value;
  int16_t left;
  int16_t right;
  uint8_t trueIfLightJump = false;
  uint32_t stopTime;

  stopTime = millis() + timeOut_ms;
  while (millis() < stopTime)
  {
    left  = get_eyeValue(LEFT);
    right = get_eyeValue(RIGHT);
    value = left + right;
    if (value - oldValue > LIGHTJUMPTRIGGERLEVEL)
    {
      trueIfLightJump = true;
      break;
    }
    oldValue = value;
  }
  return trueIfLightJump;
}

void loop()
{
  int left;
  int right;
  uint32_t count;

  if (isLightJump(1000))
  {
    setLed(EYE_LED_LEFT,  1);
    setLed(EYE_LED_RIGHT, 1);
    Serial.println("jump");

    delay(200);

  }
  else Serial.print("no");
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

