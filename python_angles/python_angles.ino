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

Servo servo1; // 첫 번째 서보 모터 객체 생성
//Servo servo2; // 두 번째 서보 모터 객체 생성 (현재 주석 처리됨)

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  servo1.attach(9); // 첫 번째 서보모터가 연결된 핀 설정
  //servo2.attach(10); // 두 번째 서보모터가 연결된 핀 설정 (현재 주석 처리됨)

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // OLED 디스플레이 초기화 시도
    Serial.println(F("SSD1306 allocation failed")); // 초기화 실패 시 에러 메시지 출력
    for(;;); // 무한 루프에 빠져 프로그램 중지
  }

  display.display(); // 초기 화면 표시
  delay(2000); // 2초 대기
  display.clearDisplay(); // 디스플레이 초기화
  display.display(); // 초기화된 화면 표시
  delay(2000); // 2초 대기
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 입력이 있는지 확인
    int angle1 = Serial.parseInt(); // 시리얼 입력으로부터 첫 번째 각도 값 읽기
    //int angle2 = Serial.parseInt(); // 시리얼 입력으로부터 두 번째 각도 값 읽기 (현재 주석 처리됨)
    
    Serial.print("Received angles: "); // 수신된 각도 출력 메시지
    Serial.print(angle1); // 첫 번째 각도 출력
    //Serial.print(", "); // 각도 구분 출력 (현재 주석 처리됨)
    //Serial.println(angle2); // 두 번째 각도 출력 (현재 주석 처리됨)

    angle1 = constrain(angle1, 0, 180); // 첫 번째 각도를 0-180 범위로 제한
    //angle2 = constrain(angle2, 0, 180); // 두 번째 각도를 0-180 범위로 제한 (현재 주석 처리됨)

    servo1.write(angle1); // 첫 번째 서보모터에 각도 적용
    //servo2.write(angle2); // 두 번째 서보모터에 각도 적용 (현재 주석 처리됨)

    display.clearDisplay(); // 디스플레이 초기화
    display.setTextSize(1); // 텍스트 크기 설정
    display.setTextColor(SSD1306_WHITE); // 텍스트 색상 설정
    display.setCursor(0, 0); // 커서 위치 설정
    display.println("Angle1:"); // "Angle1:" 텍스트 출력
    display.setTextSize(1); // 텍스트 크기 설정
    display.println(angle1); // 첫 번째 각도 값 출력
    //display.println("Angle2:"); // "Angle2:" 텍스트 출력 (현재 주석 처리됨)
    //display.setTextSize(1); // 텍스트 크기 설정 (현재 주석 처리됨)
    //display.println(angle2); // 두 번째 각도 값 출력 (현재 주석 처리됨)
    display.display(); // 디스플레이 업데이트

    delay(10); // 10ms 대기
  }
}
