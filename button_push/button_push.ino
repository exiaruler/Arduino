#include "Servo.h"

int servo_pin = D5; // for ESP8266 microcontroller

String activate="on";
Servo myservo;
int degree=160;
void setup()
{
 
  myservo.attach(servo_pin);
  //Serial.begin(9600);
  myservo.write(0);
  delay(3000);
  
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
    delay(3000);
    //go back
    myservo.write(0);
    delay(2000);

  
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
  for(int i=0; i<5; i++){
    push();
  }
}
void test(){
 
}
