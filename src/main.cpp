#include "Servo.h"


int servo_pin = D7;  // for ESP8266 microcontroller


Servo myservo;
int angle = 0;  
int count;
 
void setup() 
{ 
  myservo.attach(servo_pin);
 Serial.begin(9600);
} 
  
void loop() 
{ // move from 0 to 180 degrees with a positive angle of 1


  while(count!=4){
    for(angle = 0; angle < 180; angle += 1)
  {                          
    myservo.write(angle);
    delay(15); 
                     
  } 
  //Serial.print("forward");  
  delay(1000);
  
  // move from 180 to 0 degrees with a negative angle of 5
  
  for(angle = 180; angle>=1; angle-=5)
  {                                
    myservo.write(angle);
    delay(5);     
                        
  } 
  //Serial.print("backward");       
    //delay(1000);
  }
  count++;
  Serial.print(count);
}

void push(){ 
    for(angle = 0; angle < 180; angle += 1)
  {                          
    myservo.write(angle);
    delay(15);                       
  } 
}

void back(){
  for(angle = 180; angle>=1; angle-=5)
  {                                
    myservo.write(angle);
    delay(5);                       
  } 

}