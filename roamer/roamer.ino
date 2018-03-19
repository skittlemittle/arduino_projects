//Copyright (c) 2018 Afshaan Londhe
//this software is licensed under the MIT license
//which can be found here: https://mit-license.org/
//this code can be found here: https://github.com/afshaan4/random-arduino-code

long randNumber; //load random to a long

//assign the h-bridge pins
int ea = 0; //enable a
//motor one
int a1 = 1;
int a2 = 2;
int eb = 5; //enable b
//motor two
int b2 = 6;
int b1 = 7;
int V = 3; //power to the h-bridge
int G = 4; //ground to the h-bridge
//the ping pins
const int pingO = 12;
const int pingI = 11;

//turns back left
void backLeft() {
  //back up for a second
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000);
  //stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
  //turn left for a second
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
  delay(1000);
  //stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
}

//turn right
void backRight() {
  //back up for a second
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000);
  //stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
  //turn right for a second
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  delay(1000);
  //stop the motors
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
  delay(10);
}

//the setup stuff
void setup() {
  //setup the motor controller pins
  pinMode(ea, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(G, INPUT);
  pinMode(eb, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b1, OUTPUT);
  /*
    if analog input pin 0 is unconnected, random analog
    noise will cause the call to randomSeed() to generate
    different seed numbers each time the sketch runs.
    randomSeed() will then shuffle the random function.
  */
  randomSeed(analogRead(5));
  //turn the motor driver on and enable both motors
  digitalWrite(ea, HIGH);
  digitalWrite(eb, HIGH);
  digitalWrite(V, HIGH);
  digitalWrite(G, LOW);
  pinMode(pingO, OUTPUT);
  pinMode(pingI, INPUT);
}

//the main loop
void loop() {
  //the ping stuff
  long duration, cm;
  //send a ping
  digitalWrite(pingO, LOW);
  delayMicroseconds(2);
  digitalWrite(pingO, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingO, LOW);

  //listen for a return
  duration = pulseIn(pingI, HIGH);
  //convert the time of the ping into cm
  cm = microsecondsToCentimeters(duration);
  //put random in a variable
  randNumber = random(0, 2);

  //the avoidance stuff
  if (cm > 1){ //filters values less than 1
    if (cm < 20){ //is something closer than 20 cm
    //based on randNumber turn left (0) or right(1)
      if (randNumber == 0){
        backLeft();
      }
      if (randNumber == 1){
        backRight();
      }
    } else { //if there isnt anything in front just go straight
        digitalWrite(a1, HIGH);
        digitalWrite(a2, LOW);
        digitalWrite(b1, HIGH);
        digitalWrite(b2, LOW);
        delay(150);
    }
  }
}

//convert the ping time reading to distance
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds /29 / 2;//return it
}
