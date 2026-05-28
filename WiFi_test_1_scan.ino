#include <Adafruit_GFX.h>    
#include <Adafruit_ST7789.h> 
#include <SPI.h>
#include <WiFi.h> 

#define TFT_CS         13  
#define TFT_RST        10  
#define TFT_DC         9   
#define TFT_MOSI       11  
#define TFT_SCLK       12  

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);



void setup() {
  
  tft.init(240,320);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10,10);
  tft.println("WIFI SCANNER READY");
  
}

void loop() {
  tft.fillRect(0,30,240,320,ST77XX_BLACK);
  tft.setTextSize(1.6);
  tft.setCursor(10,30);
  tft.setTextColor(ST77XX_GREEN);
  tft.println("SCANNING.....");

  int networkCount = WiFi.scanNetworks();
  tft.setCursor(10,50);
  tft.setTextSize(1.6);
  tft.setTextColor(ST77XX_GREEN);
  tft.println("FOUND: ");
  tft.println(networkCount);
  tft.println(" NETWORKS");

  if (networkCount == 0){
    tft.setTextColor(ST77XX_RED);
    tft.println("NO NETWORK FOUND");
    
  }else{
    int maxdisplay = networkCount;
    
    tft.setTextColor(ST77XX_GREEN);
    tft.setTextSize(1.6);

    for (int i=0; i< maxdisplay; ++i){

      tft.print(i+1);
      tft.println(WiFi.SSID(i));
    }


  }
WiFi.scanDelete();
delay(10000);

}
