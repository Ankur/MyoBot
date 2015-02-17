# MyoBot
Control a servo-robot with Myo.

![demo](http://i.imgur.com/ePohxBT.webm)

Myo ---> Android ---> Arduino

## Prerequisites

* Myo Armband and Android SDK 0.10.0
* Android phone with Bluetooth 4.0 and Lollipop
* HC-06 Bluetooth Module

## Installation

* Add Myo SDK path in```build.gradle``` to ```url '<path to myo SDK>\myorepository'```
* Add your own Serial pins and Servo pins to ```MyoDataParser.ino```
* Build and run Android app
* Upload Arduino Sketch
* Go to bluetooth settings and pair with "HC-06" with pass "1234"

## Usage

* Turn on the Arduino, the HC-06 should be blinking
* Launch Android app and hit "OpenBT"
* Pair with Myo in Scan menu
* Recalibrate to place current arm position at center
* Move your arm from side to side, and recalibrate as needed
