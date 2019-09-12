int ledPin = 6;
int potPin = A0;

int ledVal = 0;
int potVal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);

  ledVal = ledVal + 4;

  if(ledVal > 255) {
    ledVal = 0;
  }

  Serial.println(ledVal);
  Serial.println(potVal);
  Serial.println();

  analogWrite(ledPin, ledVal);
  delay(potVal);
}
