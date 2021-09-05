#include <SharpIR.h>
#include <Servo.h>
#include "wall_follow.h"

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

RobotMoves::RobotMoves()
{
  const int led_green = 5;
  const int led_yellow = 6;
  const int led_red = 7;

  const int sensorPin0 = 3;
  const int sensorPin1 = 4;
  const int sensorPin2 = 5;

  const int servoPin0 = 9;
  const int servoPin1 = 10;

  const int x_min = 8;
  const int x0 = 18;s
  const int y_min = 12;
  const int y_max = 16;
  const int y0 = 30;

  Servo servoRight;
  Servo servoLeft;
}


void RobotMoves::sensorPrint(int &distance0, int &distance1, int &distance2) const
{
  Serial.print("Sensor 0: ");
  Serial.print(distance0);

  Serial.print("    Sensor 1: ");
  Serial.print(distance1);

  Serial.print("    Sensor 2: ");
  Serial.println(distance2);
}


/*
if front sensor is very close to wall:
  back up */
void RobotMoves::tooClose(int &distance1) const
{
  if (distance1 <= x_min)
  {
    servoRight.write(109);
    servoLeft.write(78); 
  }  
}


/*
if front sensor and right sensor are farther than contact length
or right sensor makes contact, and is greater than min, less than max: drive straight */
void RobotMoves::driveStraight(int &distance0, int &distance1) const
{
  if (distance1 >= x0 && distance0 >= y0)
  {
    servoRight.write(74);
    servoLeft.write(118);
  }
}


/*
if front sensor makes contact, but right sensor is not:
  turn hard left until right sensor is less than min */
void RobotMoves::hardLeft(int &distance0, int &distance1) const
{
  if (distance1 <= x0 && distance0 >= y0)
  {
    Serial.println("****** HARD LEFT ******");
    // while (distance0 >= y_min)
    // {
    //   servoRight.write(60);
    //   servoLeft.write(90);
    // }
    servoRight.write(66);
    servoLeft.write(90);
    delay(200);
  }
}


/*
if right sensor makes contact, but is greater than max:
  turn forward-right until less than min */
void RobotMoves::softRight(int &distance0) const
{
  if (distance0 <= y0 && distance0 >= y_max)
  {
    Serial.println("****** SOFT RIGHT ******");
    // while (distance0 >= y_max)
    // {
    //   servoRight.write(73);
    //   servoLeft.write(130);
    // }
    servoRight.write(79);
    servoLeft.write(118);
    delay(200);
  }
}


/*
if right sensor makes contact, but is less than min:
  turn forward-left until past min */
void RobotMoves::softLeft(int &distance0) const
{
  if (distance0 <= y0 && distance0 <= y_min)
  {
    Serial.println("****** SOFT LEFT ******");    
    // while (distance0 <= y_min)
    // {
    //   servoRight.write(60);
    //   servoLeft.write(120);
    // }
    servoRight.write(74);
    servoLeft.write(112);
    delay(200);
  }  
}


/*
if front sensor makes contact, and right sensor makes contact:
  turn hard left until right sensor is greater than max */
void RobotMoves::leftCorner(int &distance0, int &distance1)
{
  if (distance1 <= x0 && distance0 <= y0)
  {
    Serial.println("****** HARD LEFT CORNER ******");    
    // while (distance0 <= y_max)
    // {
    //   servoRight.write(60);
    //   servoLeft.write(120);
    // }
    servoRight.write(66);
    servoLeft.write(108);
    delay(750);
  } 
}

