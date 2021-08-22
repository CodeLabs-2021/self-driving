// //these define the pin connections
// const int microphonePin= 0; //the microphone positive terminal will connect to analog pin A0 to be read
// const int ledPin=13; //the code will flash the LED connected to pin 13

// int sample; //the variable that will hold the value read from the microphone each time

// const int threshold= 800;//the microphone threshold sound level at which the LED will turn on

// void setup() {
//   pinMode (ledPin, OUTPUT);//sets digital pin 13 as output
//   Serial.begin(9600); //sets the baud rate at 9600 so we can check the values the microphone is obtaining on the Serial Monitor
// }

// void loop(){
//   sample= analogRead(A0); //the arduino takes continuous readings from the microphone
//   if (sample > threshold)
//   {
//   digitalWrite (ledPin, HIGH); //if the reading is greater than the threshold value, LED turns on
//   delay (500); //LED stays on for a half a second
//   digitalWrite (ledPin, LOW); //LED turns off
//   }
//   else{ digitalWrite(ledPin, LOW); }

//   Serial.println(sample);
// } 








// Arduino
// int soundPin = A0;
int LED = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  long sum = 0;
  for(int i=0; i<100; i++)
  {
    sum += analogRead(A0);
  }

  sum = sum/100;

  if(sum > 600){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }

  Serial.println(sum);
  // Serial.println(sizeof(sum));
  delay(10);
}


	