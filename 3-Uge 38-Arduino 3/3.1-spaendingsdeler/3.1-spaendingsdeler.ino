int ldrPin = A0;
int ldrVal;

void setup() {
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  ldrVal = analogRead(ldrPin);

  Serial.println(ldrVal);

  delay(1000);
}
