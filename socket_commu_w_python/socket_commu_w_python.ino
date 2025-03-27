#include <WiFi.h> // WiFi 라이브러리 포함

#define ssid  "ConnectValue_A402_2G" // WiFi SSID 정의
#define password   "CVA402!@#$" // WiFi 비밀번호 정의

void setup() {
    Serial.begin(115200); // 시리얼 통신을 115200 baud로 시작
    WiFi.begin(ssid, password); // WiFi 연결 시도
    while (WiFi.status() != WL_CONNECTED) { // WiFi가 연결될 때까지 대기
        delay(500); // 500ms 대기
        Serial.println("."); // 연결 대기 중임을 표시
    }
    Serial.print("WiFi connected with IP:"); // WiFi 연결 성공 메시지 출력
    Serial.println(WiFi.localIP()); // 로컬 IP 주소 출력
}

int count = 0; // 카운터 변수 초기화
void loop() {
    WiFiClient client; // WiFi 클라이언트 객체 생성
    if(!client.connect(IPAddress(172,30,1,10), 10000)){ // 지정된 IP 주소와 포트로 서버에 연결 시도
    // if (!client.connect("192.168.1.68", 10000)) { // 다른 서버 IP 주소와 포트로 연결 시도 (주석 처리됨)
        Serial.println("Connection to host failed"); // 호스트 연결 실패 메시지 출력
        delay(1000); // 1초 대기
        return; // 함수 종료
    }
    //Serial.println("client connected sending packet"); // 클라이언트 연결 및 패킷 전송 메시지 (주석 처리됨)
    if(Serial.available()>0){ // 시리얼 입력이 있는지 확인
        char c = Serial.read(); // 시리얼 입력을 읽음
        if(c == 'a'){ // 입력이 'a'인 경우
            client.print("'a' is sent!"); // 클라이언트로 'a' 전송
        }else if(c == 'b'){ // 입력이 'b'인 경우
            client.print("'b' is sent!"); // 클라이언트로 'b' 전송
        }else if(c == 'c'){ // 입력이 'c'인 경우
            client.print("uga uga"); // 클라이언트로 "uga uga" 전송
        }
    } 
    //count ++; // 카운터 증가 (주석 처리됨)
    //client.print(count); // 카운터 값을 클라이언트로 전송 (주석 처리됨)
    client.stop(); // 클라이언트 연결 종료
    delay(100); // 100ms 대기
}
