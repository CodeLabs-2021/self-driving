#include <SharpIR.h>
#include <Servo.h>

const int switch_pin = 2;

const int led_green = 5;
const int led_yellow = 6;
const int led_red = 7;

const int model = 20150;

const int sensorPin0 = 0;
const int sensorPin1 = 1;
const int sensorPin2 = 2;

const int x0 = 10;
const int y_min = 12;
const int y_max = 16;
const int y0 = 18;


Servo servoRight;
Servo servoLeft;

SharpIR sensor0 = SharpIR(sensorPin0, model);
SharpIR sensor1 = SharpIR(sensorPin1, model);
SharpIR sensor2 = SharpIR(sensorPin2, model);


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
  int distance0 = sensor0.getDistance();
  int distance1 = sensor1.getDistance();
  int distance2 = sensor2.getDistance();



  /*
  if front sensor and right sensor are farther than contact length
  or right sensor makes contact, and is greater than min, less than max:
    drive straight */
  if (distance1 >= x0 && distance0 >= y0)
  {
    servoRight.write(68);
    servoLeft.write(130);
  }

  /*
  if front sensor makes contact, but right sensor is not:
    turn hard left until right sensor is less than min */
  if (distance1 <= x0 && distance0 >= y0)
  {
    while (distance0 >= y_min)
    {
      servoRight.write(60);
      servoLeft.write(90);
    }
  }

  // /*
  // if right sensor makes contact, but is greater than max:
  //   turn forward-right until less than min */
  // if (distance0 <= y0 && distance0 >= y_max)
  // {
  //   while (distance0 >= y_max)
  //   {
  //     servoRight.write(73);
  //     servoLeft.write(130);
  //   }
  // }

  // /*
  // if right sensor makes contact, but is less than min:
  //   turn forward-left until past min */
  // if (distance0 <= y0 && distance0 <= y_min)
  // {
  //   while (distance0 <= y_min)
  //   {
  //     servoRight.write(60);
  //     servoLeft.write(120);
  //   }
  // }  

  // /*
  // if front sensor makes contact, and right sensor makes contact:
  //   turn hard left until right sensor is greater than max */
  // if (distance1 <= x0 && distance0 <= y0)
  // {
  //   while (distance0 <= y_max)
  //   {
  //     servoRight.write(60);
  //     servoLeft.write(120);
  //   }
  // } 

  else
  {
    servoRight.write(68);
    servoLeft.write(130);
  }

  delay(1000);

}