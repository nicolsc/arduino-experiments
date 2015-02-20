#include "SoftwareSerial.h"


enum {
  IN_PIN = 2,
  OUT_PIN = 13,
  
  SERIAL_BAUD  = 9600,
};

int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
 
// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers
 
void setup()
{
  Serial.begin (SERIAL_BAUD);


  pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);
  digitalWrite(IN_PIN, HIGH);   // turn on the built in pull-up resistor


}
 
void loop()
{
  int switchstate;
 
  reading = digitalRead(IN_PIN);
 
  // If the switch changed, due to bounce or pressing...
  if (reading != previous) {
    // reset the debouncing timer
    time = millis();
  } 
 
  if ((millis() - time) > debounce) {
     // whatever the switch is at, its been there for a long time
     // so lets settle on it!
     switchstate = reading;
 
    digitalWrite(OUT_PIN, switchstate); //Light when tilted
  }

 
  // Save the last reading so we keep a running tally
  previous = reading;
}
