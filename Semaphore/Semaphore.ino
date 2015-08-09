#include "arduAsuro.h"

#define BUTTONPIN  11
#define LEDPIN     13

void setup()
{
  pinMode(BUTTONPIN, INPUT_PULLUP);

  pinMode(LEDPIN, OUTPUT);

  Init();
  Serial.begin(9600);
}

uint8_t Semaphore = 0;

void loop()
{
  Serial.print("semaphore: "); Serial.println(Semaphore);
  
  if ((Semaphore == FREE) || (Semaphore == 1))
  {
    Semaphore = 1;
    if (!digitalRead(BUTTONPIN)) 
    {
      Semaphore = FREE;
      Serial.println("button pressed");
      digitalWrite(LEDPIN, false);
    }
    else
    {
      digitalWrite(LEDPIN, true);
    }
  }

  if ((Semaphore == FREE) || (Semaphore == 2))
  {
    static uint32_t stopTime;
    static uint8_t stateFlag = 0;

    if (stateFlag == 0)
    {
      Semaphore = 2;
      stopTime = millis() + 1000;

      stateFlag = 1;
      MotorDir(FWD, FWD);
      MotorSpeed(255, 255);
    }else
    {
      if (millis() > stopTime)
      {
        stateFlag = 0;
        Semaphore = FREE;
      }
    }
  }

  if ((Semaphore == FREE) || (Semaphore == 3))
  {
    static uint32_t stopTime;
    static uint8_t stateFlag = 0;

    if (stateFlag == 0)
    {
      Semaphore = 3;
      stopTime = millis() + 1000;
      stateFlag = 1;
      MotorDir(FREE, FREE);
    }else
    {
      if (millis() > stopTime)
      {
        stateFlag = 0;
        Semaphore = FREE;
      }
    }
  }


}
