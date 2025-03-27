//https://shawnhymel.com/1675/arduino-websocket-server-using-an-esp32/
//  websockets library by Markus Sattler
// hardware independent ->  여기도 쓰이고 저기도 쓰일 수 있다. esp tcp에도 되고, arduino wifi에도 됨.
// web이라 얘는 http로 돌아감. string data. 사진도 색상정보를 문자열로 변환해서 전송.
// websocket이 tcp보다 많이 쓰임. tcp가 직관적이긴한데 직접 프로그램으로 다루기엔 한계가 많음. onEvent이건 것도 안 됨. 끊기면 답이 없음. 끊긴 걸 확인할 방법이 없음.
// websocket은 onEvent에 다 넣으면 됨. 
// 웹소켓의 전문가가 되어봐!

#include <WiFi.h> // WiFi 라이브러리 포함
#include <WebSocketsServer.h> // WebSocketsServer 라이브러리 포함
#define ssid  "ConnectValue_A402_2G" // WiFi SSID 정의
#define password   "CVA402!@#$" // WiFi 비밀번호 정의

WebSocketsServer webSocket = WebSocketsServer(80); //웹소켓 서버 객체 생성, 포트 80 사용

// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) //이 함수를 구현하도록 되어있음
{
  // 웹소켓 이벤트의 종류를 판별
  switch(type) {
    // 클라이언트가 연결 해제됨
    case WStype_DISCONNECTED: //Event Driven
      Serial.printf("[%u] Disconnected!\n", num); // 연결 해제 로그 출력
      break;
    // 새로운 클라이언트가 연결됨
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num); // 클라이언트의 IP 주소 가져오기
        Serial.printf("[%u] Connection from ", num); // 연결된 클라이언트 번호 출력
        Serial.println(ip.toString()); // 클라이언트 IP 주소 출력
      }
      break;
    // 클라이언트로부터 텍스트 메시지 수신
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload); // 수신된 텍스트 메시지 출력
      webSocket.sendTXT(num, payload); // 클라이언트에게 메시지 에코
      break;
    // 그 외의 경우에는 아무것도 하지 않음(클라어언트로부터 바이너리 메시지 수신/ 웹소켓 에러 발생/ 텍스트 메시지 분할 시작/ 바이너리 메시지 분할 시작/ 메시지 분할 중/ 메시지 분할 완료/ 그 외의 경우)
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}

void setup() {
  // 시리얼 포트 시작
  Serial.begin(115200);
  // 액세스 포인트에 연결
  Serial.println("Connecting");
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500); // 연결 시도 중 지연
    Serial.print("."); // 연결 시도 중 표시
  }
  // IP 주소 출력
  Serial.println("Connected!");
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());
  // 웹소켓 서버 시작 및 콜백 할당
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent); //이벤트 함수.
}

void loop() {
  // 웹소켓 데이터 처리
  webSocket.loop();
}
