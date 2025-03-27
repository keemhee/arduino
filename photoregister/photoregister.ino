void setup()
{
  pinMode(A0, INPUT); // A0 핀을 입력 모드로 설정 (포토레지스터 연결)
  pinMode(8, OUTPUT); // 8번 핀을 출력 모드로 설정 (LED 연결)
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작, 시리얼 모니터 사용
}

void loop()
{
  int brightness = analogRead(A0); // A0 핀에서 아날로그 값을 읽어 밝기 변수에 저장
  Serial.println(brightness); // 읽은 밝기 값을 시리얼 모니터에 출력 (줄 바꿈)
  
  if (brightness < 10) // 만약 밝기 값이 10보다 작으면 (어두운 경우)
  {
    digitalWrite(8, HIGH); // 8번 핀을 HIGH로 설정하여 LED를 켬
  }
  else // 그렇지 않으면 (밝은 경우)
  {
    digitalWrite(8, LOW); // 8번 핀을 LOW로 설정하여 LED를 끔
  }
  
  delay(100); // 100ms 대기
}
