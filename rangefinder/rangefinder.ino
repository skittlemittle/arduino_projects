// rangefinder using the HC-SR04 ultrasonic sensor
// this codes repo: https://github.com/afshaan4/other_arduino_projects

// the ultrasonic sensors pins
const int trigger = 12; // sends a ping
const int echo = 11; // reads the ping

const int LED = 13; // the LED or buzzer

void setup() {
  pinMode(trigger, OUTPUT); // set the trigger as output
  pinMode(echo, INPUT); // set the reader as input
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  long duration, cm; // used to calculate distance

  // send a ping
  digitalWrite(trigger, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(trigger, LOW); // pull it low again

  // store the time it takes for the ping to return
  duration = pulseIn(echo, HIGH);
  // convert the time it takes into centimeters
  cm = microsecondsToCentimeters(duration);

  /*
  depending on how far away a detected object is, blink an LED or beep a buzzer.
  We do this by letting the LED/buzzer be on or off for the distance
  of an object multiplied by 10
  we multiply by ten so the waits are longer else you wouldn't notice them.
  */
  if ((cm > 1) and (cm < 20)) { // ignore stuff closer than 1 cm and further than 20 cm.
    digitalWrite(LED, HIGH);
    delay(cm * 10);
    digitalWrite(LED, LOW);
    delay(cm * 10);
    Serial.print(cm);
    Serial.println("centimeters");
  }
}

/*
function that converts the ping time reading to distance
*/
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance traveled.
  return microseconds /29 / 2;
}
