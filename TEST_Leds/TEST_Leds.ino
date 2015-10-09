
#include "freiBot.h"

void setup()
{
  initRobotHardware();
}

void loop()
{

    setLed(EYE_LED_LEFT,  1);
    setLed(EYE_LED_RIGHT, 0);
    delay(200);
    
    setLed(EYE_LED_LEFT,  0);
    setLed(EYE_LED_RIGHT, 1);
    delay(200);

}


