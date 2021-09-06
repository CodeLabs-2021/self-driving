/* 
Prints the values being output from the IR Sensors to the
Serial connection. Also, turns on LED when within a certain
distance for sensor verification without the Serial Monitor.
*/




#include <SharpIR.h>


const int led_green = 5;
const int led_yellow = 6;
const int led_red = 7;

const int sensorPin0 = 3;
const int sensorPin1 = 4;
const int sensorPin2 = 5;

const int check_dist = 11;

SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A3 );
SharpIR sensor1 = SharpIR( SharpIR::GP2Y0A21YK0F, A4 );
SharpIR sensor2 = SharpIR( SharpIR::GP2Y0A21YK0F, A5 );

int distance0;
int distance1;
int distance2;


void setup() {
  Serial.begin(9600);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop()
{
  distance0 = sensor0.getDistance();
  distance1 = sensor1.getDistance();
  distance2 = sensor2.getDistance();

  Serial.print("Sensor 0:  ");
  Serial.print(distance0);
  Serial.print("      Sensor 1:  ");
  Serial.print(distance1);
  Serial.print("      Sensor 2:  ");
  Serial.println(distance2);

  


  if (distance0 <= check_dist)
  {
    digitalWrite(led_green, HIGH);
  }
  else
    digitalWrite(led_green, LOW);

  if (distance1 <= check_dist)
  {
    digitalWrite(led_yellow, HIGH); 
  }
  else
    digitalWrite(led_yellow, LOW); 

  if (distance2 <= check_dist)
  {
    digitalWrite(led_red, HIGH);  
  }
  else
    digitalWrite(led_red, LOW);


  delay(1000);
}
