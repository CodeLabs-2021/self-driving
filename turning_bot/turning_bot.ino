


/*
Drive straight.
Capacitor for sensor.
Two pin switch.

*/

/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/

#include <Servo.h>
#include <SharpIR.h>

#define IRPin 1
#define model 20150

Servo servoRight;
Servo servoLeft;

const int switch_pin = 2;
const int led_pin = 7;

SharpIR mySensor = SharpIR(IRPin, model);



void setup() {
  Serial.begin(9600);
  servoRight.attach(9);  
  servoLeft.attach(10);
  pinMode(led_pin, OUTPUT);
  pinMode(switch_pin, INPUT);
}


void loop() 
{
  // straight
  servoRight.write(68);
  servoLeft.write(130);  

  // forward-left
  // servoRight.write(60);
  // servoLeft.write(120); 

  // circle-right
  // servoRight.write(80);
  // servoLeft.write(130);    

  // forward-right
  // servoRight.write(73);
  // servoLeft.write(130);


  // while (digitalRead(switch_pin) == HIGH)
  // {
  //   int distance_cm = mySensor.getDistance();

  //   if (distance_cm >=10)
  //   {
  //     digitalWrite(7, LOW);
  //     servoRight.write(60);
  //     servoLeft.write(130);
  //     delay(15);
  //   }

  //   else
  //   {
  //     digitalWrite(7, HIGH);
  //     servoRight.write(60);
  //     servoLeft.write(60);
  //     delay(500);
  //   }

    // delay(3000);





    // Print the measured distance to the serial monitor:
    // Serial.print("Mean distance: ");
    // Serial.print(distance_cm);
    // Serial.println(" cm");

    // delay(1000);









    // servoRight.write(91);
    // servoLeft.write(120);

    // delay(1000);






    /*
    // Go straight
    for (pos = 90; pos >= 0; pos -= 1) { 
      servoRight.write(pos);              
      altPos = 180 - pos;
      servoLeft.write(altPos);
      delay(10);                       
    }

    delay(200);

    for (pos = 0; pos <= 90; pos += 1) { 
      servoRight.write(pos);              
      altPos = 180 - pos;
      servoLeft.write(altPos);
      delay(10);                       
    }

  delay(10);

    \\ Turn 275ish degree
    for (pos = 90; pos >= 0; pos -= 1) { 
      servoRight.write(pos);              
      altPos = 180 - pos;
      servoLeft.write(pos);
      delay(10);                       
    }

  delay(10);

    for (pos = 0; pos <= 90; pos += 1) { 
      servoRight.write(pos);             
      altPos = 180 - pos;
      servoLeft.write(pos);
      delay(10);                       
    }

  delay(10);

  */
  

}