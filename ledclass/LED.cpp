#include "LED.h"        //로컬에서 정의한 거라 다름.
#include <Arduino.h>    //#include <Servo.h> 제공해주는 표준 라이브러리
//Servo myServo; => LED myLed(13); 해서 myLed.on()만 하고 13을 따로 호출 안 해줘도 켜지게 하려고 만듦. 3

LED::LED(int p)
{
  pin = p;
}

void LED::begin()
{
  pinMode(pin, OUTPUT);
}

void LED::on()
{
  digitalWrite(pin, HIGH);
}

void LED::off()
{
  digitalWrite(pin, LOW);
}