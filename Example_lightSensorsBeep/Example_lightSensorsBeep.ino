
#include "genuBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}


int pitch;
  
void loop()
{
  int left;
  int right;
  
  left  = get_eyeValue(LEFT);
  right = get_eyeValue(RIGHT);

  if(left>right)  pitch=(pitch*11)/10;
  else            pitch=(pitch*10)/11; 

  if( pitch > 1000) pitch=1000;
  if( pitch < 400)  pitch=400;
  
  motorTone(pitch, 100);
}


