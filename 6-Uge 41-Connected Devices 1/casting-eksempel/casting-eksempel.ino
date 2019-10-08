int intVal = 200;
float floatVal = 4.65;
boolean boolVal = HIGH;

String intString;
String floatString;
String boolString;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  intString = String(intVal);
  floatString = String(floatVal);
  boolString = String(boolVal);



  Serial.println(intString);
  Serial.println(floatString);
  Serial.println(boolString);

  intVal = intString.toInt();
  floatVal = floatString.toFloat();

  if (boolString == "1") {
    boolVal = true;
  } else if (boolString == "0") {
    boolVal = false;
  }
//  boolVal = (boolString == "1");

  Serial.println(intVal);
  Serial.println(floatVal);
  Serial.println(boolVal);

  Serial.println();

  delay(1000);
}
