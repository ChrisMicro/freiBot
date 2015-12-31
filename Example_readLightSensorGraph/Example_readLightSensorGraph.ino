
/*
  ligth sensor to graphics

  The newer ARDUINO IDEs have the possibility to display data as a graph. Use the menue point

  Werkzeuge => Serialler Plotter

  to display the values.

  2015 by ChrisMicro
 
 */
#include "freiBot.h"

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
}


void loop()
{
  int value;
  
  value  = get_eyeValue(LEFT);
            
  Serial.println( value );
  //  Serial.println( value );
 
  delay(100);
}


