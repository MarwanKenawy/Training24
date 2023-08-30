#include <Wire.h>
//define pins
#define led 11

//Declaring variables
int b1 = 0;//button 1
int b2 = 0;//button 3
int pwm = 0;//led intensity

void setup()
{
  Serial.begin(9600);
  Wire.begin();//master
  pinMode(led,OUTPUT);
}

void loop()
{
  Wire.requestFrom(10,2);//requesting from slave of address 10
  while(Wire.available())
  {
    b1 = Wire.read();
    b2 = Wire.read();
  }
  //checking conditions
  if(b1==0 && b2==0)
  {
    pwm = 0;
    Serial.println("No message");
  }
  else if(b1 == 1 && b2 == 0)
  {
    pwm = 0.5*255;
    Serial.println("Vector Focused");
  }
  else if(b1 == 0 && b2 == 1)
  {
    pwm = 0.75*255;
    Serial.println("Vector Distracted");
  }
  else
  {
    pwm = 255;
    Serial.println("Glitch");
  }
  analogWrite(led,pwm);
}