
#include "sensor_node.h"
#include "leak_analyzer.h"
#include "network_manager.h"
#include "storage_manager.h"
#include "alert_system.h"

#define SENSOR_COUNT 4
#define LEAK_THRESHOLD 6.5
#define READ_INTERVAL 5000

SensorNode sensorNode(SENSOR_COUNT);
LeakAnalyzer analyzer(LEAK_THRESHOLD);
NetworkManager netManager;
StorageManager logger;
AlertSystem alerter;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("System initializing...");

  sensorNode.initialize();
  logger.initialize();
  netManager.connect();
  alerter.initialize();

  Serial.println("Calibrating baseline pressures...");
  analyzer.calibrate(sensorNode.readAll());

  Serial.println("Setup complete. Starting main loop...");
}

void loop() {
  Serial.println("Reading current pressure values...");
  float* currentReadings = sensorNode.readAll();

  Serial.print("Analyzing for leak: ");
  bool leakDetected = analyzer.detect(currentReadings);
  Serial.println(leakDetected ? "LEAK DETECTED!" : "No leak detected.");

  logger.logData(currentReadings, SENSOR_COUNT, leakDetected);
  netManager.sendData(currentReadings, SENSOR_COUNT, leakDetected);
  alerter.triggerAlert(leakDetected);

  Serial.println("Cycle complete. Sleeping...");
  delay(READ_INTERVAL);
}
