#include <FastLED.h>
#include <Control_Surface.h>

// L E D 
#define NUM_LEDS 8
#define DATA_PIN 2
#define LED_INTESITY 50

CRGB leds[NUM_LEDS];

bool waiting = true;

CRGB randomColor() {
    return CRGB(random(256), random(256), random(256));
}

// M I D I

USBMIDI_Interface midi;

const AddressMatrix<5, 5> addresses = {{
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
}};

NoteButtonMatrix<5, 5> buttonmatrix = {
  {2, 3, 4, 5, 6}, // row pins
  {7, 8, 9, 10, 11},    // column pins
  addresses,    // address matrix
  CHANNEL_1,    // channel and cable number
};

void ledSetup(){
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
void setup(){
    ledSetup();
    Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
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
