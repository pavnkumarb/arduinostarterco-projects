# Project 1: Blinking LED

**Difficulty:** Beginner | **Time:** ~10 minutes

## What You'll Learn

- How to configure a digital output pin with `pinMode()`
- How to turn a pin HIGH and LOW with `digitalWrite()`
- How to pause execution with `delay()`

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno (USB-C) | 1 |
| LED (any color) | 1 |
| 220-ohm resistor | 1 |
| Breadboard | 1 |
| Jumper wires | 2 |

## Wiring Diagram

```
Arduino Pin 13 ---[220Ω]--- LED(+) --- LED(-) --- GND
```

| Arduino Pin | Component |
|-------------|-----------|
| Pin 13 | 220-ohm resistor (one end) |
| GND | LED cathode (short leg) |

**Full wiring steps:**
1. Insert the LED into the breadboard. Note which leg is longer (anode/+).
2. Connect the 220-ohm resistor between Pin 13 and the LED's anode (long leg).
3. Connect a jumper wire from the LED's cathode (short leg) to GND on the Arduino.

## Upload & Run

1. Open `01-blinking-led.ino` in the Arduino IDE.
2. Select your board: **Tools > Board > Arduino Uno**.
3. Select the correct COM/Serial port under **Tools > Port**.
4. Click **Upload** (right-arrow button).
5. The LED should start blinking once per second.

## Expected Output

The LED on the breadboard blinks **ON for 1 second**, then **OFF for 1 second**, repeatedly.

Open the Serial Monitor (**Tools > Serial Monitor**, baud: 9600) to see status messages.

## Troubleshooting

| Problem | Solution |
|---------|----------|
| LED doesn't light up | Check that the resistor is connected to Pin 13, not 5V or GND |
| LED stays on / stays off | Verify LED polarity (long leg = anode = to resistor) |
| Upload error | Confirm correct board and port selected in Tools menu |
| LED very dim | Ensure you're using 220-ohm resistor (red-red-brown bands) |

## Challenge Extensions

- Change the blink speed by modifying the `delay()` values.
- Try making the LED blink in an SOS pattern (... --- ...).
- Add a second LED on Pin 12 and alternate the blinks.
