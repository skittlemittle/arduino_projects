// turns on and then off, a line of LED's one after the other, making a wave

// set up the variables for the leds
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;
const int LED9 = 10;
const int LED10 = 11;

// set all the led pins as outputs
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
}

/*
  turn on all the LED's one by one
  then turn them all off one after the other
  starting with the first one
*/
void loop() {
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED4, HIGH);
  delay(500);
  digitalWrite(LED5, HIGH);
  delay(500);
  digitalWrite(LED6, HIGH);
  delay(500);
  digitalWrite(LED7, HIGH);
  delay(500);
  digitalWrite(LED8, HIGH);
  delay(500);
  digitalWrite(LED9, HIGH);
  delay(500);
  digitalWrite(LED10, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED4, LOW);
  delay(500);
  digitalWrite(LED5, LOW);
  delay(500);
  digitalWrite(LED6, LOW);
  delay(500);
  digitalWrite(LED7, LOW);
  delay(500);
  digitalWrite(LED8, LOW);
  delay(500);
  digitalWrite(LED9, LOW);
  delay(500);
  digitalWrite(LED10, LOW);
  delay(500);
}
