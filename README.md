# Smart Basketball Trash Bin

This is a personal project which I have made in collaboration with my sister in order to experiment with combining physical sensors, motors and an Arduino into an interactive trash bin; the project takes the form of a mini basketball arcade game since when trash is thrown through the hoop the distance sensor picks it up and two motorised wheels draw the trash down into the bin.

I developed this project in order to gain experience in combining hardware and software and also to carry out some experiments with automated physical interactions. 

My sister helped me by designing the exterior artwork and structure of the bin.

## Features

* **Basketball-style trash disposal**
  The bin is in the form of a small basketball arcade game and enables users to throw their trash through the hoop.

* **Automatic trash intake**
  When an object goes through the hoop, an ultrasonic sensor picks this up and the Arduino then switches on two motors which drive the intake wheels and move the trash downwards.

* **Motor control**
  The L298N motor driver is used to control both DC motors, and the motors operate for five seconds once a shot has been detected.

* **Detection lockout**
  Once the motors have stopped, the system waits for five seconds before checking for another shot. This is done in order to avoid the same object being detected more than once.

* **QR code interface**
  A QR code which is printed around the rim can be used for optional digital features such as score tracking or project information.

## Hardware

The Arduino uses the following connections:

| Component           | Arduino Pin |
| ------------------- | ----------: |
| L298N Motor A — IN1 |           2 |
| L298N Motor A — IN2 |           3 |
| L298N Motor B — IN3 |           4 |
| L298N Motor B — IN4 |           5 |
| L298N Motor A — ENA |           6 |
| L298N Motor B — ENB |           7 |
| HC-SR04 — Trigger   |          11 |
| HC-SR04 — Echo      |          12 |

The system is built using an Arduino Uno R3, an HC-SR04 ultrasonic sensor, an L298N motor driver and two TT gear motors; the motors are powered by a DC wall adapter whilst the Arduino handles reading the sensor and controlling the motors.

## Coding Language Used

I used C++ in the Arduino program.

The Arduino keeps on measuring the distance from the ultrasonic sensor; if an object is detected within 15 cm it switches on both motors at a PWM speed of 220 for a period of 5 seconds and then waits an additional 5 seconds before carrying out another detection.

## Authors

* [@NaderEdward](https://github.com/NaderEdward)
