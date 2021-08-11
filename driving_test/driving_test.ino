


/*
Drive straight.
Capacitor for sensor.
Two pin switch.

*/

/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/

#include <Servo.h>
#include <SharpIR.h>


Servo servoRight;
Servo servoLeft;

const int switch_pin = 2;
const int led_green = 5;
const int led_yellow = 6;
const int led_red = 7;

SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A0 );



void setup() {
  Serial.begin(9600);
  servoRight.attach(9);  
  servoLeft.attach(10);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(switch_pin, INPUT);
}


void loop() 
{
  digitalWrite(led_green, HIGH);

  // straight
  // servoRight.write(68);
  // servoLeft.write(130);  

  // forward-left
  // servoRight.write(60);
  // servoLeft.write(120); 

  // circle-right
  // servoRight.write(80);
  // servoLeft.write(130);    

  // forward-right
  // servoRight.write(73);
  // servoLeft.write(130);

  // backwards
  servoRight.write(109);
  servoLeft.write(78);  



}