#include "sensors.cpp"
#include "mqtt_client.cpp"

void setup() {
  setup_wifi();
}

void loop() {
  reconnect();
  // Read sensors and publish data
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  float uvIndex = uv.readUV();

  String payload = String("{") +
                   "\"temp\":" + temp + "," +
                   "\"humidity\":" + humidity + "," +
                   "\"uv\":" + uvIndex + "}";
  client.publish("sensor/1/data", payload.c_str());

  delay(900000); // 15 minutes
}
