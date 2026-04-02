# Project 4: Sensor Readings

**Difficulty:** Intermediate | **Time:** ~20 minutes

## What You'll Learn

- How to read analog sensors with `analogRead()`
- How to convert raw ADC values to real-world units (voltage → °C)
- How to use `map()` for range scaling
- How to build a voltage divider for a resistive sensor (LDR)

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno (USB-C) | 1 |
| TMP36 temperature sensor | 1 |
| LDR / photoresistor | 1 |
| 10k resistor | 1 |
| Breadboard | 1 |
| Jumper wires | ~6 |

## Wiring Diagram

### TMP36 Temperature Sensor

Hold the TMP36 with the flat side facing you. Pins are numbered left to right:

```
TMP36 Pin 1 (left)   -> 5V
TMP36 Pin 2 (center) -> A0
TMP36 Pin 3 (right)  -> GND
```

**Warning:** Inserting the TMP36 backwards will cause it to heat up rapidly. Double-check orientation before powering on.

### LDR Light Sensor (Voltage Divider)

```
5V ---[LDR]--- A1 ---[10kΩ]--- GND
```

| Connection | Arduino Pin |
|------------|-------------|
| LDR (one end) | 5V |
| LDR (other end) + resistor top | A1 |
| Resistor bottom | GND |

## Upload & Run

1. Open `04-sensor-readings.ino` in the Arduino IDE.
2. Select **Tools > Board > Arduino Uno** and the correct Port.
3. Click **Upload**.
4. Open **Serial Monitor** (baud: 9600) to see live sensor data.

## Expected Output

```
Project 4: Sensor Readings — ready!
Reading temperature and light every second...
------------------------------------------
Temp: 23.4 C  /  74.1 F  |  Light: 68%
Temp: 23.5 C  /  74.3 F  |  Light: 72%
```

Cover the LDR with your hand to see the light percentage drop. Breathe warm air near the TMP36 to see temperature rise slightly.

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Temperature reads ~-50°C | TMP36 is inserted backwards — remove power immediately and flip it |
| Temperature reads ~150°C | Same as above — check orientation |
| Light always 0% or 100% | Check the 10k voltage divider resistor connection |
| Readings are noisy/jumping | Add a small capacitor (0.1µF) between A0 and GND for filtering |

## Challenge Extensions

- Add an LED that turns on when light drops below 30% (simulating a night light).
- Log readings over time via the Serial Plotter (**Tools > Serial Plotter**).
- Calculate the average of 10 readings to reduce noise.
