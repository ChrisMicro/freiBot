/*************************************************************************
  
  Radio Controlled freiBot

  Use two channels of a standart remote radio controll for steering the
  robot.
  This programm is tested with a Spectrum DX6i and an Orange receiver.
  
  Channel1 connected to THROTTLE
  Channel2 connected to AILERON
  
*************************************************************************/

#include "freiBot.h"
#include "motor.h"


#define RADIOCONTROLL_PIN_CHANNEL1 A4
#define RADIOCONTROLL_PIN_CHANNEL2 A5


void setup()
{
  initRobotHardware();
  pinMode(RADIOCONTROLL_PIN_CHANNEL1, INPUT);
  pinMode(RADIOCONTROLL_PIN_CHANNEL2, INPUT);

  Serial.begin(9600);
  
  // eyes ON
  setLed(EYE_LED_LEFT,  1);
  setLed(EYE_LED_RIGHT, 1);
}


// return value range: 0..1000
uint16_t getRadioControl(uint8_t channel)
{
  uint8_t pin;
  uint32_t time_us;
  int32_t value;


  if (channel == 0) pin = RADIOCONTROLL_PIN_CHANNEL1;
  if (channel == 1) pin = RADIOCONTROLL_PIN_CHANNEL2;

  // wait for low
  while (digitalRead(pin) != 0);
  // wait for high
  while (digitalRead(pin) == 0);
  time_us = micros();
  // wait for low
  while (digitalRead(pin) != 0);
  value = micros() - time_us;
  if (value < 1100) value = 1100;
  if (value > 2000) value = 2000;
  return value - 1100;
}


void loop()
{
  static int counter = 0;
  int l, r;
  int a, b;
  
  a = getRadioControl(0);
  b = getRadioControl(1);
  
  r = (a - (b - 400)) / 8;
  l = (a + (b - 400)) / 8;
  
  SetMotorPower (  l,  r);
  
  Serial.print(l); Serial.print(",");  Serial.println(r);

  if (counter == 0) // eyes off
  {
    setLed(EYE_LED_LEFT,  0);
    setLed(EYE_LED_RIGHT, 0);
  }
  
  counter++;
  
  if (counter == 50) // eye flash
  {
    setLed(EYE_LED_LEFT,  1);
    setLed(EYE_LED_RIGHT, 1);
    counter = 0;

  }
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



