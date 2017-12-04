
//contrant variables
//Pin numbers
const int rLEDPin = 4; //red LED
const int bLEDPin = 3; //blue LED
const int yLEDPin = 5; //yellow LED
const int gLEDPin = 2; //green LED
const int wLEDPin = 6; //white LED

//Button numbers
const int rBPin = 7; //red button
const int bBPin = 8; //blue button
const int yBPin = 9; //yellow button
const int gBPin = 10; //green button
const int wBPin = 11; //white button

int count2 = 0;
int onLight[] = {0, 0, 0, 0, 0};
int userIn[] = {0, 0, 0, 0, 0};
void setup() {

  // put your setup code here, to run once:
  //LED\\
  pinMode(rLEDPin, OUTPUT); //red
  pinMode(bLEDPin, OUTPUT); //blue
  pinMode(yLEDPin, OUTPUT); //yellow
  pinMode(gLEDPin, OUTPUT); //green
  pinMode(wLEDPin, OUTPUT); //white

  //Buttons\\
  pinMode(rBPin, INPUT); //button 3 (red)
  pinMode(bBPin, INPUT); //button 2 (blue)
  pinMode(yBPin, INPUT); //button 4 (yellow)
  pinMode(gBPin, INPUT); //button 1 (green)
  pinMode(wBPin, INPUT); //button 5 (white)

  Serial.begin(9600);
  randomSeed(analogRead(0)); //for random

}

void loop() {
  // put your main code here, to run repeatedly:

  //start up light pattern
  //fancy pattern
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(wLEDPin, HIGH);
  delay(500);
  digitalWrite(bLEDPin, HIGH);
  digitalWrite(yLEDPin, HIGH);
  delay(500);
  digitalWrite(rLEDPin, HIGH);
  delay(1000);
  digitalWrite(gLEDPin, LOW);
  digitalWrite(wLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(yLEDPin, LOW);
  digitalWrite(rLEDPin, LOW);
  delay(500);
  //all off
  digitalWrite(gLEDPin, LOW);
  digitalWrite(wLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(yLEDPin, LOW);
  digitalWrite(rLEDPin, LOW);
  delay(1000);
  //all on
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(wLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH);
  digitalWrite(yLEDPin, HIGH);
  digitalWrite(rLEDPin, HIGH);
  delay(1000);
  //all off
  digitalWrite(gLEDPin, LOW);
  digitalWrite(wLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(yLEDPin, LOW);
  digitalWrite(rLEDPin, LOW);
  delay(2000);


  //ran gen
  int ran = random(1, 6);


  if (ran == 1) {
    digitalWrite(gLEDPin, HIGH);
    delay(1000);
    digitalWrite(gLEDPin, LOW);
    onLight[0] = 1;
  }
  else if (ran == 2) {
    digitalWrite(bLEDPin, HIGH);
    delay(1000);
    digitalWrite(bLEDPin, LOW);
    onLight[1] = 1;
  }
  else if (ran == 3) {
    digitalWrite(rLEDPin, HIGH);
    delay(1000);
    digitalWrite(rLEDPin, LOW);
    onLight[2] = 1;
  }
  else if (ran == 4) {
    digitalWrite(yLEDPin, HIGH);
    delay(1000);
    digitalWrite(yLEDPin, LOW);
    onLight[3] = 1;
  }
  else if (ran == 5) {
    digitalWrite(wLEDPin, HIGH);
    delay(1000);
    digitalWrite(wLEDPin, LOW);
    onLight[4] = 1;
  }

  //wait for user input
  delay(3000);


  //user selection
  //red button
  int rBState = digitalRead(rBPin);
  if (rBState == HIGH) //pressed
    userIn[0] = 1;

  //blue button
  int bBState = digitalRead(bBPin);
  if (bBState == HIGH) //pressed
    userIn[1] = 1;

  //yellow button
  int yBState = digitalRead(yBPin);
  if (yBState == HIGH) //pressed
    userIn[2] = 1;

  //green button
  int gBState = digitalRead(gBPin);
  if (gBState == HIGH) //pressed
    userIn[3] = 1;

  //white button
  int wBState = digitalRead(wBPin);
  if (wBState == HIGH) //pressed
    userIn[4] = 1;

  //compare arrays
  for (int i = 0; i <= 5; i++)
  {
    if (!(userIn[i] == onLight[i])) //if they dont match
      flash();
    delay(2000);
  }//end for loop

}
void flash()
{
  //all on
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(wLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH);
  digitalWrite(yLEDPin, HIGH);
  digitalWrite(rLEDPin, HIGH);
  delay(1000);
  //all off
  digitalWrite(gLEDPin, LOW);
  digitalWrite(wLEDPin, LOW);
  digitalWrite(bLEDPin, LOW);
  digitalWrite(yLEDPin, LOW);
  digitalWrite(rLEDPin, LOW);
  delay(2000);
}//end flash method

