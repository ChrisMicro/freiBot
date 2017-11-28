#include <Servo.h>

Servo myservo;  

void turn( int position_degrees )
{
  static int pos = 0;
  while (pos != position_degrees)
  {
    if (position_degrees > pos) pos++;

    if (position_degrees < pos) pos--;
    myservo.write(pos);
    delay(50);
  }
}

void initServo()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);


}

void stopServo()
{
    myservo.detach();
}

void toggleLed()
{
  static uint8_t flag = 0;
  digitalWrite(LED_BUILTIN, flag);
  flag = flag ^ 1;
}


