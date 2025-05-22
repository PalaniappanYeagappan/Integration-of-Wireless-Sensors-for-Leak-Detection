
#include "network_manager.h"
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;
const char* ssid = "YourSSID";
const char* password = "YourPassword";
unsigned long channelID = 1234567;
const char* apiKey = "YOUR_API_KEY";

void NetworkManager::connect() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi.");
  ThingSpeak.begin(client);
}

void NetworkManager::sendData(float* data, int count, bool leakDetected) {
  for (int i = 0; i < count; i++) {
    ThingSpeak.setField(i + 1, data[i]);
  }
  ThingSpeak.setField(8, leakDetected ? 1 : 0);
  int response = ThingSpeak.writeFields(channelID, apiKey);
  if (response == 200) {
    Serial.println("Data successfully sent to ThingSpeak.");
  } else {
    Serial.print("Failed to send data. HTTP error code: ");
    Serial.println(response);
  }
}
