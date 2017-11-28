/*

  T-Robot
*/

#include "tservo.h"


void setup()
{
  initServo();
}

void loop()
{

  turn(0); // obere Position
  delay(1000); // eine Sekunde Verzögerung
  
  turn(45); // untere Position
  delay(1000);
  
  turn(0);
  delay(1000);
  
  turn(45);
  delay(1000);
  
  turn(0); // Ausgangsposition

  stopServo(); // Servo Strom wegnehmen

  while (1) // Stop undBlinken
  {
    toggleLed(); // LED umschalten
    delay(1000);
  }
}

