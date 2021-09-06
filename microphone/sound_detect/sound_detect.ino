/*
Prints a normalized output of sound with reduced noise. 
Intended for use with the Serial Plotter. However, it's not
very responsive.
*/

const int LED = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int sum = 0;
  for(int i=0; i<100; i++)
  {
    sum += analogRead(0);
    delay(1);             // **** EDIT ****
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


	