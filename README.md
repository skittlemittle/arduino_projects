# Arduino Projects
A set of projects made to teach Arduino.

## Blinking an LED:
Blinks an LED with one second intervals.

**Parts:**

* An Arduino.
* An LED (optional, Arduinos have one already).

**Wiring**

Arduino      |     LED
-------------|-------------
Pin 13       |     Anode(power)
GND          |     Cathode(ground)

## LED waves:
Turns on and off LED's in a sequence making a wave.

**Parts:**

* An Arduino.
* 6 LED's.

**Wiring**

Arduino      |     LEDS
-------------|-------------
Pin 3        |     LED 1
Pin 5        |     LED 2
Pin 6        |     LED 3
Pin 9        |     LED 4
Pin 10       |     LED 5
Pin 11       |     LED 6
GND          |     GND

## Interfacing with buttons:
Turn on and off an LED with a button.

**Parts:**

* An Arduino.
* A button.
* An LED.

**Wiring**

Arduino     |     Button
------------|--------------
Pin         |     Pin 1
PWR         |     Pin 2

Arduino     |     LED
------------|--------------
Pin         |     Power
GND         |     GND

## Using motors:

## A motion alarm:
Senses motion, triggers an alarm; put it in random doorways
and wait for your victims to be [bamboozled](https://pics.onsizzle.com/you-thought-was-slug-but-was-dogco-bamboozled-again-always-6281922.png)

**Parts:**

* An LED.
* A Pir motion sensor like this one: https://www.adafruit.com/product/189
* An Arduino

**Wiring**

Arduino     |     Pir sensor
------------|---------------
pin 13      |     LED
pin 2       |     Input from the Pir sensor


## roamer:
A robot car with an ultrasonic sensor that avoids objects in front of it.

**Parts:**

* HC-SR04 ultrasonic sensor, like this one: https://www.sparkfun.com/products/13959
* L293 Motor Driver(based on the L293D).
* Two DC motors.
* An Arduino.

**Wiring**

Arduino     |     Motor driver
------------|-----------------
pin 0       |     Enable pin a
pin 1       |     Motor pin a1
pin 2       |     Motor pin a2
pin 3       |     PWR
pin 4       |     GND
pin 5       |     Enable pin b
pin 6       |     Motor pin b2
pin 7       |     Motor pin b1

Arduino     |     HC-SR04
------------|-----------------
pin 12      |     Trigger (ping)
pin 11      |     Echo (input)
