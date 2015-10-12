
/*************************************************************************
  
  TESTPROGRAM: Are the motors connected correct?
  
  1. left  motor forward  
  2. left  motor backward  
  3. right motor forward  
  4. right motor backward  

  
*************************************************************************/
#include "freiBot.h"

void setup()
{
  initRobotHardware();
}


void loop()
{
  int maxSpeed=200;
  delay(5000); 
  
  //************** left motor forward ********************************
  digitalWrite(MOTOR_LEFT1, LOW);
  digitalWrite(MOTOR_LEFT2, HIGH);

  analogWrite(ENABLE_LEFT, maxSpeed);
  delay(1000); 

  analogWrite(ENABLE_LEFT, 0); // turn off
  delay(5000); 
  
  //************** left motor backward ********************************
  digitalWrite(MOTOR_LEFT1, HIGH);
  digitalWrite(MOTOR_LEFT2, LOW);

  analogWrite(ENABLE_LEFT, maxSpeed);
  delay(1000); 

  analogWrite(ENABLE_LEFT, 0); // turn off
  delay(5000); 

  //************** RIGHT motor forward ********************************
  digitalWrite(MOTOR_RIGHT1, LOW);
  digitalWrite(MOTOR_RIGHT2, HIGH);

  analogWrite(ENABLE_RIGHT, maxSpeed);
  delay(1000); 

  analogWrite(ENABLE_RIGHT, 0); // turn off
  delay(5000); 
  
  //************** RIGHT motor backward ********************************
  digitalWrite(MOTOR_RIGHT1, HIGH);
  digitalWrite(MOTOR_RIGHT2, LOW);

  analogWrite(ENABLE_RIGHT, maxSpeed);
  delay(1000); 

  analogWrite(ENABLE_RIGHT, 0); // turn off
  delay(5000); 


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


