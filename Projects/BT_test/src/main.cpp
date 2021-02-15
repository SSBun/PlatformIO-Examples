#include <Arduino.h>
#include "SoftwareSerial.h"


SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  // BTSerial.print("AT");
  // put your setup code here, to run once:
}

void loop() {

  if (BTSerial.available()) {
    char result = BTSerial.read();
    Serial.print("The blutooth callback: ");
    Serial.println(result);
  }

  if (Serial.available()) {
    String command = Serial.readString();
    Serial.print("Input command: ");
    Serial.println(command);

    BTSerial.print(command);
  };
  // put your main code here, to run repeatedly:
}