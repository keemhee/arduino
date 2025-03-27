#include "LED.h" // LED 클래스의 헤더 파일을 포함합니다.

LED myLed(13); // 핀 13에 연결된 LED 객체를 생성합니다.

void setup() {
  myLed.begin(); // LED를 초기화합니다.
}

void loop() {
  myLed.on(); // LED를 켭니다.
  delay(1000); // 1초 동안 대기합니다.
  myLed.off(); // LED를 끕니다.
  delay(1000); // 1초 동안 대기합니다.
}
