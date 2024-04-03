#include <FastLED.h>

#include <Control_Surface.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

// L E D 
#define NUM_LEDS 16
#define DATA_PIN 2

//TODO: connect both led strips into one, so it's easier to control
#define LED_INTESITY 50

CRGB leds[NUM_LEDS];

// O L E D

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

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


void setup(){
    Serial.begin(115200);
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    Control_Surface.begin();

    // Startup animation
    for(int i; i < NUM_LEDS; i++){
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
        delay(100);
    }

    // Oled setup
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      Serial.println(F("SSD1306 allocation failed"));
    }
    delay(2000);

    display.clearDisplay();

    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println("Starting UP...");
    display.display(); 
    display.startscrollright(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
    display.println("Done!");
    display.display();
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

void onNoteOn(NoteOn& note) {
  int index = note.address() - 1; 
  leds[index] = CRGB::Green; 
  FastLED.show(); 
}

void onNoteOff(NoteOff& note) {
  int index = note.address() - 1; 
  leds[index] = CRGB::Black; 
  FastLED.show(); 
}

void updateOled(){
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Time on: ")
  display.print(millis());

  display.setCursor(0, 10);
  
}

void onNoteOn(NoteOn& note) {
  int index = note.address() - 1; 
  leds[index] = CRGB::Green; 
  FastLED.show(); 
}

void onNoteOff(NoteOff& note) {
  int index = note.address() - 1; 
  leds[index] = CRGB::Black; 
  FastLED.show(); 
}

void updateOled(){
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Time on: ")
  display.print(millis());

  display.setCursor(0, 10);
  
}
