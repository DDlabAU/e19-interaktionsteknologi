int redLed = 4;
int greenLed = 5;
int blueLed = 6;
boolean redState = LOW;
boolean greenState = LOW;
boolean blueState = LOW;

int buttonPin = 2;
boolean buttonState = HIGH;
boolean prevButtonState = HIGH;

int currentTime;
int pushTime;
int releaseTime;
int clickTime = 50;
int waitTime = 500;
int clicks = 0;



void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  prevButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  currentTime = millis();

  if (buttonState == LOW && prevButtonState == HIGH) {
    pushTime = currentTime;

    Serial.println("push");
  }

  if (buttonState == HIGH && prevButtonState == LOW) {
    releaseTime = currentTime;
    Serial.println("release");

    if (releaseTime > pushTime + clickTime) {
      clicks = clicks + 1;
      //clicks++;
      Serial.print("Click: ");
      Serial.println(clicks);
    }
  }

  if (currentTime > pushTime + waitTime && currentTime > releaseTime + waitTime) {
    if (clicks == 1) {
      redState = !redState;
    } else if (clicks == 2) {
      greenState = !greenState;
    } else if(clicks == 3){
      blueState = !blueState;
    }

    clicks = 0;
  }

  digitalWrite(redLed, redState);
  digitalWrite(greenLed, greenState);
  digitalWrite(blueLed, blueState);

}
