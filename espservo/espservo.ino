#include <WiFi.h>
#include <WebServer.h>
#include <Servo.h>

#define SSID "ConnectValue_A402_2G"
#define PASSWORD "CVA402!@#$"
#define SERVO_PIN 13 // 서보 모터 핀

Servo myServo;
WebServer server(80); // HTTP 서버 생성

void handleRoot() {
    String html = "<html><body>";
    html += "<h1>Control Servo Motor</h1>";
    html += "<button onclick=\"location.href='/0'\">Move to 0 degrees</button><br>";
    html += "<button onclick=\"location.href='/90'\">Move to 90 degrees</button><br>";
    html += "</body></html>";
    server.send(200, "text/html", html);
}

void moveServo(int angle) {
    myServo.write(angle);
}

void handleServo0() {
    moveServo(0);
    server.sendHeader("Location", "/"); // root로 리다이렉션
    server.send(303);
}

void handleServo90() {
    moveServo(90);
    server.sendHeader("Location", "/"); // root로 리다이렉션
    server.send(303);
}

void setup() {
    Serial.begin(115200);
    myServo.attach(SERVO_PIN);
    myServo.write(0); // 초기 위치 설정

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/0", handleServo0);
    server.on("/90", handleServo90);
    server.begin();
}

void loop() {
    server.handleClient();
}
