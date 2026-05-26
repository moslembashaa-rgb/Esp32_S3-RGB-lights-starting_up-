#include <Adafruit_NeoPixel.h>

#define LED_PIN     48 
#define NUMPIXELS    1  

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); 
  pixels.setBrightness(100); 
}

void loop() {
  
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  delay(1000);

  
  pixels.setPixelColor(0, pixels.Color(255, 163, 0));
  pixels.show();
  delay(1000);


  pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  pixels.show();
  delay(1000);

  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
  delay(1000);

  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();
  delay(1000);

  pixels.setPixelColor(0, pixels.Color(0, 255, 255));
  pixels.show();
  delay(1000);

  pixels.setPixelColor(0, pixels.Color(255, 0, 255));
  pixels.show();
  delay(1000);
}
