const int led = 16; // LED 핀을 16으로 설정
const int toucher = 4; // GPIO4 핀을 터치 센서로 설정
int ledState = LOW; // LED의 초기 상태를 LOW로 설정 (꺼짐)
int touchThreshold = 20; // 터치 감지 임계값을 20으로 설정
int touchDetected = false; // 터치 감지 상태를 초기화

void setup() {
  pinMode(led, OUTPUT); // LED 핀을 출력 모드로 설정
  Serial.begin(115200); // 시리얼 통신을 115200 보드레이트로 시작
}

void loop() {
  int touchValue = touchRead(toucher); // 터치 센서의 값을 읽음
  if (touchValue < touchThreshold && !touchDetected) { // 터치 센서가 임계값보다 낮고 터치가 감지되지 않았을 때
    Serial.println("Touch Detected"); // "Touch Detected" 메시지를 시리얼 모니터에 출력
    ledState = !ledState; // LED 상태를 반전시킴
    digitalWrite(led, ledState); // LED 상태를 설정
    touchDetected = true; // 터치 감지 상태를 true로 설정
    delay(300); // 300밀리초 대기
  }
  // 터치가 감지된 상태에서 손을 뗄 때
  if (touchValue >= touchThreshold && touchDetected) {
    touchDetected = false; // 터치 감지 상태를 false로 설정
  }
  delay(50); // 50밀리초 대기
}
