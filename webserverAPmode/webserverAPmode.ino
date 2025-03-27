// MIT 라이선스에 대한 설명
/*MIT License

Copyright (c) 2024 JD edu. http://jdedu.kr author: conner.jeong@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

// 모터를 제어할 수 있는 기능을 포함하고 있습니다. 일단 LED 깜빡임부터 구현합니다.
#include <WiFi.h> // WiFi 라이브러리 포함
#include <WebServer.h> // 웹서버 라이브러리 포함

#define M1_B    26 // 모터 A의 핀 번호 정의
#define M1_A    27 // 모터 B의 핀 번호 정의

#define FORWARD   1 // 모터 전진 상태 정의
#define BACKWARD  2 // 모터 후진 상태 정의
#define STOP      3 // 모터 정지 상태 정의

#define LED 2 // 1021 수업 시 추가된 LED 핀 번호 정의

/* WiFi SSID와 패스워드 설정 */
const char* ssid = "esp32-khj";  // 여기서 SSID를 입력 // WiFi로 연결하면 인터넷은 없지만 로컬 연결은 됩니다.
const char* password = "123456789";  // 여기서 패스워드를 입력

/* IP 주소 설정 */
IPAddress local_ip(192,168,1,1); // 주소창에 숫자를 입력하면 ESP32 웹 서버 창이 뜹니다.
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0); // 메인 IP로 설정합니다.

int motor_status = STOP; // 모터 상태 초기화

WebServer server(80); // 웹 서버를 설정합니다. 80은 포트 번호입니다.

// 모터 제어 함수들
void go_forward(){
  Serial.println("forward"); // 전진 상태 출력
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, HIGH);
}

void go_backward(){
  Serial.println("backward"); // 후진 상태 출력
  digitalWrite(M1_A, HIGH);
  digitalWrite(M1_B, LOW);
}

void stop(){
  Serial.println("stop"); // 정지 상태 출력
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, LOW);
  delay(200);
}

void setup() {
  Serial.begin(115200); // 시리얼 통신 시작

  pinMode(M1_A, OUTPUT); // 모터 A 핀 출력 설정
  pinMode(M1_B, OUTPUT); // 모터 B 핀 출력 설정
  pinMode(LED, OUTPUT); // LED 핀 출력 설정
  stop(); // 초기 상태 정지

  WiFi.softAP(ssid, password); // AP 모드 설정
  WiFi.softAPConfig(local_ip, gateway, subnet); // IP 구성 설정
  delay(100);
  
  server.on("/", handle_OnConnect); // 루트 경로로 접속 시 handle_OnConnect 함수 실행
  server.on("/forward", handle_forward); // /forward 경로로 접속 시 handle_forward 함수 실행
  server.on("/backward", handle_backward); // /backward 경로로 접속 시 handle_backward 함수 실행
  server.on("/stop", handle_stop); // /stop 경로로 접속 시 handle_stop 함수 실행
  server.onNotFound(handle_NotFound); // 찾을 수 없는 경로로 접속 시 handle_NotFound 함수 실행
  
  server.begin(); // 서버 시작
  Serial.println("HTTP server started"); // 서버 시작 메시지 출력
}

void loop() {
  server.handleClient(); // 클라이언트 요청 처리
}

void handle_OnConnect() {
  stop(); // 접속 시 모터 정지
  Serial.println("motor stop");
  server.send(200, "text/html", SendHTML(motor_status)); // HTML 페이지 전송
}

void handle_forward() {
  // go_forward(); // 모터 전진
  digitalWrite(LED,HIGH); // LED 켜기
  motor_status = FORWARD; // 모터 상태 전진으로 변경
  Serial.println("motor forward");
  server.send(200, "text/html", SendHTML(motor_status)); // HTML 페이지 전송
}

void handle_backward() {
  go_backward(); // 모터 후진
  motor_status = BACKWARD; // 모터 상태 후진으로 변경
  Serial.println("motor backward");
  server.send(200, "text/html", SendHTML(motor_status)); // HTML 페이지 전송
}

void handle_stop() {
  digitalWrite(LED, LOW); // LED 끄기
  //stop(); // 모터 정지
  motor_status = STOP; // 모터 상태 정지로 변경
  Serial.println("motor stop");
  server.send(200, "text/html", SendHTML(motor_status)); // HTML 페이지 전송
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found"); // 404 에러 페이지 전송
}

// 웹 서버 HTML 페이지 생성 함수
String SendHTML(uint8_t motor_status){
  // HTML 문서의 시작을 선언
  String ptr = "<!DOCTYPE html> <html>\n";
  // HTML 헤드 섹션 시작, 뷰포트 메타 태그 추가
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  // 웹 페이지 제목 설정
  ptr +="<title>LED Control</title>\n";
  // HTML 스타일(CSS) 섹션 시작
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  // HTML 바디 스타일 설정
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  // 버튼 스타일 설정
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  // 단락 스타일 설정
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  // 스타일 섹션 종료
  ptr +="</style>\n";
  // 헤드 섹션 종료
  ptr +="</head>\n";
  // 바디 섹션 시작
  ptr +="<body>\n";
  // 페이지 제목 설정
  ptr +="<h1>ESP32 Web Server</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";

  // 모터 상태에 따른 HTML 내용 설정
  switch(motor_status){
    case 1: // 모터 전진 상태일 때
      {ptr +="<p>Motor forward</p><a class=\"button button-on\" href=\"/forward\">ON</a>\n";}
      {ptr +="<p>Motor backward</p><a class=\"button button-off\" href=\"/backward\">OFF</a>\n";}
      {ptr +="<p>stop</p><a class=\"button button-off\" href=\"/stop\">OFF</a>\n";}
      break;
    case 2: // 모터 후진 상태일 때
      {ptr +="<p>Motor forward</p><a class=\"button button-off\" href=\"/forward\">OFF</a>\n";}
      {ptr +="<p>Motor backward</p><a class=\"button button-on\" href=\"/backward\">ON</a>\n";}
      {ptr +="<p>stop</p><a class=\"button button-off\" href=\"/stop\">OFF</a>\n";}
      break;
    case 3: // 모터 정지 상태일 때
      {ptr +="<p>Motor forward</p><a class=\"button button-off\" href=\"/forward\">OFF</a>\n";}
      {ptr +="<p>Motor backward</p><a class=\"button button-off\" href=\"/backward\">OFF</a>\n";}
      {ptr +="<p>stop</p><a class=\"button button-on\" href=\"/stop\">ON</a>\n";}
      break;
  }
  // 바디 섹션 종료
  ptr +="</body>\n";
  // HTML 문서 종료
  ptr +="</html>\n";
  // HTML 문자열 반환
  return ptr;
}
