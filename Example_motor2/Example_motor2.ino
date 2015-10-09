
#include "freiBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}
  
void loop()
{
  Go(20,255); // full speed 20cm forward 
  delay(1000);
  
  Go(-20,255); // full speed 20cm backward
  delay(1000);
  
  Turn(180,255); // full speed +180 degree
  delay(1000);
  
  Turn(-180,255); // full speed -180 degree
  delay(1000);
  
  delay(5000);
}


