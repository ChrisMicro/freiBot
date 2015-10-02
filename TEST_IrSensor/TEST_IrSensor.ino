
#include "genuBot.h"

void setup()
{
  initRobotHardware();
}

void loop()
{
    if (isIrSignal()) // if signal, go forward
    {
    setLed(EYE_LED_LEFT,  1);
    setLed(EYE_LED_RIGHT, 0);

    } else
    {
    setLed(EYE_LED_LEFT,  0);
    setLed(EYE_LED_RIGHT, 1);
    }

    delay(200);
    


}


