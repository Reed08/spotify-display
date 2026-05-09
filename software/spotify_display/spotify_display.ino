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
#define SW_LIKE 8

#define LED 21

const char* SSID = "SSID";
const char* PASSWORD = "PASSWORD";
const char* CLIENT_ID = "CLIENT_ID";
const char* CLIENT_SECRET = "CLIENT_SECRET";

String lastArtist;
String lastTrackname;
String lastTrackId;
String currentArtist;
String currentTrackname;
String currentTrackId;
bool isPlaying = true;
bool isLiked = false;

int backVal = HIGH;
int playVal = HIGH;
int forwardVal = HIGH;
int likeVal = HIGH;

Spotify sp(CLIENT_ID, CLIENT_SECRET);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  Serial.begin(115200);

  pinMode(SW_BACK, INPUT_PULLUP);
  pinMode(SW_PLAY, INPUT_PULLUP);
  pinMode(SW_FORWARD, INPUT_PULLUP);
  pinMode(SW_LIKE, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  Serial.println("TFT initialized!");
  tft.fillScreen(ST77XX_BLACK);

  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.printf("\nConnected!\n");

  tft.setCursor(0,0);
  tft.write(WiFi.localIP().toString().c_str());

  sp.set_scopes("user-read-playback-state user-modify-playback-state user-library-read user-library-modify");
  sp.begin();
  while (!sp.is_auth()) {
    sp.handle_client();
  }
  Serial.println("Connected to Spotify!");
}

void loop() {
  currentArtist = sp.current_artist_names();
  currentTrackname = sp.current_track_name();
  currentTrackId = sp.current_track_id();
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
  }

  if (lastTrackId != currentTrackId && currentTrackId != "Something went wrong" && !currentTrackId.isEmpty()) {
    lastTrackId = currentTrackId;
    response res = sp.check_users_saved_tracks(lastTrackId.c_str());
    if (res.status_code == 200) {
      isLiked = res.reply[0].as<bool>();
      digitalWrite(LED, isLiked ? HIGH : LOW);
      Serial.println("Is liked: " + String(isLiked));
    }
  }

  backVal = digitalRead(SW_BACK);
  playVal = digitalRead(SW_PLAY);
  forwardVal = digitalRead(SW_FORWARD);
  likeVal = digitalRead(SW_LIKE);

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
  if (likeVal == HIGH) {
    if (isLiked) {
      sp.remove_users_saved_tracks(lastTrackId.c_str());
    } else {
      sp.save_tracks_for_user(lastTrackId.c_str());
    }
    isLiked = !isLiked;
    digitalWrite(LED, isLiked ? HIGH : LOW);
  }

  delay(2000);
}
