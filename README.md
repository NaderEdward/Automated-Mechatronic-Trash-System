# Automated Mechatronic Trash Bin

This is a personal project which I have made in collaboration with my sister in order to experiment with combining physical sensors, motors and an Arduino into an interactive trash bin; the project takes the form of a mini basketball arcade game since when trash is thrown through the hoop the distance sensor picks it up and two motorised wheels draw the trash down into the bin.

I developed this project in order to gain experience in combining hardware and software and also to carry out some experiments with automated physical interactions. 

My sister helped me by designing the exterior artwork and structure of the bin.

## Features

* **Basketball-style trash disposal**  
  The bin is designed to look like a small basketball arcade game in order to lure users into shooting their rubbish through the hoop.

* **Pop-Up QR Code Reward**  
  The ultrasonic sensor registers the score when an object goes through the hoop and then causes two DC motors to push the extended QR code panel out of the top frame.

* **Interactive Scanning Period**  
  The motorized mechanism keeps the QR code display visible for five seconds so that the user is able to scan it—for example, to access the digital web features or to keep track of the score—before automatically pulling it back inside the bin.

* **Bi-Directional Motor Control**  
  The motors are made to move forward in order to extend the panel and are then reversed to retract it when the scanning period is over.

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

## Coding Logic

I programmed the Arduino in C++:
The HC-SR04 ultrasonic sensor constantly checks for any objects passing within 15 cm of the rim.
When the Arduino detects the situation it causes the motors to operate using PWM (at a speed of 220) in order to eject the QR code extension mechanism.
The system keeps the display extended for five seconds before reversing the motor's direction in order to retract the module and re-arm the sensor loop.

## Authors

* [@NaderEdward](https://github.com/NaderEdward)
