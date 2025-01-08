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

int count = 0;         // 푸쉬업 개수 카운트
bool flag = false;     // 푸쉬업 완료 여부를 저장하는 플래그
int lastAngle = 0;     // 이전 각도 저장

void setup() {
  Serial.begin(9600);
  servo1.attach(9);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  delay(2000);
}

void loop() {
  if (Serial.available() > 0) {
    int angle1 = Serial.parseInt(); // 각도 값 읽기

    Serial.print("Received angle: ");
    Serial.println(angle1);

    // 각도 값을 0과 180 사이로 제한
    angle1 = constrain(angle1, 0, 180); 

    // 서보 모터에 각도 전송
    servo1.write(angle1);

    // 푸쉬업 카운팅 로직
    if (angle1 < 90 && lastAngle >= 90) {
      // 각도가 90도 이하로 내려갔고, 이전 각도가 90도 이상일 때 카운트 증가
      flag = true; // 푸쉬업 완료 플래그 설정
      count += 1;  // 카운트 증가
      Serial.print("Push-up count: ");
      Serial.println(count);
    } else if (angle1 >= 90) {
      // 각도가 90도 이상일 때 플래그를 초기화
      flag = false; // 푸쉬업 완료 플래그 초기화
    }

    // OLED 디스플레이에 각도 및 푸쉬업 개수 출력
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Angle:");

    
    display.setTextSize(1);
    display.println(angle1);
    display.setCursor(0, 16);
    display.println("Count:");
    display.setTextSize(1);
    display.println(count);
    display.display();

    lastAngle = angle1; // 현재 각도를 이전 각도로 업데이트

    delay(10);
  }
}
