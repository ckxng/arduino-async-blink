# arduino-async-blinc
an example of tracking pin states and blinking lights from a loop

## Description

The purpose of this project is to demonstrate how to use a linked list on an Arduino.  If pin 13 is used on an Arduino development board (the LED pin), then no wiring is required to demonstrate this project.

## ckxng::asyncBlink::blink(led, time)

The first time this is called, it add the pin indicated by _led_ to a linked list and set the pin state to LOW.  When it is called again, it will compare the current timestamp with the timestamp of the last time the state was changed.  If _time_ milliseconds have passed, the state will be flipped from LOW to HIGH or HIGH to LOW.
