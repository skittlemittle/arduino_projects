// blinks an LED

const int LED = 13;

// set LED as an output
void setup() {
  pinMode(LED, OUTPUT);
}

// blink the LED
void loop() {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}
