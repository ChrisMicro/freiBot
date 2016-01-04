/*
  Connecting a HC05 Bluetooth modul to soft serial.
  Forwad commands from bluetooth to the serial line and reverse.
  
  2016 ChrisMicro

*/

#include <SoftwareSerial.h> 
#include "pin_defintions.h"

SoftwareSerial BTSerial( BLUE_TXD_ARDUINO_RXD , BLUE_RXD_ARDUINO_TXD ); 

void setup() 
{
  Serial.begin(9600);
  BTSerial.begin(9600);  
}

void loop()   
{
  if (BTSerial.available())
  {
    Serial.write(BTSerial.read());
  }

  if (Serial.available())
  {
    BTSerial.write(Serial.read());
  }
}

