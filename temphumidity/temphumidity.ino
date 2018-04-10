// reads temperature and humidity from a DHTXX and sends it to a computer over serial.
// this codes repo: https://github.com/afshaan4/random-arduino-code

#include "DHT.h"

//set the sensor pin
#define DHTPIN 7

//Uncomment whatever type you're using.
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

/*
 Connect pin 1 (on the left) of the sensor to +5V
 NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
 to 3.3V instead of 5V!
 Connect pin 2 of the sensor to whatever your DHTPIN is
 Connect pin 4 (on the right) of the sensor to GROUND
 Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
*/

/*
 Initialize DHT sensor.
 Note that older versions of this library took an optional third parameter to
 tweak the timings for faster processors.  This parameter is no longer needed
 as the current DHT reading algorithm adjusts itself to work on faster processors.
*/
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin(); // initialize the sensor
  Serial.begin(9600);
}

void loop() {
  //wait a few seconds between measurements.
  delay(2000);
  //reading temperature or humidity takes about 250 milliseconds.
  //sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  //read temperature as Celsius (the default)
  float t = dht.readTemperature();
  //If you want the temperature as Fahrenheit uncomment the line below (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  //check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor :(");
    return;
  }

  /*
  print humidity and temperature readings to the screen.
  */

  // humidity goes on one line.
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  //temperature goes on the next line.
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println("*C   ");
  //separate each set of readings with a empty line.
  Serial.println("");
}