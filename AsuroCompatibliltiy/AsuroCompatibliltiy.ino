#include "arduAsuro.h"

const int sensor = A1;
const int buttonPin = 11;
const int ledPin =  13;

#define ENABLE_RIGHT 10
#define MOTOR_RIGHT1  2
#define MOTOR_RIGHT2  3

#define ENABLE_LEFT  9
#define MOTOR_LEFT1  A2
#define MOTOR_LEFT2  A3

int buttonState = 0;

void MotorSpeed(uint8_t left, uint8_t right)
{
  analogWrite(ENABLE_RIGHT, left);
  analogWrite(ENABLE_LEFT, right);
}

void MotorDir(uint8_t left, uint8_t right)
{
  //*************** left motor *****************
  if (left == FWD)
  {
    digitalWrite(MOTOR_LEFT1, LOW);
    digitalWrite(MOTOR_LEFT2, HIGH);
  }
  if (left == RWD)
  {
    digitalWrite(MOTOR_LEFT1, HIGH);
    digitalWrite(MOTOR_LEFT2, LOW);
  }
  if (left == BREAK)
  {
    digitalWrite(MOTOR_LEFT1, LOW);
    digitalWrite(MOTOR_LEFT2, LOW);
    MotorSpeed(255, 255);
  }
  if (left == FREE)
  {
    MotorSpeed(0, 0);
  }
  //********** right motor ********************
  if (right == FWD)
  {

        digitalWrite(MOTOR_RIGHT1, HIGH);
    digitalWrite(MOTOR_RIGHT2, LOW);
  }
  if (right == RWD)
  {
    digitalWrite(MOTOR_RIGHT1, LOW);
    digitalWrite(MOTOR_RIGHT2, HIGH);
  }
  if (right == BREAK)
  {
    digitalWrite(MOTOR_RIGHT1, LOW);
    digitalWrite(MOTOR_RIGHT2, LOW);
    MotorSpeed(255, 255);
  }
  if (right == FREE)
  {
    MotorSpeed(0, 0);
  }

}


void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(sensor, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);

  pinMode(ENABLE_RIGHT, OUTPUT);
  pinMode(MOTOR_RIGHT1, OUTPUT);
  pinMode(MOTOR_RIGHT2, OUTPUT);

  pinMode(ENABLE_LEFT, OUTPUT);
  pinMode(MOTOR_LEFT1, OUTPUT);
  pinMode(MOTOR_LEFT2, OUTPUT);

  // Motor rechts Vorwertsfahrt, dauerhaft
  digitalWrite(MOTOR_RIGHT1, HIGH);
  digitalWrite(MOTOR_RIGHT2, LOW);

  // Motor links Vorwertsfahrt, dauerhaft
  digitalWrite(MOTOR_LEFT1, LOW);
  digitalWrite(MOTOR_LEFT2, HIGH);
}

void loop()
{
  int n;
  if (digitalRead(buttonPin))
  {
    digitalWrite(ledPin, true);
    delay(10);
    digitalWrite(ledPin, false);
    delay(500);
  } else
  {
    digitalWrite(ledPin, false);

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
