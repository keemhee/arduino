#include "LED.h"

LED myLed(13);

void setup() {
  myLed.begin();

}

void loop() {
  myLed.on();
  delay(1000);
  myLed.off();

}
