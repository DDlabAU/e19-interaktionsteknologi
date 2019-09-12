int ledPin = 6;
int leftButtonPin = 2;
int rightButtonPin = 3;

int ledVal = 0;
boolean leftButtonVal = HIGH;
boolean rightButtonVal = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  leftButtonVal = digitalRead(leftButtonPin);
  rightButtonVal = digitalRead(rightButtonPin);

  if (leftButtonVal == LOW && rightButtonVal == LOW) {
    ledVal = 255;
  } else if (leftButtonVal == LOW)   {
    ledVal = 85;
  } else if (rightButtonVal == LOW) {
    ledVal = 170;
  } else {
    ledVal = 0;
  }



  // Hvis begge er trykket skal den være helt tændt
  // Hvis venstre er trykket skal den være værdi1
  // Hvis højre er trykket skal den være værdi2
  // Hvis ingen er trykket på skal den være slukket

  analogWrite(ledPin, ledVal);

  Serial.println(ledVal);
  Serial.println(leftButtonVal);
  Serial.println(rightButtonVal);
  Serial.println();

}
