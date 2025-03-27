#include <Servo.h> // Servo 라이브러리 포함

Servo myServo;  // 서보 객체 생성

int zeroPosition = 90;  // 서보의 기본 영점 위치 (0도에서 180도 사이 값 설정 가능)
int currentPosition = zeroPosition; // 현재 위치를 영점 위치로 초기화

void setup() {
  Serial.begin(115200); // 시리얼 통신을 115200 baud로 시작
  myServo.attach(9);  // 서보모터가 연결된 핀 번호 (예: 9번 핀)
  
  // 영점 위치로 서보모터 이동
  myServo.write(zeroPosition); // 서보모터를 zeroPosition 위치로 이동
  Serial.print("서보모터가 ");
  Serial.print(zeroPosition);
  Serial.println("도 위치에 설정되었습니다.");
}

void loop() {
  // 시리얼 입력이 있는지 확인
  if (Serial.available() > 0) {
    // 시리얼로부터 입력 값을 읽음
    int inputAngle = Serial.parseInt();
    
    // 입력 값이 유효한 각도 범위인지 확인 (0도에서 180도 사이)
    if (inputAngle >= 0 && inputAngle <= 180) {
      // 서보모터를 입력 받은 각도로 이동
      myServo.write(inputAngle);
      currentPosition = inputAngle; // 현재 위치를 업데이트
      Serial.print("서보모터가 ");
      Serial.print(inputAngle);
      Serial.println("도 위치에 설정되었습니다.");
    } else {
      Serial.println("유효하지 않은 각도입니다. 0에서 180도 사이의 값을 입력하세요.");
    }
  }

  // 현재 서보모터의 위치를 시리얼 모니터에 출력
  Serial.print("현재 서보모터 위치: ");
  Serial.print(currentPosition);
  Serial.println("도");
  delay(1000); // 1초 대기 (필요에 따라 조정 가능)
}
