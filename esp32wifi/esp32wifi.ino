// ESP32 기본 STA모드로 WIFI 연결

#include <WiFi.h> // Wi-Fi 라이브러리 포함

const char* ssid = "ConnectValue_A402_2G"; // Wi-Fi SSID 정의
const char* pw = "CVA402!@#$"; // Wi-Fi 비밀번호 정의

void setup() {
  Serial.begin(115200); // 시리얼 통신을 115200 보드레이트로 시작
  Serial.print(ssid); // SSID를 시리얼 모니터에 출력
  Serial.println(F("에 연결 중...")); // "에 연결 중..." 메시지를 시리얼 모니터에 출력

  // 와이파이에 접속
  WiFi.mode(WIFI_STA); // Wi-Fi 모드를 스테이션 모드로 설정
  WiFi.begin(ssid, pw); // 지정된 SSID와 비밀번호를 사용하여 Wi-Fi에 연결 시작

  // 진행 상태 표시
  while(WiFi.status() != WL_CONNECTED){ // Wi-Fi에 연결될 때까지 대기
    delay(500); // 500 밀리초 대기
    Serial.print(F(".")); // 시리얼 모니터에 "."을 출력하여 진행 상태 표시
  }
  // 연결될 때까지 계속 "."을 찍다가 연결되면 연결된 IP를 출력
  Serial.println(); // 줄 바꿈
  Serial.print(F("연결된 IP: ")); // "연결된 IP: " 메시지를 시리얼 모니터에 출력
  Serial.println(WiFi.localIP()); // 연결된 IP 주소를 시리얼 모니터에 출력
}

void loop() {
  // 현재 loop 함수에서는 아무런 동작도 하지 않음
}
