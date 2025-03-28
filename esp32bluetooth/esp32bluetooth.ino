#include "BluetoothSerial.h" // Bluetooth 시리얼 라이브러리 포함

BluetoothSerial SerialBT; // Bluetooth 시리얼 객체 생성

void setup() {
  Serial.begin(115200); // 시리얼 통신을 115200 보드레이트로 시작
  SerialBT.begin("khj"); // 블루투스 장치 이름을 "khj"로 설정하여 시작
  Serial.println("The device started, now you can pair it with bluetooth!"); // 블루투스 장치 시작 메시지 출력
  pinMode(2, OUTPUT); // GPIO 2번 핀을 출력 모드로 설정
}

void loop() {
  if (SerialBT.available()) { // 블루투스 시리얼에 데이터가 수신되었는지 확인
    char c = SerialBT.read(); // 수신된 데이터를 읽어 문자 변수 'c'에 저장
    Serial.println(c); // 수신된 문자를 시리얼 모니터에 출력
    if (c == 'f') { // 수신된 문자가 'f'인 경우
      digitalWrite(2, HIGH); // GPIO 2번 핀에 HIGH 신호를 보내 LED 켜기
      delay(1000); // 1초 대기
    } else if (c == 'b') { // 수신된 문자가 'b'인 경우
      digitalWrite(2, LOW); // GPIO 2번 핀에 LOW 신호를 보내 LED 끄기
      delay(1000); // 1초 대기
    }
  }
}
