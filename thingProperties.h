#include <ArduinoIoTCloud.h>
#include <WiFiConnectionManager.h>

char ssid[] = SECRET_SSID;    // Network SSID (name)
char pass[] = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

#define THING_ID "98aae8ab-5372-4ef8-84e3-c2e2dfedf2d8"

void onLedChange();

bool led;
float temp;
int pot;

void initProperties(){
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(temp, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(pot, READ, ON_CHANGE, NULL);
}

ConnectionManager *ArduinoIoTPreferredConnection = new WiFiConnectionManager(SECRET_SSID, SECRET_PASS);