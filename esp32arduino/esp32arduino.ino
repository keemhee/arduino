#include <SoftwareSerial.h> // 소프트웨어 시리얼 라이브러리 포함

// 소프트웨어 시리얼 핀 설정 (7번 TX, 8번 RX)
SoftwareSerial mySerial(7, 8);

void setup() {
  Serial.begin(115200);  // 시리얼 모니터 시작
  mySerial.begin(9600);  // ESP32와의 소프트웨어 시리얼 시작
  Serial.println("Arduino SoftwareSerial 통신 시작"); // 초기화 메시지 출력
  pinMode(13, OUTPUT);  // 13번 핀을 출력 모드로 설정 (LED 핀)
}

void loop() { 
  // 수신 데이터 확인
  if (mySerial.available() > 0) {
    char c = mySerial.read();  // 수신된 데이터 읽기
    Serial.print("수신된 문자: "); // 수신된 문자 출력
    Serial.println(c);

    if (c == 'a') {
      digitalWrite(13, HIGH);  // 13번 핀에 HIGH 신호를 보내 LED 켜기
      Serial.println("LED 켜짐"); // LED 켜짐 메시지 출력
    } else if (c == 'b') {
      digitalWrite(13, LOW);   // 13번 핀에 LOW 신호를 보내 LED 끄기
      Serial.println("LED 꺼짐"); // LED 꺼짐 메시지 출력
    }
  }
  
  // ESP32로 데이터 전송
  mySerial.println("Hello from Arduino Uno"); // ESP32로 문자열 전송
  delay(1000); // 1초 대기
}
