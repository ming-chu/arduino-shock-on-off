#include <Time.h>

// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;  // the number of the LED pin

// constants won't change:
const int inPin = 7;

// Variables will change:
int openSeconds = 3;  // duration to switch on
long lastShockTime = 0;

void setup() {
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);

}

void loop() {
  int val = digitalRead(inPin);
  if (val == 1) {
    lastShockTime = millis();

    //Turn on the led
    Serial.println("Open!!!");
    digitalWrite(ledPin, HIGH);
  }

  if ((lastShockTime + 1000 * 3) < millis()) {
    //Turn off the led
    Serial.println("Close!!!");
    digitalWrite(ledPin, LOW);
  }
}
