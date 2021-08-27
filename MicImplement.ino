#include <SharpIR.h>

//Pins used for sensors
#define IRPinFront A2
#define IRPinLeft A0
#define IRPinRight A1
//Model of the sensor
#define model 1080

//Pins for DC Motors 
//Motor A
const int AI2 = 4;
const int AI1 = 5;
const int PWM_A = 3;
//Motor B
const int BI2 = 9;
const int BI1 = 8;
const int PWM_B = 10;

//Creating SharpIR objects (model, pin)
SharpIR front_sensor = SharpIR(model, IRPinFront);
SharpIR left_sensor = SharpIR(model, IRPinLeft);
SharpIR right_sensor = SharpIR(model, IRPinRight);

//Distances from the sensors (These will change alot)
int front_distance_cm;
int left_distance_cm;
int right_distance_cm;

//Button
int buttonNew;
int buttonOld = 0;

int isOn = 0;

const int sampleWindow = 250; // Sample window width in mS (250 mS = 4Hz)
unsigned int knock;

//Methods
void forward();
void stopTracks();
void reverse();
void turnRight();
void turnLeft();
void TestSensors();

void setup() 
{
  //Setting Pins for DC Motors
  pinMode(AI2, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{

 //Get the distance from the sensors. Usually any number over 110 means theres nothing in front of it. 
  front_distance_cm = front_sensor.getDistance();
  left_distance_cm = left_sensor.getDistance();
  right_distance_cm = right_sensor.getDistance();

 unsigned long start= millis();  // Start of sample window
 unsigned int peakToPeak = 0;   // peak-to-peak level

 unsigned int signalMax = 0;
 unsigned int signalMin = 1024;

 // collect data for 250 miliseconds
 while (millis() - start < sampleWindow)
 {
   knock = analogRead(5);
      if (knock < 1024)  //This is the max of the 10-bit ADC so this loop will include all readings
      {
         if (knock > signalMax)
         {
           signalMax = knock;  // save just the max levels
         }
      else if (knock < signalMin)
        {
         signalMin = knock;  // save just the min levels
         }
     }
 }
 peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
 double volts = (peakToPeak * 3.3) / 1024;  // convert to volts


Serial.println(volts);
 if (volts >=1.0)
 {
   if(isOn == 0){
      
      Serial.print("ON\n");
      //Because of chasis we need a good amount of space when maneuvering (turning).
      //This will make wall-e go forward until it sees something.
      if(front_distance_cm > 20){
        Serial.println("FORWARD");
        forward();
      }else{
        stopTracks();
      }

      if(front_distance_cm <= 20){
        stopTracks();
        front_distance_cm = front_sensor.getDistance();
        left_distance_cm = left_sensor.getDistance();
        right_distance_cm = right_sensor.getDistance();
        delay(1000);
//        Serial.println("Front BLOCKED");
//        Serial.println(front_distance_cm);
//        Serial.println(left_distance_cm);
//        Serial.println(right_distance_cm);
        if(right_distance_cm > 20){
          Serial.println("Turning RIGHT");
          turnRight();
        }else if(left_distance_cm > 20){
          Serial.println("Turning LEFT");
          turnLeft();
        }else{
          Serial.println("BOXED IN");
          stopTracks();
          reverse();
          while(left_distance_cm <= 20 && right_distance_cm <= 20){
            left_distance_cm = left_sensor.getDistance();
            right_distance_cm = right_sensor.getDistance();
            delay(1000);
          }
          stopTracks();
          if(right_distance_cm > 20){
            turnRight();
          }else if(left_distance_cm > 20){
            turnLeft();
          }
        }
      }
      
      isOn = 1;
     }else{
      Serial.print("OFF\n");
      stopTracks();
      isOn = 0;
     }
 }          
   
}


void forward(){
  //Forward
  //Motor A
  digitalWrite(AI2, LOW);
  digitalWrite(AI1, HIGH);
  analogWrite(PWM_A, 150);
  //Motor B
  digitalWrite(BI2, LOW);
  digitalWrite(BI1, HIGH);
  analogWrite(PWM_B, 150);
}

void stopTracks(){
  //Break
  //Motor A
  digitalWrite(AI2, LOW);
  digitalWrite(AI1, LOW);
  analogWrite(PWM_A, 0);
  //Motor B
  digitalWrite(BI2, LOW);
  digitalWrite(BI1, LOW);
  analogWrite(PWM_B, 0);
}

void reverse(){
   //Reverse
  //Motor A
  digitalWrite(AI2, HIGH);
  digitalWrite(AI1, LOW);
  analogWrite(PWM_A, 100);
  //Motor B
  digitalWrite(BI2, HIGH);
  digitalWrite(BI1, LOW);
  analogWrite(PWM_B, 100);
}

void turnRight(){
  
  while(front_distance_cm <= 15) {
    digitalWrite(AI2, HIGH);
    digitalWrite(AI1, LOW);
    analogWrite(PWM_A, 255);

    //Motor B
    digitalWrite(BI2, LOW);
    digitalWrite(BI1, HIGH);
    analogWrite(PWM_B, 255);

    front_distance_cm = front_sensor.getDistance();
    left_distance_cm = left_sensor.getDistance();
    right_distance_cm = right_sensor.getDistance();
  }
    stopTracks();
}

void turnLeft(){
   while(front_distance_cm <= 15) {
    
    digitalWrite(AI2, LOW);
    digitalWrite(AI1, HIGH);
    analogWrite(PWM_A, 255);

    //Motor B
    digitalWrite(BI2, HIGH);
    digitalWrite(BI1, LOW);
    analogWrite(PWM_B, 255);
     
    front_distance_cm = front_sensor.getDistance();
    left_distance_cm = left_sensor.getDistance();
    right_distance_cm = right_sensor.getDistance();
   }
    stopTracks();
}

void TestSensors(){
//    Serial.println(front_distance_cm);
//    Serial.println();
//    Serial.println(left_distance_cm);
//    Serial.println();
//    Serial.println(right_distance_cm);
//    Serial.println();
  if(front_distance_cm <= 15){
    Serial.println("FRONT \n");
  } else if(right_distance_cm <= 15){
    Serial.println("RIGHT\n");
  } else if(left_distance_cm <= 15) {
    Serial.println("LEFT\n");
  }
}
