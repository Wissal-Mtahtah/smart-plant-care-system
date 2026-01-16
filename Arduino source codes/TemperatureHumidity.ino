#include "DHT.h"
#include <Stepper.h>

// DHT Sensor
DHT dht(2, DHT11);

// Stepper Motor
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 3, 4, 5, 6); 
// Correct wiring for 28BYJ-48 motor + ULN2003 driver

const int COLD = 7;

void setup() {
  Serial.begin(9600);
  dht.begin();
  myStepper.setSpeed(11); // 11 RPM (slow and safe for 28BYJ)
  pinMode(COLD, OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  // Fan logic
  if (t > 20) {
    // Too hot, spin the fan
    myStepper.step(stepsPerRevolution / 8); // small turn (~45°)
  }
  else {
    // Temperature OK, don't move
    // Optional: you can set a low stepper hold current if needed
  }

  // Cold output control
  if (t < 20) {
    digitalWrite(COLD, HIGH); // Turn ON something (maybe cooler?)
  } else {
    digitalWrite(COLD, LOW); // Turn OFF
  }

  delay(100); // Short delay so the loop runs fast
}

