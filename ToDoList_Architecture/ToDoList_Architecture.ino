/*
 ============================================================================
 Name        : ToDoBuffer_Architecture.c
 Author      : chris
 Version     :
 Copyright   : GPL V3
 Description : ToDo list architecture to control a robot
 ============================================================================
 */
#include "freiBot.h"

#include "ringBuffer.h"

#define TODOLIST_SIZE 100
ToDo_t ToDoList[TODOLIST_SIZE];

ringBuffer_t ToDoBuffer;

void Speed(int16_t a, int16_t b)
{
  MotorSpeed(a, b);
}

void Direction(int16_t a, int16_t b)
{
  MotorDir(a, b);
}

#define FORWARD_LENGTH 2
ToDo_t Forward_List[] =
{
  // turn robot
  {0, Direction, FWD, FWD},
  {500, Speed, 200, 200},
};

#define TURNLEFT_LENGTH 3
ToDo_t TurnLeft_List[] =
{
  // turn robot
  {0, Direction, FWD, RWD},
  {500, Speed, 200, 200},
  // stop motors and wait for two seconds
  {2000, Direction, FREE, FREE}
};

#define BOUNCE_BACK 4
ToDo_t BounceBack_List[] =
{
  // drive back
  {0, Direction, RWD, RWD},
  {300, Speed, 200, 200},
  // turn
  {300, Direction, FWD, RWD},
  // stop motors and wait for 200ms
  {200, Direction, FREE, FREE}
};

void bounceBackBehaviour(int16_t var1, int16_t var2)
{
  ringBufAddInFront(&ToDoBuffer, BounceBack_List, BOUNCE_BACK);
}

void rotateBehaviour(int16_t var1, int16_t var2)
{
  ringBufAddInFront(&ToDoBuffer, TurnLeft_List, TURNLEFT_LENGTH);
}

void forwardBehaviour(int16_t var1, int16_t var2)
{
  ringBufAddInFront(&ToDoBuffer, Forward_List, FORWARD_LENGTH);
}

void setup()
{
  initRobotHardware();
  Serial.begin(9600);
  ringBufferInit( &ToDoBuffer, ToDoList, TODOLIST_SIZE  );

  ringBufAddInFront(&ToDoBuffer, TurnLeft_List, TURNLEFT_LENGTH);
  bounceBackBehaviour(0, 0);
  ringBufAddInFront(&ToDoBuffer, TurnLeft_List, TURNLEFT_LENGTH);
}

void simpleIrMotorControl()
{
  int n, k;
  beep();
  waitForIrSignal(); // wait for start signal
  MotorDir(FWD, RWD); // rotate if there is no signal
  MotorSpeed(200, 200);
  for (n = 0; n < 300; n++)
  {
    if (isIrSignal()) // if signal, go forward
    {
      setLed(EYE_LED_LEFT, 1);
      MotorDir(FWD, FWD);
      delay(500);
      setLed(EYE_LED_LEFT, 0);
    } else
    {
      MotorDir(FWD, RWD); // rotate if there is no signal
      delay(10);
    }
    if (whiskerTouched())
    {
      chirp();

      MotorSpeed(200, 200);
      // go back
      MotorDir(RWD, RWD);
      delay(300);
      // turn
      MotorDir(FWD, RWD);
      delay(300);
    }
  }
  MotorDir(FREE, FREE); // turn of motor if there is no signal

}

uint32_t NextTime = 0;

void whiskerTest()
{
  if (whiskerTouched())
  {
    setLed(EYE_LED_LEFT, 1);

    delay(1);

  } else setLed(EYE_LED_LEFT, 0);
}

void loop()
{
  ToDo_t action;

  if (millis() > NextTime) // check if the next action has to be taken
  {
    if ( ! ringBufferIsEmpty(&ToDoBuffer) )
    {
      action = ringBufGetValue( &ToDoBuffer);
      action.DoFunction(action.var1, action.var2);

      NextTime = millis() + action.runTime;

      printf("size:%d: ", ringBufGetFillSize(&ToDoBuffer));
    }
  }

  // sensor activations
  if( whiskerTouched() ) bounceBackBehaviour(0, 0);
  //if( isIrSignal()     ) forwardBehaviour(0,0);
}

