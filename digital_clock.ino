#include <Adafruit_GFX.h>    
#include <Adafruit_ST7789.h> 
#include <SPI.h>

#define TFT_CS         13  
#define TFT_RST        10  
#define TFT_DC         9   
#define TFT_MOSI       11  
#define TFT_SCLK       12  

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int hour = 13;
int minutes = 15;
int sec = 33;


void setup() {
  tft.init(240,320);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(3);
  
}

void loop() {
  tft.setCursor(50,140);
  tft.setTextColor(ST77XX_BLACK);
  printTime();

  sec = sec + 1;

  if (sec >= 60){
    sec = 0;
    minutes = minutes + 1;

  }

  if (minutes >= 60){
    minutes = 0;
    hour = hour + 1;

  }

  if (hour >= 24){
    hour = 0;
  }

  tft.setCursor(50,140);
  tft.setTextColor(ST77XX_GREEN);
  printTime();
  delay(1000);

}

void printTime(){
  if (hour < 10) tft.print("0");
  tft.print(hour);
  tft.print(":");

  if (minutes < 10) tft.print("0");
  tft.print(minutes);
  tft.print(":");

  if (sec < 10) tft.print("0");
  tft.print(sec);
  
}