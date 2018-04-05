//Turn on an LED when the button is pressed and keep it on
//improved so it actually works, with debouncing.

//based on code from Massimo Banzi's 'Getting started with arduino'

//the pin for the LED and button
const int LED = 13;
const int BUTTON = 7;

int val = 0; //used to store the state of the input pin.

int old_val = 0; //used to store the previous value of 'val'.

int state = 0; //used to remember if the LED has to be on or off.

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON); //read the button's state and store it.

  //check if there was a transition
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;
    delay(10); //debouncing, removes button noise.
  }

  old_val = val; // 'val' is old now, remember that.

  //if the state is 1 turn the LED on
  if (state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
