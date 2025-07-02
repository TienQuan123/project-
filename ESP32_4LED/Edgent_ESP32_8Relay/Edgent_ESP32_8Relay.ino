#define APP_DEBUG
#include "BlynkEdgent.h"
#define BLYNK_TEMPLATE_ID "TMPL6n8BhlM3i"
#define BLYNK_TEMPLATE_NAME "4 LED"
#define BLYNK_AUTH_TOKEN "LKHAxWu0xEWNHk8jyYb1zwLOwDspAtVE"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
const int out2 = 14;
const int out3 = 12;
const int out4 = 13;
const int out1 = 27;
WidgetLED ledConnect(V0);
unsigned long timesBlinkLed=millis();
void setup(){
  Serial.begin(115200);
  delay(100);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  BlynkEdgent.begin();
}

void loop(){
  BlynkEdgent.run();
  if(millis()-timesBlinkLed>1000){
    if(ledConnect.getValue()){
      ledConnect.off();
    }else{
      ledConnect.on();
    }
    unsigned long value = millis() / 1000;
    Blynk.virtualWrite(V9, String(value));
    timesBlinkLed=millis();
  }
}
BLYNK_WRITE(V1){
  int p = param.asInt();
  digitalWrite(out1,p);
}
BLYNK_WRITE(V2){
  int p = param.asInt();
  digitalWrite(out2,p);
}
BLYNK_WRITE(V3){
  int p = param.asInt();
  digitalWrite(out3,p);
}
BLYNK_WRITE(V4){
  int p = param.asInt();
  digitalWrite(out4,p);
}
