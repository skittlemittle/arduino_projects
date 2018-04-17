/*
 makes two DC motors spin one direction for a second then the other

 Note: The L293D has "motor-enable" pins, these are used to turn on and off the motors
 you an also control the speed of the motors by sending a PWM to these pins.
 For this example give the enable pins 5 volts.

 If you board doesn't have these pin or they are shorted to power
 and you don't want to do speed control stuff then you don't need to give them power.
*/

// assign the motor controller pins
int a1 = 2; // motor a pin 1
int a2 = 3; // motor a pin 2
int b1 = 4; // motor b pin 1
int b2 = 5; // motor b pin 2

void setup() {
  // setup the motor controller pins
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
}

void loop() {
  // turn on pin 1 and turn off pin 2
  // the motor spins one way
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000); // let it spin for a second
  // turn off pin 1 and turn on pin 2
  // the motor spins the other way
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  delay(1000); // let it spin for a second
}
