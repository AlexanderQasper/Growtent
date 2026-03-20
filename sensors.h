#ifndef SENSORS_H
#define SENSORS_H

void setupSensors();
void readSensors();

float getTemperature();
float getHumidity();
int getLightRaw();
int getLightPercent();

#endif