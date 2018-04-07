// Fades an LED in and out, like a sleeping laptop

const int LED = 9;
int i = 0; // used to count up and down

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // loop from 0 to 255 and increase the 
  // brightness of the LED each time we go through the loop
  for (i = 0; i < 255; i++) { 
    analogWrite(LED, i);
    delay(10);
  }

  // loop from 255 to 0 and decrease the 
  // brightness of the LED each time we go through the loop
  for (i = 255; i > 0; i--) {
    analogWrite(LED, i);
    delay(10);
  }
}