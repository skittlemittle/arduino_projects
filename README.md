# other_arduino_projects
A set of projects made to teach Arduino.

## motion_alarm

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

==========================================================

## roamer

A car robot with an ultrasonic sensor that avoids objects in front of it.

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

==========================================================
