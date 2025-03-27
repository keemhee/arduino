// WiFi 서버

#include <WiFi.h> // Wi-Fi 라이브러리 포함

const char* ssid = "ConnectValue_A402_2G"; // Wi-Fi SSID 정의
const char* pw = "CVA402!@#$"; // Wi-Fi 비밀번호 정의

WiFiServer server(80); // Wi-Fi 서버 객체 생성, 포트 80 사용

void setup(){
  Serial.begin(115200); // 시리얼 통신 시작 (115200 보드레이트)
  Serial.print(ssid); // SSID 출력
  Serial.println(F("에 연결 중...")); // 연결 중 메시지 출력

  // 고정 IP 설정
  IPAddress ip (172, 30, 1, 167); // 고정 IP 주소 설정
  IPAddress gateway (172, 30, 1, 254); // 게이트웨이 설정
  IPAddress subnet (255, 255, 255, 0); // 서브넷 마스크 설정
  WiFi.config(ip, gateway, subnet); // Wi-Fi 설정 적용

  // Wi-Fi 접속 설정
  WiFi.mode(WIFI_STA); // Wi-Fi 모드를 스테이션 모드로 설정
  WiFi.begin(ssid, pw); // Wi-Fi 연결 시작

  // Wi-Fi 연결 완료 대기
  while(WiFi.status() != WL_CONNECTED){
    delay(500); // 500밀리초 대기
    Serial.print(F(".")); // 연결 시도 표시
  }
  Serial.println(); // 줄 바꿈
  Serial.print(F("연결된 IP: ")); // 연결된 IP 주소 출력
  Serial.println(WiFi.localIP()); // 로컬 IP 주소 출력

  // Wi-Fi 서버 시작
  server.begin();
  Serial.println(F("Server started")); // 서버 시작 메시지 출력
}

void loop(){
  // 클라이언트가 접속하면 클라이언트 객체를 반환
  WiFiClient client = server.available(); // 서버가 열리면 클라이언트 객체 대입

  // 클라이언트가 접속하지 않으면 루프를 새로 시작
  if(!client){
    return;
  }
  Serial.println(F("새 클라가 접속했음.")); // 클라이언트 접속 메시지 출력

  // 클라이언트 요청 읽기
  String request = client.readStringUntil('\n'); // 요청 내용을 한 줄 읽음
  Serial.println(request); // 요청 내용 출력

  // 서버에서 클라이언트로 응답 전송
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=utf-8\r\n\r\n<!DOCTYPE HTML><html><body>"));
  client.print(F("<table border=1 width=400><tr><td colspan=2>Response from server"));
  //client.print((val) ? F("high") : F("low")); // LED 제어 코드 (나중에 구현 가능)
  client.print(F("</td></tr><tr><td width=200>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/switch/0'>SW0</a>")); // SW0 링크 추가
  client.print(F("</td><td width=200>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/switch/1'>SW1</a>")); // SW1 링크 추가
  client.print(F("</td></tr></table></body></html>"));

  // 클라이언트 접속 종료
  Serial.println(F("클라가 접속을 종료함")); // 접속 종료 메시지 출력
  client.stop(); // 클라이언트 접속 강제 종료
}
