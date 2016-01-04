 /*
*
* Compatiblity library for the "freiBot" 
* Functions like the ASURO LIB
*
* http://sourceforge.net/projects/asuro/
*
*/
#include "asuro.h"

extern "C"
{
	void Msleep(uint32_t time_ms)
	{
	  delay(time_ms);
	}

	void Sleep(uint32_t time_us)
	{
	  delayMicroseconds(time_us);
	}

	void MotorSpeed(uint8_t left, uint8_t right)
	{
	  analogWrite(ENABLE_RIGHT, right);
	  analogWrite(ENABLE_LEFT, left);
	}

	void MotorDir(uint8_t left, uint8_t right)
	{
	  //*************** left motor *****************
	  if (left == FWD)
	  {
	    digitalWrite(MOTOR_LEFT1, LOW);
	    digitalWrite(MOTOR_LEFT2, HIGH);
	  }
	  if (left == RWD)
	  {
	    digitalWrite(MOTOR_LEFT1, HIGH);
	    digitalWrite(MOTOR_LEFT2, LOW);
	  }
	  if (left == BREAK)
	  {
	    digitalWrite(MOTOR_LEFT1, LOW);
	    digitalWrite(MOTOR_LEFT2, LOW);
	    MotorSpeed(255, 255);
	  }
	  if (left == FREE)
	  {
    	    analogWrite(ENABLE_LEFT, 0);
    	    digitalWrite(MOTOR_LEFT1, LOW);
	    digitalWrite(MOTOR_LEFT2, LOW);
	  }
	  //********** right motor ********************
	  if (right == FWD)
	  {
	    digitalWrite(MOTOR_RIGHT1, LOW);
	    digitalWrite(MOTOR_RIGHT2, HIGH);
	  }
	  if (right == RWD)
	  {
	    digitalWrite(MOTOR_RIGHT1, HIGH);
	    digitalWrite(MOTOR_RIGHT2, LOW);
	  }
	  if (right == BREAK)
	  {
	    digitalWrite(MOTOR_RIGHT1, LOW);
	    digitalWrite(MOTOR_RIGHT2, LOW);
	    MotorSpeed(255, 255);
	  }
	  if (right == FREE)
	  {
	    analogWrite(ENABLE_RIGHT, 0);
	    digitalWrite(MOTOR_RIGHT1, LOW);
	    digitalWrite(MOTOR_RIGHT2, LOW);
	  }

	}

	/*!
	 *  moves the robot forward/backward  OR  turns the robot 
	 *        You can use the old function-names Go() and Turn()
	 *
	 * \param distance travalling distance in cm. positive = forward, negative = backward
	 *             
	 * \param degree degrees to turn. positive = turn right, negative = turn left. range: -360..360
	 * \param speed motor speed. range: 0..255
	 *
	 */
	// void GoTurn(int distance, int degree, int speed);

	// tbd: rework
	// preliminary functions:
	// there is no encoder evailable on this robot
	// therefore the distance is even a coarse estimation
	#define DISTANCE_FACTOR 32
	#define TURN_FAKTOR 33

	void Go(int16_t distance, uint8_t speed) 
	{
	  if(distance>0)  MotorDir(FWD, FWD); 
	  else            MotorDir(RWD, RWD); 
	  MotorSpeed(speed,speed);
	  delay((int32_t)abs(distance)*DISTANCE_FACTOR);
	  MotorDir(BREAK,BREAK); // rotate if there is no signal
	  delay(200);
	}

	void Turn(int16_t degree, uint8_t speed)
	{
	  if(degree>0)  MotorDir(FWD, RWD);
	  else          MotorDir(RWD, FWD); 
	  MotorSpeed(speed,speed);
	  delay((int32_t)abs(degree)*TURN_FAKTOR/10);
	  MotorDir(BREAK,BREAK); 
	  delay(200);
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

