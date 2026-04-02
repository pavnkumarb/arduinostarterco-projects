# Project 2: Servo Control

**Difficulty:** Beginner | **Time:** ~15 minutes

## What You'll Learn

- How to use the built-in `Servo` library
- How to attach a servo and write angles with `servo.write()`
- How to read commands from the Serial Monitor

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno (USB-C) | 1 |
| Servo motor (SG90 or compatible) | 1 |
| Breadboard | 1 |
| Jumper wires | 3 |

## Wiring Diagram

```
Servo brown/black  -> GND
Servo red          -> 5V
Servo orange/yellow -> Pin 9
```

| Wire Color | Arduino Pin |
|------------|-------------|
| Brown / Black | GND |
| Red | 5V |
| Orange / Yellow (signal) | Pin 9 |

**Note:** Servo colors vary by brand. When in doubt: center wire = power (5V), dark wire = ground, remaining wire = signal.

## Upload & Run

1. Open `02-servo-control.ino` in the Arduino IDE.
2. Select **Tools > Board > Arduino Uno** and the correct Port.
3. Click **Upload**.
4. The servo will automatically sweep from 0° to 180° and back.

## Manual Control via Serial Monitor

1. Open Serial Monitor (**Tools > Serial Monitor**, baud: 9600).
2. Type any angle between `0` and `180` and press Enter.
3. The servo jumps to that position immediately.

## Expected Output

- Servo sweeps continuously back and forth across its full range.
- Serial Monitor displays the current angle when manually set.

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Servo twitches but doesn't move | Check 5V and GND connections |
| No movement | Confirm signal wire is on Pin 9 |
| Arduino resets when servo moves | Servo drawing too much current — power the servo from a separate 5V supply |
| Servo only moves partially | Mechanical obstruction or incorrect angle range for this servo model |

## Challenge Extensions

- Connect a potentiometer to A0 and use it to control the servo angle.
- Add a second servo and control both simultaneously.
- Program the servo to move to specific angles on a timed sequence.
