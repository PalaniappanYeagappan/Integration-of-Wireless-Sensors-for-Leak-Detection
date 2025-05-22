# Integration-of-Wireless-Sensors-for-Leak-Detection

This project is based on the research published in our paper:
📄 **Integration of Wireless Sensors to Detect Fluid Leaks in Industries**  
🔗 [Springer Link](https://link.springer.com/chapter/10.1007/978-981-16-3728-5_46)

It was developed as part of my undergraduate capstone project over two semesters at **Department of ECE, Amrita School of Engineering, Amrita Vishwa Vidyapeetham, Coimbatore under the guidance of Prof. Ganesan**.

## 🧪 Research Background

The system aims to reduce fluid leakage losses in industries by deploying pressure sensors along pipelines. It monitors the pressure profile using Bernoulli’s principle and identifies discrepancies indicative of leaks. The approach integrates real-time data acquisition, wireless communication, and alert generation, offering a cost-effective solution to traditional leak detection mechanisms.

---

## 📦 Project Structure

```
AdvancedLeakDetectionSystem/
├── src/
│   ├── main.ino
│   ├── sensor_node.h / .cpp
│   ├── leak_analyzer.h / .cpp
│   ├── network_manager.h / .cpp
│   └── alert_system.h / .cpp
├── Leak_Detection_Thingspeak.m
└── README.md
```

## 🔧 Features

- Reads pressure from 4 sensors (BMP085)
- Detects leaks using threshold deviation from baseline
- Sends real-time data to ThingSpeak
- Triggers buzzer and LED alert on leak
- Debug output via serial monitor
- Modular and scalable architecture

## 📡 ThingSpeak Integration

**ThingSpeak Channel Fields**:
- Field 1–4: Pressure readings (in hPa)
- Field 8: Leak status (`1` = leak, `0` = normal)

**MATLAB Cloud Script**:
- Periodically reads ThingSpeak channel
- Compares with baseline values
- Sends alert emails via `sendEmail()` if leak detected

## 📁 Setup Instructions

1. Flash the `main.ino` project using PlatformIO or Arduino IDE.
2. Configure WiFi credentials and ThingSpeak keys in `network_manager.cpp`.
3. Connect 4 BMP085 sensors via I2C (shared lines, use mux if needed).
4. Connect a buzzer and LED to digital pins (D3, D4).
6. Upload the MATLAB script to [ThingSpeak > MATLAB Analysis](https://thingspeak.com/apps).

## ⚠️ Calibration Note

Initial baseline values are hardcoded. Use serial prints to read startup pressures and adjust baseline in:
- `leak_analyzer.cpp`
- `Leak_detection_Thingspeak.m`

## 📧 Email Alerts

Make sure to:
- Verify your ThingSpeak email
- Use `sendEmail()` inside the ThingSpeak environment only

## 🛠 Future Improvements

- LoRaWAN instead of WiFi for long-range deployment
- Adaptive learning for thresholds
- Integration with a dashboard (Node-RED, Grafana, Blynk)

---

Created with ❤️ at Amrita Vishwa Vidyapeetham as part of an industrial IoT capstone research project.
