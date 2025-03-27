#include <WiFi.h> // Wi-Fi 라이브러리 포함
#include <WebServer.h> // 웹 서버 라이브러리 포함
#include <Servo.h> // 서보 모터 라이브러리 포함

#define SSID "ConnectValue_A402_2G" // Wi-Fi SSID 정의
#define PASSWORD "CVA402!@#$" // Wi-Fi 비밀번호 정의
#define SERVO_PIN 13 // 서보 모터 핀 정의

Servo myServo; // 서보 모터 객체 생성
WebServer server(80); // HTTP 서버 객체 생성 (포트 80)

void handleRoot() {
    String html = "<html><body>"; // HTML 시작 태그
    html += "<h1>Control Servo Motor</h1>"; // 제목 추가
    html += "<button onclick=\"location.href='/0'\">Move to 0 degrees</button><br>"; // 0도로 이동 버튼 추가
    html += "<button onclick=\"location.href='/90'\">Move to 90 degrees</button><br>"; // 90도로 이동 버튼 추가
    html += "</body></html>"; // HTML 종료 태그
    server.send(200, "text/html", html); // HTML 페이지 전송
}

void moveServo(int angle) {
    myServo.write(angle); // 서보 모터를 지정된 각도로 이동
}

void handleServo0() {
    moveServo(0); // 서보 모터를 0도로 이동
    server.sendHeader("Location", "/"); // root로 리다이렉션
    server.send(303); // 303 응답 코드 전송
}

void handleServo90() {
    moveServo(90); // 서보 모터를 90도로 이동
    server.sendHeader("Location", "/"); // root로 리다이렉션
    server.send(303); // 303 응답 코드 전송
}

void setup() {
    Serial.begin(115200); // 시리얼 통신 시작 (115200 보드레이트)
    myServo.attach(SERVO_PIN); // 서보 모터 핀에 연결
    myServo.write(0); // 서보 모터 초기 위치 설정 (0도)

    WiFi.begin(SSID, PASSWORD); // Wi-Fi 연결 시작
    while (WiFi.status() != WL_CONNECTED) { // Wi-Fi에 연결될 때까지 대기
        delay(500); // 500밀리초 대기
        Serial.print("."); // 연결 시도 표시
    }
    Serial.println("Connected!"); // 연결 성공 메시지 출력
    Serial.print("IP address: "); // IP 주소 출력
    Serial.println(WiFi.localIP()); // 로컬 IP 주소 출력

    server.on("/", handleRoot); // root URL 처리 등록
    server.on("/0", handleServo0); // "/0" URL 처리 등록
    server.on("/90", handleServo90); // "/90" URL 처리 등록
    server.begin(); // 서버 시작
}

void loop() {
    server.handleClient(); // 클라이언트 요청 처리
}
