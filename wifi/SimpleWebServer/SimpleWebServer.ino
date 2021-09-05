/*
  WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 9.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the WiFi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 9

 created 25 Nov 2012
 by Tom Igoe
 */
#include <SPI.h>
#include <WiFi101.h>
#include <SharpIR.h>
#include <Servo.h>

#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
WiFiServer server(80);


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

SharpIR sensor0 = SharpIR( SharpIR::GP2Y0A21YK0F, A3 );
SharpIR sensor1 = SharpIR( SharpIR::GP2Y0A21YK0F, A4 );
SharpIR sensor2 = SharpIR( SharpIR::GP2Y0A21YK0F, A5 );

int distance0;
int distance1;
int distance2;
int robot_go = 0;

void sensorPrint(int &distance0, int &distance1, int &distance2);
void tooClose(int &distance1);
void driveStraight(int &distance1, int &distance2);
void hardLeft(int &distance0, int &distance1);
void softRight(int &distance0);
void softLeft(int &distance0);
void leftCorner(int &distance0, int &distance1);


void setup() {
  Serial.begin(9600);      // initialize serial communication
  pinMode(9, OUTPUT);      // set the LED pin mode

  servoRight.attach(9);  
  servoLeft.attach(10);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(switch_pin, INPUT);  

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);       // don't continue
  }

  // attempt to connect to WiFi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();                           // start the web server on port 80
  printWiFiStatus();                        // you're connected now, so print out the status
}



void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> turn the LED on pin 9 on<br>");
            client.print("Click <a href=\"/L\">here</a> turn the LED on pin 9 off<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
                robot_go = 1;
        }
        if (currentLine.endsWith("GET /L")) {
                robot_go = 0;
          digitalWrite(9, HIGH);                // GET /L turns the LED off
        }
      }
        if (robot_go == 1)
        {
          distance0 = sensor0.getDistance();
          distance1 = sensor1.getDistance();
          distance2 = sensor2.getDistance();

          sensorPrint(distance0, distance1, distance2);
          tooClose(distance1);
          driveStraight(distance1, distance2);
          hardLeft(distance0, distance1);
          softRight(distance0);
          softLeft(distance0);
          leftCorner(distance0, distance1);

          delay(250); // GET /H turns the LED on
        }

    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}




void sensorPrint(int &distance0, int &distance1, int &distance2)
{
  Serial.print("Sensor 0: ");
  Serial.print(distance0);

  Serial.print("    Sensor 1: ");
  Serial.print(distance1);

  Serial.print("    Sensor 2: ");
  Serial.println(distance2);
}


/*
if front sensor is very close to wall:
  back up */
void tooClose(int &distance1)
{
  if (distance1 <= x_min)
  {
    servoRight.write(109);
    servoLeft.write(78); 
  }  
}


/*
if front sensor and right sensor are farther than contact length
or right sensor makes contact, and is greater than min, less than max: drive straight */
void driveStraight(int &distance0, int &distance1)
{
  if (distance1 >= x0 && distance0 >= y0)
  {
    servoRight.write(74);
    servoLeft.write(118);
  }
}


/*
if front sensor makes contact, but right sensor is not:
  turn hard left until right sensor is less than min */
void hardLeft(int &distance0, int &distance1)
{
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
}


/*
if right sensor makes contact, but is greater than max:
  turn forward-right until less than min */
void softRight(int &distance0)
{
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
}


/*
if right sensor makes contact, but is less than min:
  turn forward-left until past min */
void softLeft(int &distance0)
{
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
}


/*
if front sensor makes contact, and right sensor makes contact:
  turn hard left until right sensor is greater than max */
void leftCorner(int &distance0, int &distance1)
{
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
}