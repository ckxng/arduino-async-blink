// set clock to 1MHz; 1 microsecond = 1 clock cycle
#define F_CPU 1000000L

#include "asyncBlink.h"

int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ckxng::asyncBlink::blink(led, 100);
  delay(10);
}
