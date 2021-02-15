#include <Arduino.h>
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"

const String kSsid = "No,thankyou-2";
const String kPassword = "beijing_newhome_11.3";

ESP8266WiFiMulti kWifiMulti;

void setup() {
  delay(200);
  Serial.begin(9600);

  // WiFi.softAP(kSsid, kPassword);

  // Serial.print("SSID: ");
  // Serial.println(kSsid);
  // Serial.print("IP: ");
  // Serial.println(WiFi.softAPIP());

  // WiFi.begin(kSsid, kPassword);

  // Serial.print("Conntect wifi: ");
  // Serial.println(kSsid);
  // Serial.println("...");

  // int i = 0;
  // while (WiFi.status() != WL_CONNECTED) {
  //   i ++;
  //   delay(1000);
  //   Serial.print("Connecte to wifi: retry count: ");
  //   Serial.println(i);
  // }

  // Serial.print("Connect wifi success, local IP: ");
  // Serial.println(WiFi.localIP());

  kWifiMulti.addAP("No,thankyou-2", "beijing_newhome_11.3");
  kWifiMulti.addAP("daydayup_55555555555555", "beijing_newhome_11.3");


  Serial.println("Connect to wifi ...");  
  int retry = 0;
  while (kWifiMulti.run() != WL_CONNECTED) {    
    retry ++;
    delay(1000);
    Serial.print("Retry: ");
    Serial.println(retry);
  }

  Serial.print("Connect success, ssid: ");
  Serial.println(WiFi.SSID());
  Serial.print("local id: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}