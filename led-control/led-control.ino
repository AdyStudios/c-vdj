#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 2

#define LED_INTESITY 50

bool waiting = true;

CRGB randomColor() {
    return CRGB(random(256), random(256), random(256));
}

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(LED_INTESITY);
    for(int j = 0; j < 2 ; j++){

    
      for(int i = 0; i < NUM_LEDS; i++){
          leds[i] = CRGB(0, 255, 255);
          FastLED.show();
          delay(50);
          leds[i] = CRGB(0, 0, 0);
          FastLED.show();
          
      }
      for (int i = NUM_LEDS; i --> 0; ){
          leds[i] = CRGB(0, 255, 255);
          FastLED.show();
          delay(50);
          leds[i] = CRGB(0, 0, 0);
          FastLED.show();
      }
    }
}

void loop() { 
    if(waiting){
      waitingAnim();
    }
}

void waitingAnim(){
  for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = randomColor();
      FastLED.show();
      delay(300);
      for (int j = 255; j >= 0; j--) {
            leds[i].fadeToBlackBy(10); // Fade the LED
            FastLED.show();
            delay(5);
        }
    }
} 
