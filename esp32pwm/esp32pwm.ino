const int ledPin = 2;
const int channel = 0; //pwm 채널번호
const int freq - 5000; //pwm주파수(hz)
const int resolution = 8; //pwm해상도(비트)
void setup(){
  ledcSetuo(channel, freq, resolution); //pwm채널설정
  ledcAttachPin(ledPin, channel); //채널0을 핀2에 할당
}
void loop(){
  int percent = 50; //50%듀티사이클
  //퍼센트를 듀티 사이클 값(0~255)으로 변환
  int dutyCycle = map(percent, 0, 100, 0, 255);
  //듀티 사이클 값 적용
  ledcWrite(channel, dutyCycle);//채널0에 50%듀티사이클 설정
  delay(1000);//1초 대기
}