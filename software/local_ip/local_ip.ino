#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>
#include <SpotifyEsp32.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_RST 3
#define TFT_DC 4
#define TFT_SCLK 6
#define TFT_MOSI 10

const char* SSID = "SSID";
const char* PASSWORD = "PASSWORD";

void setup() {
  Serial.begin(115200);

  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.printf("\nConnected!\n");

  Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  Serial.println("TFT initialized!");
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,0);
  tft.write(WiFi.localIP().toString().c_str());
}

void loop() {
  // put your main code here, to run repeatedly:

}
