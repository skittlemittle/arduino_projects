/*
 A cap that beeps buzzers or provides haptic feedback based on how far objects are from it.
 It uses three ultrasonic rangefinders on the rim of the cap to tell how far stuff is from it.
 This codes github repo: https://github.com/afshaan4/other_arduino_projects
*/

// Right rangefinder 
const int rTrig = 12;
const int rEcho = 11;

// Middle rangefinder
const int mTrig = 10;
const int mEcho = 9;

// Left rangefinder
const int lTrig = 8;
const int lEcho = 7;

// The feedback devices (buzzers or vibration motors)
const int rBuzz = 5;
const int mBuzz = 3;
const int lBuzz = 7;

void setup() {
	// set the feedback devices as outputs
	pinMode(rBuzz, OUTPUT);
	pinMode(mBuzz, OUTPUT);
	pinMode(lBuzz, OUTPUT);
	// rangefinder stuff
	pinMode(rTrig, OUTPUT);
	pinMode(mTrig, OUTPUT);
	pinMode(lTrig, OUTPUT);
	pinMode(rEcho, INPUT);
	pinMode(mEcho, INPUT);
	pinMode(lEcho, INPUT);

	// for debugging
	Serial.begin(9600);
}

void loop() {

  long rDuration, rCm; // used to calculate distance for right sensor
  long mDuration, mCm; // used to calculate distance for middle sensor
  long lDuration, lCm; // used to calculate distance for left sensor

  /*
  send a ping on the right sensor
  */
  digitalWrite(rTrig, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(rTrig, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(rTrig, LOW); // pull it low again

  // store the time it takes for the ping to return
  rDuration = pulseIn(rEcho, HIGH);
  // convert the time it takes into centimeters
  rCm = microsecondsToCentimeters(rDuration);

 /*
  send a ping on the left sensor
  */
  digitalWrite(lTrig, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(lTrig, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(lTrig, LOW); // pull it low again

  // store the time it takes for the ping to return
  lDuration = pulseIn(lEcho, HIGH);
  // convert the time it takes into centimeters
  lCm = microsecondsToCentimeters(lDuration);

  /*
  send a ping on the middle sensor
  */
  digitalWrite(mTrig, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(mTrig, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(mTrig, LOW); // pull it low again

  // store the time it takes for the ping to return
  mDuration = pulseIn(mEcho, HIGH);
  // convert the time it takes into centimeters
  mCm = microsecondsToCentimeters(mDuration);

  /*
    turn on the right buzzer if it sees anything 
  */
  if ((rCm > 1) and (rCm < 100)) { // ignore stuff closer than 1 cm and further than 100 cm.
    digitalWrite(rBuzz, HIGH);
    delay(rCm * 10);
    digitalWrite(rBuzz, LOW);
    delay(rCm * 10);
    Serial.print(rCm);
    Serial.println("rCm");
  }

  /*
    turn on the left buzzer if it sees anything 
  */
  if ((lCm > 1) and (lCm < 100)) { // ignore stuff closer than 1 cm and further than 100 cm.
    digitalWrite(lBuzz, HIGH);
    delay(lCm * 10);
    digitalWrite(lBuzz, LOW);
    delay(lCm * 10);
    Serial.print(lCm);
    Serial.println("lCm");
  }  

  /*
    turn on the middle buzzer if it sees anything 
  */
  if ((mCm > 1) and (mCm < 100)) { // ignore stuff closer than 1 cm and further than 100 cm.
    digitalWrite(mBuzz, HIGH);
    delay(mCm * 10);
    digitalWrite(mBuzz, LOW);
    delay(mCm * 10);
    Serial.print(mCm);
    Serial.println("mCm");
  }
}


/*
function that converts the ping time reading to distance
*/
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance traveled.
  return microseconds /29 / 2;
}