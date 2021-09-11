# Self-Driving Robot

Program for an Arduino Uno-based differential-drive robot which uses IR sensors, a microphone and Wi-Fi to navigate around objects and respond to commands.

![](https://github.com/CodeLabs-2021/self-driving/blob/main/Robot_Rock.gif)

---

## Installation

There are three different versions in this repository, each under a different branch. To download one of these versions, switch branches under <img src="https://img.shields.io/badge/-main-lightgrey.svg"/> then **Download ZIP** under <img src="https://img.shields.io/badge/-Code-brightgreen.svg"/>. Individual sketches must then be uploaded to the board with the Arduino IDE.

### Requirements:

#### Hardware
* [Arduino Uno](https://store-usa.arduino.cc/products/arduino-uno-rev3)
* [Microphone](https://learn.adafruit.com/adafruit-agc-electret-microphone-amplifier-max9814/)
* [Servos](https://www.pololu.com/product/1248)            Quantity: 2
* [IR Sensors](https://www.pololu.com/product/136)      Quantity: 3
* [WiFi Shield](https://www.adafruit.com/product/3653)
* [Breadboard](https://www.adafruit.com/product/4539)
* You'll also need jumper wires and a power source, either a long USB cable or a [power pack](https://www.newegg.com/black-anker-powercore-slim-10000-10000-mah-power-bank/p/39G-000T-000B9)

#### Software
* [Arduino IDE](https://www.arduino.cc/en/software)
* Arduino Libraries
    * Servo
    * SharpIR
    * WiFi101
    * FFT

Different branches may have additional required libraries.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Maintanence
Each branch is maintained separately by the contributor that created it.

## License
[MIT](https://choosealicense.com/licenses/mit/)

