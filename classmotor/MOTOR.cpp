#include "MOTOR.h"
#include <Arduino.h>
MOTOR::MOTOR(int f, int b, int s) : fpin(f), bpin(b), speed(s){}
void MOTOR::begin(){
  pinMode(fpin, OUTPUT);
  pinMode(bpin, OUTPUT);
}
void MOTOR::on(bool is_forward){
  if(is_forward) {
    analogWrite(fpin, speed);
    analogWrite(bpin, 0);
  } else {
    analogWrite(fpin, 0);
    analogWrite(bpin, speed);
  }
}
void MOTOR::off(){
  analogWrite(fpin, 0);
  analogWrite(bpin, 0);
}
void MOTOR::changeSpeed(int addnum){
  speed += addnum;
}