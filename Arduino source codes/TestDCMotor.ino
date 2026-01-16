int motorPin = 2; // Motor control pin

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, HIGH); // Turn motor ON
  delay(3000);                  // Wait 3 seconds
  digitalWrite(motorPin, LOW);  // Turn motor OFF
  delay(2000);                  // Wait 2 seconds
}
