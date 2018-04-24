// Turns a servo based on readings from an analog sensor.

#include <Servo.h>
// turns a servo to an angle based on readings from analog 0

Servo myServo; // name the servo

int val, mapped; // used to store the reading from analog 0

void setup() {
	myServo.attach(9); // set the pin the servo is connected to
	Serial.begin(9600);
}

void loop() {
	val = analogRead(0); // read analog 0
	// map the readings from the sensor to the servos range.
	mapped = map (val, 100, 900, 0, 180);
	myServo.write(mapped); // turn the servo to the angle read from the sensor
	// print the stuff to the computer
	delay(400);
}