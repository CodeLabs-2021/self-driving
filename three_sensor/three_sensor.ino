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

const int check_dist = 10;

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

  if (distance0 <= check_dist)
  {
    Serial.println("Sensor 0");
    Serial.println(distance0);

    servoRight.write(80);
    servoLeft.write(130);
    delay(15);

    digitalWrite(led_green, HIGH);
  }

  else if (distance1 <= check_dist)
  {
    Serial.println("Sensor 1");
    Serial.println(distance1);

    servoRight.write(90);
    servoLeft.write(160);
    delay(15);

    digitalWrite(led_yellow, HIGH); 
  }

  else if (distance2 <= check_dist)
  {
    Serial.println("Sensor 2");
    Serial.println(distance2);

    servoRight.write(60);
    servoLeft.write(90);
    delay(15);

    digitalWrite(led_red, HIGH);  
  }

  else
  {
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);   
    digitalWrite(led_red, LOW);

    servoRight.write(60);
    servoLeft.write(130);
    delay(500);
  }

  // delay(1000);
  // digitalWrite(led_green, LOW);
  // digitalWrite(led_yellow, LOW);   
  // digitalWrite(led_red, LOW); 
}