#define outputA 2
#define outputB 3

double counter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(outputA,INPUT_PULLUP);
  pinMode(outputB,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(outputA),ISR_encoderA,CHANGE);
  attachInterrupt(digitalPinToInterrupt(outputB),ISR_encoderB,CHANGE);
}

void loop() {
  Serial.print("Counts = ");
  Serial.println(counter);

}
void ISR_encoderA()
{
  if(digitalRead(outputA) != digitalRead(outputB))
    counter++;
  else
    counter--;
}
void ISR_encoderB()
{
  if(digitalRead(outputA) == digitalRead(outputB))
    counter++;
  else
    counter--;
}