
int RightMotorForward=13; 
int RightMotorReverse=12;
 
int LeftMotorForward =11; 
int LeftMotorReverse =10; 

const int trig_front = 7;
const int echo_front = 8;

int recValue;
long timer_front;
float dist_front;

void setup() 
{   
  pinMode(trig_front, OUTPUT); 
  pinMode(RightMotorForward, OUTPUT); 
  pinMode(RightMotorReverse, OUTPUT); 
  pinMode(LeftMotorForward, OUTPUT); 
  pinMode(LeftMotorReverse, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trig_front,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_front,LOW);
  timer_front=pulseIn(echo_front,HIGH);
  dist_front=(timer_front/2)/28.5;
    
  if (dist_front <= 15)
  {
    Serial.println("Carpmak Uzeresin");
    delay(50);
  }
  else if (dist_front > 15)
  {
    Serial.println(dist_front);
    delay(50);
  }
   
  if(Serial.available())    
  {
      recValue = Serial.read();
  
      if (recValue == 100) //  FORWARD 
      {
        digitalWrite(RightMotorForward, HIGH); 
        digitalWrite(LeftMotorForward , HIGH); 
        digitalWrite(RightMotorReverse,LOW); 
        digitalWrite(LeftMotorReverse,LOW);
        delay(50);
      } 
      else if (recValue == 101) //  right 
      {
        digitalWrite(RightMotorForward, HIGH); 
        digitalWrite(LeftMotorForward , LOW);
        digitalWrite(RightMotorReverse,LOW); 
        digitalWrite(LeftMotorReverse,LOW); 
        delay(50);
      } 
      else if (recValue == 102) //  left 
      {
        digitalWrite(RightMotorForward, LOW); 
        digitalWrite(LeftMotorForward , HIGH);
        digitalWrite(RightMotorReverse,LOW); 
        digitalWrite(LeftMotorReverse,LOW); 
        delay(50);
      }  
      else if (recValue == 103) //  back 
      {
        digitalWrite(RightMotorForward, LOW); 
        digitalWrite(LeftMotorForward , LOW);
        digitalWrite(RightMotorReverse,HIGH); 
        digitalWrite(LeftMotorReverse,HIGH); 
        delay(50);
      } 
      else if (recValue == 105) //  stop 
      {
        digitalWrite(RightMotorForward, LOW); 
        digitalWrite(LeftMotorForward , LOW);
        digitalWrite(RightMotorReverse,LOW); 
        digitalWrite(LeftMotorReverse,LOW); 
        delay(50);
      }
  }
}
