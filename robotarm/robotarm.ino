#include <Servo.h> // 서보 모터 제어를 위한 Servo 라이브러리 포함

Servo servo1;  // 첫 번째 서보
Servo servo2;  // 두 번째 서보
Servo servo3;  // 고정 서보

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  servo1.attach(9);  // 첫 번째 서보가 연결된 핀
  servo2.attach(10); // 두 번째 서보가 연결된 핀
  servo3.attach(11); // 고정 서보가 연결된 핀 (원점 고정)
  
  // 고정 서보를 원점(0도)으로 설정
  servo3.write(0);
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 입력이 있는지 확인
    String angles = Serial.readStringUntil('\n'); // 각도를 문자열로 읽기
    int separatorIndex = angles.indexOf(','); // 쉼표를 기준으로 두 각도 분리

    if (separatorIndex > 0) { // 유효한 입력인지 확인
      // 각도를 문자열에서 추출
      String angle1_str = angles.substring(0, separatorIndex);
      String angle2_str = angles.substring(separatorIndex + 1);

      int angle1 = angle1_str.toInt(); // 첫 번째 각도 변환
      int angle2 = angle2_str.toInt(); // 두 번째 각도 변환

      angle1 = constrain(angle1, 0, 180); // 각도를 0-180 범위로 제한
      angle2 = constrain(angle2, 0, 180); // 각도를 0-180 범위로 제한

      servo1.write(angle1); // 첫 번째 서보에 각도 적용
      servo2.write(angle2); // 두 번째 서보에 각도 적용

      Serial.print("Servo1 Angle: "); // 첫 번째 서보 각도 출력
      Serial.print(angle1); // 첫 번째 서보 각도 출력
      Serial.print(" | Servo2 Angle: "); // 두 번째 서보 각도 출력
      Serial.println(angle2); // 두 번째 서보 각도 출력
    }
  }
}
