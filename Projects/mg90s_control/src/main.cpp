#include <Arduino.h>
#include "Servo.h"


Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  Serial.begin(9600);
  Serial.println("Please input you angle :");
}

void loop() {
  if (Serial.available()) {
    int angle = Serial.parseInt();
    Serial.print("Input angle: ");
    Serial.println(angle);
    servo.write(angle);
    delay(20);
  }

  Serial.print("anagle: ");
  Serial.println(servo.read());
}