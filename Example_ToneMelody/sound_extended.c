#include "asuro.h"
#include "sound.h"

#define ONETONE_DURATION_MS 10

uint8_t Loudness=255;

void motrChirp(uint16_t startFreq_HZ, uint16_t stopFreq_HZ,uint16_t duration_ms)
{
  uint16_t n;
  uint16_t increment;
  increment=(stopFreq_HZ-startFreq_HZ)*ONETONE_DURATION_MS/duration_ms;
  for(n=startFreq_HZ;n<stopFreq_HZ;n+=increment)
  {
    Sound (n,ONETONE_DURATION_MS,Loudness);

    //motorTone(n,ONETONE_DURATION_MS);
  }
}

void ringSound()
{
  uint8_t n;
  for(n=0;n<5;n++)
  {
    BEEP;
    delay(100);
  }
}

void chirp()
{
 motrChirp(1000,2000,100);
}

