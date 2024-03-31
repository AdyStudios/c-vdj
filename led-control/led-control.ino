#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 2

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
  for(int i; i < NUM_LEDS; i++){
    leds[i] = CRGB(0, 255, 255);
    FastLED.show();
    delay(200);
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(200);
  }
}
