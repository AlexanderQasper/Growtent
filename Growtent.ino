#include "sensors.h"
#include "reporting.h"
#include "actuators.h"
#include "control.h"

void setup() {
  setupReporting();
  setupSensors();
  setupActuators();
  setupControl();

  reportStartup();
}

void loop() {
  readSensors();
  updateControl();
  applyActuators();
  reportState();
}