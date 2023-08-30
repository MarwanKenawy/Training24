#include <Wire.h>

//define pins
#define button1 2
#define button2 3

//declaring variables
int b1 = 0;//button 1
int b2 = 0;//button 2

void setup()
{
  Wire.begin(10);//slave of address 10
  Wire.onRequest(sendValues);
  Serial.begin(9600);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  //changing values of b1 and b2 when pressing buttons
  attachInterrupt(digitalPinToInterrupt(button1),chb1,RISING);
  attachInterrupt(digitalPinToInterrupt(button2),chb2,RISING);
}
void chb1()//change value of button 1
{
  b1 = !b1;
}
void chb2()//change value of button 2
{
  b2 = !b2;
}
void sendValues()//sending values on request
{
  Wire.write(b1);
  Wire.write(b2);
}
void loop()
{
  Serial.print("Button1: ");
  Serial.println(b1);
  Serial.print("Button2: ");
  Serial.println(b2);
}