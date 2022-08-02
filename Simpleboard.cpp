// C++ code
//
/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/

int Temperature = 0;

void setup()
{
  pinMode(A1, INPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Temperature = (-39 + 0.488155 * (analogRead(A1) - 20));
  Serial.print(Temperature);
  Serial.println("");
  if (Temperature < 17) {
    digitalWrite(7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(7, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (Temperature > 24) {
    digitalWrite(13, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(13, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}