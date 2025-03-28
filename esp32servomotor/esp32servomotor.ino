#include <WiFi.h> // Wi-Fi 라이브러리 포함
#include <WebServer.h> // 웹 서버 라이브러리 포함
#include <Servo.h> // 서보 모터 라이브러리 포함

#define M1_B    26 // 모터 B 핀 정의
#define M1_A    27 // 모터 A 핀 정의

#define FORWARD   1 // 앞으로 이동 상태 정의
#define BACKWARD  2 // 뒤로 이동 상태 정의
#define STOP      3 // 정지 상태 정의

#define LED 2 // LED 핀 정의

Servo myservo; // 서보 모터 객체 생성

const char* ssid = "esp32-k"; // Wi-Fi SSID 정의
const char* password = "123456789"; // Wi-Fi 비밀번호 정의

IPAddress local_ip(192,168,1,1); // 고정 IP 주소 정의
IPAddress gateway(192,168,1,1); // 게이트웨이 IP 주소 정의
IPAddress subnet (255,255,255,0); // 서브넷 마스크 정의

int motor_status = STOP; // 모터 초기 상태를 정지로 설정

WebServer server(80); // 웹 서버 객체 생성 (포트 80)

/*void go_forward(){
  Serial.println("forward");
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, HIGH);
}

void go_backward(){
  Serial.println("backward");
  digitalWrite(M1_A, HIGH);
  digitalWrite(M1_B, LOW);
}

void stop(){
  Serial.println("stop");
  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, LOW);
  delay(200);
}*/

void setup() {
  Serial.begin(115200); // 시리얼 통신을 115200 보드레이트로 시작

  pinMode(M1_A, OUTPUT); // 모터 A 핀을 출력 모드로 설정
  pinMode(M1_B, OUTPUT); // 모터 B 핀을 출력 모드로 설정
  pinMode(LED, OUTPUT); // LED 핀을 출력 모드로 설정

  myservo.attach(18); // 서보 모터 핀을 18번 핀에 연결 (수정된 부분)

  stop(); // 모터 정지 함수 호출

  WiFi.softAP(ssid, password); // ESP32를 액세스 포인트 모드로 설정하여 Wi-Fi 네트워크 시작
  WiFi.softAPConfig(local_ip, gateway, subnet); // 고정 IP 주소 설정
  delay(100); // 100 밀리초 대기

  server.on("/", handle_OnConnect); // 루트 URL 요청 처리 함수 등록
  server.on("/forward", handle_forward); // "/forward" URL 요청 처리 함수 등록
  server.on("/backward", handle_backward); // "/backward" URL 요청 처리 함수 등록
  server.on("/stop", handle_stop); // "/stop" URL 요청 처리 함수 등록
  server.onNotFound(handle_NotFound); // 존재하지 않는 URL 요청 처리 함수 등록
  
  server.begin(); // 웹 서버 시작
  Serial.println("HTTP server started"); // 서버 시작 메시지 출력
}

void loop() {
  server.handleClient(); // 클라이언트 요청 처리
}

/*void handle_OnConnect() {
  stop();
  Serial.println("motor stop");
  server.send(200, "text/html", SendHTML(motor_status)); 
}

void handle_forward() {
  //go_forward();
  //digitalWrite(LED,HIGH);
  motor_status = FORWARD;
  Serial.println("motor forward");
  server.send(200, "text/html", SendHTML(motor_status)); 
}

void handle_backward() {
  go_backward();
  motor_status = BACKWARD;
  Serial.println("motor backward");
  server.send(200, "text/html", SendHTML(motor_status)); 
}

void handle_stop() {
  //digitalWrite(LED, LOW);
  //stop();
  motor_status = STOP;
  Serial.println("motor stop");
  server.send(200, "text/html", SendHTML(motor_status)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}*/

String SendHTML(uint8_t motor_status){
  String ptr = "<!DOCTYPE html> <html>\n"; // HTML 시작 태그
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n"; // 메타 태그와 뷰포트 설정
  ptr +="<title>LED Control</title>\n"; // HTML 문서의 제목 설정
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n"; // 스타일 태그 시작
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n"; // 기본 스타일 설정
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n"; // 버튼 스타일 설정
  ptr +=".button-on {background-color: #3498db;}\n"; // 버튼 활성화 상태 스타일
  ptr +=".button-on:active {background-color: #2980b9;}\n"; // 버튼 활성화 상태에서 클릭 시 스타일
  ptr +=".button-off {background-color: #34495e;}\n"; // 버튼 비활성화 상태 스타일
  ptr +=".button-off:active {background-color: #2c3e50;}\n"; // 버튼 비활성화 상태에서 클릭 시 스타일
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n"; // 단락 스타일 설정
  ptr +="</style>\n"; // 스타일 태그 종료
  ptr +="</head>\n"; // 헤드 태그 종료
  ptr +="<body>\n"; // 바디 태그 시작
  ptr +="<h1>ESP32 Web Server</h1>\n"; // 제목 출력
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n"; // 부제목 출력

  switch(motor_status){
    case 1:
      {ptr +="<p>Servo motor</p><a class=\"button button-on\" href=\"/forward\">ON</a>\n";} // 서보 모터가 앞으로 이동 중일 때 버튼 생성
      /*{ptr +="<p>Motor backward</p><a class=\"button button-off\" href=\"/backward\">OFF</a>\n";}
      {ptr +="<p>stop</p><a class=\"button button-off\" href=\"/stop\">OFF\n";}
      */break;
    case 2:
      {ptr +="<p>Servo motor</p><a class=\"button button-off\" href=\"/forward\">OFF</a>\n";} // 서보 모터가 뒤로 이동 중일 때 버튼 생성
      /*{ptr +="<p>Motor backward</p><a class=\"button button-on\" href=\"/backward\">ON\</a>\n";}
      {ptr +="<p>stop</p><a class=\"button button-off\" href=\"/stop\">OFF\n";}
      */break;
    case 3:
      {ptr +="<p>Servo motor</p><a class=\"button button-off\" href=\"/forward\">OFF\</a>\n";} // 서보 모터가 정지 상태일 때 버튼 생성
      /*{ptr +="<p>Motor backward</p><a class=\"button button-off\" href=\"/backward\">OFF\</a>\n";}
      {ptr +="<p>stop</p><a class=\"button button-on\" href=\"/stop\">ON</a>\n";}
      */break;
  }
  ptr +="</body>\n"; // 바디 태그 종료
  ptr +="</html>\n"; // HTML 종료 태그
  return ptr; // 생성된 HTML 문자열 반환
}
