# ArduinoStarterCo — Starter Kit Projects

Welcome! This repository contains all 5 tutorial projects included in the **ArduinoStarterCo Starter Kit**.

Each project folder contains a ready-to-upload Arduino sketch (`.ino`) and a detailed `README.md` with wiring diagrams, expected output, and troubleshooting tips.

---

## Projects

| # | Project | Concepts | Difficulty |
|---|---------|----------|------------|
| [01](./01-blinking-led/) | [Blinking LED](./01-blinking-led/README.md) | `digitalWrite`, `delay`, digital output | Beginner |
| [02](./02-servo-control/) | [Servo Control](./02-servo-control/README.md) | `Servo` library, motor control, Serial input | Beginner |
| [03](./03-lcd-display/) | [LCD Display](./03-lcd-display/README.md) | `LiquidCrystal` library, `millis()`, display output | Intermediate |
| [04](./04-sensor-readings/) | [Sensor Readings](./04-sensor-readings/README.md) | `analogRead`, temperature math, voltage divider | Intermediate |
| [05](./05-complete-circuit/) | [Complete Circuit](./05-complete-circuit/README.md) | Multi-component integration, capstone | Advanced |

---

## Getting Started

### What You Need

- Arduino Uno (USB-C compatible) — included in kit
- USB-C cable — included in kit
- All components listed in each project's README (included in kit)
- A computer with the [Arduino IDE](https://www.arduino.cc/en/software) installed (free download)

### Setup Steps

1. **Install the Arduino IDE** — Download from [arduino.cc/en/software](https://www.arduino.cc/en/software). Version 2.x recommended.
2. **Connect your Arduino** — Use the included USB-C cable to connect the Arduino to your computer.
3. **Select your board** — In the IDE: **Tools > Board > Arduino AVR Boards > Arduino Uno**.
4. **Select your port** — In the IDE: **Tools > Port** — choose the port that appeared when you plugged in the Arduino.
5. **Open a project** — Navigate to any project folder and open the `.ino` file.
6. **Upload** — Click the right-arrow (Upload) button. The code will compile and flash to your Arduino.

### Start with Project 1

Each project builds on the previous. We recommend going in order: start with **01-blinking-led** and work your way to the **05-complete-circuit** capstone.

---

## Component Reference

These components are used across the 5 projects:

| Component | Used In |
|-----------|---------|
| Arduino Uno (USB-C) | All projects |
| Breadboard | All projects |
| Jumper wires | All projects |
| LED | Projects 1, 5 |
| 220-ohm resistor | Projects 1, 3, 5 |
| Servo motor (SG90) | Projects 2, 5 |
| 16x2 LCD display | Projects 3, 5 |
| 10k potentiometer | Projects 3, 5 |
| TMP36 temperature sensor | Projects 4, 5 |
| LDR photoresistor | Projects 4, 5 |
| 10k resistor | Projects 4, 5 |

---

## QR Code URLs

The QR codes printed on your kit cards link directly to each project folder in this repository:

| QR Code | URL |
|---------|-----|
| Project 1 | `https://github.com/pavnkumarb/arduinostarterco-projects/tree/main/01-blinking-led` |
| Project 2 | `https://github.com/pavnkumarb/arduinostarterco-projects/tree/main/02-servo-control` |
| Project 3 | `https://github.com/pavnkumarb/arduinostarterco-projects/tree/main/03-lcd-display` |
| Project 4 | `https://github.com/pavnkumarb/arduinostarterco-projects/tree/main/04-sensor-readings` |
| Project 5 | `https://github.com/pavnkumarb/arduinostarterco-projects/tree/main/05-complete-circuit` |

These URLs are permanent and will not change. Safe to encode in QR codes for kit packaging.

---

## License

All code in this repository is released under the **MIT License**. See [LICENSE](./LICENSE) for details.

You are free to use, modify, and share this code for personal and commercial projects.

---

## Support

Having trouble? Check the **Troubleshooting** section in each project's README first.

For additional help:
- Visit [arduinostarterco.com](https://arduinostarterco.com)
- Join our community Discord
- Open an issue in this repository

Happy building!
