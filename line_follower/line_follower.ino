/*
 A simple line follower using 2 IR sensors

 The logic used here is simple:

 If the left sensor is on the line         > turn left
 If the right sensor is on the line        > turn right
 If both the sensors are on the line       > stop
 If neither of the sensors are on the line > go forward
*/

// the left and right IR sensors
const int rSensor = 8;
const int lSensor = 9;

// the motors
const int  a1 = 2;
const int  a2 = 3;
const int  b1 = 4;
const int  b2 = 5;

// used to store readings from the sensors
int lVal;
int rVal;

void setup() {
	// set the sensors as inputs
	pinMode(rSensor, INPUT);
	pinMode(lSensor, INPUT);

	// set the motors as outputs
	pinMode(a1, OUTPUT);
	pinMode(a2, OUTPUT);
	pinMode(b1, OUTPUT);
	pinMode(b2, OUTPUT);
	// for debugging
	Serial.begin(9600);
}

void loop() {
	rVal = digitalRead(rSensor);
	lVal = digitalRead(lSensor);

	// if both sensors see white, go forward
	if ((rVal == 1) && (lVal == 1)) {
		digitalWrite(a1, HIGH);
		digitalWrite(a2, LOW);
		digitalWrite(b1, HIGH);
		digitalWrite(b2, LOW);
	}

	// if the left sensor is on the line, turn left
	if ((rVal == 1) && (lVal == 0)) {
		digitalWrite(a1, HIGH);
		digitalWrite(a2, LOW);
		digitalWrite(b1, LOW);
		digitalWrite(b2, LOW);
	}

	// if the right sensor is on the line, turn right
	if ((rVal == 0) && (lVal == 1)) {
		digitalWrite(a1, LOW);
		digitalWrite(a2, LOW);
		digitalWrite(b1, HIGH);
		digitalWrite(b2, LOW);
	}

	// if both sensors are on the line, stop
	if ((rVal == 0) && (lVal == 0)) {
		digitalWrite(a1, LOW);
		digitalWrite(a2, LOW);
		digitalWrite(b1, LOW);
		digitalWrite(b2, LOW);
	}
}