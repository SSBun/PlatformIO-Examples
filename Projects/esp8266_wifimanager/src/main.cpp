#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <WiFiServer.h>
#include <WiFiManager.h>

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFiManager wifiManager;
  // wifiManager.resetSettings();
  
  wifiManager.autoConnect("CSL_ESP_LINK", "123456");

}

void loop() {

}