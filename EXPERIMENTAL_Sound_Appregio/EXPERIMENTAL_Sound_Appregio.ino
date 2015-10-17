#include "freiBot.h"
// http://fonte.me/arduino/#Arpeggio

/*
 Arpeggio
 
 Plays arpeggios of chosen chords
 
 Requires an 8-ohm speaker on digital pin 8
 
//Copyright (c) 2012 Jeremy Fonte
//This code is released under the MIT license
//http://opensource.org/licenses/MIT

// code addapted to freiBot: stochri 2015

 */
 #include "pitches.h"

void playArp(int notes[]);

// available chord to arpeggiate
//C major
int c[] = {
  NOTE_C4, NOTE_E4,NOTE_G4, NOTE_C5, NOTE_E5};

//D minor
int d[] = {
  NOTE_D4, NOTE_F4,NOTE_A4, NOTE_D5, NOTE_F5};

//E minor
int e[] = {
  NOTE_E4, NOTE_G4,NOTE_B4, NOTE_E5, NOTE_G5};

//F major
int f[] = {
  NOTE_F4, NOTE_A4,NOTE_C5, NOTE_F5, NOTE_A5};

//G major
int g[] = {
  NOTE_G4, NOTE_B4,NOTE_D5, NOTE_G5, NOTE_B5};

//A minor
int a[] = {
  NOTE_A4, NOTE_C5,NOTE_E5, NOTE_A5, NOTE_C6};

//B diminished
int b[] = {
  NOTE_B4, NOTE_D5,NOTE_F5, NOTE_B5, NOTE_D6};

void setup() {
}

void loop() {
  //list any chord sequence here by calling playArp(chord)
  //Only plays chords in the key of C Major/A Minor
  //for example, C Major is playArp(c) and A Minor is playArp(a)
  playArp(c);
  playArp(b);
  playArp(a);
  playArp(g);
  delay(5000);
}

void playArp(int notes[]) {
   // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote <= 3; thisNote++) {

    //tone(8, notes[thisNote],125);
        motorTone( notes[thisNote],125);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = 125;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    //noTone(8);
  }
  for(int thisNote = 4; thisNote >= 1; thisNote--) {
    
    //tone(8, notes[thisNote],125);
    motorTone( notes[thisNote],125);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = 125;
    delay(pauseBetweenNotes);

  }
}
