int soilPin = A0;
int soilValue;
int PUMP = 2;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP,OUTPUT);
}

void loop() {
  soilValue = analogRead(soilPin);

  if (soilValue > 700) {
    Serial.println("Soil is dry! Water the plant!");
    digitalWrite(PUMP,HIGH);
  }
  else {
    Serial.println("Soil is moist. No need to water.");
    digitalWrite(PUMP,LOW);
  }

}
