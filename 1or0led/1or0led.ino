int led_pin = 13; // LED가 연결된 핀 번호를 13번으로 설정합니다.
char data; // 시리얼 데이터를 저장할 변수를 선언합니다.

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600bps로 시작합니다.
  pinMode(led_pin, OUTPUT); // LED 핀을 출력 모드로 설정합니다.
}

void loop() {
  if (Serial.available() > 0) // 시리얼 통신으로부터 데이터가 들어온 개수를 확인합니다.
  {
    data = Serial.read(); // 시리얼 통신으로부터 하나의 데이터를 읽어옵니다.
    Serial.println(data); // 읽어온 데이터를 시리얼 모니터에 출력합니다.
  }
  if (data == '1') // 읽어온 데이터가 '1'이면
  {
    digitalWrite(led_pin, HIGH); // LED를 켭니다.
  }
  else if (data == '0') // 읽어온 데이터가 '0'이면
  {
    digitalWrite(led_pin, LOW); // LED를 끕니다.
  }
}