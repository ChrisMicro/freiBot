#include "arduAsuro.h"

void Msleep(uint32_t time_ms)
{
  delay(time_ms);
}

void Init(void)
{
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

