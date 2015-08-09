#include "Arduino.h"
#include "stdint.h"



#define ENABLE_RIGHT 10
#define MOTOR_RIGHT1  2
#define MOTOR_RIGHT2  3

#define ENABLE_LEFT  9
#define MOTOR_LEFT1  A2
#define MOTOR_LEFT2  A3

#define BREAK   0                     /*!< Motor bremsen */
#define FREE    1                     /*!< Motor freilaufend */
#define FWD     2                     /*!< Motor vorwaerts */
#define RWD     3                     /*!< Motor rueckwaerts */

void Init(void);
void Msleep(uint32_t time_ms);
void MotorSpeed(uint8_t left, uint8_t right);
void MotorDir(uint8_t left, uint8_t right);

//  MotorSpeed(150,150);
//  MotorDir(FWD,FWD);
