//Copyright (c) 2018 Afshaan Londhe
//this software is licensed under the MIT license
//which can be found here: https://mit-license.org/
//this code can be found here: https://github.com/afshaan4/random-arduino-code

//blinks an LED

const int LED = 13;

//set LED as an output
void setup() {
  pinMode(LED, OUTPUT);
}

//blink the LED
void loop() {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}
