


#include <SharpIR.h>
#define IRPin 0
#define model 20150

// int distance_cm;

/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/

// int sensor_dist;

void limitLight(int sensor_dist, int LED_pin) 
{
  if (sensor_dist <= 5)
    digitalWrite(LED_pin, HIGH);
  else
    digitalWrite(LED_pin, LOW);
}


SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A0 );

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get a distance measurement and store it as distance_cm:
  distance_cm = mySensor.getDistance();

  // Print the measured distance to the serial monitor:
  Serial.print("Mean distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(1000);
}
