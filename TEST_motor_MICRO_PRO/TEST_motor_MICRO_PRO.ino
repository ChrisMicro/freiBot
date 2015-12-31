#include "freiBot.h"

void setup()
{
  initRobotHardware();
}

int geschwindigkeit = 100;

void loop()
{
  //delay(5000);

  Go   ( 20, geschwindigkeit ); // vorwaerts 20cm
  delay(1000);

  Go   ( -20, geschwindigkeit); // rueckwärts 20cm
  delay(1000);

  Turn ( 90, geschwindigkeit ); // drehen rechts 90 grad
  delay(1000);

  Turn ( -90, geschwindigkeit ); // drehen links 90 grad
  delay(1000);
}


