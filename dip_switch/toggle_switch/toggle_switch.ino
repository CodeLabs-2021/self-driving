/*
Basic functionality for a dip switch. Turns on an LED.
*/

int switch_pin = 2;
int led_pin = 7;

byte leds = 0;


void setup() {
  pinMode(switch_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if(digitalRead(switch_pin) == HIGH){
    digitalWrite(led_pin, HIGH);
  }
  if(digitalRead(switch_pin) == LOW){
    digitalWrite(led_pin, LOW);
  }

}