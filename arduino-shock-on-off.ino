#include <Time.h>

// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;  // the number of the LED pin

// constants won't change:
const int inPin = 7;
const int relayPin = 2;

// Variables will change:
int openSeconds = 1;  // duration to switch on
long lastShockTime = 0;

void setup() {
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  pinMode(relayPin, OUTPUT);

}

void loop() {
  int val = digitalRead(inPin);
  if (val == 1) {
    lastShockTime = millis();

    //Turn on the led
    Serial.println("Open!!!");
    digitalWrite(ledPin, HIGH);
    digitalWrite(relayPin, HIGH);
  }

  if ((lastShockTime + 1000 * openSeconds) < millis()) {
    //Turn off the led
    Serial.println("Close!!!");
    digitalWrite(ledPin, LOW);
    digitalWrite(relayPin, LOW);
  }
}
