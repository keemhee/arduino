#define RXD2 16  // RX 핀
#define TXD2 17  // TX 핀

void setup() {
  Serial.begin(115200);  // Serial Monitor 시작
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);  // Serial2 통신 시작
  Serial.println("ESP32 Serial2 통신 시작");
}

void loop() {
  // 'a' 또는 'b' 전송
  static bool sendA = true;  // 'a'와 'b'를 교대로 보내기 위한 플래그
  
  if (sendA) {
    Serial2.println('a');  // 'a' 전송
    Serial.println("a 전송");
  } else {
    Serial2.println('b');  // 'b' 전송
    Serial.println("b 전송");
  }

  sendA = !sendA;  // 플래그 변경하여 'a'와 'b'를 교대로 전송
  delay(2000);  // 2초 대기

  // 수신 데이터 확인
  if (Serial2.available() > 0) {
    String received = Serial2.readString();
    Serial.print("수신된 데이터: ");
    Serial.println(received);
  }
}
