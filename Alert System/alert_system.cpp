
#include "alert_system.h"
#include <Arduino.h>

#define BUZZER_PIN D3
#define ALERT_LED D4

void AlertSystem::initialize() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ALERT_LED, OUTPUT);
  Serial.println("Alert system initialized.");
}

void AlertSystem::triggerAlert(bool leak) {
  if (leak) {
    Serial.println("Activating alert signals.");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(ALERT_LED, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(ALERT_LED, LOW);
  }
}
