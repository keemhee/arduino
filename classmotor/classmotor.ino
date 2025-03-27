#include "MOTOR.h" // MOTOR 클래스 포함
MOTOR motor1(11, 10, 100); // 첫 번째 모터 인스턴스 생성 (핀 11, 10, 초기 속도 100)
MOTOR motor2(5, 6, 100); // 두 번째 모터 인스턴스 생성 (핀 5, 6, 초기 속도 100)

void setup() {
  motor1.begin(); // 첫 번째 모터 초기화
  motor2.begin(); // 두 번째 모터 초기화
}

void loop() {
  motor1.on(true); // 첫 번째 모터 켜기
  motor2.on(true); // 두 번째 모터 켜기
  delay(3000); // 3초 대기
  motor1.on(false); // 첫 번째 모터 끄기
  motor2.on(false); // 두 번째 모터 끄기
  delay(3000); // 3초 대기
  motor1.off(); // 첫 번째 모터 완전히 끄기
  motor2.off(); // 두 번째 모터 완전히 끄기
  delay(3000); // 3초 대기
  changeSpeed(50); // 모터 속도 변경 (+50)
  motor1.on(true); // 첫 번째 모터 켜기
  motor2.on(true); // 두 번째 모터 켜기
  delay(3000); // 3초 대기
  motor1.off(); // 첫 번째 모터 끄기
  motor2.off(); // 두 번째 모터 끄기
  delay(3000); // 3초 대기
  changeSpeed(-50); // 모터 속도 원래대로 변경 (-50)
  motor1.on(true); // 첫 번째 모터 켜기
  motor2.on(true); // 두 번째 모터 켜기
  delay(3000); // 3초 대기
  motor1.off(); // 첫 번째 모터 끄기
  motor2.off(); // 두 번째 모터 끄기
  delay(3000); // 3초 대기
}
