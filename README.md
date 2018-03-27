# Arduino Projects
A few projects made to teach Arduino, from the basics to making simple robots.

## Blinking an LED:
Blinks an LED with one second intervals.
Put a 220ohm resistor between the LED's power pin and pin 13 on the Arduino
(a 1k resistor will work fine too).

**Parts:**

* An Arduino.
* An LED (optional, Arduinos have one already).

**Wiring**

Arduino      |     LED
-------------|-------------
Pin 13       |     Anode(power)
GND          |     Cathode(ground)

**Diagram:**

![blink](https://raw.githubusercontent.com/afshaan4/other_arduino_projects/master/circuit_diagrams/blink.png)

## LED waves:
Turns on and off LED's in a sequence, making a wave.

**Parts:**

* An Arduino.
* 6 LED's.

**Wiring**

Arduino      |     LED's
-------------|-------------
Pin 3        |     LED 1
Pin 5        |     LED 2
Pin 6        |     LED 3
Pin 9        |     LED 4
Pin 10       |     LED 5
Pin 11       |     LED 6
GND          |     GND

**Diagram:**

![wave](https://raw.githubusercontent.com/afshaan4/other_arduino_projects/master/circuit_diagrams/led_wave.png)

## Interfacing with buttons:
Turn on and off an LED with a button.

* *button:*  turn the LED on when the button is held down, and off when it is released.
* *button2:* turn the LED on when the button is pressed and keep it on after it's released.
* *button2_improved:* same as button2 but with improvements.
* *button2_debouncing:* same as button2_improved, with debouncing to remove noise.

**Parts:**

* An Arduino.
* A button.
* An LED.

**Wiring**

Arduino     |     Button
------------|--------------
Pin7        |     Pin 1
PWR         |     Pin 2

Arduino     |     LED
------------|--------------
Pin13       |     Power
GND         |     GND

**Diagrams:**

![button](https://raw.githubusercontent.com/afshaan4/other_arduino_projects/master/circuit_diagrams/button.png)

## Using motors:
Controlling DC motors with an Arduino.
Makes the motor spin one way for a while then the other way.

*pins 0 & 1 on the Arduino are used to upload sketches to it and we are using
them for the motor controller, so to prevent noise in the upload process
disconnect the motor controller pins going to pins 0 and 1*

**Parts:**

* An Arduino.
* A [DC motor](https://duckduckgo.com/?q=DC+motor&t=ffab&atb=v100-7&iar=images&iax=images&ia=images&iai=http%3A%2F%2Fshop.rabtron.co.za%2Fcatalog%2Fimages%2FMM10.jpg).
* A L293 motor driver board(using the L293D chip).

**Wiring**

Arduino     |     Motor driver
------------|-------------------
Pin0        |     Enable motor a
Pin1        |     Motor a pin 1
Pin2        |     Motor a pin 2
Pin3        |     PWR
Pin4        |     GND

## motion alarm:
Senses motion, triggers an alarm; put it in random doorways
and wait for your victims to be [bamboozled.](https://pics.onsizzle.com/you-thought-was-slug-but-was-dogco-bamboozled-again-always-6281922.png)

**Parts:**

* An LED.
* A Pir motion sensor like this one: https://www.adafruit.com/product/189
* An Arduino

**Wiring**

Arduino     |     LED & sensor
------------|-----------------
pin 13      |     LED
pin 2       |     Input from the Pir sensor
GND         |     GND

## rangefinder:
A rangefinder using an [HC-SR04](https://www.sparkfun.com/products/13959) ultrasonic distance sensor.

**Parts:**

* An [HC-SR04](https://www.sparkfun.com/products/13959) ultrasonic sensor.
* An Arduino.
* LED's/buzzer.

**Wiring**

Arduino     |     HC-SR04
------------|-----------------
pin 12      |     Trigger (ping)
pin 11      |     Echo (input)
GND         |     GND
PWR         |     PWR

Arduino     |     LED/buzzer
------------|---------------
Pin13       |     Power
GND         |     GND

## roamer:
A robot car with an ultrasonic sensor that avoids objects in front of it.

**Parts:**

* An [HC-SR04](https://www.sparkfun.com/products/13959) ultrasonic sensor.
* A L293 motor driver board(based on the L293D chip).
* Two DC motors.
* An Arduino.

**Wiring**

Arduino     |     Motor driver
------------|-----------------
pin 0       |     Enable motor a
pin 1       |     Motor a pin 1
pin 2       |     Motor a pin 2
pin 3       |     PWR
pin 4       |     GND
pin 5       |     Enable motor b
pin 6       |     Motor b pin 2
pin 7       |     Motor b pin 1

Arduino     |     HC-SR04
------------|-----------------
pin 12      |     Trigger (ping)
pin 11      |     Echo (input)
GND         |     GND
PWR         |     PWR
