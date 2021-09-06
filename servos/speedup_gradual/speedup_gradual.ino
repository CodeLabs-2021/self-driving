/* 
Method for gradually speeding servo up then
slowing down.
*/




#include <Servo.h>

Servo servoRight;
Servo servoLeft;

const int switch_pin = 4;

void setup() {
  servoRight.attach(9);  
  servoLeft.attach(10);
  pinMode(switch_pin, INPUT);
}


void loop() {

  int pos = 0;
  int altPos = 0;

  // Go straight
  if (digitalRead(switch_pin) == HIGH)
  {
    for (pos = 90; pos >= 0; pos -= 1) { 
        servoRight.write(pos);              
        altPos = 180 - pos;
        servoLeft.write(altPos);
        delay(100);                       
    }

    delay(2000);

    for (pos = 0; pos <= 90; pos += 1) { 
        servoRight.write(pos);              
        altPos = 180 - pos;
        servoLeft.write(altPos);
        delay(100);                       
    }

    delay(2000);
  }

   // Reverse
  else
  {
    for (pos = 90; pos <= 180; pos += 1) { 
        servoRight.write(pos);              
        altPos = 180 - pos;
        servoLeft.write(altPos);
        delay(100);                       
    }

    delay(2000);

    for (pos = 180; pos >= 90; pos -= 1) { 
        servoRight.write(pos);              
        altPos = 180 - pos;
        servoLeft.write(altPos);
        delay(100);                       
    }

    delay(2000);

  }
}
