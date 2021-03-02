#include "Servo.h"

int servo_pin = D7; // for ESP8266 microcontroller
int ExiaMode = 4;
String activate="on";
Servo myservo;

void setup()
{
 // pinMode(6, OUTPUT);
  myservo.attach(servo_pin);
  Serial.begin(9600);
  myservo.write(5);
  delay(2000);
}

void loop()
{
  if(activate=="on"){
    for(int i=0; i<5; i++){
    push();
    }
    activate="off";
    
  }
  
  while(activate=="off"){
        
        myservo.write(5);
        delay(1000);
     
  }
  
    
}

void push()
{
  myservo.write(180);
    delay(3000);
    myservo.write(5);
    delay(1000);
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
