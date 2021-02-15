#include <Arduino.h>
#include "FastLED.h"


#define LED_PIN     5
#define COLOR_ORDER GRB
#define CHIPSET  WS2812B
#define NUM_LEDS  16

#define BRIGHTNESS  255
#define FRAMES_PER_SECOND 60

int kStartIndex = 0;

CRGB leds[NUM_LEDS];

void setup() {
  delay(1000);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  kStartIndex ++;
  fill_palette(leds, 16, kStartIndex, 8, OceanColors_p, 120, LINEARBLEND);  
  FastLED.show();
  delay(25);
  // int i;
  // for (i = 0; i < NUM_LEDS - 2; i ++) {
  //   leds[i] = CRGB::Blue;
  //   leds[i+1] = CRGB::Red;
  //   leds[i+2] = CRGB::Green;
  //   FastLED.show();
  //   delay(100);
  //   leds[i] = CRGB::Black;
  //   leds[i+1] = CRGB::Black;
  //   leds[i+2] = CRGB::Black;
  // }
  // delay(1000);
  // put your main code here, to run repeatedly:
}