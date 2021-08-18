#include <Servo.h>
 #include <SharpIR.h>
//#include "IRremote.h"

/*SHARP GP2Y0A21YK0F IR distance sensor with Arduino and SharpIR library example code. More info: https://www.makerguides.com */

// Include the library:
#include <SharpIR.h>

// Define model and input pin:
#define IRPin A0
#define model 1080

/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/
 
// Create a new instance of the SharpIR class:
SharpIR sensor = SharpIR(IRPin, model);

// backward - 0, stop - 90, forward - 180
int pos = 90;
int distance_cm;
int left_servo_pin = 3;
int right_servo_pin = 9;
int sensor_servo_pin = 6;

Servo left_servo, right_servo, sensor_servo;
//SharpIR left_sensor = SharpIR(IRPin, model);
//SharpIR right_sensor = SharpIR(IRPin, model);


void setup() {
  Serial.begin(9600);
  
  left_servo.attach(left_servo_pin);
  right_servo.attach(right_servo_pin);
  sensor_servo.attach(sensor_servo_pin);
  
  left_servo.write(pos);
  right_servo.write(pos);
  sensor_servo.write(pos);
}

void stop_left_wheel() {
  left_servo.write(90);
}

void stop_right_wheel() {
  right_servo.write(90);
}

void turn_left(int ms) {
  right_servo.write(0);
  stop_left_wheel();
  delay(ms);
}

void turn_right(int ms) {
  left_servo.write(180);
  stop_right_wheel();
  delay(ms);
}

void forward() {
  left_servo.write(180);  
  right_servo.write(0);
}

void backward() {
  left_servo.write(0);
  right_servo.write(180);
}

void stop_move() {
  left_servo.write(90);
  right_servo.write(90);
}

void move_in_square() {
  forward();
  delay(3000);
  turn_left(750);
}


int get_distance() {
  return sensor.distance();
}

int get_direction() {
//  -1 - left, 0 - reverve, 1 - right
  int left_dis, right_dis;
  
  sensor_servo.write(0);
  delay(750);
  left_dis = get_distance();
  
  sensor_servo.write(180);
  delay(750);
  right_dis = get_distance();
  if (left_dis >= 20 && right_dis >= 20) {
    return -1;
  } else if (left_dis < 20 && right_dis < 20) {  
    return 0;
  } else if (left_dis > right_dis) {
    return -1;
  } else {
    return 1;
  }
}

void turn_around() {
  sensor_servo.write(90);
  delay(700);
  backward();
  delay(1000);
  stop_move();
  
  int left_dis, right_dis;
  
  sensor_servo.write(0);
  delay(750);
  left_dis = get_distance();
  
  sensor_servo.write(180);
  delay(750);
  right_dis = get_distance();
  while (left_dis < 20 and right_dis < 20) {
    sensor_servo.write(90); 
    delay(700);
    
    backward();
    delay(1000);
    stop_move();
    
    sensor_servo.write(0);
    delay(750);
    left_dis = get_distance();
    
    sensor_servo.write(180);
    delay(750);
    right_dis = get_distance();
  }

  if (right_dis >= 20) {
    turn_right(750);
  } else {
    turn_left(750);
  }
}

void loop(){
//  move_in_square();
//  forward();
  sensor_servo.write(90);
  delay(700);

  while (get_distance() > 15) {
    forward();
  }
  stop_move();
  int turn_dir = get_direction();
  switch (turn_dir) {
    case -1:
      turn_left(750);
      break;
    case 0:
      turn_around();   
      break;
    case 1:
      turn_right(750);
      break;
  }
}

