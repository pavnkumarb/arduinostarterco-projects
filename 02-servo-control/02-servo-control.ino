/*
 * Project 2: Servo Control
 * ArduinoStarterCo Starter Kit
 *
 * Demonstrates: Servo library, sweeping a servo motor, Serial input control
 *
 * Components:
 *   - Arduino Uno (USB-C compatible)
 *   - 1x Servo motor (SG90 or compatible)
 *   - Breadboard
 *   - Jumper wires
 *
 * Wiring:
 *   - Servo brown/black wire -> GND
 *   - Servo red wire -> 5V
 *   - Servo orange/yellow (signal) wire -> Pin 9
 *
 * Expected output:
 *   The servo sweeps back and forth from 0° to 180°.
 *   Send an angle (0-180) via Serial Monitor to jump to that position.
 *
 * License: MIT
 */

#include <Servo.h>

Servo myServo;

const int SERVO_PIN = 9;
int currentAngle = 0;
int sweepDirection = 1;  // 1 = increasing, -1 = decreasing

void setup() {
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);
  Serial.println("Project 2: Servo Control — ready!");
  Serial.println("Type an angle (0-180) and press Enter to position the servo.");
  myServo.write(0);
  delay(500);
}

void loop() {
  // Check for Serial input to manually position servo
  if (Serial.available() > 0) {
    int targetAngle = Serial.parseInt();
    if (targetAngle >= 0 && targetAngle <= 180) {
      myServo.write(targetAngle);
      currentAngle = targetAngle;
      Serial.print("Moved to: ");
      Serial.print(targetAngle);
      Serial.println("°");
    } else {
      Serial.println("Invalid angle. Enter a value between 0 and 180.");
    }
    // Flush remaining input
    while (Serial.available()) Serial.read();
    return;
  }

  // Auto-sweep
  myServo.write(currentAngle);
  delay(20);

  currentAngle += sweepDirection;
  if (currentAngle >= 180) sweepDirection = -1;
  if (currentAngle <= 0)   sweepDirection = 1;
}
