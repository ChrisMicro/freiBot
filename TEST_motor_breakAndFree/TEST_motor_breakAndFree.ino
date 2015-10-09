
/*************************************************************************
  
  TESTPROGRAM: 
  
  Test the decelaration difference with the motor parameters 
  BREAK and FREE.
  
  In the BREAK mode the motors are "short cut" and the break is hard.
  In the Free mode the motor pins are high impedance and the robot is 
  breaking smoothly.
  
  1. move vorward and break
  2. move backward and break
  3. move vorward and break free
  4. move backward and break free
  
*************************************************************************/
#include "freiBot.h"

void setup()
{
  initRobotHardware();
}

void loop()
{
  int maxSpeed=150;
  delay(5000); 

  // left motor forward  
  MotorSpeed(maxSpeed, maxSpeed);
  MotorDir( FWD,FWD);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000); 

  // left motor backward  
  MotorSpeed(maxSpeed, maxSpeed);
  MotorDir(RWD,RWD);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(5000);
  
  // left motor forward  
  MotorSpeed(maxSpeed, maxSpeed);
  MotorDir( FWD,FWD);
  delay(500); 
  MotorDir(FREE, FREE);
  delay(2000); 

  // left motor backward  
  MotorSpeed(maxSpeed, maxSpeed);
  MotorDir(RWD,RWD);
  delay(500); 
  MotorDir(FREE, FREE);
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


