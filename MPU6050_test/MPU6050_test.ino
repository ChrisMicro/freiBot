#include "arduAsuro.h"
// MPU6050 test for genubot
// function:
// touch the robot and it will turn
// made by ChrisMicro alias stochri

// use the MPU6050 library from jeff rowberg:
// I2C device class (I2Cdev) demonstration Arduino sketch for MPU6050 class
// 10/7/2011 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high

int16_t ax, ay, az;

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(WHISKERPIN, INPUT_PULLUP);

  pinMode(LEDPIN, OUTPUT);
  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);

  Init();


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  // initialize device
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

}

void loop() {
  uint32_t acceleration;
  accelgyro.getAcceleration(&ax, &ay, &az);
  // display tab-separated accel/gyro x/y/z values
  Serial.print("a/g:\t");
  Serial.print(ax / 100); Serial.print("\t");
  Serial.print(ay / 100); Serial.print("\t");
  Serial.print(az / 100); Serial.print("\t");
  acceleration = sqrt((ax / 100) * (ax / 100) + (ay / 100) * (ay / 100) + (az / 100) * (az / 100));
  Serial.print("  accelleration:");
  Serial.println(acceleration);

  if (acceleration <10)
  {
    MotorDir(FWD, RWD);
    MotorSpeed(250, 250);
    delay(1000);
    MotorDir(FREE, FREE);
    delay(1000);
  }
}
