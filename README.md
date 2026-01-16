# Smart Plant Care System – Arduino-Based Embedded Project

## 📌 Project Description
This project consists of designing and implementing an automated plant care
system based on an Arduino platform. The system monitors environmental and
soil conditions in real time and reacts automatically to maintain suitable
conditions for plant growth.

The project was carried out as part of a university mechatronics engineering
assignment and focuses on embedded systems, sensor integration, simulation,
and prototyping.

---

## 🎯 Project Objectives
The main objective is to automate basic plant maintenance tasks by monitoring:
- Soil moisture
- Ambient temperature
- Air humidity
- Light intensity
- Water level in the reservoir

Based on sensor readings, the system:
- Activates a water pump when the soil is dry
- Turns on artificial lighting when light levels are low
- Provides visual and audible feedback to the user

---

## 🧠 System Overview
The system is composed of several interconnected subsystems, each responsible
for monitoring a specific parameter. All modules are integrated into a complete
embedded system controlled by an Arduino board.

---

## 🧰 Hardware Components
- Arduino UNO
- Soil moisture sensor
- Temperature and humidity sensor
- Light sensor (LDR)
- Water level sensor
- Water pump
- LEDs
- Buzzer
- DC motor
- Stepper motor
- LED Matrix 8x8 (MAX7219)
- LCD display
- Resistors, wires, breadboard

---

## 🔧 Subsystems Description

### 🌱 Soil Moisture Monitoring
- Measures soil humidity
- Activates LEDs and buzzer when soil is dry
- Triggers watering when conditions are met

### 🌡️ Temperature & Humidity Control
- Monitors ambient conditions
- Controls DC motor or stepper motor depending on thresholds
- Uses LEDs for status indication

### 🌞 Light Detection System
- Measures ambient light intensity using an LDR
- Displays information on an LED matrix
- Activates artificial lighting when illumination is insufficient

### 💧 Water Level Detection
- Monitors the water level in the reservoir
- Uses LED indication to alert when water is low
- Prevents pump activation if the reservoir is empty

---

## 🔗 System Integration
All subsystems are combined into a single automated plant care system.
The system demonstrates:
- Embedded system architecture
- Sensor data processing
- Decision-making logic
- Actuator control
- Hardware–software integration

---

## 🧪 Simulation & Tools
- **Proteus (ISIS)** was used to design electrical schematics and simulate
  the complete system, including sensors, actuators, and Arduino code.
- Simulation allowed validation of system behavior before physical realization.

---

## 🔧 Implementation
After simulation, the system was implemented using an Arduino Starter Kit.
The prototype validates the feasibility of the proposed solution and confirms
correct system behavior under real conditions.

---

## 📄 Documentation
- The complete technical report and the project presentation are available in the folder,
  along with the source code and Proteus simulation files.

---

## 👤 Authors
Project realized by:
- Nid Mansour Chaima  
- Mtahtah Wissal  
- Zoubai Douha  

Supervised by:
- Mr. Mohamed Chouiekh  

Université Abdelmalek Essaâdi  
École Nationale des Sciences Appliquées de Tétouan  
Academic Year: 2024 / 2025

---

## 🎓 Academic Context
This project was developed as part of a university assignment to practice
embedded systems design, simulation, and prototyping using Arduino.
