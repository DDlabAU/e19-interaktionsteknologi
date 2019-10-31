int ledPin = 8;
int ledState = HIGH;

int currentTime;
int lastChange;
int delayTime = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  currentTime = millis();

  if (currentTime > lastChange + delayTime) {
    //    ledState = !ledState;

    if (ledState == HIGH) {
      ledState = LOW;
      delayTime = 200;
    } else {
      ledState = HIGH;
      delayTime = 1000;
    }
    lastChange = millis();
  }

  digitalWrite(ledPin, ledState);
}
