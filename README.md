# 🚧 Automatic Barrier System with Ultrasonic Sensor, Servo, LED, and Buzzer

This Arduino project implements an **automatic barrier gate system** using an ultrasonic sensor to detect objects, a servo motor to control a physical gate, and visual/audio feedback with LEDs and a buzzer. Ideal for prototype smart parking gates, access control systems, or object detection projects.

---

## 📦 Features

- **Ultrasonic Sensor** to detect objects within a set distance.
- **Servo Motor** opens the gate when an object is near and closes it after a delay.
- **Red and Blue LEDs** indicate gate status (closed/open).
- **Buzzer** beeps at regular intervals when the gate is open.

---

## 🔧 Components Required

| Component                    | Quantity |
|-----------------------------|----------|
| Arduino UNO                 | 1        |
| Ultrasonic Sensor (HC-SR04) | 1        |
| Servo Motor                 | 1        |
| Red LED                     | 1        |
| Blue LED                    | 1        |
| Buzzer                      | 1        |
| Resistors (220Ω)            | 2        |
| Jumper Wires                | several  |
| Breadboard                  | 1        |

---

## 🔌 Pin Configuration

| Arduino Pin | Component              |
|-------------|------------------------|
| D2          | HC-SR04 Trigger        |
| D3          | HC-SR04 Echo           |
| D4          | Red LED (Anode)        |
| D8          | Red LED (Cathode)      |
| D5          | Blue LED (Anode)       |
| D7          | Blue LED (Cathode)     |
| D6          | Servo Signal           |
| D12         | Buzzer                 |

---

## ⚙️ How It Works

1. **Object Detected:**
   - If an object is detected within 10 cm:
     - Servo rotates to open gate.
     - Red LED turns off, blue LED turns on.
     - Buzzer beeps every 500 ms.

2. **Object Leaves:**
   - After 5 seconds of no detection:
     - Servo closes gate.
     - Blue LED turns off, red LED turns on.
     - Buzzer stops.

---

## 🧠 Code Highlights

- `getDistance()` uses the HC-SR04 sensor to calculate distance.
- `loop()` handles the detection logic and gate control.
- `buzzerState` toggles to create the beep effect.
- LEDs and buzzer reflect the system state.

---

## 🛠 Setup Instructions

1. Connect all components as shown in the pin configuration table.
2. Upload the code to your Arduino using the Arduino IDE.
3. Power the Arduino board.
4. Test the system by placing an object near the ultrasonic sensor.


---

## 📄 License

This project is open-source and intended for educational and personal use.
Feel free to modify and expand upon it!

---
