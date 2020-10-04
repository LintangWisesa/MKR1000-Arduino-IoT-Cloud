#include "arduino_secrets.h"
#include "thingProperties.h"
#include "DHT.h"
#define DHTPIN 5
#define LEDPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  setDebugMessageLevel(2);
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  led = false;
  dht.begin();
}

void loop() {
  ArduinoCloud.update();
  pot = analogRead(A0);
  temp = dht.readTemperature();
}

void onLedChange() {
  digitalWrite(LEDPIN, led);
}