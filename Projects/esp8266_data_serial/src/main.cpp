#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char strVal = Serial.read();
    Serial.print("receive string value: ");
    Serial.println(strVal);
    int value = Serial.parseInt();
    Serial.print("receive value: ");
    Serial.println(value);
  }
  // put your main code here, to run repeatedly:
}