/*
 * Project 5: Complete Circuit
 * ArduinoStarterCo Starter Kit
 *
 * Demonstrates: Integrating multiple components — LCD display, servo motor,
 *               temperature sensor, LDR light sensor, and LED into one sketch.
 *
 * This capstone project ties together everything from Projects 1–4.
 * The LCD shows live temperature and light readings.
 * The servo angle reflects the current light level (0° = dark, 180° = bright).
 * The LED turns on when temperature exceeds a threshold.
 *
 * Components:
 *   - Arduino Uno (USB-C compatible)
 *   - 1x 16x2 LCD display (HD44780)
 *   - 1x Servo motor (SG90)
 *   - 1x TMP36 temperature sensor
 *   - 1x LDR photoresistor
 *   - 1x 10k resistor (LDR voltage divider)
 *   - 1x LED
 *   - 1x 220-ohm resistor (LED current limiting)
 *   - 1x 10k potentiometer (LCD contrast)
 *   - Breadboard
 *   - Jumper wires
 *
 * Wiring:
 *   LCD: same as Project 3 (RS=12, EN=11, D4=5, D5=4, D6=3, D7=2)
 *   Servo signal -> Pin 9
 *   TMP36 -> A0 (same as Project 4)
 *   LDR voltage divider -> A1 (same as Project 4)
 *   LED -> Pin 13 (with 220-ohm resistor, same as Project 1)
 *
 * Expected output:
 *   LCD Line 1: Temperature reading
 *   LCD Line 2: Light level + servo position
 *   LED turns on when temp > TEMP_THRESHOLD_C
 *
 * License: MIT
 */

#include <LiquidCrystal.h>
#include <Servo.h>

// --- Pin definitions ---
const int TEMP_PIN        = A0;
const int LIGHT_PIN       = A1;
const int SERVO_PIN       = 9;
const int LED_PIN         = 13;
const float TEMP_THRESHOLD_C = 28.0;  // LED activates above this temperature

// --- Library instances ---
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myServo;

// --- Timing ---
unsigned long lastUpdate = 0;
const unsigned long UPDATE_INTERVAL = 500;  // ms

void setup() {
  pinMode(LED_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);
  lcd.begin(16, 2);

  Serial.begin(9600);
  Serial.println("Project 5: Complete Circuit — ready!");

  lcd.setCursor(0, 0);
  lcd.print("ArduinoStarterCo");
  lcd.setCursor(0, 1);
  lcd.print("  Loading...    ");
  delay(1500);
  lcd.clear();
}

void loop() {
  if (millis() - lastUpdate < UPDATE_INTERVAL) return;
  lastUpdate = millis();

  // --- Read sensors ---
  int rawTemp  = analogRead(TEMP_PIN);
  int rawLight = analogRead(LIGHT_PIN);

  float voltage_mV = rawTemp * (5000.0 / 1024.0);
  float tempC      = (voltage_mV - 500.0) / 10.0;
  int   lightPct   = map(rawLight, 0, 1023, 0, 100);
  int   servoAngle = map(lightPct, 0, 100, 0, 180);

  // --- Update servo ---
  myServo.write(servoAngle);

  // --- Update LED ---
  digitalWrite(LED_PIN, tempC > TEMP_THRESHOLD_C ? HIGH : LOW);

  // --- Update LCD ---
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print((char)223);  // degree symbol
  lcd.print("C   ");     // trailing spaces clear old chars

  lcd.setCursor(0, 1);
  lcd.print("Light:");
  lcd.print(lightPct);
  lcd.print("% Srv:");
  lcd.print(servoAngle);
  lcd.print((char)223);
  lcd.print("  ");

  // --- Serial output ---
  Serial.print("Temp: ");
  Serial.print(tempC, 1);
  Serial.print("C | Light: ");
  Serial.print(lightPct);
  Serial.print("% | Servo: ");
  Serial.print(servoAngle);
  Serial.print("deg | LED: ");
  Serial.println(tempC > TEMP_THRESHOLD_C ? "ON (warm!)" : "off");
}
