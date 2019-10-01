#include "Keyboard.h"

int sensorPin = A0;
int sensorVal;
int prevSensorVal;
int threshold = 400;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  prevSensorVal = sensorVal;
  sensorVal = analogRead(sensorPin);


  if (sensorVal >= threshold && prevSensorVal < threshold) {
    Keyboard.write(' ');
  }

}
