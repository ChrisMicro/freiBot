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

#define AVERAGING_EYE_VALUES 170

uint16_t get_eyeValue(uint8_t side)
{
  uint16_t eye, n;
  uint32_t value = 0;

  if (side == LEFT) eye = EYE_LED_LEFT;
  else              eye = EYE_LED_RIGHT;

  pinMode(eye, OUTPUT);
  digitalWrite(eye, 0); // discharge
  pinMode(eye, INPUT);

  for (n = 0; n < AVERAGING_EYE_VALUES; n++)
  {
    value = value+ analogRead(eye);
  }

  value /= AVERAGING_EYE_VALUES;

  return value;
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
  static uint8_t oldState=0;
  uint8_t state;
  uint8_t result=0;
  
  state=!digitalRead(WHISKERPIN);
  
  if((state!=0)&&(oldState==0)) result=1;

  oldState=state;
  
  return result;
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

// original sound code from Asuro:
/****************************************************************************/
/*!
  \file     sound.c
  \brief    Soundausgabe Funktionen
  Mit den Motoren des ASUROs lassen sich auch Töne erzeugen.\n
  Das Prinzip dahinter ist folgendes:\n
  Die Frequenz des Tons wird durch umschalten der Motor Drehrichtung bestimmt.\n
  Die Lautstärke wird über die Geschwindigkeit der Motoren bestimmt.\n
  Theoretisch liessen sich damit auch Stereo Signale erzeugen, da es ja zwei\n
  Motoren gibt, die sich auch getrennt ansteuern lassen. Dazu müsste die\n
  Sound Funktion allerdings umgeschrieben werden.
  \see      Define fuer die Steuerung der Motoren in asuro.h\n
            FWD, RWD
  \version  sto2 - 01.09.2006 - stochri\n
            first version
  \version  V001 - 09.02.2007 - m.a.r.v.i.n\n
            +++ Alle Funktionen\n
            Kommentierte Version (KEINE Funktionsaenderung)
  \version  V002 - 18.02.2007 - Sternthaler\n
            +++ Alle Funktionen\n
            Einheitliche Formatierung zu den anderen Sourcen.
  \version  V003 - 26.06.2007 - stochri\n
            Bugfix Fehler in der Soundlaenge (max. 250ms)  
            
*****************************************************************************/
/*****************************************************************************
*                                                                            *
*   This program is free software; you can redistribute it and/or modify     *
*   it under the terms of the GNU General Public License as published by     *
*   the Free Software Foundation; either version 2 of the License, or        *
*   any later version.                                                       *
*                                                                            *
*****************************************************************************/
//#include "asuro.h"



/****************************************************************************/
/*!
  \brief
  Soundausgabe ueber die Motoren.
  \param[in]
  freq          Frequenz in Hz
  \param[in]
  duration_msec Laenge in Millisekunden
  \param[in]
  amplitude     Amplitude
  \return
  nichts
  \par  Beispiel:
  (Nur zur Demonstration der Parameter/Returnwerte)
  \code
  // Laesst den Asuro einen Ton von 1kHz für eine 1/2 Sekunde
  // mit max. Amplitude (255) spielen.
  Sound (1000, 500, 255);
  \endcode
*****************************************************************************/
/*
void Sound (
  uint16_t freq,
  uint16_t duration_msec,
  uint8_t  amplitude)
{
  uint16_t wait_tics;
  uint32_t n,k,period_usec,dauer_usec;

  period_usec = 1000000L / freq;
  dauer_usec = 1000 * (uint32_t) duration_msec;
  k = dauer_usec / period_usec;

  //IR Interuptfreq=36KHz
  //Wavefreq=18KHz

  wait_tics = 18000 / freq;

  MotorSpeed (amplitude, amplitude);

  for (n = 0; n < k; n++)
  {
    MotorDir (FWD, FWD);
    Sleep (wait_tics);
    MotorDir (RWD, RWD);
    Sleep (wait_tics);
  }
  MotorSpeed (0, 0);
}*/


#define BEEP sound (1000, 100, 255)

