#include "actuators.h"

#include <Arduino.h>

static const uint8_t RELAY_PIN = 7;
static bool relayState = false;   // логическое состояние
static bool relayDirty = true;    // нужно ли применить состояние к пину

void setupActuators() {
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW); // OFF
  relayState = false;
  relayDirty = false;
}

void applyActuators() {
  if (!relayDirty) {
    return;
  }

  if (relayState) {
    digitalWrite(RELAY_PIN, HIGH);  // ON
  } else {
    digitalWrite(RELAY_PIN, LOW);   // OFF
  }

  relayDirty = false;
}

void setRelay(bool on) {
  if (relayState != on) {
    relayState = on;
    relayDirty = true;
  }
}

bool isRelayOn() {
  return relayState;
}