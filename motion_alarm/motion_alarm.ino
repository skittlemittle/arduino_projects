//PIR motion alarm

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
      //we have just turned on
      Serial.println("Something moves in the shadows!");
      //we only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(buzzer, LOW); //turn the buzzer OFF
    if (pirState == HIGH){
      //we have just turned off
      Serial.println("The movement has ended.");
      //we only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
