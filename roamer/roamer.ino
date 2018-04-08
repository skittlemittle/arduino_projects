// an obstacle avoiding robot
// wiring diagrams and assembly guides can be found here: https://aaalearn.mystagingwebsite.com/2018/03/arduino-camp/

long randNumber; // used to store the random number

// assign the motor controller pins
int ea = 0; //enable a
// motor one
int a1 = 1;
int a2 = 2;
int eb = 5; // enable b
// motor two
int b2 = 6;
int b1 = 7;
int V = 3; // power to the motor controller
int G = 4; // ground to the motor controller
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
  pinMode(ea, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(G, INPUT);
  pinMode(eb, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b1, OUTPUT);
  /*
    analog input 0 is used as a random noise source 
    to seed the random number genrator.
    the analog noise that analog 0 picks up
    is the source of randomness
  */
  randomSeed(analogRead(5));
  // turn the motor driver on and enable both motors
  digitalWrite(ea, HIGH);
  digitalWrite(eb, HIGH);
  digitalWrite(V, HIGH);
  digitalWrite(G, LOW);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

// the main loop
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
  if (cm > 1){
    if (cm < 20){
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
