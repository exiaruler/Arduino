#include "Servo.h"


int servo_pin = D7;  // for ESP8266 microcontroller


Servo myservo;
int count=0;
 
void setup() 
{ 
  myservo.attach(servo_pin);
 Serial.begin(9600);
 myservo.write(5);
 delay(2000);
} 
  
void loop() 
{ 
 if(count!=4){
  myservo.write(180);
  delay(1000);
  myservo.write(5);
  delay(1000);
  count++;
 }
 
 
 

}

void push(){ 

}

void back(){

}