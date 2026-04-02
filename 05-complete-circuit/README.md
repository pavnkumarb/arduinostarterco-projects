# Project 5: Complete Circuit

**Difficulty:** Advanced | **Time:** ~45 minutes

## What You'll Learn

This is the capstone project. It combines everything from Projects 1–4:

- **Project 1** — LED output based on a condition
- **Project 2** — Servo motor driven by a sensor value
- **Project 3** — Live data displayed on LCD
- **Project 4** — Temperature and light sensor readings

You'll build a real-time environment monitor that displays temperature on the LCD, moves a servo proportional to the light level, and activates an LED when it gets too warm.

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno (USB-C) | 1 |
| 16x2 LCD display (HD44780) | 1 |
| Servo motor (SG90) | 1 |
| TMP36 temperature sensor | 1 |
| LDR / photoresistor | 1 |
| LED (any color) | 1 |
| 10k potentiometer (LCD contrast) | 1 |
| 10k resistor (LDR divider) | 1 |
| 220-ohm resistor (LED) | 1 |
| Breadboard | 1 |
| Jumper wires | ~20 |

## Wiring Diagram

Combine the wiring from Projects 1–4:

### LCD (same as Project 3)
```
LCD Pin  1 (VSS)   -> GND
LCD Pin  2 (VDD)   -> 5V
LCD Pin  3 (VO)    -> Potentiometer wiper
LCD Pin  4 (RS)    -> Arduino Pin 12
LCD Pin  5 (RW)    -> GND
LCD Pin  6 (EN)    -> Arduino Pin 11
LCD Pin 11 (D4)    -> Arduino Pin 5
LCD Pin 12 (D5)    -> Arduino Pin 4
LCD Pin 13 (D6)    -> Arduino Pin 3
LCD Pin 14 (D7)    -> Arduino Pin 2
LCD Pin 15 (A/LED+)-> 5V via 220-ohm resistor
LCD Pin 16 (K/LED-)-> GND
```

### Servo (same as Project 2)
```
Servo GND (brown/black) -> GND
Servo VCC (red)         -> 5V
Servo signal (orange)   -> Arduino Pin 9
```

### TMP36 (same as Project 4)
```
TMP36 Pin 1 (left, flat side)   -> 5V
TMP36 Pin 2 (center, flat side) -> A0
TMP36 Pin 3 (right, flat side)  -> GND
```

### LDR (same as Project 4)
```
5V ---[LDR]--- A1 ---[10kΩ]--- GND
```

### LED (same as Project 1)
```
Arduino Pin 13 ---[220Ω]--- LED(+) --- LED(-) --- GND
```

## Upload & Run

1. Open `05-complete-circuit.ino` in the Arduino IDE.
2. Select **Tools > Board > Arduino Uno** and the correct Port.
3. Click **Upload**.
4. Adjust the LCD contrast potentiometer until text is visible.

## Expected Output

**LCD display:**
```
Line 1: Temp: 23.5°C
Line 2: Light:65% Srv:117°
```

**LED behavior:** Turns on when temperature exceeds 28°C (adjustable via `TEMP_THRESHOLD_C` constant).

**Servo behavior:** Points to approximately 0° in darkness and 180° in bright light.

**Serial Monitor (baud: 9600):**
```
Temp: 23.5C | Light: 65% | Servo: 117deg | LED: off
```

## Troubleshooting

| Problem | Solution |
|---------|----------|
| LCD blank | Adjust contrast potentiometer; check pin 4 (RS) and 6 (EN) wiring |
| Servo not moving | Confirm Pin 9 signal wire; check 5V power |
| No temperature reading | Check TMP36 orientation (flat side facing you: 5V, A0, GND left to right) |
| LED always on | Breathe warm air near TMP36; or lower `TEMP_THRESHOLD_C` in code |
| Arduino resets | Servo drawing too much current — use an external 5V supply for the servo |

## Customization Ideas

- Change `TEMP_THRESHOLD_C` to any temperature that makes sense for your environment.
- Swap the LED for a buzzer to make an audible temperature alarm.
- Add a button to toggle between Celsius and Fahrenheit on the LCD.
- Log data to a computer using Serial and graph it with the Arduino Serial Plotter.

## Congratulations!

You've completed all 5 projects in the ArduinoStarterCo Starter Kit. You now know how to:
- Control digital and analog outputs
- Read analog sensors
- Drive servo motors
- Display information on an LCD
- Combine multiple components in a single program

**What's next?** Visit [arduinostarterco.com](https://arduinostarterco.com) for more project ideas and kits!
