#include "arduAsuro.h"

#define BUTTONPIN  11
#define LEDPIN     13

void setup()
{
  pinMode(BUTTONPIN, INPUT_PULLUP);

  pinMode(LEDPIN, OUTPUT);

  Init();
}

void loop()
{
  int n;
  if (digitalRead(BUTTONPIN))
  {
    digitalWrite(LEDPIN, true);
    delay(10);
    digitalWrite(LEDPIN, false);
    delay(500);
  } else
  {
    digitalWrite(LEDPIN, false);

    for (n = 0; n < 3; n++)
    {

      MotorDir(FWD,FWD);
      MotorSpeed(255,255);

      delay(1000);

      MotorDir(FWD,FWD);
      MotorSpeed(180,180);

      delay(1000);

      MotorDir(FREE,FREE);

      delay(1000);
      
      MotorDir(FWD,RWD);
      MotorSpeed(180,180);
      
      delay(1000);

      MotorDir(FREE,FREE);
      
      delay(3000);

    }
  }
}
