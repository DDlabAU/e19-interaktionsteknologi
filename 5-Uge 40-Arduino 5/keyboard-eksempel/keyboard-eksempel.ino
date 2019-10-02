#include "Keyboard.h"

int sensorPin = A0;
int sensorVal;
int prevSensorVal;
int threshold = 300;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  prevSensorVal = sensorVal;
  sensorVal = analogRead(sensorPin);

  Serial.println(prevSensorVal);
  Serial.println(sensorVal);

  if(sensorVal <= threshold && prevSensorVal > threshold) {
    Keyboard.write(' ');
    Serial.println("Trykker!");
    delay(500);
  }

  Serial.println();
}
