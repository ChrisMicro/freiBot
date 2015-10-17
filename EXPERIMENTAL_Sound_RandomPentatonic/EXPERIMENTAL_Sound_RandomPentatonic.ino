#include "freiBot.h"

// http://fonte.me/arduino/#Musician
/*
 Musician

Plays a (fairly) random tune until the program is stopped
8-ohm speaker on digital pin 8

//Copyright (c) 2012 Jeremy Fonte
//This code is released under the MIT license
//http://opensource.org/licenses/MIT
*/
// addapte for freiBot: stochri, 2015

int randomNote = 131;
int randomDuration = 2;
int noteStep = 1;
int notes[15];

void setup() {

  pinMode(8, OUTPUT);

  notes[1] = 131;
  notes[2] = 147;
  notes[3] = 165;
  notes[4] = 196;
  notes[5] = 220;
  notes[6] = 262;
  notes[7] = 294;
  notes[8] = 330;
  notes[9] = 392;
  notes[10] = 440;
  notes[11] = 523;
  notes[12] = 587;
  notes[13] = 659;
  notes[14] = 784;
  notes[15] = 880;

  randomNote = random(1, 15);
}

void loop() {
  static uint8_t count = 0;

  setLed(EYE_LED_LEFT,  !((count) & 01));
  setLed(EYE_LED_RIGHT, (count) & 01);
  count++;

  noteStep = random(-3, 3);
  randomNote = randomNote + noteStep;
  if (randomNote < 1) {
    randomNote = random(1, 15);
  }
  else if (randomNote > 15) {
    randomNote = random(1, 15);
  }

  randomDuration = random(1, 8);
  // to calculate the note duration, take one second
  // divided by the note type.
  //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  int noteDuration = 3000 / randomDuration;
  //tone(8, notes[randomNote],noteDuration);
  motorTone( notes[randomNote], noteDuration);

  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(10);
  // stop the tone playing:
  //noTone(8);
}


