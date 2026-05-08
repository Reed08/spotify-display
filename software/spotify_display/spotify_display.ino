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

#define SW_BACK 0
#define SW_PLAY 1
#define SW_FORWARD 2

const char* SSID = "SSID";
const char* PASSWORD = "PASSWORD";
const char* CLIENT_ID = "CLIENT_ID";
const char* CLIENT_SECRET = "CLIENT_SECRET";

const char* BOT_PLAYING = "|<          ||          >|";
const char* BOT_PAUSED = "|<          >          >|";

String lastArtist;
String lastTrackname;
String currentArtist;
String currentTrackname;
bool isPlaying = true;

int backVal = HIGH;
int playVal = HIGH;
int forwardVal = HIGH;

Spotify sp(CLIENT_ID, CLIENT_SECRET);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  Serial.begin(115200);

  pinMode(SW_BACK, INPUT_PULLUP);
  pinMode(SW_PLAY, INPUT_PULLUP);
  pinMode(SW_FORWARD, INPUT_PULLUP);

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  Serial.println("TFT initialized!");
  tft.fillScreen(ST77XX_BLACK);

  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi...")l
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.printf("\nConnected!\n");

  tft.setCursor(0,0);
  tft.write(WiFi.localIP().toString().c_str());

  sp.begin();
  while (!sp.is_auth()) {
    sp.handle_client();
  }
  Serial.println("Connected to Spotify!");
}

void loop() {
  currentArtist = sp.current_artist_names();
  currentTrackname = sp.current_track_name();
  isPlaying = sp.is_playing();

  if (lastArtist != currentArtist && currentArtist != "Something went wrong" && !currentArtist.isEmpty()) {
    tft.fillScreen(ST77XX_BLACK);
    lastArtist = currentArtist;
    Serial.println("Artist: " + lastArtist);
    tft.setCursor(10,10);
    tft.write(lastArtist.c_str());
  }

  if (lastTrackname != currentTrackname && currentTrackname != "Something went wrong" && currentTrackname != "null") {
    lastTrackname = currentTrackname;
    Serial.println("Track: " + lastTrackname);
    tft.setCursor(10,40);
    tft.write(lastTrackname.c_str());
    tft.setCursor(10, 70);
    tft.write(isPlaying ? BOT_PLAYING : BOT_PAUSED);
  }

  backVal = digitalRead(SW_BACK);
  playVal = digitalRead(SW_PLAY);
  forwardVal = digitalRead(SW_FORWARD);

  if (backVal == HIGH) {
    sp.skip_to_previous();
  }
  if (playVal == HIGH) {
    if (isPlaying) {
      sp.pause_playback();
    } else {
      sp.start_a_users_playback();
    }
  }
  if (forwardVal == HIGH) {
    sp.skip_to_next();
  }

  delay(2000);
}
