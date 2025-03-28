#define RXD2 16  // RX 핀 정의
#define TXD2 17  // TX 핀 정의

void setup() {
  Serial.begin(115200);  // 시리얼 모니터를 115200 보드레이트로 시작
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);  // Serial2 포트를 9600 보드레이트, 8비트 데이터, 패리티 없음, 1비트 스톱으로 설정하여 시작
  Serial.println("ESP32 Serial2 통신 시작");  // 시리얼 모니터에 초기화 메시지 출력
}

void loop() {
  static bool sendA = true;  // 'a'와 'b'를 교대로 보내기 위한 플래그 변수

  if (sendA) {  // sendA가 true인 경우
    Serial2.print('a');  // Serial2 포트로 'a' 문자 전송
    Serial.println("a 전송");  // 시리얼 모니터에 "a 전송" 메시지 출력
  } else {  // sendA가 false인 경우
    Serial2.print('b');  // Serial2 포트로 'b' 문자 전송
    Serial.println("b 전송");  // 시리얼 모니터에 "b 전송" 메시지 출력
  }

  sendA = !sendA;  // sendA 플래그를 반전하여 다음 루프에서 다른 문자를 전송
  delay(2000);  // 2초 대기

  if (Serial2.available() > 0) {  // Serial2 포트에 수신된 데이터가 있는지 확인
    String received = Serial2.readString();  // 수신된 데이터를 문자열로 읽기
    Serial.print("수신된 데이터: ");  // 시리얼 모니터에 "수신된 데이터: " 메시지 출력
    Serial.println(received);  // 수신된 데이터를 시리얼 모니터에 출력
  }
}
