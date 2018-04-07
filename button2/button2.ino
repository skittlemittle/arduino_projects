// Turn on an LED when the button is pressed and keep it on after it is released.

// based on code from Massimo Banzi's 'Getting started with arduino'

// the pin for the LED and button
const int LED = 13;
const int BUTTON = 7;

int val = 0; // used to store the state of the input pin.

int state = 0; // used to remember if the LED has to be on or off.

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON); // read the button's state and store it.

  // check if the button is pressed and change the state.
  // 1 - 0 = 1 and 1 - 1 = 0, and so it swithces, neat right?
  if (val == HIGH) {
    state = 1 - state;
  }

  // if the state is 1 turn the LED on
  if (state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
