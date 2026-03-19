#include "control.h"

#include "sensors.h"
#include "actuators.h"

static const float TEMP_THRESHOLD = 30.0;

void setupControl() {
}

void updateControl() {
  float temp = getTemperature();

  if (temp > TEMP_THRESHOLD) {
    setRelay(true);   // ON
  } else {
    setRelay(false);  // OFF
  }
}