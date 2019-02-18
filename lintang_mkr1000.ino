#include "arduino_secrets.h"
#include "thingProperties.h"
#include "DHT.h"
#define DHTPIN 4
#define LEDPIN 3
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
  potentio = analogRead(A0);
  suhu = dht.readTemperature();
}

void onLedChange() {
  digitalWrite(LEDPIN, led);
}