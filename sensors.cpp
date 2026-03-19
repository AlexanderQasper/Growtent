#include "sensors.h"

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

static const uint8_t LIGHT_PIN = A0;
static const uint8_t BME_ADDRESS = 0x76;

static Adafruit_BME280 bme;

static float airTemp = 0.0f;
static float airHum = 0.0f;
static float airPress = 0.0f;
static int lightRaw = 0;
static int lightPercent = 0;

void setupSensors() {
  if (!bme.begin(BME_ADDRESS)) {
    Serial.println("ERROR: BME280 not found");
    while (1) {
      delay(100);
    }
  }
}

void readSensors() {
  airTemp = bme.readTemperature();
  airHum = bme.readHumidity();
  airPress = bme.readPressure() / 100.0f;

  lightRaw = analogRead(LIGHT_PIN);

  // Темно: ~500-600
  // Свет: ~90-150
  lightPercent = map(lightRaw, 600, 100, 0, 100);
  lightPercent = constrain(lightPercent, 0, 100);
}

float getTemperature() {
  return airTemp;
}

float getHumidity() {
  return airHum;
}

float getPressure() {
  return airPress;
}

int getLightRaw() {
  return lightRaw;
}

int getLightPercent() {
  return lightPercent;
}