/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products
*/
//contrant variables
//Pin numbers
const int rLEDPin = 2; //red LED
const int bLEDPin = 3; //blue LED
const int yLEDPin = 4; //yellow LED
const int gLEDPin = 5; //green LED
const int wLEDPin = 6; //white LED

//Button numbers
const int rBPin = 7; //red button
const int bBPin = 8; //blue button
const int yBPin = 9; //yellow button
const int gBPin = 10; //green button
const int wBPin = 11; //white button

// the setup function runs once when you press reset or power the board
void setup() {

  //LED\\
  pinMode(rLEDPin, OUTPUT); //red
  pinMode(bLEDPin, OUTPUT); //blue
  pinMode(yLEDPin, OUTPUT); //yellow
  pinMode(gLEDPin, OUTPUT); //green
  pinMode(wLEDPin, OUTPUT); //white

  //Buttons\\
  pinMode(rBPin, INPUT); //button 1 (red)
  pinMode(bBPin, INPUT); //button 2 (blue)
  pinMode(yBPin, INPUT); //button 3 (yellow)
  pinMode(gBPin, INPUT); //button 4 (green)
  pinMode(wBPin, INPUT); //button 5 (white)

}

// the loop function runs over and over again forever
void loop() {
  //flash LEDs 5 times to signal start up
  int count = 0;
  int i = 0;
  //loop to move through array of pin numbers
  while (count <= 5) {
    while (i <= 5) {
int pinNum[] = {2,3,4,5,6};
int currentPin = pinNum[i];

      digitalWrite(currentPin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for .5 second
      digitalWrite(currentPin, LOW);    // turn the LED off by making the voltage LOW
      delay(500);                       // wait for .5 second
      i++;
      count = count + 1;
    }//end while loop
  }//end while loop

//game start
int light = ranLight();
//make loop here and call ranLght() again
int count2 = 0;
for(int numLights = 0; numLights<=10; numLights++)
{
  while(count2<=numLights)
  {
lightON(light);
  
  
  count2++;
  }//end while loop
}//end for loop
  
}//end void loop

//ranLight method
////generates which light turns on
int ranLight() 
{
int LED1, LED2, LED3, LED4;
int ran = random(1, 4);
int on; //which light gets turned on
//switch for selecting lights
switch (ran)
{
case 1:
on = LED1;
break;

case 2:
on = LED2;
break;

case 3:
on = LED3;
break;

case 4:
on = LED4;
break;
}//end switch
return on;
}//end ranGen method

void lightON(int light)
{
if(light == 1)
digitalWrite(rLEDPin, HIGH);
else if(light == 2)
digitalWrite(bLEDPin, HIGH);
else if(light == 3)
digitalWrite(yLEDPin, HIGH);
else if(light == 4)
digitalWrite(gLEDPin, HIGH);
else if(light ==5)
digitalWrite(wLEDPin, HIGH);

}//end lightON method


