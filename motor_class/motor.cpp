#include "MOTOR.h"
#include <Arduino.h>

MOTOR::MOTOR(int aia, int aib)
{
  motor_aia = aia;
  motor_aib = aib;
}

void MOTOR::begin()
{
  pinMode(motor_aia, OUTPUT);
  pinMode(motor_aib, OUTPUT);
}

void MOTOR::forward()
{
  digitalWrite(motor_aia, HIGH);
  digitalWrite(motor_aib, LOW); 
  //forward(int speed) {analogWrite(motor_aia, speed); analogWrite(motor_aib, speed);}
}

void MOTOR::stop()
{
  digitalWrite(motor_aia, LOW);
  digitalWrite(motor_aib, LOW);
}

void MOTOR::backward()
{
  digitalWrite(motor_aia, LOW);
  digitalWrite(motor_aib, HIGH);
}