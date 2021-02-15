#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>


IRrecv recever(D2);


decode_results result;

void setup() {
  Serial.begin(115200);
  delay(500);
  recever.enableIRIn();
  Serial.println("Ready receive infrared signal...");
}

void loop() {
  delay(1000);
  if (recever.decode(&result)) {
    Serial.println((unsigned long)result.value, HEX);
    recever.resume();        
    delay(100);
  }  
}