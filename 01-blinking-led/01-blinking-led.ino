/*
 * Project 1: Blinking LED
 * ArduinoStarterCo Starter Kit
 *
 * Demonstrates: Digital output, pinMode, digitalWrite, delay
 *
 * Components:
 *   - Arduino Uno (USB-C compatible)
 *   - 1x LED (any color)
 *   - 1x 220-ohm resistor
 *   - Breadboard
 *   - Jumper wires
 *
 * Wiring:
 *   - LED anode (long leg) -> 220-ohm resistor -> Pin 13
 *   - LED cathode (short leg) -> GND
 *
 * Expected output:
 *   The LED blinks on and off once per second.
 *
 * License: MIT
 */

const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Project 1: Blinking LED — ready!");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  Serial.println("LED ON");
  delay(1000);                  // Wait 1 second

  digitalWrite(LED_PIN, LOW);   // Turn LED off
  Serial.println("LED OFF");
  delay(1000);                  // Wait 1 second
}
