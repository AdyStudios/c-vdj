#include <FastLED.h>
#include <Control_Surface.h>

// L E D 
#define NUM_LEDS 8
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

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


void setup(){
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    Control_Surface.begin();
    // Startup animation
    for(int i; i < NUM_LEDS; i++){
        leds[i] = CRGB(0, 255, 255);
        FastLED.show();
        delay(100);
        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
        delay(100);
  }
}

void loop() {
  Control_Surface.loop();
}
