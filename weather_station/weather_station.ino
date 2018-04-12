/* 
  An Arduino weather station, using:
  * A BMP180 barometer.
  * A DHT11 temperature and humidity sensor.
  * An LDR.
  * A "rain sensor".
  * A Soil moisture sensor(because we can).

  For wiring diagrams and stuff visit: 
  this codes repo: https://github.com/afshaan4/other_arduino_projects
*/

#include "DHT.h"
#include <LiquidCrystal.h>
#include <SFE_BMP180.h>
#include <Wire.h>

//set the sensor and LCD pins
#define DHTPIN 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//create an SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure;
#define ALTITUDE 920.0 //set your altitude here(in meters)

//Uncomment whatever type you're using.
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

/*
 Initialize DHT sensor.
 Note that older versions of this library took an optional third parameter to
 tweak the timings for faster processors.  This parameter is no longer needed
 as the current DHT reading algorithm adjusts itself to work on faster processors.
*/
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  lcd.write("Weather Station");
  dht.begin();

  // Initialize the BMP180 sensor (it is important to get calibration values stored on the device).
  if (pressure.begin()) {
    Serial.println("BMP180 init success");
  } else {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }

}

void loop() {
  //wait a few seconds between measurements.
  delay(2000);
  lcd.setCursor(0, 1); 

  // variables for the BMP180
  char status;
  double T,P,p0,a; // temperature, pressure, sea-level compensated pressure, computed altitude.

  //reading temperature or humidity takes about 250 milliseconds!
  //sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  //read temperature as Celsius (the default)
  float t = dht.readTemperature();
  //If you want the temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  //check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.print("Failed to read from DHT sensor :(");
    return;
  }

  //print humidity and temperature redings to the screen.
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%\t ");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("*C   ");
}