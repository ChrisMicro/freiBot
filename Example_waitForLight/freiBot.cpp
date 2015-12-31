#include "asuro.h"

void initRobotHardware()
{
  pinMode(IR_SENSOR, INPUT);

  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(WHISKERPIN, INPUT_PULLUP);

  pinMode(LEDPIN, OUTPUT);
  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);

  pinMode(ENABLE_RIGHT, OUTPUT);
  pinMode(MOTOR_RIGHT1, OUTPUT);
  pinMode(MOTOR_RIGHT2, OUTPUT);

  pinMode(ENABLE_LEFT, OUTPUT);
  pinMode(MOTOR_LEFT1, OUTPUT);
  pinMode(MOTOR_LEFT2, OUTPUT);

}

#define EYESAMPLINGTIME_US (20000-396) // experimental filter time should be 20ms @ 50 Hz

uint16_t get_eyeValue(uint8_t side)
{
  uint16_t eye, n;
  uint32_t value = 0;
  uint32_t stopTime;
  uint32_t count = 0;


  if (side == LEFT) eye = EYE_LED_LEFT;
  else              eye = EYE_LED_RIGHT;

  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);
  digitalWrite(EYE_LED_LEFT, 0); // discharge
  digitalWrite(EYE_LED_RIGHT, 0); // discharge

  pinMode(eye, INPUT_PULLUP);
  digitalWrite(eye, 1); // precharge

  pinMode(eye, INPUT);
  delay(20);

  stopTime = micros() + EYESAMPLINGTIME_US;
  do
  {
    value = value + analogRead(eye);
    count++;
  }
  while (micros() < stopTime);

  value = value / count;

  return value;
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

void setLed(uint8_t led, uint8_t value)
{
  if (led == EYE_LED_LEFT)
  {
    pinMode(EYE_LED_LEFT, OUTPUT);
    digitalWrite(EYE_LED_LEFT, value);
  }
  if (led == EYE_LED_RIGHT)
  {
    pinMode(EYE_LED_RIGHT, OUTPUT);
    digitalWrite(EYE_LED_RIGHT, value);
  }
}

uint8_t isIrSignal()
{
  return !digitalRead(IR_SENSOR);
}

void waitForIrSignal()
{
  while (!isIrSignal());
}

uint8_t whiskerTouched()
{
  static uint8_t oldState = 0;
  uint8_t state;
  uint8_t result = 0;

  state = !digitalRead(WHISKERPIN);

  if ((state != 0) && (oldState == 0)) result = 1;

  oldState = state;

  return result;
}


/*******************************************************************************
*   -c--date---version--nickname--------email---------------------------------
*
*   (c) 2015   V0.1     stochri         christoph(at)roboterclub-freiburg.de
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
