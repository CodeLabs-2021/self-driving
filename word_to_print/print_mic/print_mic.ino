#define MIC A0
#define INTERVAL 5

void setup() {
    Serial.begin(115200);
    pinMode(MIC, INPUT);
}

void loop() {
    Serial.println(analogRead(MIC));
    delay(INTERVAL);
}