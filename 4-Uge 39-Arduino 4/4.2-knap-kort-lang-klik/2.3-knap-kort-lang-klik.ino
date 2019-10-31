int ledPin = 8;
int ledState = LOW;

int buttonPin = 2;
boolean buttonState = HIGH;
boolean prevButtonState = HIGH;

int pushTime;
int releaseTime;
int longPress = 1000;
int shortPress = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  prevButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && prevButtonState == HIGH){
      pushTime = millis();
  }

  if(buttonState == HIGH && prevButtonState == LOW){
    releaseTime = millis();

    if(releaseTime > pushTime + longPress){
      Serial.println("long press");
      ledState = LOW;
    } else if(releaseTime > pushTime + shortPress){
      Serial.println("short press");
      ledState = HIGH;
    }

  }

  digitalWrite(ledPin, ledState);
}
