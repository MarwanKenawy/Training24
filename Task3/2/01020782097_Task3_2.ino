//define pins
#define pingRight 7
#define echoRight 6
#define pingLeft 5
#define echoLeft 4
#define pingUp 3
#define echoUp 2
#define pingDown 9
#define echoDown 8

//declaring variables
int x = 0,y = 0;//x,y coordinates
void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  
  pinMode(pingRight,OUTPUT);
  pinMode(echoRight,INPUT);
  digitalWrite(pingRight,LOW);
  
  pinMode(pingLeft,OUTPUT);
  pinMode(echoLeft,INPUT);
  digitalWrite(pingLeft,LOW);
  
  pinMode(pingUp,OUTPUT);
  pinMode(echoUp,INPUT);
  digitalWrite(pingUp,LOW);
  
  pinMode(pingDown,OUTPUT);
  pinMode(echoDown,INPUT);
  digitalWrite(pingDown,LOW);
  delay(100);
}

void loop()
{
  // establish variables for duration of the ping, and the distance result
  // in centimeters
  long durationRight,durationLeft,durationUp,durationDown,cmRight,cmLeft,cmUp,cmDown;
  digitalWrite(pingRight,HIGH);
  digitalWrite(pingLeft,HIGH);
  digitalWrite(pingUp,HIGH);
  digitalWrite(pingDown,HIGH);
  delayMicroseconds(10);
  
  // The echo is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  digitalWrite(pingRight,LOW);
  durationRight = pulseIn(echoRight,HIGH);
  
  digitalWrite(pingLeft,LOW);
  durationLeft = pulseIn(echoLeft,HIGH);
  
  digitalWrite(pingUp,LOW);
  durationUp = pulseIn(echoUp,HIGH);
  
  digitalWrite(pingDown,LOW);
  durationDown = pulseIn(echoDown,HIGH);
  
  // convert the time into a distance
  cmRight = microsecondsToCentimeters(durationRight);
  cmLeft = microsecondsToCentimeters(durationLeft);
  cmUp = microsecondsToCentimeters(durationUp);
  cmDown = microsecondsToCentimeters(durationDown);
  
  //To get coodinates x,y we calculate the offset of Left and Down sensors
  //mapping reading to the room dimensions (5*6)meters
  x = map(cmLeft,2,336,0,5);
  constrain(x,0,5);
  y = map(cmDown,2,336,0,6);
  constrain(y,0,6);
  
  //printing output of four sensors and x,y coordinates
  Serial.print(cmUp);
  Serial.print(", ");
  Serial.print(cmDown);
  Serial.print(", ");
  Serial.print(cmRight);
  Serial.print(", ");
  Serial.println(cmLeft);
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);
  delay(200);
}
long microsecondsToCentimeters(long microseconds) {
   // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
   return microseconds / 29 / 2;
}