#include <Servo.h>

Servo myServo;  // 서보 객체 생성

int zeroPosition = 90;  // 서보의 기본 영점 위치 (0도에서 180도 사이 값 설정 가능)

void setup() {
  Serial.begin(115200);
  myServo.attach(9);  // 서보모터가 연결된 핀 번호 (예: 9번 핀)
  
  // 영점 위치로 서보모터 이동
  myServo.write(zeroPosition);
  Serial.print("서보모터가 ");
  Serial.print(zeroPosition);
  Serial.println("도 위치에 설정되었습니다.");
}

void loop() {
  // 여기서 추가적인 제어를 할 수 있습니다. 예를 들어 입력 값을 받아서 제어 가능.
}
