// Define pin connections & motor's steps per revolution
#define buzzer 12
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;
int stepDelay=2000;
char dire;
int count=0;
char start='S';  // currently on Stop (S) State 
int j=0;



void spin_reverse(int loc)
{
  digitalWrite(dirPin,HIGH);
  
  while(loc > 0)
  {
    Serial.println("Returning On Original Position");
      if(Serial.available() > 0){
 start = Serial.read();  // Spin motor
  }
  if(start=='S')
  {
    break;
  }
      for(int x = 0; x < stepsPerRevolution; x++)
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
      }
      loc--;
  }
  j=0;   //setting location at initial point
  digitalWrite(buzzer,LOW);
}


void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600); //default baud rate for bt 38400
  pinMode(buzzer,OUTPUT);
  
}



void loop()
{
  if(Serial.available() > 0)
  {
    start = Serial.read();  // Spin motor
  }
   if(start=='R')
   {
          
           digitalWrite(buzzer,LOW);
           digitalWrite(buzzer,HIGH);
           digitalWrite(buzzer,LOW);

           while(j < 76)
           {
            j++;
            if(Serial.available() > 0)
            {
            start=Serial.read();
            }
            if(start=='S')
            {
              break;
            }
            count++;
                   }
            //clockwise
 
  
             
                digitalWrite(dirPin, LOW);
                Serial.println("Infusion in Progress.......");
             
               Serial.println("Number of stroke entered :  " + count);
      for(int x = 0; x < stepsPerRevolution; x++)
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
      }
      delay(2000); // Wait a second

   }
   digitalWrite(buzzer,HIGH);
   Serial.println("Infusion has Paused....");
   
   }
   else if(start=='0')
   {
    spin_reverse(j);
      digitalWrite(buzzer,LOW);
   }
   
  
}
