int h_red = 5;   // 횡단보도 빨간불 핀 번호
int h_green = 8; // 횡단보도 초록불 핀 번호
int c_red = 9;   // 차량 빨간불 핀 번호
int c_yellow = 10; // 차량 노란불 핀 번호
int c_green = 11;  // 차량 초록불 핀 번호

void setup() {
  pinMode(h_red, OUTPUT);   // 횡단보도 빨간불 핀을 출력 모드로 설정
  pinMode(h_green, OUTPUT); // 횡단보도 초록불 핀을 출력 모드로 설정
  pinMode(c_red, OUTPUT);   // 차량 빨간불 핀을 출력 모드로 설정
  pinMode(c_yellow, OUTPUT);// 차량 노란불 핀을 출력 모드로 설정
  pinMode(c_green, OUTPUT); // 차량 초록불 핀을 출력 모드로 설정
  
  // 초기 설정 코드 작성 부분
}

void loop() {
  digitalWrite(h_red, HIGH);   // 횡단보도 빨간불 켜기
  digitalWrite(h_green, LOW);  // 횡단보도 초록불 끄기
  digitalWrite(c_yellow, LOW); // 차량 노란불 끄기
  digitalWrite(c_green, HIGH); // 차량 초록불 켜기
  digitalWrite(c_red, LOW);    // 차량 빨간불 끄기
  delay(1000);                 // 1초 대기
  digitalWrite(h_red, LOW);    // 횡단보도 빨간불 끄기
  digitalWrite(c_green, LOW);  // 차량 초록불 끄기
  digitalWrite(c_yellow, HIGH);// 차량 노란불 켜기
  delay(1000);                 // 1초 대기
  digitalWrite(c_yellow, LOW); // 차량 노란불 끄기
  digitalWrite(c_red, HIGH);   // 차량 빨간불 켜기
  digitalWrite(h_green, HIGH); // 횡단보도 초록불 켜기
  delay(1000);                 // 1초 대기
  // 메인 코드 작성 부분 (반복 실행)
}
