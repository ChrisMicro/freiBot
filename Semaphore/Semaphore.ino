#include "freiBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}



uint8_t Semaphore = 0;
// robot state machine with semaphores
void stateMachine()
{
  while (1)
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
      } else
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
      } else
      {
        if (millis() > stopTime)
        {
          stateFlag = 0;
          Semaphore = 2;
        }
      }
    }
  }
}

#define MAXSPEED 230
#define MINSPEDD 1
#define SPEEDINCREMENT 10

void lightChaser()
{
  uint8_t leftSpeed = 0;
  uint8_t rightSpeed = 0;
  MotorDir(FWD, FWD);

  while (1)
  {
    MotorSpeed(leftSpeed, rightSpeed);
    if (get_eyeValue(LEFT) > get_eyeValue(RIGHT))
    {
      leftSpeed += SPEEDINCREMENT;
      rightSpeed -= SPEEDINCREMENT;

      setLed(EYE_LED_LEFT, 1);
      setLed(EYE_LED_RIGHT, 0);
      delay(10);
    }
    else
    {
      leftSpeed -= SPEEDINCREMENT;
      rightSpeed += SPEEDINCREMENT;
      setLed(EYE_LED_LEFT, 0);
      setLed(EYE_LED_RIGHT, 1);
      delay(10);
    }
    if (leftSpeed < MINSPEDD)leftSpeed = MINSPEDD;
    if (rightSpeed < MINSPEDD)rightSpeed = MINSPEDD;
    if (leftSpeed > MAXSPEED )leftSpeed = MAXSPEED ;
    if (rightSpeed > MAXSPEED )rightSpeed = MAXSPEED ;
  }
}

void testIrInput()
{
  setLed(EYE_LED_LEFT, 0);
  waitForIrSignal();
  setLed(EYE_LED_LEFT, 1);
  delay(100);
}

void simpleIrMotorControl()
{
  int n, k;
  BEEP;
  waitForIrSignal(); // wait for start signal
  MotorDir(FWD, RWD); // rotate if there is no signal
  MotorSpeed(200, 200);
  for (n = 0; n < 300; n++)
  {
    if(isIrSignal()) // if signal, go forward
    {
      setLed(EYE_LED_LEFT, 1);
      MotorDir(FWD, FWD); 
      delay(500);
      setLed(EYE_LED_LEFT, 0);
    } else 
    {
      MotorDir(FWD, RWD); // rotate if there is no signal
      delay(10);
    }
    if(whiskerTouched())
    {
      chirp();

      MotorSpeed(200, 200);
      // go back
      MotorDir(RWD, RWD); 
      delay(300);
      // turn
      MotorDir(FWD, RWD);
      delay(300);
    }
  }
  MotorDir(FREE, FREE); // turn of motor if there is no signal

}



void loop()
{
  simpleIrMotorControl();
  //testIrInput();
  /*
  lightChaser();
  Serial.print("left: "); Serial.print(get_eyeValue(LEFT));
  Serial.print("  right: "); Serial.println(get_eyeValue(RIGHT));
  delay(10);
  */
}

