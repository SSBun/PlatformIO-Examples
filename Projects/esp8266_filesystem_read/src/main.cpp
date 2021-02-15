#include <Arduino.h>
#include "LittleFS.h"

#define FILE_PATH "/data/config.txt"

void setup() {
  Serial.begin(9600);
  Serial.println("");

  if (LittleFS.begin()) {
    Serial.println("FS start success");
  } else {
    Serial.println("FS start failed");
  }

  if (LittleFS.exists(FILE_PATH)) {    
    Serial.print("Find file: ");
    Serial.println(FILE_PATH);
  } else {
    Serial.print(FILE_PATH);
    Serial.println(" not found");
  }

  File dataFile = LittleFS.open(FILE_PATH, "r");

  for (long unsigned int i = 0; i < dataFile.size(); i ++) {
    Serial.print((char)dataFile.read());
  }

  dataFile.close();
}

void loop() {
  // put your main code here, to run repeatedly:
}