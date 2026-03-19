#include "reporting.h"
#include "actuators.h"

#include <Arduino.h>
#include "sensors.h"

static unsigned long lastReportMs = 0;
static const unsigned long REPORT_INTERVAL_MS = 2000;

void setupReporting() {
  Serial.begin(115200);
  delay(300);
}

void reportStartup() {
  Serial.println("System start");
}

void reportState() {
  unsigned long now = millis();

  if (now - lastReportMs < REPORT_INTERVAL_MS) {
    return;
  }

  lastReportMs = now;

  Serial.print("Temp: ");
  Serial.print(getTemperature());
  Serial.print(" C | Hum: ");
  Serial.print(getHumidity());
  Serial.print(" % | Press: ");
  Serial.print(getPressure());
  Serial.print(" hPa | LightRaw: ");
  Serial.print(getLightRaw());
  Serial.print(" | Light: ");
  Serial.print(getLightPercent());
  Serial.print(" % | Relay: ");
  Serial.println(isRelayOn() ? "ON" : "OFF");
}