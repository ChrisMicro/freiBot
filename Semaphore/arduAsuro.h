#include "Arduino.h"
#include "stdint.h"

// Arduino Nano pin out and schematic:
// https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf

//===== robot pin  ===  ARDUINO pin ====
#define MOTOR_RIGHT1    2
#define MOTOR_RIGHT2    3
#define IR_SENSOR       4 // signal of SFH5110 sensor is active low
#define ENABLE_LEFT     9 // OC1A used for motor PWM
#define ENABLE_RIGHT   10 // OC1B used for motor PWM
#define BUTTONPIN      11
#define WHISKERPIN     12
#define LEDPIN         13 // ARDUINO LED & I2C SCK

#define EYE_LED_LEFT   A0 // digital out or analog in
#define EYE_LED_RIGHT  A1 // digital out or analog in
#define MOTOR_LEFT1    A2
#define MOTOR_LEFT2    A3
// A2
// A3
// A4 analog4 input and I2C SDA
// A5 analog5 input and I2C SCL
// A6
// A7



// ASRURO Motor states
#define FREE    0                     /*!< Motor freilaufend */
#define BREAK   1                     /*!< Motor bremsen */
#define FWD     2                     /*!< Motor vorwaerts */
#define RWD     3                     /*!< Motor rueckwaerts */

#define LEFT	1
#define RIGHT   2

void Init(void);
void Msleep(uint32_t time_ms);
void MotorSpeed(uint8_t left, uint8_t right);
void MotorDir(uint8_t left, uint8_t right);

// exampels:
//  MotorSpeed(150,150);
//  MotorDir(FWD,FWD);
