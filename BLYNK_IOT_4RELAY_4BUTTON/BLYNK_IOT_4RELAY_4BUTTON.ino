#define BLYNK_TEMPLATE_ID "TMPL6n8BhlM3i"
#define BLYNK_TEMPLATE_NAME "4 LED"
#define BLYNK_AUTH_TOKEN "YPdLHoGjgFMq5cg2vxyCd2tF-8M3rtZk"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Hjhjhaha";
char pass[] = "1234567890";

const int out[4] = {26, 25, 33, 32}; // Các chân LED
unsigned long timeUpdata = 0;

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

BLYNK_WRITE(V1) {
  digitalWrite(out[0], param.asInt());
}

BLYNK_WRITE(V2) {
  digitalWrite(out[1], param.asInt());
}

BLYNK_WRITE(V3) {
  digitalWrite(out[2], param.asInt());
}

BLYNK_WRITE(V4) {
  digitalWrite(out[3], param.asInt());
}

void setup() {
  Serial.begin(115200);
  for(int i = 0; i < 4; i++) {
    pinMode(out[i], OUTPUT);
  }
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  if(millis() - timeUpdata > 1000) {
    Blynk.virtualWrite(V0, millis() / 1000);
    timeUpdata = millis();
  }
}