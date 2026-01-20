#include <DHT.h>
#include <Wire.h>
#include <Adafruit_LTR390.h>
#include <TinyGPS++.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Pin and sensor definitions
#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);
Adafruit_LTR390 uv = Adafruit_LTR390();
TinyGPSPlus gps;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  uv.begin();
  pinMode(LED_PIN, OUTPUT);

  // Connect to WiFi and MQTT
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  float uvIndex = uv.readUV();

  // Simplified GPS
  float lat = 0.0;
  float lng = 0.0;

  // MQTT payload
  String payload = String("{") +
                   "\"temp\":" + temp + "," +
                   "\"humidity\":" + humidity + "," +
                   "\"uv\":" + uvIndex + "," +
                   "\"lat\":" + lat + "," +
                   "\"lng\":" + lng + "}";
  Serial.println(payload);

  // LED blink to show activity
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);

  // Sleep 15 min for battery conservation
  delay(900000);
}
