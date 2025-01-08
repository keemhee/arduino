//https://shawnhymel.com/1675/arduino-websocket-server-using-an-esp32/
//  websockets library by Markus Sattler
// hardware independent ->  여기도 쓰이고 저기도 쓰일 수 있다. esp tcp에도 되고, arduino wifi에도 됨.
// web이라 얘는 http로 돌아감. string data. 사진도 색상정보를 문자열로 변환해서 전송.
// websocket이 tcp보다 많이 쓰임. tcp가 직관적이긴한데 직접 프로그램으로 다루기엔 한계가 많음. onEvent이건 것도 안 됨. 끊기면 답이 없음. 끊긴 걸 확인할 방법도 없음.
// websocket은 onEvent에 다 넣으면 됨. 
// 웹소켓의 전문가가 되어봐!

#include <WiFi.h>
#include <WebSocketsServer.h>
#define ssid  "ConnectValue_A402_2G"
#define password   "CVA402!@#$"

WebSocketsServer webSocket = WebSocketsServer(80); //webSocket은 class. 얘는 소프트웨어다. 객체만듦

// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) //이 함수를 구현하도록 되어있음
{

  // Figure out the type of WebSocket event
  switch(type) {

    // Client has disconnected
    case WStype_DISCONNECTED:           //Event Driven
      Serial.printf("[%u] Disconnected!\n", num);
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        Serial.println(ip.toString());
      }
      break;

    // Echo text message back to client
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload);
      webSocket.sendTXT(num, payload);   // 여기에 프린트하고 다시 보냄. loop back?
      break;

    // For everything else: do nothing
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
  // Start Serial port
  Serial.begin(115200);
  // Connect to access point
  Serial.println("Connecting");
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  // Print our IP address
  Serial.println("Connected!");
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());
  // Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);  //이벤트 함수. 
}

void loop() {

  // Look for and handle WebSocket data
  webSocket.loop();
}