int ledPin = 6;
int potPin = A0;
int buttonPin = 2;

int ledVal = 0;
int potVal = 0;
boolean buttonVal = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  buttonVal = digitalRead(buttonPin);

  if(buttonVal == LOW) {
    ledVal = ledVal + 4;

    if(ledVal > 255) {
      ledVal = 0;
    }
  }

  Serial.println(ledVal);
  Serial.println(potVal);
  Serial.println();

  analogWrite(ledPin, ledVal);
  delay(potVal);


}
