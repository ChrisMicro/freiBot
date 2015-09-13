#include "arduAsuro.h"

void initRobotHardware()
{
  pinMode(IR_SENSOR, INPUT);

  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(WHISKERPIN, INPUT_PULLUP);

  pinMode(LEDPIN, OUTPUT);
  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);
  
  pinMode(ENABLE_RIGHT, OUTPUT);
  pinMode(MOTOR_RIGHT1, OUTPUT);
  pinMode(MOTOR_RIGHT2, OUTPUT);

  pinMode(ENABLE_LEFT, OUTPUT);
  pinMode(MOTOR_LEFT1, OUTPUT);
  pinMode(MOTOR_LEFT2, OUTPUT);

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

uint8_t isIrSignal()
{
  return !digitalRead(IR_SENSOR);
}

void waitForIrSignal()
{
  while (!isIrSignal());
}

uint8_t whiskerTouched()
{
  return !digitalRead(WHISKERPIN);
}

/******************* sound functions ***************************************************/
void motorTone(uint16_t freq_HZ, uint16_t duration_ms)
{
  uint16_t n;
  uint32_t delayTime_us;
  uint32_t counts;
  
  delayTime_us=1000000UL/freq_HZ/2;
  counts=duration_ms*1000/delayTime_us;
  MotorSpeed(255, 255);
  
  for(n=0;n<counts;n++)
  {
    MotorDir(FWD, FWD); // rotate if there is no signal
    delayMicroseconds(delayTime_us);
    MotorDir(RWD, RWD); // rotate if there is no signal
    delayMicroseconds(delayTime_us);
  }
  MotorDir(FREE, FREE); // turn of motor if there is no signal
}
// beep with motors
void beep()
{
  motorTone(440,100);
}

#define ONETONE_DURATION_MS 10
void motrChirp(uint16_t startFreq_HZ, uint16_t stopFreq_HZ,uint16_t duration_ms)
{
  uint16_t n;
  uint16_t increment;
  increment=(stopFreq_HZ-startFreq_HZ)*ONETONE_DURATION_MS/duration_ms;
  for(n=startFreq_HZ;n<stopFreq_HZ;n+=increment)
  {
    motorTone(n,ONETONE_DURATION_MS);
  }
}

void ringSound()
{
  uint8_t n;
  for(n=0;n<5;n++)
  {
    beep();
    delay(100);
  }
}

void chirp()
{
 motrChirp(1000,2000,100);
}
