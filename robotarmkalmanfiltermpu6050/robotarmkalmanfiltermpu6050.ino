#include <SPI.h> // SPI 라이브러리 포함
#include <Wire.h> // I2C 통신을 위한 Wire 라이브러리 포함
#include <Adafruit_GFX.h> // 아다프루트 GFX 그래픽 라이브러리 포함
#include <Adafruit_SSD1306.h> // 아다프루트 SSD1306 OLED 라이브러리 포함
#include <Servo.h> // 서보 모터 제어를 위한 Servo 라이브러리 포함

#define SCREEN_WIDTH 128 // OLED 디스플레이의 너비 정의
#define SCREEN_HEIGHT 32 // OLED 디스플레이의 높이 정의
#define OLED_RESET     -1 // OLED 디스플레이의 리셋 핀 정의 (리셋 핀이 없는 경우 -1)
#define SCREEN_ADDRESS 0x3C // I2C 주소 정의
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // OLED 디스플레이 객체 생성

Servo servo1; // 서보 객체 생성

float angle1 = 0;  // 초기 각도
float angle1_filtered = 0;  // 필터링된 각도

// 칼만 필터 관련 변수
float q = 0.001;  // 프로세스 노이즈
float r = 0.01;   // 측정 노이즈
float k = 0;      // 칼만 게인

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  servo1.attach(9); // 서보모터가 연결된 핀 번호 (예: 9번 핀)

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // OLED 디스플레이 초기화 시도
    Serial.println(F("SSD1306 allocation failed")); // 초기화 실패 시 에러 메시지 출력
    for(;;); // 무한 루프에 빠져 프로그램 중지
  }

  display.display(); // 초기 화면 표시
  delay(2000); // 2초 대기
  display.clearDisplay(); // 디스플레이 초기화
  display.display(); // 초기화된 화면 표시
  delay(2000); // 2초 대기

  // 칼만 필터 초기화
  angle1_filtered = 0;  // 초기 필터링된 각도
}

float kalman_filter(float angle_measured) {
  // 예측 단계
  angle1_filtered += 0;  // 상태 예측 (여기서는 고정)

  // 업데이트 단계
  k = (angle1_filtered + r) / (angle1_filtered + r);  // 칼만 게인 계산
  angle1_filtered += k * (angle_measured - angle1_filtered);  // 상태 업데이트

  return angle1_filtered; // 필터링된 각도 반환
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 입력이 있는지 확인
    String angle1_str = Serial.readStringUntil('\n'); // 시리얼 입력을 문자열로 읽기
    angle1 = angle1_str.toInt(); // 문자열을 정수로 변환하여 각도 값으로 저장

    angle1 = constrain(angle1, 0, 180);  // 각도 값을 0과 180 사이로 제한

    // 칼만 필터 적용
    angle1_filtered = kalman_filter(angle1); // 입력된 각도를 필터링하여 저장

    servo1.write(angle1_filtered);  // 필터링된 각도로 서보 제어

    // OLED 디스플레이 업데이트
    display.clearDisplay(); // 디스플레이 초기화
    display.setTextSize(1); // 텍스트 크기 설정
    display.setTextColor(SSD1306_WHITE); // 텍스트 색상 설정
    display.setCursor(0, 0); // 커서 위치 설정
    display.println("Angle1:"); // "Angle1:" 텍스트 출력
    display.setTextSize(1); // 텍스트 크기 설정
    display.println(angle1_filtered);  // 필터링된 각도 표시
    display.display(); // 디스플레이 업데이트

    Serial.print("Filtered Angle1: "); // 필터링된 각도 출력 메시지
    Serial.println(angle1_filtered); // 필터링된 각도 출력
    
    delay(10); // 10ms 대기
  }
}
