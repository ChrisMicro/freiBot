#include "Arduino.h"
#include "stdint.h"
#include "pin_defintions.h"


/************************************************************************************

	driver definitions

************************************************************************************/
// ASRURO Motor states
#define FREE    0                     /*!< Motor freilaufend */
#define BREAK   1                     /*!< Motor bremsen */
#define FWD     2                     /*!< Motor vorwaerts */
#define RWD     3                     /*!< Motor rueckwaerts */

#define LEFT	1
#define RIGHT   2

void Msleep(uint32_t time_ms);
void MotorSpeed(uint8_t left, uint8_t right);
void MotorDir(uint8_t left, uint8_t right);
void Go   ( int16_t distance, uint8_t speed ); 
void Turn ( int16_t degree  , uint8_t speed );

// exampels:
//  MotorSpeed(150,150);
//  MotorDir(FWD,FWD);


