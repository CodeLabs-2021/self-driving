


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

#define LOG_OUT 1 // use the log output function
#define FFT_N 256 // set to 256 point fft

#include <FFT.h> // include the library


// #include <Servo.h>
// #include <SharpIR.h>


// Servo servoRight;
// Servo servoLeft;

// const int switch_pin = 2;
// const int led_green = 5;
// const int led_yellow = 6;
// const int led_red = 7;

// SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A0 );





int counter;



void setup() {
  Serial.begin(115200);
  // TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  DIDR0 = 0x01; // turn off the digital input for adc0  

  // servoRight.attach(9);  
  // servoLeft.attach(10);
  // pinMode(led_green, OUTPUT);
  // pinMode(led_yellow, OUTPUT);
  // pinMode(led_red, OUTPUT);
  // pinMode(switch_pin, INPUT);
}


void loop() 
{
  // digitalWrite(led_green, HIGH);

  // straight
  // servoRight.write(68);
  // servoLeft.write(130);  

  // forward-left
  // servoRight.write(60);
  // servoLeft.write(120); 

  // circle-right
  // servoRight.write(80);
  // servoLeft.write(130);    

  // forward-right
  // servoRight.write(73);
  // servoLeft.write(130);

  // backwards
//   servoRight.write(109);
//   servoLeft.write(78);  


  // counter++;
  // Serial.println(counter);
  // delay(1000);


  // Serial.println("While loop");


  while(1) { // reduces jitter
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
    for (int i = 0; i < 256/2; i++) { 
      Serial.println(fft_log_out[i]); // send out the data
      Serial.println(i);
    }
  }
}

