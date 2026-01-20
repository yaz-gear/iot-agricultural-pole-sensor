# IoT Agricultural Pole Sensor

## Overview
This project demonstrates an ESP32-based IoT agricultural pole sensor network. The poles collect environmental data (temperature, humidity, soil moisture, UV light, GPS location) and send it via MQTT to a Raspberry Pi. The Raspberry Pi aggregates and logs data to a server for visualization.

The system is designed to be **low-cost, energy-efficient, and easy to deploy**, helping farmers monitor crops reliably and sustainably.

## Objectives
- Measure temperature and humidity (air and soil)
- Measure UV light intensity
- Share sensor data and GPS position
- Communicate with other poles and propagate alerts
- Provide periodic readings every 10–30 minutes
- Indicate sensor status using an LED (traffic-light metaphor)
- Easy deployment and low-cost hardware

## System Description
- **ESP32 Pole Sensor**:
  - Adafruit LTR390 UV sensor
  - DHT22/11 Temperature & Humidity
  - Soil moisture sensor
  - GPS module (Adafruit Ultimate GPS)
  - RGB LED for status
  - Powered by LiPo battery + solar panel
- **Raspberry Pi 3**:
  - MQTT broker (Python-based)
  - Receives data from multiple poles
  - Logs data to server

**Communication:**  
- MQTT (publish-subscribe model)
- WiFi network (MERUSYS 300 Mbps Router)
- ESP32 publishes readings → Raspberry Pi subscribes

## My Contribution
- Designed ESP32 firmware for sensors and LED status
- Implemented MQTT communication with Raspberry Pi
- Created Raspberry Pi data logger for server integration
- Designed schematics and 3D models for pole sensors
- Implemented low-power periodic reading logic

## Technologies Used
- ESP32 DevKitC
- Raspberry Pi 3
- Arduino IDE (ESP32 programming)
- Python (MQTT broker & data logger)
- MQTT protocol
- Adafruit sensors (LTR390, DHT22/11, GPS)
- 3D modeling (STL files)
- Flexible solar panel and LiPo battery


