/*
Robot follows a wall on the right-hand side.
*/


#include <SharpIR.h>
#include <Servo.h>

const int switch_pin = 2;

const int led_green = 5;
const int led_yellow = 6;
const int led_red = 7;

const int model = 20150;

const int sensorPin0 = 3;
const int sensorPin1 = 4;
const int sensorPin2 = 5;

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

  Serial.print("Sensor 0: ");
  Serial.print(distance0);

  Serial.print("    Sensor 1: ");
  Serial.print(distance1);

  Serial.print("    Sensor 2: ");
  Serial.println(distance2);

  /*
  if front sensor is very close to wall:
    back up */
  if (distance1 <= x_min)
  {
    servoRight.write(109);
    servoLeft.write(78); 
  }

  /*
  if front sensor and right sensor are farther than contact length
  or right sensor makes contact, and is greater than min, less than max:
    drive straight */
  if (distance1 >= x0 && distance0 >= y0)
  {
    servoRight.write(74);
    servoLeft.write(118);
  }

  /*
  if front sensor makes contact, but right sensor is not:
    turn hard left until right sensor is less than min */
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

  /*
  if right sensor makes contact, but is greater than max:
    turn forward-right until less than min */
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

  /*
  if right sensor makes contact, but is less than min:
    turn forward-left until past min */
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

  /*
  if front sensor makes contact, and right sensor makes contact:
    turn hard left until right sensor is greater than max */
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

  // else
  // {
  //   servoRight.write(68);
  //   servoLeft.write(130);
  // }
;
  delay(250);

}