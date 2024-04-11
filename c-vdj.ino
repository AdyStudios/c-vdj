#include <FastLED.h>
#include <Control_Surface.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// L E D 
#define NUM_LEDS 8
#define DATA_PIN 0

//TODO: connect both led strips into one, so it's easier to control
#define LED_INTESITY 255

CRGB leds[NUM_LEDS];

// O L E D

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

char formattedTime[9];

char* getElapsedTime() {
    unsigned long elapsedTime = millis();
    unsigned int seconds = elapsedTime / 1000;
    unsigned int minutes = seconds / 60;
    unsigned int hours = minutes / 60;
    seconds %= 60;
    minutes %= 60;

    snprintf(formattedTime, 9, "%02lu:%02lu:%02lu", hours, minutes, seconds);

    return formattedTime;
}

// M I D I

USBMIDI_Interface midi;

const AddressMatrix<4, 7> addresses = {{
  {1,2,3,4,5,6,7},
  {8,9,10,11,12,13,14},
  {15,16,17,18,19,20,21},
  {22,23,24,25,26,27,28},
}};

NoteButtonMatrix<4, 7> buttonmatrix = {
  {10,11,12,13}, // row pins
  {2,3,4,5,6,8,9},    // column pins
  addresses,    // address matrix
  CHANNEL_1,    // channel and cable number
};

void oledSetup(){
  // Oled setup
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void setup(){
    Serial.begin(115200);
    oledSetup();

    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(LED_INTESITY);

    Control_Surface.begin();
}

void loop() {
  //updateOled();
  Control_Surface.loop();
}

/*void updateOled(){
  delay(1000);

  //clear display
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Time on:");
  display.setTextSize(2);
  display.setCursor(15,10);
  display.print(getElapsedTime());
  
  display.display(); 
  
}*/

/*void onNoteOn(NoteOn& note) {
  int index = note.address() - 1; 
  leds[index] = CRGB::Green; 
  FastLED.show(); 
}

void onNoteOff(NoteOff& note) {
  int index = note.address() - 1; 
  leds[index] = CRGB::Black; 
  FastLED.show(); 
}*/
