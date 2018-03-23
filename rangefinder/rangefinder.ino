//rangefinder using the HC-SR04 ultrasonic sensor

//the ultrasonic sensors pins
const int pingO = 12; //sends a ping
const int pingI = 11; //reads the ping

void setup() {
  pinMode(pingO, OUTPUT); //set the trigger as output
  pinMode(pingI, INPUT); //set the reader as input
}

void loop() {

  long duration, cm; //used to calculate distance

  //send a ping
  digitalWrite(pingO, LOW); //pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(pingO, HIGH); //send the ping
  delayMicroseconds(5);
  digitalWrite(pingO, LOW); //pull it low again

  //store the time it takes for the ping to return
  duration = pulseIn(pingI, HIGH);
  //convert the time it takes into centimeters
  cm = microsecondsToCentimeters(duration);
}

//function that converts the ping time reading to distance
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds /29 / 2;
}
