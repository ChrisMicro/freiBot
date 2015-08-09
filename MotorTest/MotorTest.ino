
const int sensor = A1;          
const int buttonPin = 11;     
const int ledPin =  13;      

const int enable_rechts = 10;    
const int motor_rechts1 = 2;     
const int motor_rechts2 = 3;     

const int enable_links = 9;      
const int motor_links1 = A2;     
const int motor_links2 = A3;     

int buttonState = 0;       

void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(sensor, INPUT_PULLUP);  
  
  pinMode(ledPin, OUTPUT); 

  pinMode(enable_rechts, OUTPUT);  
  pinMode(motor_rechts1, OUTPUT);   
  pinMode(motor_rechts2, OUTPUT);  

  pinMode(enable_links, OUTPUT);  
  pinMode(motor_links1, OUTPUT);   
  pinMode(motor_links2, OUTPUT);   

  // Motor rechts Vorwertsfahrt, dauerhaft
  digitalWrite(motor_rechts1, HIGH);
  digitalWrite(motor_rechts2, LOW);

  // Motor links Vorwertsfahrt, dauerhaft
  digitalWrite(motor_links1, LOW);
  digitalWrite(motor_links2, HIGH);
}

void loop() 
{
  int n;
    if(digitalRead(buttonPin))
    {
      digitalWrite(ledPin,true);
      delay(10);
      digitalWrite(ledPin,false);
      delay(500);
    }else
    {  
     digitalWrite(ledPin,false);
  
      for(n=0;n<3;n++)
      {
      analogWrite(enable_rechts, 255);     
      analogWrite(enable_links, 255);  
      
      delay(1000);
      analogWrite(enable_rechts, 200);     
      analogWrite(enable_links, 200); 
      
      delay(1000);
      analogWrite(enable_rechts, 0);     
      analogWrite(enable_links, 0);
      
      delay(3000);
      }
    }
}
