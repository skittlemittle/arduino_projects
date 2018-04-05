// blink an LED at a speed based on 
// analog input from analog pin 0

const int LED = 13;

int val = 0;

void setup() {
	pinMode(LED, OUTPUT);

	//analog pins are input by defalut
}

void loop() {
	val = analogRead(0); // read the sensor value

	digitalWrite(LED, HIGH); 
	delay(val); // wait, using the reading from val as the wait time
	digitalWrite(LED, LOW);
	delay(val); // wait, using the reading from val as the wait time
}