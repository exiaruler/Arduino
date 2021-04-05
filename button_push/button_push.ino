#include "Servo.h"
#include "exia_functions.h"
//pin init
int servo_pin = D5; // exia
String activate="on";
// 170
int degree=180;

// exia settings
Servo myservo;
int Restart=6;
int startup=1;
int normal=2;
int preTrans=3;
int transAm=4;
int cycle=5;
void setup()
{
 
  myservo.attach(servo_pin);
  //Serial.begin(9600);
  myservo.write(0);
  delay(500);
  warmUp();
  delay(2000);
  
}

void loop()
{
  if(activate=="on"){
    exiaCycle();
    activate="off";
    
  }
  
  while(activate=="off"){
        
        myservo.write(0);
        myservo.detach();
        delay(1000);
        
     
  }
  
    
}

void push()
{
 
  myservo.write(degree);
    delay(10000);
    //go back
    myservo.write(0);
    delay(4000);

  
}
void warmUp()
{
 for(int i=0; i<3; i++){
  myservo.write(90);
    delay(1000);
    //go back
    myservo.write(0);
    delay(500);
 }
  
}

void exiaStart(){
  push();
}

void exiaNormal(){
  for(int i=0; i<2; i++){
    push();
  }
}

void exiaPretrans(){
  for(int i=0; i<3; i++){
    push();
  }
}
void exiaTransAm(){
  for(int i=0; i<4; i++){
    push();
  }
}
void exiaCycle(){
  //int count=0;
  for(int count=0; count<5; count++){
   
    push();
    
  }
}
void powerDown(){
  
 
}
