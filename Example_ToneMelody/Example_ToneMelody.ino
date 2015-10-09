/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

modified for genubot: ChrisMicro Sep.2015


 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "freiBot.h"
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void Sound2 (
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
    delayMicroseconds (wait_tics);
    MotorDir (RWD, RWD);
    delayMicroseconds (wait_tics);
  }
  MotorSpeed (0, 0);
}

void setup() 
{
  initRobotHardware();
  int geschwindigkeit=50;
  delay(5000); 

         
  MotorSpeed(geschwindigkeit, geschwindigkeit);
  
      MotorDir (FWD, FWD);
    delay(500);
    MotorDir (RWD, RWD);
    delay (500);
      MotorDir(FREE, FREE);
  delay(2000); 
  
  // left motor forward  
  MotorDir( FWD,FREE);
  delay(500); 
  MotorDir(FREE, FREE);
  delay(2000); 

  // left motor backward  
  MotorDir(RWD,FREE);
  delay(500); 
  MotorDir(FREE, FREE);
  delay(2000);
  
  MotorSpeed(0, geschwindigkeit);
  
  // right motor forward  
  MotorDir(BREAK, FWD);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000); 

  // right motor backward  
  MotorDir(BREAK, RWD);
  delay(500); 
  MotorDir(BREAK, BREAK);
  delay(2000); 
    
    
    
         Sound2 (440, 1000,50);
         while(1);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];

    //motorTone(melody[thisNote], noteDuration);
     Sound (thisNote, noteDuration,50);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:

  }
}

void loop() {
  // no need to repeat the melody.
}


