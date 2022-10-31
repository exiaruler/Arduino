#include "Servo.h"
#include "Exia.h"

//pin init
int servo_pin = D5; // exia
int servo_pin2= D7; //artoria
String activate="on";
double degree=151.5;
int restState=10;

// exia settings
Servo myservo;
Servo secondservo;
int Restart=6;
int startup=1;
int normal=2;
int preTrans=3;
int transAm=4;
int cycle=5;
int timeDelay=6000;
// artoria testing
Servo saber;
int pushS=180;
int pushB=89;
int standby=0;
String state="";
// time calculation 
int between=1000;
void setup()
{
 
  myservo.attach(servo_pin);
  myservo.write(restState);
  saber.attach(servo_pin2);
  saber.write(pushS);
  delay(1000);
  saber.write(pushB);
  delay(1000);
  saber.write(pushS);
  delay(500);
  state="standard";
  saber.detach();
  warmUp();
  delay(1000);
}

void loop()
{
  if(activate=="on"){
    //saber.detach();
    exiaCycle();
   // saber.detach();
    activate="off";
    
  }
  
  while(activate=="off"){
        
        myservo.write(restState);
        myservo.detach();
        saber.detach();
        delay(1000);
        delay(calculateTime(30));
        repositSaber();
        delay(calculateTime(30));
        if(state=="standard"){
          saber.attach(servo_pin2);
          saber.write(pushS);
         delay(3000);
          saber.write(pushB);
          delay(between);
          saber.write(pushS);
          delay(3000);
          state="fade";
          saber.detach();
       }else{
          if(state=="fade"){
            saber.attach(servo_pin2);
            saber.write(pushS);
            delay(3000);
            saber.write(pushB);
            delay(between);
            saber.write(pushS);
            delay(1000);
            saber.write(pushB);
            delay(between);
            saber.write(pushS);
            delay(3000);
            state="standard";
            saber.detach();
        }
       }
       
        
  }
}
int calculateTime(int t){
 int min=1000*60;
 return min*t;
}
void repositSaber(){
  saber.attach(servo_pin2);
  saber.write(180);
  delay(5000);
  saber.detach();
}
void push()
{
 
  myservo.write(degree);  
   delay(timeDelay);
    //go back
    myservo.write(restState);
    delay(2000);

  
}
void warmUp()
{
 for(int i=0; i<3; i++){
  myservo.write(70);
    delay(1000);
    //go back
    myservo.write(restState);
    delay(1000);
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
   if(count==5){
      myservo.detach();
   }
    push();
    
  }
}
