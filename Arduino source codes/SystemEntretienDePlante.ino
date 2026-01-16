#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <LedControl.h>

// =============== LCD Setup ==================
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust 0x27 if your LCD has another address

// =============== DHT11 Setup =================
#define DHTPIN 2    // DHT11 data pin (example: D2)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// =============== Moisture + Water Level Setup ==========
int soilPin = A0;
int waterLevelPin = A1;
int soilValue;
int waterLevelValue;
int pumpPin = 4;
int DRYalert = 6;

// =============== Light Sensor + LED Matrix Setup ========
LedControl lc = LedControl(11, 13, 12, 1);
int LDR_PIN = A3;
int ldrThreshold = 500;

// =============== Fan Control ============
int fanPin = 3;
int coldLedPin = 5;

// =============== Time Counters =============
unsigned long lightStartTime = 0;
unsigned long darkStartTime = 0;
bool isLight = false;
bool isDark = false;
unsigned long lightDuration = 0;
unsigned long darkDuration = 0;

void setup() {
  Serial.begin(9600);

  // LCD
  lcd.init();
  lcd.backlight();

  // DHT
  dht.begin();

  // Moisture/Water Level
  pinMode(pumpPin, OUTPUT);
  pinMode(DRYalert, OUTPUT);

  // Fan
  pinMode(fanPin, OUTPUT);
  pinMode(coldLedPin, OUTPUT);

  // LED Matrix
  lc.shutdown(0, false);
  lc.setIntensity(0, 10);
  lc.clearDisplay(0);

  lcd.setCursor(0, 0);
  lcd.print("System Starting..");
  delay(2000);
  lcd.clear();
}

void loop() {
  // ================== Read Sensors ==================
  soilValue = analogRead(soilPin);
  waterLevelValue = analogRead(waterLevelPin);
  int ldrValue = analogRead(LDR_PIN);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // ================== Light/Dark Duration ============
  Serial.println(ldrValue);   // Only print LDR value

  if (ldrValue < ldrThreshold) {
    delay(3000);
    // Turn ON ALL LEDs (all rows + all columns) 
    for (int row = 0; row < 8; row++) {
      lc.setRow(0, row, 0b11111111);  // Binary 255 = ALL LEDs in row ON
    }
  }
  else {
    lc.clearDisplay(0);  // Turn OFF ALL LEDs
  }
  delay(100);


  // ================== Pump Control ===================
  if (soilValue > 700 && waterLevelValue > 350) {
    digitalWrite(pumpPin, HIGH); // Water the plant
    digitalWrite(DRYalert,LOW);
  } else if (soilValue < 700) {
      digitalWrite(pumpPin, LOW);
      digitalWrite(DRYalert,LOW);
  } else if (soilValue > 700 && waterLevelValue < 350) {
    digitalWrite(pumpPin, LOW);
    digitalWrite(DRYalert,HIGH);
  }

  // ================== Fan Control ====================
  if (temperature > 25) {
    digitalWrite(fanPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
  }

  if (temperature < 20) {
    digitalWrite(coldLedPin, HIGH);
  } else {
    digitalWrite(coldLedPin, LOW);
  }

  // ================== LED Matrix Control =============
  if (ldrValue < ldrThreshold) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(0, row, 0b11111111);
    }
  } else {
    lc.clearDisplay(0);
  }

  // ================== LCD Display ====================
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(map(soilValue, 1023, 0, 0, 100)); // Mapping soil moisture %

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  if (isLight) {
    lcd.print("Light ");
    lcd.print(lightDuration);
    lcd.print("s");
  } else {
    lcd.print("Dark ");
    lcd.print(darkDuration);
    lcd.print("s");
  }

  lcd.setCursor(0, 1);
  if (soilValue > 700 && waterLevelValue <= 350) {
    lcd.print("REFILL RESERVOIR");
  } else {
    lcd.print("RESERVOIR FULL");
  }

  delay(2000);
}
