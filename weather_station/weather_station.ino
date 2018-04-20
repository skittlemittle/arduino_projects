/* 
  An Arduino weather station, using:
  * A BMP180 barometer.
  * A DHT11 temperature and humidity sensor.
  * An LDR.
  * A "rain sensor".
  * A 16x2 LCD.

  The sensor readings are sent to the LCD
  and debugging stuff is sent to a computer over serial

  For wiring diagrams and stuff visit: 
  this codes repo: https://github.com/afshaan4/other_arduino_projects
*/

#include "DHT.h"
#include <LiquidCrystal.h>
#include <SFE_BMP180.h>
#include <Wire.h>

const int rain = 8;
const int light = A0;

int rval; // used to read the rain sensor
int lval; // used to read the LDR

// set the sensor and LCD pins
#define DHTPIN 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// create an SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure;
#define ALTITUDE 920.0 // set your altitude here(in meters)

// Uncomment whatever type you're using.
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
  dht.begin();
  Serial.begin(9600);

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

  // variables for the BMP180
  char status;
  double T,P,p0,a; // temperature, pressure, sea-level compensated pressure, computed altitude.

  // read the rain and light sensors
  lval = analogRead(light);
  rval = digitalRead(rain);

  // reading temperature or humidity takes about 250 milliseconds!
  // sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // If you want the temperature as Fahrenheit (isFahrenheit = true)
  // float f = dht.readTemperature(true);

  // check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.print("Failed to read from DHT sensor :(");
    return;
  }


  // Loop here getting pressure readings every 10 seconds.

  // If you want sea-level-compensated pressure, as used in weather reports,
  // you will need to know the altitude at which your measurements are taken.
  // We're using a constant called ALTITUDE in this sketch:
  
  lcd.print("given alt: ");
  lcd.print(ALTITUDE,0);
  lcd.print("m");
  lcd.setCursor(0, 1);
  
  // You must first get a temperature measurement to perform a pressure reading.
  
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, 0 is returned.

  status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:
    delay(status);

    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Function returns 1 if successful, 0 if failure.

    status = pressure.getTemperature(T);
    if (status != 0)
    {
      // Start a pressure measurement:
      // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
      // If request is successful, the number of ms to wait is returned.
      // If request is unsuccessful, 0 is returned.

      status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed pressure measurement:
        // Note that the measurement is stored in the variable P.
        // Note also that the function requires the previous temperature measurement (T).
        // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
        // Function returns 1 if successful, 0 if failure.

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          // Print out the measurement:
          lcd.print("ab Pr: ");
          lcd.print(P,2);
          lcd.print("mb");
          delay(3000);
          lcd.clear();

          // The pressure sensor returns abolute pressure, which varies with altitude.
          // To remove the effects of altitude, use the sealevel function and your current altitude.
          // This number is commonly used in weather reports.
          // Parameters: P = absolute pressure in mb, ALTITUDE = current altitude in m.
          // Result: p0 = sea-level compensated pressure in mb

          p0 = pressure.sealevel(P,ALTITUDE); // we're at 920 meters.
          lcd.print("rel Pr ");
          lcd.print(p0,2);
          lcd.print("mb");
          delay(3000);
          lcd.clear();

        }
        // these are for debugging so we send them to the computer.
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");


  // print humidity and temperature readings to the screen.
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("*C   ");
  lcd.setCursor(1, 1);
  delay(3000);
  lcd.clear();

  lcd.print("Light: ");
  lcd.print(lval);
  lcd.setCursor(1, 1);

  if(rval == HIGH) {
    lcd.print("No rain");
    delay(3000);
    lcd.clear();
  } else {
    lcd.print("Raining");
    delay(3000);
    lcd.clear();
  }
}