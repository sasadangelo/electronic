/*
  Copyright (c) 2025 Salvatore D'Angelo

  Released under the MIT License:
  https://opensource.org/licenses/MIT
*/
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // set the built-in LED as an output
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
  delay(1000);                     // wait for 1000 milliseconds (1 second)
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
  delay(1000);                     // wait for 1000 milliseconds (1 second)
}
