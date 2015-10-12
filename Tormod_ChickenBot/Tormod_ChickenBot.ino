/***********************************************************

 light seeker robot sounding like a chicken.
 
 ***********************************************************/
#include "freiBot.h"

void setup()
{
  initRobotHardware();
  delay(2000); 

}

int groesse         = 20; // in cm
int geschwindigkeit = 105;
int passed = 0;
int toggle = 0;
int tgcount = 0;
int ledR = 0;
int tick = 0;
int orient, oldorient = 0;
int eyeD, oldEyeD = 0;
float meanD;
int flashL;


void loop()
{
  int n;
  int eyeL, eyeR;
  int spike;
  
  for(n=0;n<4;n++)
  {
    tgcount++;
    if (tgcount == 1000) {
      tgcount = 0;
      // setLed(EYE_LED_RIGHT, toggle);
      toggle = 1 - toggle;
      tick = 1;
    } else {
      tick= 0;
    }

    eyeL = get_eyeValue(LEFT);
    eyeR = get_eyeValue(RIGHT);
    oldEyeD = eyeD;
    eyeD = eyeL - eyeR;

    oldorient = orient;
    orient = - eyeD;

    meanD = 0.95 * meanD + 0.05 * orient;
    spike = orient - meanD;
    
    if (orient > 4) {
        Turn ( 10,      geschwindigkeit );
    } else if (orient < -4) {
        Turn ( -10,     geschwindigkeit );
    }

    if (spike > 5) {
        flashL = 100;
        if (spike > 95)
          spike = 95;
        Go( (float) groesse  * (spike - 5) / 20.0, geschwindigkeit );
    }

    if (tick && flashL > 0)
      flashL--;
    if (flashL != 0) {
      // setLed(EYE_LED_LEFT,  1);
    } else {
      // setLed(EYE_LED_LEFT,  0);
    }
    if (isIrSignal()) {
      // setLed(EYE_LED_LEFT,  1);
      if (passed > 50) {
        // setLed(EYE_LED_RIGHT, 1);
        Go   ( groesse, geschwindigkeit );
      } else {
        // setLed(EYE_LED_RIGHT, 0);
        Turn ( 90,      geschwindigkeit ); // 90 grad
      }
      passed = 0;
    } else {
      // setLed(EYE_LED_LEFT,  0);
      passed += tick;
      if (passed > 1000)
         passed = 1000;
    }



    
  } // for
} // loop 
/*******************************************************************************
*   -c--date---version--nickname--------email---------------------------------
*
*   (c) 2015   V0.1     Tormod
*   
*******************************************************************************/

