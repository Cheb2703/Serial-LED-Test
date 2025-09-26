#include <Arduino.h>  // Needed for PlatformIO
#include <Adafruit_NeoPixel.h>

#define LED_PIN     25      // Pin where LED strip is connected
#define LED_COUNT   144     // Number of LEDs in your strip
int R = 0;
int G = 0;
int B = 255;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);   // Start Serial communication
  strip.begin();
  strip.show(); // Initialize all LEDs to 'off'
  strip.setBrightness(10);  //Set brightness level
  delay(1000);            // Give the Serial Monitor time to connect
}

void loop() {
  // Go through each LED one by one
  for (int i = 0; i < LED_COUNT; i++) {
    strip.clear();              // Turn off all LEDs
    strip.setPixelColor(i, strip.Color(R, G, B)); // Red (R,G,B)
    strip.show();               // Send updated color to strip
    delay(2);                 // Pause between LEDs
  }

  for (int i = LED_COUNT ; i > 0 ; i--) {
    strip.clear();              // Turn off all LEDs
    strip.setPixelColor(i, strip.Color(R, G, B)); // Red (R,G,B)
    strip.show();               // Send updated color to strip
    delay(10);                 // Pause between LEDs
  }

  /*
  for (int i = 1; i <= 50; i++) {
    Serial.println(i);    // Print number to Serial Monitor
    delay(100);           // 500 milliseconds delay
  }
    */
}