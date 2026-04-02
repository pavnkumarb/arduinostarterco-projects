# Project 3: LCD Display

**Difficulty:** Intermediate | **Time:** ~20 minutes

## What You'll Learn

- How to wire and initialize a 16x2 LCD in 4-bit mode
- How to use the `LiquidCrystal` library (`lcd.print()`, `lcd.setCursor()`, `lcd.clear()`)
- How to use `millis()` for non-blocking timing

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno (USB-C) | 1 |
| 16x2 LCD display (HD44780) | 1 |
| 10k potentiometer | 1 |
| 220-ohm resistor | 1 |
| Breadboard | 1 |
| Jumper wires | ~12 |

## Wiring Diagram

```
LCD Pin  1 (VSS)   -> GND
LCD Pin  2 (VDD)   -> 5V
LCD Pin  3 (VO)    -> Potentiometer wiper (center pin)
LCD Pin  4 (RS)    -> Arduino Pin 12
LCD Pin  5 (RW)    -> GND
LCD Pin  6 (EN)    -> Arduino Pin 11
LCD Pin 11 (D4)    -> Arduino Pin 5
LCD Pin 12 (D5)    -> Arduino Pin 4
LCD Pin 13 (D6)    -> Arduino Pin 3
LCD Pin 14 (D7)    -> Arduino Pin 2
LCD Pin 15 (A/LED+)-> 5V (through 220-ohm resistor)
LCD Pin 16 (K/LED-)-> GND

Potentiometer: Left pin -> GND, Right pin -> 5V, Center -> LCD Pin 3
```

**Tip:** The LCD pins are numbered 1–16 from left to right when the display is facing you.

## Upload & Run

1. Open `03-lcd-display.ino` in the Arduino IDE.
2. Select **Tools > Board > Arduino Uno** and the correct Port.
3. Click **Upload**.
4. Adjust the potentiometer until text appears clearly on the LCD.

## Expected Output

- **On startup:** "ArduinoStarterCo" on line 1, "Kit Project 3!" on line 2 for 2 seconds.
- **Then:** "Uptime (sec):" on line 1, incrementing second counter on line 2.

## Troubleshooting

| Problem | Solution |
|---------|----------|
| No text visible | Adjust the potentiometer slowly — contrast may be set too high or too low |
| Blocks/squares appear | LCD initialized but text not displaying — check RS and EN pin wiring |
| Partial text / garbled | Check D4–D7 data pin connections |
| Backlight off | Check 220-ohm resistor connection to LCD Pin 15 |

## Challenge Extensions

- Display a custom welcome message with your name.
- Use `lcd.createChar()` to define a custom character (e.g., a heart or smiley).
- Read a potentiometer value on A0 and display it live on the LCD.
