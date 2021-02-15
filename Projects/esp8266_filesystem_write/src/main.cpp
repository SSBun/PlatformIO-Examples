#include <Arduino.h>
#include "LittleFS.h"

#define FILE_PATH "/data/config.txt"

void setup() {
  Serial.begin(9600);
  Serial.println("");

  Serial.println("FS format start");
  LittleFS.format();
  Serial.println("FS format finish");

  if (LittleFS.begin()) {
    Serial.println("FS started");
  } else {
    Serial.println("FS failed to start");
  }

  File dataFile = LittleFS.open(FILE_PATH, "w");
  dataFile.println("Hello Iot world");
  dataFile.close();
  Serial.println("Finished writing data to FS");
}

void loop() {
  // put your main code here, to run repeatedly:
}