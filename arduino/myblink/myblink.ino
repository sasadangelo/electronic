/*
  Copyright (c) 2025 Salvatore D'Angelo

  Released under the MIT License:
  https://opensource.org/licenses/MIT
*/
const int ledPin = 8;

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin 8 as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(ledPin, HIGH); // turn the LED on the pin 8 on (HIGH is the voltage level)
  delay(1000);                // wait for a second
  digitalWrite(ledPin, LOW);  // turn the LED on the pin 8  off by making the voltage LOW
  delay(1000);                // wait for a second
}
