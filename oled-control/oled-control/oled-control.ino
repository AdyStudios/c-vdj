#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

char* getElapsedTime() {
    // Get the elapsed time since device power-on
    unsigned long elapsedTime = millis();

    // Calculate elapsed time in seconds, minutes, and hours
    unsigned long seconds = elapsedTime / 1000;
    unsigned long minutes = seconds / 60;
    unsigned long hours = minutes / 60;

    // Calculate remaining seconds and minutes after hours
    seconds %= 60;
    minutes %= 60;

    // Create a character array to store the formatted time
    static char formattedTime[9]; // Format: "hh:mm:ss\0"

    // Format the time into the character array
    snprintf(formattedTime, 9, "%02lu:%02lu:%02lu", hours, minutes, seconds);

    // Return the formatted time
    return formattedTime;
}

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(1000);

  //clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Time on: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(getElapsedTime());
  
  display.display(); 
}