void setup()
{
  pinMode(A0, INPUT); // input은 생략해도 읽힘
  pinMode(8, OUTPUT);
  Serial.begin(9600); // 시리얼 모니터를 사용하겠다. 그래야 볼 수 있음. 
  					  // 파라미터로 속도 받음.9600은 일반적인 속도
}

void loop()
{
  int brightness = analogRead(A0);
  Serial.println(brightness); // 프린트할 때 라인바꾸기.
  if (brightness <10 )
  {
    digitalWrite(8, HIGH);
  }
  else 
  {
    digitalWrite(8, LOW);
  }
  delay(100);
}