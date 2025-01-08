#include "MOTOR.h"

MOTOR MOTOR(5, 6);

void setup() {
  motor.begin();
}

void loop() {
  motor.forward();
  delay(100);
  motor.stop();
  delay(100);
  motor.backward();
}
