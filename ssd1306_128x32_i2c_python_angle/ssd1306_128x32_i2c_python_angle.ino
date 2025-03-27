#include <SPI.h> // SPI 라이브러리 포함
#include <Wire.h> // I2C 라이브러리 포함
#include <Adafruit_GFX.h> // Adafruit 그래픽 라이브러리 포함
#include <Adafruit_SSD1306.h> // Adafruit SSD1306 OLED 디스플레이 라이브러리 포함

#define SCREEN_WIDTH 128 // OLED 디스플레이의 너비를 128 픽셀로 정의
#define SCREEN_HEIGHT 32 // OLED 디스플레이의 높이를 32 픽셀로 정의

#define OLED_RESET     -1 // OLED 디스플레이의 리셋 핀을 정의하지 않음
#define SCREEN_ADDRESS 0x3C // OLED 디스플레이의 I2C 주소
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // OLED 디스플레이 객체 생성

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // 디스플레이 초기화 시도
    Serial.println(F("SSD1306 allocation failed")); // 디스플레이 초기화 실패 시 메시지 출력
    for(;;); // 무한 루프에 빠져 프로그램 중지
  }

  display.display(); // 디스플레이를 켜고 초기화 내용을 표시
  delay(2000); // 2초간 대기
  display.clearDisplay(); // 디스플레이 내용 지우기
  display.display(); // 디스플레이를 다시 켜기
  delay(2000); // 2초간 대기
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 입력이 있는지 확인
    String angle = Serial.readStringUntil('\n'); // 시리얼 입력을 줄 단위로 읽기
    display.clearDisplay(); // 디스플레이 내용 지우기
    display.setTextSize(1); // 텍스트 크기를 1로 설정
    display.setTextColor(SSD1306_WHITE); // 텍스트 색상을 흰색으로 설정
    display.setCursor(0, 0); // 커서를 디스플레이의 시작 위치로 이동
    display.println("Angle 1:"); // "Angle 1:" 텍스트를 디스플레이에 출력
    display.setTextSize(1); // 텍스트 크기를 1로 설정 (다시 설정하는 이유는 크기를 변경할 수 있기 때문)
    display.println(angle); // 시리얼로 받은 각도 값을 디스플레이에 출력
    display.display(); // 디스플레이에 출력된 내용을 실제로 표시
    delay(10); // 10ms 대기
  }
}
