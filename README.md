🌱 Growtent

Modular control system for an indoor grow tent based on Arduino and Raspberry Pi.

⸻

📌 Overview

Growtent is a hardware-software project designed to automate environmental control inside a grow tent.

The system collects sensor data (temperature, humidity, light) and controls actuators (relays, fans, lighting) using a modular architecture.

The goal is to build a reliable, extensible and maintainable system that can later be integrated with Raspberry Pi for monitoring, logging and remote control.

⸻

⚙️ Current Features (Stage 1)
	•	🌡️ Air temperature, humidity and pressure monitoring (BME280)
	•	💡 Light level measurement (analog sensor with normalization)
	•	🔌 Relay control (active HIGH module)
	•	🧠 Basic control logic (temperature-based switching)
	•	🧩 Modular architecture:
	•	sensors
	•	control
	•	actuators
	•	reporting

⸻

🧠 System Architecture

            +---------------------+
            |     Sensors         |
            |---------------------|
            | BME280 (I2C)        |
            | Light sensor (A0)   |
            +----------+----------+
                       |
                       v
            +---------------------+
            |      Control        |
            |---------------------|
            | Decision logic      |
            | (e.g. temperature)  |
            +----------+----------+
                       |
                       v
            +---------------------+
            |     Actuators       |
            |---------------------|
            | Relay module        |
            | (light / fan)       |
            +----------+----------+
                       |
                       v
            +---------------------+
            |     Reporting       |
            |---------------------|
            | Serial output       |
            +---------------------+


⸻

🔌 Hardware

Microcontrollers
	•	Arduino Uno (current prototype)
	•	Arduino Mega (planned for expansion)
	•	Raspberry Pi 5 (future integration)

Sensors
	•	BME280 (temperature, humidity, pressure via I2C)
	•	Light sensor (analog, normalized to %)

Actuators
	•	4-channel relay module (active HIGH)

⸻

🧱 Software Structure

Growtent/
├── Growtent.ino       # main entry point
├── sensors.cpp/h      # sensor handling
├── control.cpp/h      # decision logic
├── actuators.cpp/h    # relay control
├── reporting.cpp/h    # serial/debug output
├── .gitignore
└── README.md

Design principles
	•	Separation of concerns (each module has one responsibility)
	•	No hardware logic inside main loop
	•	Debug output isolated from core logic
	•	Easy extensibility

⸻

🔄 Control Logic (current)

Simple rule-based control:

if temperature > 30°C → relay ON
else → relay OFF

Note: This will be improved with hysteresis in the next stage.

⸻

🚀 Next Steps
	•	Add hysteresis to prevent relay oscillation
	•	Implement automatic watering system
	•	Add tank level monitoring
	•	Integrate Raspberry Pi:
	•	data logging
	•	web interface
	•	remote control
	•	Add multi-zone support (second tent)

⸻

🧪 Development Approach
	•	Build and test modules independently
	•	Prototype on a hardware stand
	•	Validate scenarios before deployment
	•	Gradually increase system complexity

⸻

📦 Requirements

Arduino libraries:
	•	Adafruit BME280
	•	Adafruit Unified Sensor

⸻

Arduino Uno

BME280 (I2C)
-----------------
VCC  -> 3.3V
GND  -> GND
SDA  -> A4
SCL  -> A5

Light sensor (RobotDyn)
-----------------
VCC  -> 5V
GND  -> GND
AOut -> A0
DOut -> (not used)

Relay module (4ch, используем 1 канал)
-----------------
VCC  -> 5V
GND  -> GND
IN1  -> D7
SGND -> (already bridged to GND on module)


## 🔌 Wiring (Pin Connections)

### Arduino Uno

#### BME280 (I2C)
VCC  -> 3.3V  
GND  -> GND  
SDA  -> A4  
SCL  -> A5  

#### Light Sensor (RobotDyn)
VCC  -> 5V  
GND  -> GND  
AOut -> A0  
DOut -> (not used)  

#### Relay Module (4-channel, using IN1)
VCC  -> 5V  
GND  -> GND  
IN1  -> D7  
SGND -> (bridged to GND on module)  

---

## 🧠 Logic Levels

Relay behavior (this module):
- HIGH → ON (relay active)
- LOW  → OFF

---

## ⚠️ Notes

### Power
- BME280: use 3.3V (recommended)
- Light sensor + relay: use 5V

### Ground
All components must share common ground:

Arduino GND ↔ BME GND ↔ Light GND ↔ Relay GND

### Light Sensor Behavior
- Dark → higher values (~500–600)
- Light → lower values (~90–150)
- Values are normalized in code to 0–100%

---

## 🧭 Simplified Diagram
    +-------------------+
    |    Arduino Uno    |
    |-------------------|
    | A4 (SDA) ---------|---- BME280
    | A5 (SCL) ---------|
    | A0 ---------------|---- Light sensor (AOut)
    | D7 ---------------|---- Relay IN1
    | 5V ---------------|---- VCC (Light, Relay)
    | 3.3V -------------|---- VCC (BME280)
    | GND --------------|---- GND (all)
    +-------------------+

