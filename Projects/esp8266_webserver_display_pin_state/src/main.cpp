#include <Arduino.h>
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
#include "ESP8266WebServer.h"

ESP8266WiFiMulti kWifiMulti;
ESP8266WebServer kWebServer(80);

#define BUTTON_PIN D3

bool kButtonState;

void handleRoot();
void handleNotFound();
void handleLed();

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  kWifiMulti.addAP("No,thankyou-2", "beijing_newhome_11.3");
  kWifiMulti.addAP("daydayup_55555555555555", "beijing_newhome_11.3");

  Serial.println("Connect to wifi ...");
  int retry = 0;
  while (kWifiMulti.run() != WL_CONNECTED)
  {
    retry++;
    delay(1000);
    Serial.print("Retry: ");
    Serial.println(retry);
  }

  Serial.print("Connect success, ssid: ");
  Serial.println(WiFi.SSID());
  Serial.print("local id: ");
  Serial.println(WiFi.localIP());

  kWebServer.begin();
  kWebServer.on("/LED", HTTP_POST, handleLed);
  kWebServer.on("/", HTTP_GET, handleRoot);
  kWebServer.onNotFound(handleNotFound);

  Serial.println("Web server started !");

}

void handleLed() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  kWebServer.sendHeader("Location", "/");
  kWebServer.send(303);
}

void handleRoot() {
  String result;
  if (kButtonState) {
    result = "Button is ON";
  } else {
    result = "Button is OFF";
  }
  kWebServer.send(200, "text/html", result);
}

void handleNotFound() {
  kWebServer.send(404, "text/plain", "Not found");
}

void loop()
{
  kWebServer.handleClient();
  kButtonState = digitalRead(BUTTON_PIN);
  // put your main code here, to run repeatedly:
}