int ledPin = 3;
int ledVal = 0;

int lightSensor = A0;
int lightVal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(lightSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(lightSensor);
  Serial.println(lightVal);

  lightVal = constrain(lightVal, 10, 670);
  Serial.println(lightVal);

  ledVal = map(lightVal, 10, 670, 255, 0);
  Serial.println(ledVal);
  Serial.println();


  analogWrite(ledPin, ledVal);
}
