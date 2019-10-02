int lightSensor = A0;
int lightVal;

int redLed = 3;
int greenLed = 5;
int blueLed = 6;
int redVal;
int greenVal;
int blueVal;

void setup() {
  pinMode(lightSensor, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(lightSensor);

  lightVal = constrain(lightVal, 10, 670);

  redVal = map(lightVal, 10, 670, 5, 200);
  greenVal = map(lightVal, 10, 670, 40, 60);
  blueVal = map(lightVal, 10, 670, 200, 5);

  Serial.println(redVal);
  Serial.println(greenVal);
  Serial.println(blueVal);
  Serial.println();

  analogWrite(redLed, redVal);
  analogWrite(greenLed, greenVal);
  analogWrite(blueLed, blueVal);
}
