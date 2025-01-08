void setup() {
  Serial.begin(115200);

  pinMode(encoder_R, INPUT_PULLUP);
  pinMode(encoder_L, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoder_R), encoder_R_ISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoder_L), encoder_L_ISR, FALLING);

  start_time = millis();
  stop_flag = false;
}

void loop() {
  if (!stop_flag) {
    forward(speed_R, speed_L);
    Serial.print("speed_R: ");
    Serial.println(speed_R);
    Serial.print("speed_L: ");
    Serial.println(speed_L);
    Serial.println("");
  } else {
    stopAll();
  }
  time_curr = millis();
  if (time_curr - time_prev >= 100) {
    time_prev = time_curr;
    speed_correct();
  }
  delay(50);
}