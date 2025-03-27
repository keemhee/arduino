// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int distance = 0; // 변수 distance를 0으로 초기화
int red = 3;     // 빨간색 LED 핀 번호
int green = 5;   // 초록색 LED 핀 번호
int blue = 6;    // 파란색 LED 핀 번호

void setup() {
  Serial.begin(9600); // 시리얼 모니터를 9600 baud로 열어 핑 결과를 확인
  pinMode(red, OUTPUT);   // 빨간색 LED 핀을 출력 모드로 설정
  pinMode(green, OUTPUT); // 초록색 LED 핀을 출력 모드로 설정
  pinMode(blue, OUTPUT);  // 파란색 LED 핀을 출력 모드로 설정
}

void loop() {
  delay(50);                     // 핑 사이의 간격을 50ms로 설정 (약 20회/초 핑). 29ms는 핑 사이의 최소 간격
  Serial.print("Ping: ");
  distance = sonar.ping_cm(); // 핑을 보내고, 반환된 거리 (cm)를 저장 (0 = 설정된 거리 범위 외)
  Serial.print(distance);
  Serial.println("cm");
  
  int state= map(distance, 0, MAX_DISTANCE, 1, 3); // 거리를 1에서 3 사이의 값으로 매핑
//  if (distance > 200)
//  {
//    state = 3;
//  }
//  else if (distance <= 30)
//  {
//    state = 1;
//  }
//  else if ((distance>30) && (distance <= 170))
//  {
//    state = 2;
//  }

  switch (state) // 매핑된 state 값에 따라 LED 색상을 변경
  {
    case 1 : // state가 1인 경우
      Serial.println("war");
      analogWrite(red, 255);   // 빨간색 LED 최대 밝기
      analogWrite(green, 0);   // 초록색 LED 끄기
      analogWrite(blue, 0);    // 파란색 LED 끄기
      break;
    case 2 : // state가 2인 경우
      Serial.println("be prepare");
      analogWrite(red, 255);   // 빨간색 LED 최대 밝기
      analogWrite(green, 255); // 초록색 LED 최대 밝기
      analogWrite(blue, 0);    // 파란색 LED 끄기
      break;
    case 3 : // state가 3인 경우
      Serial.println("relax");
      analogWrite(red, 255);   // 빨간색 LED 최대 밝기
      analogWrite(green, 255); // 초록색 LED 최대 밝기
      analogWrite(blue, 255);  // 파란색 LED 최대 밝기
      break;
    default : // 기본 상태 (어떤 case에도 해당하지 않는 경우)
      analogWrite(red,0);      // 빨간색 LED 끄기
      analogWrite(green, 0);   // 초록색 LED 끄기
      analogWrite(blue, 0);    // 파란색 LED 끄기
      break;
  }
}
