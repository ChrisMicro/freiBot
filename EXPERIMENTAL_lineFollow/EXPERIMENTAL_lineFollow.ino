// experimental, not working yet


#include "freiBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}

#define EYESAMPLINGTIME_MS 20

uint16_t get_eyeValue2(uint8_t side)
{
  uint16_t eye,ledEye, n;
  uint32_t value = 0;
  uint32_t stopTime;
  uint32_t count = 0;

  stopTime = millis() + EYESAMPLINGTIME_MS;

  if (side == LEFT)
 {
   eye = EYE_LED_LEFT;
     ledEye = EYE_LED_RIGHT;
 }
  else 
{
  eye = EYE_LED_RIGHT;
     ledEye = EYE_LED_LEFT;
}

  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);
  digitalWrite(ledEye,1); // use as lamp
  digitalWrite(eye, 0); // discharge

  pinMode(eye, INPUT);

  while (millis() < stopTime)
  {
    value = value + analogRead(eye);
    count++;
  }

  value = value / count;
  digitalWrite(ledEye,0); //  lamp off
  return value;
}

void loop()
{
  int left;
  int right;
  
  left  = get_eyeValue2(LEFT);
  right = get_eyeValue2(RIGHT);

  if(left>right)   Serial.print("    (o) (-)     ");
  else             Serial.print("    (-) (0)     ");
            
  Serial.print("l:");   Serial.print( left );
  Serial.print(" r:");  Serial.print( right );
  
  Serial.println();
  
  delay(100);
}


