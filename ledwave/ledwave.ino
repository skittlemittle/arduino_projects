// turns on and then off, a line of LED's one after the other, making a wave

void setup() {
  // no need to set up pins they are outputs by default.
}

/*
  turn on all the LED's one by one
  then turn them all off one after the other
  starting with the first one
*/
void loop() {
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
  digitalWrite(10, LOW);
  delay(500);
  digitalWrite(11, LOW);
  delay(500);
}
