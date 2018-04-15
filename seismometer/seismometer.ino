/*
 A "seismometer" using a piezo element and an Arduino to detect vibrations.
 This is not scientific or accurate, it just shows if there 
 is vibration and how much in raw analog signals.

 the sensor is connected to analog in 0.

 Open the serial plotter in the Arduino IDE for nice graphs.
*/

int val = 0;
int reading = 0; // used to map the readings from sensor to a range of 0 to 100.

void setup() {
	Serial.begin(9600);

	//analog pins are input by default.
}

void loop() {
	val = analogRead(0); // read the sensor value.
	/*
	 val varies a lot, from 0 to 500, so to make the graphs a bit neater
	 and so the vibrations are apparent, we map the readings from a range of 
	 0 to 500 to a range of 0 to 100.
	 like so: map(value, fromLow, fromHigh, toLow, toHigh);
	*/
	reading = map(val, 0, 500, 0, 100);

	Serial.println(reading); // super simple: read the sensor and send the reading to a computer.
	delay(10);
}