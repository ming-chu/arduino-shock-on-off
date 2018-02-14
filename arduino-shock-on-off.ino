// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;  // the number of the LED pin

// constants won't change:
const int inPin = 7;

// Variables will change:
int openSeconds = 3;  // duration to switch on



void setup() {
  Serial.begin(9600);
  
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
    int val = digitalRead(inPin);
    if (val == 1) {
      digitalWrite(ledPin, HIGH);
      Serial.println("Open!!!");
      delay(1000 * openSeconds);
      digitalWrite(ledPin, LOW);
      Serial.println("Close!!!");
    }
}
