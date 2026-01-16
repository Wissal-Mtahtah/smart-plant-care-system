#include "DHT.h"

#define DHTPIN 2     // DHT11 connected to digital pin 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int motorPin = 9;    // Motor control pin via transistor
int COLD = 5;        // Another output pin if you want (example: for LED)

void setup() {
  dht.begin();
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(COLD, OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  // Control Motor based on temperature
  if (t > 25) {
    digitalWrite(motorPin, HIGH); // Fan ON
  } else {
    digitalWrite(motorPin, LOW);  // Fan OFF
  }

  // Control another device if needed
  if (t < 20) {
    digitalWrite(COLD, HIGH); // Turn on something if very cold
  } else {
    digitalWrite(COLD, LOW);
  }

  delay(1000); // Read every 1 second
}
