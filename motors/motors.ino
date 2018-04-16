// makes a DC motor spin one direction for a second then the other

// assign the motor controller pins
int a1 = 2; // motor a pin 1
int a2 = 3; // motor a pin 2
int ea = 4; // enable motor a
int V = 5; // power to the motor controller
int G = 6; // ground to the motor controller

void setup() {
  // setup the motor controller pins
  pinMode(ea, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(G, INPUT);

  digitalWrite(ea, HIGH); // turn on motor a
  // power on the controller board
  digitalWrite(V, HIGH);
  digitalWrite(G, LOW);
}

void loop() {
  // turn on pin 1 and turn off pin 2
  // the motor spins one way
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  delay(1000); // let it spin for a second
  // turn off pin 1 and turn on pin 2
  // the motor spins the other way
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  delay(1000); // let it spin for a second
}
