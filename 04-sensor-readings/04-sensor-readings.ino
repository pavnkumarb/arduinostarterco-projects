/*
 * Project 4: Sensor Readings
 * ArduinoStarterCo Starter Kit
 *
 * Demonstrates: Analog input, reading a temperature sensor (TMP36) and a
 *               light-dependent resistor (LDR/photoresistor), Serial output
 *
 * Components:
 *   - Arduino Uno (USB-C compatible)
 *   - 1x TMP36 temperature sensor
 *   - 1x LDR (photoresistor)
 *   - 1x 10k resistor (voltage divider for LDR)
 *   - Breadboard
 *   - Jumper wires
 *
 * Wiring:
 *   TMP36:
 *     - Pin 1 (flat side, left)   -> 5V
 *     - Pin 2 (flat side, center) -> A0
 *     - Pin 3 (flat side, right)  -> GND
 *
 *   LDR voltage divider:
 *     - One end of LDR -> 5V
 *     - Other end of LDR -> A1 AND one end of 10k resistor
 *     - Other end of 10k resistor -> GND
 *
 * Expected output:
 *   Serial Monitor prints temperature (°C and °F) and light level every second.
 *
 * License: MIT
 */

const int TEMP_PIN  = A0;
const int LIGHT_PIN = A1;

void setup() {
  Serial.begin(9600);
  Serial.println("Project 4: Sensor Readings — ready!");
  Serial.println("Reading temperature and light every second...");
  Serial.println("------------------------------------------");
}

void loop() {
  // --- Temperature reading (TMP36) ---
  int rawTemp = analogRead(TEMP_PIN);
  // TMP36: Vout = 10mV/°C with 500mV offset
  // Vout (mV) = rawTemp * (5000 / 1024)
  float voltage_mV = rawTemp * (5000.0 / 1024.0);
  float tempC = (voltage_mV - 500.0) / 10.0;
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  // --- Light reading (LDR) ---
  int rawLight = analogRead(LIGHT_PIN);
  // Higher value = more light (LDR resistance drops with light)
  int lightPercent = map(rawLight, 0, 1023, 0, 100);

  // --- Serial output ---
  Serial.print("Temp: ");
  Serial.print(tempC, 1);
  Serial.print(" C  /  ");
  Serial.print(tempF, 1);
  Serial.print(" F  |  Light: ");
  Serial.print(lightPercent);
  Serial.println("%");

  delay(1000);
}
