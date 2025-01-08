#include "MOTOR.h"
MOTOR motor1(11,10, 100);
MOTOR motor2(5, 6, 100);

void setup() {
  motor1.begin();
  motor2.begin();

}

void loop() {
  motor1.on(true);
  motor2.on(true);
  delay(3000);
  motor1.on(false);
  motor2.on(false);
  delay(3000);
  motor1.off();
  motor2.off();
  delay(3000);
  changeSpeed(50);
  motor1.on(true);
  motor2.on(true)
  delay(3000);
  motor1.off();
  motor2.off();
  delay(3000);
  changeSpeed(-50);
  motor1.on(true);
  motor2.on(true);
  delay(3000);
  motor1.off();
  motor2.off();
  delay(3000);
}
