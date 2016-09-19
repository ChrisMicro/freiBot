
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
  int geschwindigkeit=200;
  delay(5000); 

  MotorSpeed(geschwindigkeit, geschwindigkeit);
  
  // left motor forward  
  MotorDir( FWD,FWD);


  delay(10000); 
    MotorDir(BREAK, BREAK);
/*
  // left motor backward  
  MotorDir(RWD,BREAK);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000);
  
  MotorSpeed(0, geschwindigkeit);
  
  // right motor forward  
  MotorDir(BREAK, FWD);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000); 

  // right motor backward  
  MotorDir(BREAK, RWD);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000); */
  while(1);
  
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


