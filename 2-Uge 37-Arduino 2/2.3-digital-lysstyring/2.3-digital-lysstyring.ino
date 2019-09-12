int ledPin = 6;
int buttonPin = 2;

int ledVal = 0;
boolean buttonVal = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  buttonVal = digitalRead(buttonPin);

  if(buttonVal == HIGH) {
    ledVal = 255;
  } else {
    ledVal = 0;
  }

  analogWrite(ledPin, ledVal);

  Serial.println(ledVal);
  Serial.println(buttonVal);
  Serial.println();

}
