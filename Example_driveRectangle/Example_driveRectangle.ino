
#include "genuBot.h"

void setup()
{
  initRobotHardware();
}

int groesse         = 20; // in cm
int geschwindigkeit = 255;
  
void loop()
{
  int n;
  
  for(n=0;n<4;n++)
  {
    Go   ( groesse, geschwindigkeit ); 
    Turn ( 90,      geschwindigkeit ); // 90 grad
  }  
  
  delay(5000);
}


