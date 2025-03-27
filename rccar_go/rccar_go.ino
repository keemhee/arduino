int encoder_pin = 2; // 엔코더 핀 정의
int counter = 0; // 엔코더 카운터 변수 초기화
int A_IA = 5; // 모터 A의 IA 핀 정의
int A_IB = 6; // 모터 A의 IB 핀 정의
int B_IA = 11; // 모터 B의 IA 핀 정의
int B_IB = 10; // 모터 B의 IB 핀 정의
int LED = 13; // LED 핀 정의

void setup() {
  Serial.begin(9600); // 시리얼 통신을 9600 baud로 시작
  pinMode(encoder_pin, INPUT); // 엔코더 핀을 입력 모드로 설정
  pinMode(A_IA, OUTPUT); // 모터 A의 IA 핀을 출력 모드로 설정
  pinMode(A_IB, OUTPUT); // 모터 A의 IB 핀을 출력 모드로 설정
  pinMode(B_IA, OUTPUT); // 모터 B의 IA 핀을 출력 모드로 설정
  pinMode(B_IB, OUTPUT); // 모터 B의 IB 핀을 출력 모드로 설정
  pinMode(LED, OUTPUT); // LED 핀을 출력 모드로 설정
  attachInterrupt(digitalPinToInterrupt(encoder_pin), count_encoder, RISING); // 엔코더 인터럽트 설정
}

void loop() {
  forward(); // 전진 함수 호출
  Serial.print("Counter: "); // "Counter: " 출력
  Serial.println(counter); // 카운터 값 출력
  count_encoder(); // 엔코더 카운터 증가
  delay(4000); // 4000ms 대기
  turnright(); // 우회전 함수 호출
  delay(800); // 800ms 대기
  forward(); // 전진 함수 호출
  delay(4000); // 4000ms 대기
  turnright(); // 우회전 함수 호출
  delay(800); // 800ms 대기
  forward(); // 전진 함수 호출
  delay(4000); // 4000ms 대기
  turnright(); // 우회전 함수 호출
  delay(800); // 800ms 대기
  forward(); // 전진 함수 호출
  delay(4000); // 4000ms 대기
  turnright(); // 우회전 함수 호출
  delay(800); // 800ms 대기
  stop(); // 정지 함수 호출
  delay(10000); // 10000ms 대기
}

void count_encoder() {
  counter++; // 카운터 증가
}

void forward() {
  analogWrite(A_IA, 80); // 모터 A 전진
  analogWrite(A_IB, 0); // 모터 A 전진
  analogWrite(B_IA, 80); // 모터 B 전진
  analogWrite(B_IB, 0); // 모터 B 전진
}

void backward() {
  analogWrite(A_IA, 0); // 모터 A 후진
  analogWrite(A_IB, 100); // 모터 A 후진
  analogWrite(B_IA, 0); // 모터 B 후진
  analogWrite(B_IB, 100); // 모터 B 후진
}

void turnleft() {
  analogWrite(A_IA, 0); // 모터 A 좌회전
  analogWrite(A_IB, 80); // 모터 A 좌회전
  analogWrite(B_IA, 80); // 모터 B 좌회전
  analogWrite(B_IB, 0); // 모터 B 좌회전
}

void turnright() {
  analogWrite(A_IA, 80); // 모터 A 우회전
  analogWrite(A_IB, 0); // 모터 A 우회전
  analogWrite(B_IA, 0); // 모터 B 우회전
  analogWrite(B_IB, 80); // 모터 B 우회전
}

void stop() {
  analogWrite(A_IA, 0); // 모터 A 정지
  analogWrite(A_IB, 0); // 모터 A 정지
  analogWrite(B_IA, 0); // 모터 B 정지
  analogWrite(B_IB, 0); // 모터 B 정지
}
