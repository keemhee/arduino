#include <SoftwareSerial.h>

// 소프트웨어 시리얼 핀 설정 (7번 TX, 8번 RX)
SoftwareSerial mySerial(7, 8);

void setup() {
  Serial.begin(115200);  // 시리얼 모니터 시작
  mySerial.begin(9600);  // ESP32와의 소프트웨어 시리얼 시작
  Serial.println("Arduino SoftwareSerial 통신 시작");
  pinMode(13, OUTPUT);  // LED 핀 설정
}

void loop() { 
  // 수신 데이터 확인
  if (mySerial.available() > 0) {
    char c = mySerial.read();  // 수신된 데이터 읽기
    Serial.print("수신된 문자: ");
    Serial.println(c);

    if (c == 'a') {
      digitalWrite(13, HIGH);  // LED 켜기
      Serial.println("LED 켜짐");
    } else if (c == 'b') {
      digitalWrite(13, LOW);   // LED 끄기
      Serial.println("LED 꺼짐");
    }
  }
  
  // ESP32로 데이터 전송
  mySerial.println("Hello from Arduino Uno");
  delay(1000);
}
