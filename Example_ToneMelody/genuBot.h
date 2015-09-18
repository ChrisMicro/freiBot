
  #include "arduAsuro.h"
  
  void initRobotHardware(void);
  void setLed(uint8_t led, uint8_t value);
  uint8_t isIrSignal(void);
  void waitForIrSignal(void);
  uint8_t whiskerTouched(void);
  void motorTone(uint16_t freq_HZ, uint16_t duration_ms);
  void motrChirp(uint16_t startFreq_HZ, uint16_t stopFreq_HZ,uint16_t duration_ms);
  void ringSound(void);
  void chirp(void);
  void beep(void);



