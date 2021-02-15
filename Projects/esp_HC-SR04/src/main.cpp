#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <DHT.h>
#include <HCSR04.h>

#define DHTTYPE DHT11
#define DHT11_PIN D4

UltraSonicDistanceSensor distanceSensor(D3, D5);

DHT dht(DHT11_PIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  dht.begin();
}

void loop()
{
   delay(1000);
  float temperature = dht.readTemperature();
  double distance = distanceSensor.measureDistanceCm(temperature);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C - Distance: ");
  Serial.print(distance);
  Serial.println("cm"); 
}