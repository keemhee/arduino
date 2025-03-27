#include "MOTOR.h" // MOTOR 클래스의 헤더 파일을 포함합니다.

MOTOR motor(5, 6); // 핀 5와 6에 연결된 모터 객체를 생성합니다.

void setup() {
  motor.begin(); // 모터를 초기화합니다.
}

void loop() {
  motor.forward(); // 모터를 앞으로 이동시킵니다.
  delay(100); // 100밀리초 동안 대기합니다.
  motor.stop(); // 모터를 정지시킵니다.
  delay(100); // 100밀리초 동안 대기합니다.
  motor.backward(); // 모터를 뒤로 이동시킵니다.
}
