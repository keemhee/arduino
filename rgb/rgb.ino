// C++ code
//
int input_data = 0; // 입력 데이터 변수 초기화
int input_pin = A0; // 가변저항이 연결된 아날로그 핀 설정
int red = 3; // 빨간색 LED 핀 설정
int green = 6; // 초록색 LED 핀 설정
int blue = 5; // 파란색 LED 핀 설정

void setup()
{
  //RGB
  pinMode(3, OUTPUT); // 빨간색 LED 핀을 출력 모드로 설정
  pinMode(5, OUTPUT); // 파란색 LED 핀을 출력 모드로 설정
  pinMode(6, OUTPUT); // 초록색 LED 핀을 출력 모드로 설정
  //가변저항
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  pinMode(input_pin, INPUT); // 가변저항 핀을 입력 모드로 설정
}

void loop()
{
  input_data = analogRead(input_pin); // 가변저항 값 읽기
  
  int blue = map(input_data, 0, 1023, 0, 255); // 가변저항 값을 0-255 범위로 매핑
  Serial.println(blue); // 매핑된 파란색 값을 시리얼 모니터에 출력
  change_color(255, 0, blue); // 빨간색 255, 초록색 0, 파란색 매핑된 값으로 색상 변경
  delay(1000); // 1초 대기
}

void change_color(int red, int green, int blue)
{
  analogWrite(red, red); // 빨간색 LED 밝기 설정
  analogWrite(green, green); // 초록색 LED 밝기 설정
  analogWrite(blue, blue); // 파란색 LED 밝기 설정
}

void navy()
{
  analogWrite(3, 153); // 빨간색 LED를 153으로 설정
  analogWrite(5, 0); // 초록색 LED를 0으로 설정
  analogWrite(6, 0); // 파란색 LED를 0으로 설정
}

void pink()
{
  analogWrite(3, 229); // 빨간색 LED를 229로 설정
  analogWrite(5, 204); // 초록색 LED를 204로 설정
  analogWrite(6, 255); // 파란색 LED를 255로 설정
}
