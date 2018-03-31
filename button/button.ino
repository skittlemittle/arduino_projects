//Turn on an LED when the button is pressed
//and off when the buuton is released.

//the pin for the LED and button
const int LED = 13;
const int BUTTON = 7;

int val = 0; //used to store the state of the input pin

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON); //read the button's state and store it.

  //if the button is pressed turn on the LED, else leave it off.
  if (val == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
