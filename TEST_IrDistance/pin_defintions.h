/*************************************************************************************

  GENUBOT 

  robot hardware:

  microcontroller:     Arduino Nano
  motor driver:        L293D
  motors:              Pollin motors 
  wheels:              inline skate ball bearings
  
  sensors:
  - button
  - 1 whisker 
  - 2 LEDs ( used as light sensor )
  - MPU6050 3 axis accelerometer/gyrometer 
  - IR sensor SFH5110

************************************************************************************/

// Arduino Nano pin out and schematic:
// https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf

// connecting the ARDUINO Nano and the MPU6050 accelerometer:
// http://shirotsuku.sakura.ne.jp/blog/?p=442
// ( interrupt pin is not connected at the moment to genubot )

// net list:
//===== robot pin name =  ARDUINO pin ===============================================================
#define MOTOR_RIGHT1     2 // dout, L293D pin10, motor driver right side, half bridge 1
#define MOTOR_RIGHT2     3 // dout, L293D pin15, motor driver right side, half bridge 2
#define IR_SENSOR        4  // din , SFH5110 sensor ( signal is active low )
#define IR_LED           5  // output
#define NEOPIXEL_PIN     7  // dout, WS2812 RGB LED controll pin
#define ENABLE_RIGHT     9  // dout, L293D pin1, motor driver enable pin for right motor, OC1B used for motor PWM
#define ENABLE_LEFT      10 // dout, L293D pin9, motor driver enable pin for left moter, OC1A used for motor PWM
#define BUTTONPIN        11 // din,  button ( configure with pull up )
#define WHISKERPIN       12 // din,  whisker ( like a button configure with pull up )
#define LEDPIN           13 // dout, ARDUINO NANO LED 

#define EYE_LED_LEFT     A0 // dout,ain, LED or LED as light sensor
#define EYE_LED_RIGHT    A1 // dout,ain, LED or LED as light sensor
#define MOTOR_LEFT2      A2  // dout, L293D pin2, motor driver left side half bridge 2
#define MOTOR_LEFT1      A3  // dout, L293D pin7, motor driver left side half bridge 1

// A2
// A3
#define I2C_SDA_PIN      A4 // I2C SDA, connected to MPU6050
#define I2C_SCL_PIN      A5 // I2C SCL, connected to MPU6050
// A6
// A7

// tbd:
// IR-LED digital out for distance sensor
// digital input for second whisker
// CNY70 line sensor digital out for LED
// CNY70 line sensor digital in for sensor

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
