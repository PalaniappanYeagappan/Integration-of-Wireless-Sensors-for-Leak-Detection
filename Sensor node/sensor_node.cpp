
#include "sensor_node.h"
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmpSensors[4];

SensorNode::SensorNode(int count) {
  this->count = count;
  pressures = new float[count];
}

void SensorNode::initialize() {
  Serial.println("Initializing pressure sensors...");
  for (int i = 0; i < count; i++) {
    if (!bmpSensors[i].begin()) {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(" failed to initialize.");
    } else {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(" initialized successfully.");
    }
  }
}

float* SensorNode::readAll() {
  for (int i = 0; i < count; i++) {
    pressures[i] = bmpSensors[i].readPressure() / 100.0;
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(pressures[i]);
    Serial.println(" hPa");
  }
  return pressures;
}
