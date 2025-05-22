
#include "leak_analyzer.h"
#include <Arduino.h>

LeakAnalyzer::LeakAnalyzer(float threshold) {
  this->threshold = threshold;
  baselineReadings = new float[4];
}

void LeakAnalyzer::calibrate(float* baseline) {
  Serial.println("Setting baseline pressures:");
  for (int i = 0; i < 4; i++) {
    baselineReadings[i] = baseline[i];
    Serial.print("Baseline ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(baseline[i]);
  }
}

bool LeakAnalyzer::detect(float* readings) {
  for (int i = 0; i < 4; i++) {
    float diff = abs(readings[i] - baselineReadings[i]);
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(" delta: ");
    Serial.println(diff);
    if (diff > threshold) {
      Serial.println("Leak threshold exceeded.");
      return true;
    }
  }
  return false;
}
