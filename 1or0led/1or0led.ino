int led_pin = 13;
char data;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) //총 몇개가 들어왔는지 알려줌.뭔가 시리얼을 통해 들어오면 이렇게 해라.
  {
    data = Serial.read(); //하나씩 읽어줌.
    Serial.println(data);
  }
  if (data == '1')
  {
    digitalWrite(led_pin, HIGH);
    
  }
  else if (data == '0')
  {
    digitalWrite(led_pin, LOW);
    
  }

}
