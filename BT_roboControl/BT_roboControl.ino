/*
  Controlling the robot with a bluetooth modul hc05

  You may control the robot with a mobile phone
  The commands are compatible to this APP for a mobile phone:
  https://play.google.com/store/apps/details?id=pl.mobilerobots.vacuumcleanerrobot&hl=de
  
  2016 ChrisMicro

*/

/*

Comands

up:fs
down:bs
left:ls
right:rs
forward right: cs
forward left ds
backward right: es
backward left: hs
go: g
stop: s
<y122>
<x163>


*/


#include <SoftwareSerial.h>
#include "freiBot.h"

SoftwareSerial BTSerial( BLUE_TXD_ARDUINO_RXD , BLUE_RXD_ARDUINO_TXD );
int Speed=255;

void roboPreter(char c)
{
  if (c == 's')
  {
    
    Serial.println("stop");
     MotorSpeed(0,0);
  }
  if (c == 'g')
  {
    Serial.println("go");
    MotorSpeed(Speed, Speed);
  }
  if (c == 'f')
  {
    Serial.println("forward");
    MotorDir(FWD, FWD);
    MotorSpeed(Speed, Speed);
  }
  if (c == 'b')
  {
    Serial.println("fback");
    MotorDir(RWD, RWD);
    MotorSpeed(Speed, Speed);
  }
    if (c == 'l')
  {
    Serial.println("fleft");
    MotorDir(RWD, FWD);
    MotorSpeed(Speed, Speed);
  }
  if (c == 'r')
  {
    Serial.println("rigth");
    MotorDir(FWD, RWD);
    MotorSpeed(Speed, Speed);
  }
    if (c == 'c')
  {
    Serial.println("forward to the right");
    //MotorDir(FWD, BREAK);
    MotorDir(BREAK, FWD);
    MotorSpeed(Speed, Speed);
  }
  if (c == 'd')
  {
    Serial.println("forward to the left");
    //MotorDir(BREAK, FWD);
    MotorDir(FWD, BREAK);
    MotorSpeed(Speed, Speed);
  }
  
  if (c == 'e')
  {
    Serial.println("backward to the right");
    //MotorDir(RWD, BREAK);
    MotorDir(BREAK, RWD);
    .MotorSpeed(Speed, Speed);
  }
  if (c == 'h')
  {
    Serial.println("backward to the left");
    //MotorDir(BREAK, RWD);
    MotorDir(RWD, BREAK);
    MotorSpeed(Speed, Speed);
  }
  
}

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop()
{
  char c;
  if (BTSerial.available())
  {
    c = BTSerial.read();
    Serial.write(c); Serial.println("");
    roboPreter(c);
  }

  if (Serial.available())
  {
    BTSerial.write(Serial.read());
  }
}

