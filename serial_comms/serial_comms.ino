/*
 sends values read from analog input 0
 to a computer with serial print.
 this codes repo: https://github.com/afshaan4/other_arduino_projects
*/

const int sensor = 0; // the pin for the analog sensor

int val = 0; // used to store the reading from the sensor

void setup() {
	// open the serial port to the computer
	// and set the transmission speed to 9600 baud
	Serial.begin(9600); 

	// analog pins are input by default
} 

void loop() {
	val = analogRead(sensor); // read the sensor
	Serial.println(val); // send the value read from the sensor to the computer
	
	delay(100); // wait between each send makes reading through the stuff easier
}