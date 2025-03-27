void setup() {
  Serial.begin(115200); // 시리얼 통신을 115200 보드레이트로 시작

  pinMode(encoder_R, INPUT_PULLUP); // 오른쪽 인코더 핀을 풀업 입력 모드로 설정
  pinMode(encoder_L, INPUT_PULLUP); // 왼쪽 인코더 핀을 풀업 입력 모드로 설정

  attachInterrupt(digitalPinToInterrupt(encoder_R), encoder_R_ISR, FALLING); // 오른쪽 인코더의 인터럽트를 FALLING 모드로 설정
  attachInterrupt(digitalPinToInterrupt(encoder_L), encoder_L_ISR, FALLING); // 왼쪽 인코더의 인터럽트를 FALLING 모드로 설정

  start_time = millis(); // 프로그램 시작 시의 시간을 기록
  stop_flag = false; // 정지 플래그를 초기화
}

void loop() {
  if (!stop_flag) { // 정지 플래그가 설정되지 않았을 때
    forward(speed_R, speed_L); // 모터를 앞으로 움직임
    Serial.print("speed_R: "); // 오른쪽 모터 속도를 시리얼 모니터에 출력
    Serial.println(speed_R); 
    Serial.print("speed_L: "); // 왼쪽 모터 속도를 시리얼 모니터에 출력
    Serial.println(speed_L);
    Serial.println("");
  } else { // 정지 플래그가 설정되었을 때
    stopAll(); // 모터를 정지시킴
  }
  time_curr = millis(); // 현재 시간을 기록
  if (time_curr - time_prev >= 100) { // 이전 시간과의 차이가 100밀리초 이상일 때
    time_prev = time_curr; // 이전 시간을 현재 시간으로 업데이트
    speed_correct(); // 속도 보정 함수 호출
  }
  delay(50); // 50밀리초 대기
}
