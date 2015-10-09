#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __SOUND__
  #define __SOUND__

  #include "stdint.h"
  
  void Sound ( uint16_t freq,  uint16_t duration_msec,  uint8_t  amplitude);
  void motorTone(uint16_t freq_HZ, uint16_t duration_ms);
  
  #define BEEP motorTone (1000, 100)
 
  #endif // __SOUND__

#ifdef __cplusplus
}
#endif
