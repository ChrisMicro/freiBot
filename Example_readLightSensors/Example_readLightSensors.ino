
#include "genuBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}

void loop()
{
  int left;
  int right;
  
  left  = get_eyeValue(LEFT);
  right = get_eyeValue(RIGHT);

  if(left>right)   Serial.print("    (o) (-)     ");
  else             Serial.print("    (-) (0)     ");
            
  Serial.print("l:");   Serial.print( left );
  Serial.print(" r:");  Serial.print( right );
  
  Serial.println();
  
  delay(100);
}


