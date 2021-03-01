#include "Servo.h"

int servo_pin = D7; // for ESP8266 microcontroller
int count = 0;

Servo myservo;

void setup()
{

  myservo.attach(servo_pin);
  Serial.begin(9600);
  myservo.write(5);
  delay(2000);
}

void loop()
{
  if (count != 4)
  {
    myservo.write(180);
    delay(1000);
    myservo.write(5);
    delay(1000);
    count++;
  }
  else
  {
    if (count == 4)
    {
      myservo.write(5);
   
     // yield();
    }
  }
}

void push()
{
  myservo.write(180);
    delay(1000);
    myservo.write(5);
    delay(1000);
}
