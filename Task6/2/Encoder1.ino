#define outputA 6
#define outputB 7

int counter = 0;
int aState;
int aLastState;

void setup() {
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);

  Serial.begin(9600);

  aLastState = digitalRead(outputA); //initial state of the outputA
}

void loop() {
  aState = digitalRead(outputA);
  if(aState != aLastState)
  {
    if(digitalRead(outputB) != aState)
    {
      counter++;
    }
    else
    {
      counter--;
    }
    Serial.print("Position: ");
    Serial.println(counter);
  }
  aLastState = aState;//updates the previous stateof the outputA
}
