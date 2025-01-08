#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo servo1;

float angle1 = 0;  // 초기 각도
float angle1_filtered = 0;  // 필터링된 각도

// 칼만 필터 관련 변수
float q = 0.001;  // 프로세스 노이즈
float r = 0.01;   // 측정 노이즈
float k = 0;      // 칼만 게인

void setup() {
  Serial.begin(9600);
  servo1.attach(9);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  delay(2000);

  // 칼만 필터 초기화
  angle1_filtered = 0;  // 초기 필터링된 각도
}

float kalman_filter(float angle_measured) {
  // 예측 단계
  angle1_filtered += 0;  // 상태 예측 (여기서는 고정)

  // 업데이트 단계
  k = (angle1_filtered + r) / (angle1_filtered + r);  // 칼만 게인 계산
  angle1_filtered += k * (angle_measured - angle1_filtered);  // 상태 업데이트

  return angle1_filtered;
}

void loop() {
  if (Serial.available() > 0) {
    String angle1_str = Serial.readStringUntil('\n');
    angle1 = angle1_str.toInt();

    angle1 = constrain(angle1, 0, 180);  // 각도 제한

    // 칼만 필터 적용
    angle1_filtered = kalman_filter(angle1);

    servo1.write(angle1_filtered);  // 필터링된 각도로 서보 제어

    // OLED 디스플레이 업데이트
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Angle1:");
    display.setTextSize(1);
    display.println(angle1_filtered);  // 필터링된 각도 표시
    display.display();

    Serial.print("Filtered Angle1: ");
    Serial.println(angle1_filtered);
    
    delay(10);
  }
}
