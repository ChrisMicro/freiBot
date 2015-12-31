
/*
  fast adc sampling and displaying a graph.

  The newer ARDUINO IDEs have the possibility to display data as a graph. Use the menue point

  Werkzeuge => Serialler Plotter

  to display the values.

  2015 by ChrisMicro
 
 */

#include "freiBot.h"

void setup()
{
  Serial.begin(9600);
}

void setPins()
{
  
  uint8_t eye=EYE_LED_LEFT;

  pinMode(EYE_LED_LEFT, OUTPUT);
  pinMode(EYE_LED_RIGHT, OUTPUT);
  digitalWrite(EYE_LED_LEFT, 0); // discharge
  digitalWrite(EYE_LED_RIGHT, 0); // discharge
  pinMode(EYE_LED_LEFT, INPUT_PULLUP);
  digitalWrite(EYE_LED_LEFT, 1); // precharge
 
  pinMode(eye, INPUT);
}


#define SIGNNAL_LENGTH_MAX 512

uint16_t Signal[SIGNNAL_LENGTH_MAX];

float SampleRate_us; 

// full speed
uint32_t sample(uint8_t adcChannel,uint16_t numberOfSamples)
{
  uint32_t startTime,samplingDuration;
  uint16_t n;

  startTime=micros();

  for(n=0;n<numberOfSamples;n++)
  {
    Signal[n] = analogRead(adcChannel); 
  }
  
  samplingDuration =  micros() - startTime;
  SampleRate_us    = (float) samplingDuration / numberOfSamples;

  return samplingDuration ; // return total sampling duration  
}

// fixed sample rate
uint32_t sampleFixedRate(uint8_t adcChannel, uint16_t numberOfSamples)
{
  uint16_t n;
  uint32_t startTime;
  uint32_t delayTime;
  
  delayTime=SampleRate_us;
  
  startTime = micros();
  for(n=0;n<numberOfSamples;n++)
  {
    Signal[n] = analogRead(adcChannel); 
    while( (uint32_t) (micros() - startTime) < delayTime);
    startTime += delayTime;
  }
  
  return SampleRate_us*numberOfSamples;  
}


void loop()
{
  uint16_t n;
  uint16_t numberOfSamples=SIGNNAL_LENGTH_MAX;
  uint32_t signal_length_us;

  setPins();
  SampleRate_us=1000;
  signal_length_us=sampleFixedRate(0,numberOfSamples);

  //signal_length_us=sample(0,length);


  for(n=0;n<numberOfSamples;n++)
  {          
    Serial.println( Signal[n] );
  }
  
  Serial.print("signal length: ");    Serial.print(signal_length_us);  Serial.println("us");
  Serial.print("sample rate: ");      Serial.print(SampleRate_us);     Serial.println("us");
  Serial.print("sample frequency: "); Serial.print(1e6/SampleRate_us); Serial.println("Hz");
  
  delay(3000);
}


