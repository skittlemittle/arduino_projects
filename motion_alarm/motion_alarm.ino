// Beeps a buzzer when motion is detected.

int buzzer = 13;                // the pin for the buzzer
int inputPin = 2;               // input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(buzzer, OUTPUT);      // declare buzzer as output
  pinMode(MOTION_PIN, INPUT_PULLUP);     // declare sensor as input, and internally pull it up

  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {           // check if the input is HIGH
    digitalWrite(buzzer, HIGH);  // turn buzzer ON
    if (pirState == LOW) {
      // we only print if there is a change in state
      Serial.println("Something moves in the shadows!");
      pirState = HIGH; // the motion began set pirState high
    }
  } else {
    digitalWrite(buzzer, LOW); // turn the buzzer OFF
    if (pirState == HIGH) {
      // we only want to print if there is a change in state
      Serial.println("The movement has ended.");
      pirState = LOW;  // the motion began set pirState low
    }
  }
}
