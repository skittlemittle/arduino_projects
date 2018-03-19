//Copyright (c) 2018 Afshaan Londhe
//this software is licensed under the MIT license
//which can be found here: https://mit-license.org/
//this code can be found here: https://github.com/afshaan4/random-arduino-code

// this code pulses an LED

const int LED = 9;
int i = 0; //used to count up and down

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // increase the brightness till we reach maximum brightness
  for (i = 0; i < 255; i++) {
    analogWrite(LED, i);
    delay(10);
  }

  // decrease brightness till we reach minimum brightness
  for (i = 255; i > 0; i--) {
    analogWrite(LED, i);
    delay(10);
  }
}
