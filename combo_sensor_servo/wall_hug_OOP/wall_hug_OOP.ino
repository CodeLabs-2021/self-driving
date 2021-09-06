/* 
Wall hugging code written using object-oriented header files and 
specification files. Turns out this make the upload much bigger 
and strains the limited storage capacity of the Arduino.
*/



#include <SharpIR.h>
#include <Servo.h>
#include "wall_follow.h"

using namespace wall_fns;


const int baud_rate = 9600;

const int led_green = 5;
const int led_yellow = 6;
const int led_red = 7;

const int sensorPin0 = 3;
const int sensorPin1 = 4;
const int sensorPin2 = 5;

const int servoPin0 = 9;
const int servoPin1 = 10;

const int x_min = 8;
const int x0 = 18;
const int y_min = 12;
const int y_max = 16;
const int y0 = 30;



Servo servoRight;
Servo servoLeft;

SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A3 );
SharpIR sensor1 = SharpIR( SharpIR::GP2Y0A21YK0F, A4 );
SharpIR sensor2 = SharpIR( SharpIR::GP2Y0A21YK0F, A5 );

int distance0;
int distance1;
int distance2;

RobotMoves robot;


void setup() {
  Serial.begin(baud_rate);
  servoRight.attach(servoPin0);  
  servoLeft.attach(servoPin1);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}


void loop()
{
  distance0 = sensor0.getDistance();
  distance1 = sensor1.getDistance();
  distance2 = sensor2.getDistance();

  robot.sensorPrint(distance0, distance1, distance2);
  robot.tooClose(distance1);
  robot.driveStraight(distance1, distance2);
  robot.hardLeft(distance0, distance1);
  robot.softRight(distance0);
  robot.softLeft(distance0);
  robot.leftCorner(distance0);

  delay(250);
}