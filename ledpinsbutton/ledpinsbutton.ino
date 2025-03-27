// 배열을 만들어 여러 개의 LED 핀 번호를 저장합니다.
int ledPins[] = {3, 5, 7, 8, 10, 11};
int length = sizeof(ledPins)/sizeof(ledPins[0]); // 배열의 길이를 계산합니다.

bool flag = false; // LED 상태를 나타내는 플래그 변수입니다.
int input = 1; // 입력 상태를 저장하는 변수입니다.
bool prev_input = true; // 이전 입력 상태를 저장하는 변수입니다.

void setup() {
  Serial.begin(9600); // 시리얼 통신을 시작합니다.
  for (int i = 0; i < length; i++) {
    pinMode(ledPins[i], OUTPUT); // 각 LED 핀을 출력 모드로 설정합니다.
  }
  pinMode(12, INPUT_PULLUP); // 핀 12를 입력 풀업 모드로 설정합니다.
}

void loop() {
  input = digitalRead(12); // 핀 12의 입력 상태를 읽습니다.
  if ((input == 0) && (prev_input == true)) { // 버튼이 눌렸을 때 (핀 12가 LOW로 변경되었을 때)
    flag = !flag; // 플래그 변수를 토글합니다.
    turnOnLeds(); // LED를 켭니다.
    delay(1000); // 1초 동안 대기합니다.
    turnOffLeds(); // LED를 끕니다.
    delay(1000); // 1초 동안 대기합니다.
  }
  prev_input = input; // 이전 입력 상태를 갱신합니다.
}

void turnOnLeds() {
  for (int i = 0; i < length; i++) {
    digitalWrite(ledPins[i], HIGH); // 각 LED를 켭니다.
    delay(100); // 100밀리초 동안 대기합니다.
  }
}

void turnOffLeds() {
  for (int i = length-1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW); // 각 LED를 끕니다.
    delay(100); // 100밀리초 동안 대기합니다.
  }
}
