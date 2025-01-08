// WiFi 서버

#include <WiFi.h>

const char* ssid = "ConnectValue_A402_2G";
const char* pw = "CVA402!@#$";

WiFiServer server(80); //wifi 기본포트 80. 웹소켓은 81

void setup(){
  Serial.begin(115200);
  Serial.print(ssid);
  Serial.println(F("에 연결 중..."));

  //고정 IP 만들어서 접속. 내부ip이기 때문에 고정으로 설정가능(esp32기계에서 쓰는 거니까)
  IPAddress ip (172, 30, 1, 167);
  IPAddress gateway (172, 30, 1, 254);
  IPAddress subnet (255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);

  //WiFi 접속
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pw);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.print(F("연결된 IP: "));
  Serial.println(WiFi.localIP());

  //WIFI서버 시작
  server.begin();
  Serial.println(F("Server started")); //중간중간 알려주는 거 넣어주기

}

void loop(){
  //서버에 클라가 접속하면 클라 객체를 리턴받아서 client에 대입
  WiFiClient client = server.available(); //서버 열리면 서버는 listening 상태. client가 먼저 서버에 연락

  //클라가 접속을 안 하면 루프를 새로 시작. 접속할 때까지 무한 대기 반복. 
  if(!client){
    return;
  }
  Serial.println(F("새 클라가 접속했음.")); //if문을 지났다는 걸 접속했다는 것.

  //요청 사항 읽어오기. 한줄
  String request = client.readStringUntil('\n');
  Serial.println(request);

  //서버->클라(172.30.1.111): Response
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=utf-8\r\n\r\n<!DOCTYPE HTML><html><body>"));
  client.print(F("<table border=1 width=400><tr><td colspan=2>Response from server"));
  //client.print((val) ? F("high") : F("low")); //LED용 켜고/끄기 코드. 나중에 구현.
  client.print(F("</td></tr><tr><td width=200>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/switch/0'>SW0</a>")); //sw0누르면 이 웹주소로 가고
  client.print(F("</td><td width=200>"));
  client.print(F("<a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/switch/1'>SW1</a>")); // sw1누르면 이 웹주소로 간다.
  client.print(F("</td></tr></table></body></html>"));

  //클라가 서버에 response를 수신하면 클라가 자동으로 몇 초 후 접속 종료
  Serial.println(F("클라가 접속을 종료함"));
  client.stop(); //안 해도 끊기는데 안 될 수도 있어서 강제종료
}