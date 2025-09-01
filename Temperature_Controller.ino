// shady nikooei

// --- Pin Definitions ---
// LM35 Temperature Sensor Pin
const int TEMP_SENSOR_PIN = A0;

// Control LEDs
const int FAN_LED_PIN = 8;
const int HEATER_LED_PIN = 9;

// Seven Segment Display Pins (A, B, C, D, E, F, G)
const int SEG_A = 2;
const int SEG_B = 3;
const int SEG_C = 4;
const int SEG_D = 5;
const int SEG_E = 6;
const int SEG_F = 7;
const int SEG_G = 13;

// Digit Selector Pins for the two 7-segment displays
const int DIGIT_UNITS_PIN = 11;
const int DIGIT_TENS_PIN = 12;

// --- Global Variables & Constants ---
// Patterns for displaying digits 0-9 on a common cathode 7-segment display
byte digitPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

// State variables for hysteresis logic
bool isFanOn = false;
bool isHeaterOn = false;

void setup() {
  Serial.begin(9600);

  // Set all segment and control pins to OUTPUT mode
  int outputPins[] = {
    SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G,
    DIGIT_UNITS_PIN, DIGIT_TENS_PIN,
    FAN_LED_PIN, HEATER_LED_PIN
  };
  for (int pin : outputPins) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  float temperature = readTemperature();
  int tempInt = (int)temperature;

  //Serial.print("Temperature: ");
  //Serial.println(temperature);
  Serial.println(temperature);
  applyControlLogic(temperature);

  // Display the temperature repeatedly for a short duration to ensure stable visibility
  unsigned long startTime = millis();
  while (millis() - startTime < 200) {
    displayTemperature(tempInt);
  }
}

/**
 * Reads the raw analog value from the LM35 sensor and converts it to Celsius.
 */
float readTemperature() {
  int sensorValue = analogRead(TEMP_SENSOR_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);
  float tempCelsius = voltage * 100.0;
  return tempCelsius;
}

/**
 * Applies the hysteresis logic to control the fan and heater LEDs.
 */
void applyControlLogic(float temp) {
  // Fan control logic
  if (temp > 30) {
    isFanOn = true;
  } else if (temp < 25) {
    isFanOn = false;
  }
  digitalWrite(FAN_LED_PIN, isFanOn);

  // Heater control logic
  if (temp < 20) {
    isHeaterOn = true;
  } else if (temp > 25) {
    isHeaterOn = false;
  }
  digitalWrite(HEATER_LED_PIN, isHeaterOn);
}

/**
 * Displays an integer temperature on the two 7-segment displays
 * by rapidly switching between the tens and units digit.
 */
void displayTemperature(int temp) {
  if (temp < 0 || temp > 99) return;

  int tens = temp / 10;
  int units = temp % 10;

  // Show tens digit
  digitalWrite(DIGIT_UNITS_PIN, LOW);
  digitalWrite(DIGIT_TENS_PIN, HIGH);
  showDigit(tens);
  delay(5);

  // Show units digit
  digitalWrite(DIGIT_TENS_PIN, LOW);
  digitalWrite(DIGIT_UNITS_PIN, HIGH);
  showDigit(units);
  delay(5);
}

/**
 * Sets the segment pins to display a single digit (0-9).
 */
void showDigit(int digit) {
  int segmentPins[] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G};
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}