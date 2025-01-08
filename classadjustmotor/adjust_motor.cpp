#include "adjust_motor.h"
#include <Arduino.h>

ADJUSTMOTOR::ADJUSTMOTOR(){}

void ADJUSTMOTOR::begin(){
  pinMode(encoder_R, OUTPUT);
  pinMode(encoder_L, OUTPUT);
}

void ADJUSTMOTOR::encoder_R_ISR() {
  encoder_R_cnt++;
}

void ADJUSTMOTOR::encoder_L_ISR() {
  encoder_L_cnt++;
}

void ADJUSTMOTOR::speed_correct() {
  static int encoder_R_cnt_last = 0;
  static int encoder_L_cnt_last = 0;

  delta_R = encoder_R_cnt - encoder_R_cnt_last;
  delta_L = encoder_L_cnt - encoder_L_cnt_last;

  encoder_R_cnt_last = encoder_R_cnt;
  encoder_L_cnt_last = encoder_L_cnt;

  int diff = delta_R - delta_L;

  int correction_factor = 1;

  if (diff > 0) {
    speed_R -= diff * correction_factor;
    speed_L += diff * correction_factor;
    if (speed_R < 0) speed_R = 0;
    if (speed_L > 255) speed_L = 255;

  } else if (diff < 0) {
    speed_R += -diff * correction_factor;
    speed_L -= -diff * correction_factor;
    if (speed_R > 255) speed_R = 255;
    if (speed_L < 0) speed_L = 0;
  }
}


