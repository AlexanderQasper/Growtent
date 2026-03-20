#include "reporting.h"

#include <Arduino.h>
#include "sensors.h"
#include "actuators.h"

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

  Serial.print("TEMP=");
  Serial.print(getTemperature());
  Serial.print(";HUM=");
  Serial.print(getHumidity());
  Serial.print(";LIGHT=");
  Serial.print(getLightPercent());
  Serial.print(";RELAY=");
  Serial.println(isRelayOn() ? 1 : 0);
}