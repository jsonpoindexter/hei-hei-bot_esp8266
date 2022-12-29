
#include <Arduino.h>
#include <wifi_secrets.h>

#define OUTPUT_PIN 4

#include <FastLED.h>
#define NUM_LEDS 1
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid = SSID_SECRET;
const char* password = PASSWORD_SECRET;
const char* hostname = HOSTNAME_SECRET;

const char* PARAM_MESSAGE = "message";

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

bool activateHeiHeiBot = false;


void setup() {
    Serial.begin(9600);
    delay(2000);

    pinMode(OUTPUT_PIN, OUTPUT);

    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(32);
    FastLED.clear();

    WiFi.mode(WIFI_STA);
    WiFi.hostname(hostname);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }
    Serial.println();
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Hostname: ");
    Serial.println(WiFi.getHostname());

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        activateHeiHeiBot = true;
        request->send(200);
    });

    server.onNotFound(notFound);

    server.begin();
}

void loop() {
 
  if (activateHeiHeiBot) {
    Serial.println("DIGITAL WRITE HIGH");
    digitalWrite(OUTPUT_PIN, HIGH);

    leds[0] = CRGB::Red;
    FastLED.show();
    delay(50);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(50);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(120);
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(50);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(300);
    leds[0] = CRGB::Red;
    FastLED.show();
    
    Serial.println("DIGITAL WRITE LOW");
    digitalWrite(OUTPUT_PIN, LOW);

    delay(11 * 1000);

    leds[0] = CRGB::Black;
    FastLED.show();

    activateHeiHeiBot = false;
  }
}