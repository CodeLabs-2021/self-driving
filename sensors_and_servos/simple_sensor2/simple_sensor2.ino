/*SHARP GP2Y0A21YK0F IR distance sensor with Arduino and SharpIR library example code. More info: https://www.makerguides.com */

// Include the library:
#include <SharpIR.h>

// Define model and input pin:
#define IRPin 1
#define model 20150

#include <Servo.h>

Servo servoRight;
Servo servoLeft;

// int pos = 0;
// int altPos = 0;

// Create variable to store the distance:
int distance_cm;

/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/

// Create a new instance of the SharpIR class:
SharpIR mySensor = SharpIR(IRPin, model);

void setup() {
  // Begin serial communication at a baudrate of 9600:
  Serial.begin(9600);
  servoRight.attach(9);  
  servoLeft.attach(10);
}

void loop() {
  // Get a distance measurement and store it as distance_cm:
  distance_cm = mySensor.getDistance();

  // Print the measured distance to the serial monitor:
//  Serial.print("Mean distance: ");
//  Serial.print(distance_cm);
//  Serial.println(" cm");

//  delay(1000);

  if (mySensor.getDistance() <= 12)
  {
    servoRight.write(60);
    servoLeft.write(120);
  // for (pos = 90; pos >= 0; pos -= 1) { 

    // servoRight.write(pos);              
    // altPos = 180 - pos;
    // servoLeft.write(pos);
    // delay(10);                       
  }

// delay(10);

//   for (pos = 0; pos <= 90; pos += 1) { 
//     servoRight.write(pos);             
//     altPos = 180 - pos;
//     servoLeft.write(pos);
//     delay(10);                       
//   }

// delay(10);
  // }

  else
  {
    servoRight.write(60);
    servoLeft.write(60);
  //   for (pos = 90; pos >= 0; pos -= 1) { 
  //   servoRight.write(pos);            ,,,  
  //   altPos = 180 - pos;
  //   servoLeft.write(altPos);
  //   delay(10);                       
  // }
  }

  delay(2000);  
  
}
