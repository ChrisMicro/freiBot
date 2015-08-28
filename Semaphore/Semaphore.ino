#include "arduAsuro.h"

uint8_t whiskerTouched()
{
  return !digitalRead(WHISKERPIN);
}

void setup()
{
  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(WHISKERPIN, INPUT_PULLUP);

  pinMode(LEDPIN, OUTPUT); 
  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);
    
  Init();
  Serial.begin(9600);
}

uint8_t Semaphore = 0;

// robot state machine with semaphores
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
  
  if (whiskerTouched())
  {
      MotorDir(RWD, RWD);
      MotorSpeed(255, 100);
      digitalWrite(EYE_LED_LEFT,  0);
      digitalWrite(EYE_LED_RIGHT, 1);
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
      digitalWrite(EYE_LED_LEFT,  1);
      digitalWrite(EYE_LED_RIGHT, 1);
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
      digitalWrite(EYE_LED_LEFT,  0);
      digitalWrite(EYE_LED_RIGHT, 0);
    }else
    {
      if (millis() > stopTime)
      {
        stateFlag = 0;
        Semaphore = 2;
      }
    }
  }


}
