/*
 * Project 3: LCD Display
 * ArduinoStarterCo Starter Kit
 *
 * Demonstrates: LiquidCrystal library, displaying text and numbers on a 16x2 LCD
 *
 * Components:
 *   - Arduino Uno (USB-C compatible)
 *   - 1x 16x2 LCD display (HD44780 compatible)
 *   - 1x 10k potentiometer (contrast adjustment)
 *   - Breadboard
 *   - Jumper wires
 *
 * Wiring (4-bit mode):
 *   LCD Pin 1  (VSS)  -> GND
 *   LCD Pin 2  (VDD)  -> 5V
 *   LCD Pin 3  (VO)   -> Potentiometer wiper (center pin)
 *   LCD Pin 4  (RS)   -> Pin 12
 *   LCD Pin 5  (RW)   -> GND
 *   LCD Pin 6  (EN)   -> Pin 11
 *   LCD Pin 11 (D4)   -> Pin 5
 *   LCD Pin 12 (D5)   -> Pin 4
 *   LCD Pin 13 (D6)   -> Pin 3
 *   LCD Pin 14 (D7)   -> Pin 2
 *   LCD Pin 15 (A/LED+)-> 5V (via 220-ohm resistor)
 *   LCD Pin 16 (K/LED-)-> GND
 *   Potentiometer: outer pins to 5V and GND
 *
 * Expected output:
 *   Line 1: "ArduinoStarterCo"
 *   Line 2: Scrolling uptime counter in seconds
 *
 * License: MIT
 */

#include <LiquidCrystal.h>

// Initialize the library with the pin numbers (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long lastUpdate = 0;
int uptimeSeconds = 0;

void setup() {
  lcd.begin(16, 2);  // 16 columns, 2 rows

  // Display welcome message
  lcd.setCursor(0, 0);
  lcd.print("ArduinoStarterCo");
  lcd.setCursor(0, 1);
  lcd.print("Kit Project 3!");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Uptime (sec):");

  Serial.begin(9600);
  Serial.println("Project 3: LCD Display — ready!");
}

void loop() {
  // Update display every second
  if (millis() - lastUpdate >= 1000) {
    lastUpdate = millis();
    uptimeSeconds++;

    lcd.setCursor(0, 1);
    // Pad with spaces to clear previous number
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(uptimeSeconds);
    lcd.print(" sec");

    Serial.print("Uptime: ");
    Serial.print(uptimeSeconds);
    Serial.println(" sec");
  }
}
