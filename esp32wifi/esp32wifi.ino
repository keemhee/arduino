// ESP32 기본 STA모드로 WIFI 연결

#include <WiFi.h>

const char* ssid = "ConnectValue_A402_2G";
const char* pw = "CVA402!@#$";

void setup() {
  Serial.begin(115200);
  Serial.print(ssid);
  Serial.println(F("에 연결 중..."));

  //와이파이에 접속
  WiFi.mode(WIFI_STA); //모드설정.
  WiFi.begin(ssid, pw); 

  //진행 상태 표시
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(F("."));
  //연결될 때까지 계속 .찍다가 연결되면 연결된 IP 를 내놔봐로 넘어감
  }
  Serial.println();
  Serial.print(F("연결된 IP: "));
  Serial.println(WiFi.localIP());
}

void loop() {

}
