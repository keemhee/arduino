int button_pin = 7; // 버튼이 연결된 핀 번호를 저장합니다.
int input = 0; // 버튼의 입력 상태를 저장할 변수를 선언합니다.

void setup() {
  Serial.begin(9600); // 시리얼 통신을 시작합니다.
  pinMode(button_pin, INPUT); // 버튼 핀을 입력 모드로 설정합니다.
  pinMode(5, OUTPUT); // 핀 5를 출력 모드로 설정합니다.
}

void loop() {
  input = digitalRead(button_pin); // 버튼 핀의 입력 상태를 읽어서 input 변수에 저장합니다.
  Serial.println(input); // 버튼의 입력 상태를 시리얼 모니터에 출력합니다.
  if (input == 1) { // 버튼이 눌렸을 때 (입력이 HIGH일 때)
    digitalWrite(5, HIGH); // 핀 5에 연결된 LED를 켭니다.
  } else { // 버튼이 눌리지 않았을 때 (입력이 LOW일 때)
    digitalWrite(5, LOW); // 핀 5에 연결된 LED를 끕니다.
  }
  delay(100); // 100밀리초 동안 대기합니다.
}
