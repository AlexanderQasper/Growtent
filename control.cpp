#include "control.h"

#include "sensors.h"
#include "actuators.h"

// Пороги
static const float TEMP_ON = 30.0;
static const float TEMP_OFF = 28.0;

void setupControl() {
}

void updateControl() {
  float temp = getTemperature();

  // если сейчас ВЫКЛЮЧЕНО → проверяем включение
  if (!isRelayOn() && temp > TEMP_ON) {
    setRelay(true);
  }

  // если сейчас ВКЛЮЧЕНО → проверяем выключение
  else if (isRelayOn() && temp < TEMP_OFF) {
    setRelay(false);
  }
}