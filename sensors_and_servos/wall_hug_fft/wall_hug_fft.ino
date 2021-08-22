

#define LOG_OUT 1 // use the log output function
#define FFT_N 256 // set to 256 point fft

#include <FFT.h> // include the library
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

SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A0 );
SharpIR sensor1 = SharpIR( SharpIR::GP2Y0A21YK0F, A1 );
SharpIR sensor2 = SharpIR( SharpIR::GP2Y0A21YK0F, A2 );
// SharpIR sensor0 = SharpIR(sensorPin0, model);
// SharpIR sensor1 = SharpIR(sensorPin1, model);
// SharpIR sensor2 = SharpIR(sensorPin2, model);


int sound_check;


void setup() {
  Serial.begin(9600);
  servoRight.attach(9);  
  servoLeft.attach(10);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(switch_pin, INPUT);
  TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  DIDR0 = 0x01; // turn off the digital input for adc0
}

void loop()
{

  cli();  // UDRE interrupt slows this way down on arduino1.0
  for (int i = 0 ; i < 512 ; i += 2) { // save 256 samples
    while(!(ADCSRA & 0x10)); // wait for adc to be ready
    ADCSRA = 0xf5; // restart adc
    byte m = ADCL; // fetch adc data
    byte j = ADCH;
    int k = (j << 8) | m; // form into an int
    k -= 0x0200; // form into a signed int
    k <<= 6; // form into a 16b signed int
    fft_input[i] = k; // put real data into even bins
    fft_input[i+1] = 0; // set odd bins to 0
  }
  fft_window(); // window the data for better frequency response
  fft_reorder(); // reorder the data before doing the fft
  fft_run(); // process the data in the fft
  fft_mag_log(); // take the output of the fft
  sei();
  Serial.println("start");
  for (int i = 0 ; i < FFT_N/2 ; i++) { 
    Serial.println(fft_log_out[i]); // send out the data
  }
  

  if (fft_log_out[7] > 160)
  {
    digitalWrite(6, HIGH);
    sound_check = 1;
  }
  else
    digitalWrite(6, LOW);



  if (sound_check)
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

}