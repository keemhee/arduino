// C++ code
//
void setup()
{
  pinMode(7, OUTPUT); // 빨간색 LED 핀을 출력 모드로 설정
  pinMode(6, OUTPUT); // 초록색 LED 핀을 출력 모드로 설정
  pinMode(5, OUTPUT); // 파란색 LED 핀을 출력 모드로 설정
}

void loop()
{
  int red = random(0, 255); // 빨간색 값을 무작위로 설정 (0-255)
  int green = random(0, 255); // 초록색 값을 무작위로 설정 (0-255)
  int blue = random(0, 255); // 파란색 값을 무작위로 설정 (0-255)
  change_color(red, green, blue); // 무작위 색상으로 LED 색상 변경
  delay(1000); // 1초 대기
  navy(); // 네이비 색상으로 변경
  delay(1000); // 1초 대기
  pink(); // 핑크 색상으로 변경
  delay(1000); // 1초 대기
}

void change_color(int red, int green, int blue)
{
  analogWrite(7, red); // 빨간색 LED 밝기 설정
  analogWrite(6, green); // 초록색 LED 밝기 설정
  analogWrite(5, blue); // 파란색 LED 밝기 설정
}

void navy()
{
  analogWrite(5, 153); // 파란색 LED를 153으로 설정
  analogWrite(6, 0); // 초록색 LED를 0으로 설정
  analogWrite(7, 0); // 빨간색 LED를 0으로 설정
}

void pink()
{
  analogWrite(5, 229); // 파란색 LED를 229로 설정
  analogWrite(6, 204); // 초록색 LED를 204로 설정
  analogWrite(7, 255); // 빨간색 LED를 255로 설정
}
