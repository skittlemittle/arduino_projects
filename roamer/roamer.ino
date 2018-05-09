/*
 An obstacle avoiding robot, using an HC-SR04 ultrasonic sensor

 Note: The L293D has "motor-enable" pins, these are used to turn on and off the motors
 you an also control the speed of the motors by sending a PWM to these pins.
 For this example give the enable pins 5 volts.

 If you board doesn't have these pin or they are shorted to power
 and you don't want to do speed control stuff then you don't need to give them power.

 wiring diagrams and assembly guides can be found here: https://aaalearn.mystagingwebsite.com/2018/03/arduino-camp/
 this codes repo: https://github.com/afshaan4/other_arduino_projects

 This code is licensed under the MIT license: https://mit-license.org/
*/

long randNumber; // used to store the random number

// assign the motor controller pins
// motor one
int a1 = 2;
int a2 = 3;
// motor two
int b1 = 4;
int b2 = 5;
// the ultrasonic sensors pins
const int trigger = 12;
const int echo = 11;

/*
 function used to make the robot back up and then turn left
*/
void backLeft() {
  // back up for a second
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000);
  // stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
  // turn left for a second
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  delay(1000);
  // stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
}

/*
 function used to make the robot back up and then turn right
*/
void backRight() {
  // back up for a second
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000);
  // stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
  // turn right for a second
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000);
  // stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
}

// the setup stuff
void setup() {
  // setup the motor controller pins
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b1, OUTPUT);
  // set the ultrasonic sensors pins
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // the ping stuff
  long duration, cm;
  // send a ping
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  // listen for a return
  duration = pulseIn(echo, HIGH);
  // convert the time of the ping into cm
  cm = microsecondsToCentimeters(duration);
  // put random in a variable
  randNumber = random(0, 2);

  // the avoidance stuff
  // filter out values less than 1 and greater than 20 cm
  if ((cm > 1) && (cm < 40)){
    // based on randNumber turn left (0) or right(1)
    if (randNumber == 0){
      backLeft();
    }
    if (randNumber == 1){
        backRight();
    }
  } else { // if there isn't anything in front just go straight
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    delay(150);
  }
}

/*
 function that converts the ping time reading to distance
*/
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds /29 / 2;
}
