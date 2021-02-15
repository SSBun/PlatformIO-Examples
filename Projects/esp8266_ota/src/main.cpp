#include <Arduino.h>
#include <Ticker.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <WiFiServer.h>
#include <WiFiManager.h>

#define LED_BLINK_DURATION (3)
Ticker ledTicker;

void toggleLed(void);

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFiManager wifiManager;
  wifiManager.autoConnect("CSL_LINK_WIFI", "0123456");
  
  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  ArduinoOTA.setHostname("CSL_IOT");
  ArduinoOTA.setPassword("012345");
  ArduinoOTA.begin();
  Serial.println("OTA started");

  ledTicker.attach(LED_BLINK_DURATION, toggleLed);
}

void toggleLed()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void loop()
{
  ArduinoOTA.handle();
}