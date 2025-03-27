int encoder_pin = 2; // 엔코더 핀 정의
int counter = 0; // 엔코더 카운터 변수 초기화
int A_IA = 11; // 모터 A의 IA 핀 정의
int A_IB = 10; // 모터 A의 IB 핀 정의
int B_IA = 6; // 모터 B의 IA 핀 정의
int B_IB = 5; // 모터 B의 IB 핀 정의
int IR = 3; // 적외선 센서 핀 정의
int IR2 = 9; // 두 번째 적외선 센서 핀 정의
int LED = 13; // LED 핀 정의

int IRsensor; // 적외선 센서 값 저장 변수
int IR2sensor; // 두 번째 적외선 센서 값 저장 변수

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  pinMode(encoder_pin, INPUT); // 엔코더 핀을 입력 모드로 설정
  pinMode(A_IA, OUTPUT); // 모터 A의 IA 핀을 출력 모드로 설정
  pinMode(A_IB, OUTPUT); // 모터 A의 IB 핀을 출력 모드로 설정
  pinMode(B_IA, OUTPUT); // 모터 B의 IA 핀을 출력 모드로 설정
  pinMode(B_IB, OUTPUT); // 모터 B의 IB 핀을 출력 모드로 설정
  pinMode(IR, INPUT); // 적외선 센서 핀을 입력 모드로 설정
  pinMode(IR2, INPUT); // 두 번째 적외선 센서 핀을 입력 모드로 설정
  pinMode(LED, OUTPUT); // LED 핀을 출력 모드로 설정
  attachInterrupt(digitalPinToInterrupt(encoder_pin), count_encoder, RISING); // 엔코더 인터럽트 설정
}

void loop() {
  IRsensor = digitalRead(IR); // 적외선 센서 값 읽기
  IR2sensor = digitalRead(IR2); // 두 번째 적외선 센서 값 읽기
  Serial.println(IRsensor); // 적외선 센서 값 출력
  Serial.println(IR2sensor); // 두 번째 적외선 센서 값 출력
  forward(); // 전진 함수 호출
  Serial.print("Counter: "); // "Counter: " 출력
  Serial.println(counter); // 카운터 값 출력
  delay(100); // 100ms 대기
  turning(); // 회전 함수 호출
}

void count_encoder() {
  counter++; // 카운터 증가
}

void turning() {
  if (IRsensor == LOW && IR2sensor == HIGH) {
    Serial.println("turn right"); // 우회전 메시지 출력
  } else if (IRsensor == HIGH && IR2sensor == LOW) {
    Serial.println("turn left"); // 좌회전 메시지 출력
  }
  delay(500); // 500ms 대기
}

void forward() {
  analogWrite(A_IA, 150); // 모터 A 전진
  analogWrite(A_IB, 0); // 모터 A 전진
  analogWrite(B_IA, 150); // 모터 B 전진
  analogWrite(B_IB, 0); // 모터 B 전진
}

void backward() {
  analogWrite(A_IA, 0); // 모터 A 후진
  analogWrite(A_IB, 150); // 모터 A 후진
  analogWrite(B_IA, 0); // 모터 B 후진
  analogWrite(B_IB, 150); // 모터 B 후진
}

void turnleft() {
  analogWrite(A_IA, 150); // 모터 A 좌회전
  analogWrite(A_IB, 0); // 모터 A 좌회전
  analogWrite(B_IA, 0); // 모터 B 좌회전
  analogWrite(B_IB, 150); // 모터 B 좌회전
}

void turnright() {
  analogWrite(A_IA, 150); // 모터 A 우회전
  analogWrite(A_IB, 0); // 모터 A 우회전
  analogWrite(B_IA, 0); // 모터 B 우회전
  analogWrite(B_IB, 0); // 모터 B 우회전
}

void stop() {
  analogWrite(A_IA, 0); // 모터 A 정지
  analogWrite(A_IB, 0); // 모터 A 정지
  analogWrite(B_IA, 0); // 모터 B 정지
  analogWrite(B_IB, 0); // 모터 B 정지
}
