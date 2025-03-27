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

int count = 0;         // 푸쉬업 개수 카운트
bool flag = false;     // 푸쉬업 완료 여부를 저장하는 플래그
int lastAngle = 0;     // 이전 각도 저장

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  servo1.attach(9); // 서보모터가 연결된 핀 번호 (예: 9번 핀)

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // OLED 디스플레이 초기화 시도
    Serial.println(F("SSD1306 allocation failed")); // 초기화 실패 시 에러 메시지 출력
    for (;;); // 무한 루프에 빠져 프로그램 중지
  }

  display.display(); // 초기 화면 표시
  delay(2000); // 2초 대기
  display.clearDisplay(); // 디스플레이 초기화
  display.display(); // 초기화된 화면 표시
  delay(2000); // 2초 대기
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 입력이 있는지 확인
    int angle1 = Serial.parseInt(); // 각도 값 읽기

    Serial.print("Received angle: "); // 수신된 각도 출력 메시지
    Serial.println(angle1); // 수신된 각도 값 출력

    // 각도 값을 0과 180 사이로 제한
    angle1 = constrain(angle1, 0, 180); 

    // 서보 모터에 각도 전송
    servo1.write(angle1);

    // 푸쉬업 카운팅 로직
    if (angle1 < 90 && lastAngle >= 90) { // 각도가 90도 이하로 내려갔고, 이전 각도가 90도 이상일 때
      flag = true; // 푸쉬업 완료 플래그 설정
      count += 1;  // 카운트 증가
      Serial.print("Push-up count: "); // 푸쉬업 개수 출력 메시지
      Serial.println(count); // 푸쉬업 개수 출력
    } else if (angle1 >= 90) { // 각도가 90도 이상일 때
      flag = false; // 푸쉬업 완료 플래그 초기화
    }

    // OLED 디스플레이에 각도 및 푸쉬업 개수 출력
    display.clearDisplay(); // 디스플레이 초기화
    display.setTextSize(1); // 텍스트 크기 설정
    display.setTextColor(SSD1306_WHITE); // 텍스트 색상 설정
    display.setCursor(0, 0); // 커서 위치 설정
    display.println("Angle:"); // "Angle:" 텍스트 출력
    
    display.setTextSize(1); // 텍스트 크기 설정
    display.println(angle1); // 각도 값 출력
    display.setCursor(0, 16); // 커서 위치 설정
    display.println("Count:"); // "Count:" 텍스트 출력
    display.setTextSize(1); // 텍스트 크기 설정
    display.println(count); // 푸쉬업 개수 출력
    display.display(); // 디스플레이 업데이트

    lastAngle = angle1; // 현재 각도를 이전 각도로 업데이트

    delay(10); // 10ms 대기
  }
}
