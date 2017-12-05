
//contrant variables
//Pin numbers
const int rLEDPin = 2; //red LED
const int bLEDPin = 4; //blue LED
const int yLEDPin = 5; //yellow LED
const int gLEDPin = 3; //green LED
const int wLEDPin = 6; //white LED

//Button numbers
const int rBPin = 2; //red button
const int bBPin = 3; //blue button
const int yBPin = 4; //yellow button
const int gBPin = 5; //green button
const int wBPin = 6; //white button

int count2 = 0;
char onLight[20];
char userIn[20];
int wait = 0; //counter for code to wait untill user selects 5 buttons

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

}//end set up

void loop() {
  // put your main code here, to run repeatedly:

  game();


}//end main loop



//game method
void game()
{
  //start up light pattern
  litLights();

  //generate random light
  for (int b = 0; b <= 5; b++)
  {
    onLight[b] = ranLight();
  }//end for loop



  //wait for user input
  //delay(3000);
  while (!(wait = 5))
  {
    //user selection
    userSel();

  }//while loop


  //loop for if user gets pattern wrong twice
  int twoWrong = 0;
  while (twoWrong < 2) {
    //compare user input to light pattern
    if (compare() == false)
    {
      redoPattern();
      twoWrong++;
      //wait for user input
      //delay(1000);
      while (!(wait = 5))
      {
        //user selection
        userSel();

      }//while loop
    }//end if compare
  }//end two wrong loop
}//end game method

//start up light pattern
void litLights()
{
  //reset pins to recieve output
  resetOut();

  //fancy pattern
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(wLEDPin, HIGH);
  delay(500);
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(yLEDPin, HIGH);
  delay(500);
  digitalWrite(bLEDPin, HIGH);
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
}//end start up sequence

void flash()
{
  //reset pins to recieve output
  resetOut();

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

//generates random light
char ranLight()
{
  //reset pins to recieve output
  resetOut();

  //ran gen
  int ran = random(1, 6);

  char light;

  if (ran == 1) {
    digitalWrite(gLEDPin, HIGH);
    delay(700);
    digitalWrite(gLEDPin, LOW);
    //onLight[0] = 'g';
    light = 'g';
  }
  else if (ran == 2) {
    digitalWrite(bLEDPin, HIGH);
    delay(700);
    digitalWrite(bLEDPin, LOW);
    //onLight[1] = 'b';
    light = 'b';
  }
  else if (ran == 3) {
    digitalWrite(rLEDPin, HIGH);
    delay(700);
    digitalWrite(rLEDPin, LOW);
    //onLight[2] = 'r';
    light = 'r';
  }
  else if (ran == 4) {
    digitalWrite(yLEDPin, HIGH);
    delay(700);
    digitalWrite(yLEDPin, LOW);
    //onLight[3] = 'y';
    light = 'y';
  }
  else if (ran == 5) {
    digitalWrite(wLEDPin, HIGH);
    delay(700);
    digitalWrite(wLEDPin, LOW);
    //onLight[4] = 'w';
    light = 'w';
  }
  return light;
}//end random light

//replays light pattern
void redoPattern()
{
  //reset pins to recieve output
  resetOut();

  for (int i = 0; i <= 5; i++) //goes through array to turn on correct lights
  {
    if (onLight[i] =  'g') {
      digitalWrite(gLEDPin, HIGH);
      delay(800);
      digitalWrite(gLEDPin, LOW);
    }
    else if (onLight[i] = 'b') {
      digitalWrite(bLEDPin, HIGH);
      delay(800);
      digitalWrite(bLEDPin, LOW);
    }
    else if (onLight[i] = 'r') {
      digitalWrite(rLEDPin, HIGH);
      delay(800);
      digitalWrite(rLEDPin, LOW);
    }
    else if (onLight[3] = 'y') {
      digitalWrite(yLEDPin, HIGH);
      delay(800);
      digitalWrite(yLEDPin, LOW);
    }
    else if (onLight[4] = 'w') {
      digitalWrite(wLEDPin, HIGH);
      delay(800);
      digitalWrite(wLEDPin, LOW);
    }
  }//end for loop
}//end redoPattern


//end user selection
void userSel()
{
  //reset pins to recieve input
  resetIn();

  //red button
  int rBState = digitalRead(rBPin);
  if (rBState == HIGH) //pressed
    userIn[0] = 'r';
  wait++;
  //blue button
  int bBState = digitalRead(bBPin);
  if (bBState == HIGH) //pressed
    userIn[1] = 'b';
  wait++;
  //yellow button
  int yBState = digitalRead(yBPin);
  if (yBState == HIGH) //pressed
    userIn[2] = 'y';
  wait++;
  //green button
  int gBState = digitalRead(gBPin);
  if (gBState == HIGH) //pressed
    userIn[3] = 'g';
  wait++;
  //white button
  int wBState = digitalRead(wBPin);
  if (wBState == HIGH) //pressed
    userIn[4] = 'w';
  wait++;
}//end user selection

//compare string arrays
boolean compare()
{
  //reset pins to recieve output
  resetOut();

  boolean result;
  //compare arrays
  for (int i = 0; i <= 5; i++)
  {
    if ((userIn[i] == onLight[i])) //if they do match
    { right();
      result = true;
    }
    else {
      wrong();
      result = false;
    }
    delay(2000);
  }//end for loop
  return result; //if false its wrong. If true, its right. Used to determine if lights replay
}//end compare string arrays

//wrong input
void wrong()
{
  //reset pins to recieve output
  resetOut();

  for (int a = 0; a <= 5; a++)
  {
    digitalWrite(rLEDPin, HIGH);
    delay(200);
    digitalWrite(rLEDPin, LOW);
  }//end for loop
}//end wrong method

//right input
void right()
{
  //reset pins to recieve output
  resetOut();

  for (int a = 0; a <= 5; a++)
  {
    digitalWrite(gLEDPin, HIGH);
    delay(200);
    digitalWrite(gLEDPin, LOW);
  }//end for loop

}//end right method

//reset pins to recieve output
void resetOut()
{
  //LED\\
  pinMode(rLEDPin, OUTPUT); //red
  pinMode(bLEDPin, OUTPUT); //blue
  pinMode(yLEDPin, OUTPUT); //yellow
  pinMode(gLEDPin, OUTPUT); //green
  pinMode(wLEDPin, OUTPUT); //white
}//end reset out

//reset pins to recieve input
void resetIn()
{
  //Buttons\\
  pinMode(rBPin, INPUT); //button (red)
  pinMode(bBPin, INPUT); //button (blue)
  pinMode(yBPin, INPUT); //button (yellow)
  pinMode(gBPin, INPUT); //button (green)
  pinMode(wBPin, INPUT); //button (white)
}//end reset in

