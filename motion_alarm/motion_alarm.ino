//Copyright (c) 2018 Afshaan Londhe
//this software is licensed under the MIT license
//which can be found here: https://mit-license.org/
//this code can be found here: https://github.com/afshaan4/random-arduino-code

/*
 * PIR motion alarm
 */

int buzzer = 13;                // choose the pin for the buzzer
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(buzzer, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {           // check if the input is HIGH
    digitalWrite(buzzer, HIGH);  // turn buzzer ON
    if (pirState == LOW) {
      //we have just turned on
      Serial.println("Motion detected!");
      //we only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(buzzer, LOW); //turn the buzzer OFF
    if (pirState == HIGH){
      //we have just turned off
      Serial.println("Motion ended!");
      //we only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
