#include "sensors.h"

#include <Arduino.h>
#include <SHT1x.h>

// -------------------- Pins --------------------
static const uint8_t SHT_DATA_PIN = 3;
static const uint8_t SHT_CLOCK_PIN = 2;
static const uint8_t LIGHT_PIN = A0;

// -------------------- Sensor objects --------------------
static SHT1x sht(SHT_DATA_PIN, SHT_CLOCK_PIN);

// -------------------- Stored values --------------------
static float airTemp = 0.0f;
static float airHum = 0.0f;
static int lightRaw = 0;
static int lightPercent = 0;

void setupSensors() {
  // Для SHT1x отдельная инициализация не нужна
}

void readSensors() {
  airTemp = sht.readTemperatureC();
  airHum = sht.readHumidity();

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

int getLightRaw() {
  return lightRaw;
}

int getLightPercent() {
  return lightPercent;
}