//reads a rain detector and turns on an LED if it detects rain

int LED = 13;
int rainSensor = 8;
int val; //used to read sensor

void setup() {
	pinMode(LED, OUTPUT);
	pinMode(rainSensor, INPUT);
}

void loop()  {
	val =  digitalRead(rainSensor);

    //the sensor returns HIGH if there is no rain
    //and LOW when there is rain
	if(val == HIGH) {
		digitalWrite(LED, LOW);
	} else {
		digitalWrite(LED, HIGH);
	}
}