/*
Funky robot dance.
*/




#include <Servo.h>

Servo servoRight;
Servo servoLeft;

int pos = 0;
int altPos = 0;

void setup() {
  servoRight.attach(9);  
  servoLeft.attach(10);
}


void loop() {

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

  // Turn 275ish degree
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

}
