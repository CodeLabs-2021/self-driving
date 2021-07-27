#include <SharpIR.h>

const int switch_pin = 2;

const int led_green = 5;
const int led_yellow = 6;
const int led_red = 7;

const int model = 20150;

const int sensorPin0 = 0;
const int sensorPin1 = 1;
const int sensorPin2 = 2;

const int check_dist = 20;

// int distance0;
// int distance1;
// int distance2;

SharpIR sensor0 = SharpIR(sensorPin0, model);
SharpIR sensor1 = SharpIR(sensorPin1, model);
SharpIR sensor2 = SharpIR(sensorPin2, model);


void setup() {
  Serial.begin(9600);
//   servoRight.attach(9);  
//   servoLeft.attach(10);
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

  Serial.print("Sensor 0:  ");
  Serial.print(distance0);
  Serial.print("      Sensor 1:  ");
  Serial.print(distance1);
  Serial.print("      Sensor 2:  ");
  Serial.println(distance2);




  // if (distance0 <= check_dist)
  // {
  //   Serial.println("Sensor 0");
  //   Serial.println(distance0);

  //   digitalWrite(led_green, HIGH);
  // }

  // if (distance1 <= check_dist)
  // {
  //   Serial.println("Sensor 1");
  //   Serial.println(distance1);

  //   digitalWrite(led_yellow, HIGH); 
  // }

  // if (distance2 <= check_dist)
  // {
  //   Serial.println("Sensor 2");
  //   Serial.println(distance2);

  //   digitalWrite(led_red, HIGH);  
  // }

  // delay(1000);
  // digitalWrite(led_green, LOW);
  // digitalWrite(led_yellow, LOW);   
  // digitalWrite(led_red, LOW); 
}