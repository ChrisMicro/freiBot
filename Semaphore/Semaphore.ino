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
#define AVERAGING_EYE_VALUES 200
uint16_t get_eyeValue(uint8_t side)
{
  uint8_t eye, n;
  uint32_t value = 0;

  if (side == LEFT) eye = EYE_LED_LEFT;
  else           eye = EYE_LED_RIGHT;

  pinMode(eye, OUTPUT);
  digitalWrite(eye, 0); // discharge
  pinMode(eye, INPUT);

  for (n = 0; n < AVERAGING_EYE_VALUES; n++)
  {
    value += analogRead(eye);
  }
  value /= AVERAGING_EYE_VALUES;

  return value;
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

void setLed(uint8_t led, uint8_t value)
{
  if (led == EYE_LED_LEFT)
  {
    pinMode(EYE_LED_LEFT, OUTPUT);
    digitalWrite(EYE_LED_LEFT, value);
  }
  if (led == EYE_LED_RIGHT)
  {
    pinMode(EYE_LED_RIGHT, OUTPUT);
    digitalWrite(EYE_LED_RIGHT, value);
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


void loop()
{
  lightChaser();
  Serial.print("left: "); Serial.print(get_eyeValue(LEFT));
  Serial.print("  right: "); Serial.println(get_eyeValue(RIGHT));
  delay(10);
}
