
#include "genuBot.h"

void setup()
{
  initRobotHardware();

}


void loop()
{
  int geschwindigkeit=100;
  delay(5000); 


  MotorSpeed(geschwindigkeit, 0);
  
    // left motor forward  
  MotorDir( FWD,BREAK);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000); 

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
  delay(2000); 
  
}


