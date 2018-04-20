// reads analog signals from a soil moisture sensor
// and sends the values to a computer

int val = 0; // value for storing moisture value 
int sensor = A0;// Declare a variable for the soil moisture sensor 
// used to power the sensor, this way we can turn it off when not in use so it doesn't corrode
int sensorPwr = 7;

void setup() 
{
  Serial.begin(9600);

  // sensorPwr is an output, and we set it to LOW so its off.
  pinMode(sensorPwr, OUTPUT);
  digitalWrite(sensorPwr, LOW);
}

void loop() 
{
Serial.print("Soil Moisture = ");    
// get soil moisture value from the function below and print it
Serial.println(readSoil());

// we use a one second delay so you can see the change 
// if you are using this to monitor your plant set this to a few hours.
delay(1000);// take a reading every second
}

// function used to read soil moisture
int readSoil()
{

    digitalWrite(sensorPwr, HIGH); // turn D7 "On"
    delay(10); // wait 10 milliseconds 
    val = analogRead(sensor); // Read the SIG value form sensor 
    digitalWrite(sensorPwr, LOW); // turn D7 "Off"
    return val; // send current moisture value
}