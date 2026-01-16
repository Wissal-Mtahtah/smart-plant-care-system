int soilPin = A0;
int soilValue;
const int analogInPin = A1;
int WaterLevel = 0;
int PUMP = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP,OUTPUT);
}

void loop() {
  soilValue = analogRead(soilPin);
  WaterLevel = analogRead(analogInPin);


  if (soilValue > 700 and WaterLevel<=350) {
    Serial.println("Soil is dry! Water the plant!");
    digitalWrite(PUMP,HIGH);
  }
  else if (soilValue <= 700) {
    Serial.println("Soil is moist. No need to water.");
    digitalWrite(PUMP,LOW);
  }

}
