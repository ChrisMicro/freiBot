/*
  sound test
 */
 
#include "freiBot.h"

void setup() 
{
  initRobotHardware(); 
}

void loop() 
{
  BEEP;                            delay(2000);
  
  ringSound();                     delay(2000);
  
  chirp();                         delay(2000);
    
  motrChirp(300, 6000, 1000);      delay(2000);   //motrChirp(uint16_t startFreq_, uint16_t stopFreq_HZ,uint16_t duration_ms);
    
  delay(5000);

  sirene(2);
}


