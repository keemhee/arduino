int A_IA = 11; // 모터 A의 IN1 핀
int A_IB = 10; // 모터 A의 IN2 핀
int B_IA = 6;  // 모터 B의 IN1 핀
int B_IB = 5;  // 모터 B의 IN2 핀

void setup() {
  pinMode(A_IA, OUTPUT); // 모터 A의 IN1 핀을 출력 모드로 설정
  pinMode(A_IB, OUTPUT); // 모터 A의 IN2 핀을 출력 모드로 설정
  pinMode(B_IA, OUTPUT); // 모터 B의 IN1 핀을 출력 모드로 설정
  pinMode(B_IB, OUTPUT); // 모터 B의 IN2 핀을 출력 모드로 설정
}

void loop() {
  forward(); // 모터를 앞으로 움직입니다
  delay(2000); // 2초 동안 대기합니다
  backward(); // 모터를 뒤로 움직입니다
  delay(2000); // 2초 동안 대기합니다
}

void forward() {
  analogWrite(A_IA, 150); // 모터 A의 IN1 핀에 150의 PWM 신호를 출력
  analogWrite(A_IB, 0);   // 모터 A의 IN2 핀에 0의 PWM 신호를 출력
  analogWrite(B_IA, 150); // 모터 B의 IN1 핀에 150의 PWM 신호를 출력
  analogWrite(B_IB, 0);   // 모터 B의 IN2 핀에 0의 PWM 신호를 출력
}

void backward() {
  analogWrite(A_IA, 0);   // 모터 A의 IN1 핀에 0의 PWM 신호를 출력
  analogWrite(A_IB, 150); // 모터 A의 IN2 핀에 150의 PWM 신호를 출력
  analogWrite(B_IA, 0);   // 모터 B의 IN1 핀에 0의 PWM 신호를 출력
  analogWrite(B_IB, 150); // 모터 B의 IN2 핀에 150의 PWM 신호를 출력
}

void turnleft() {
  analogWrite(A_IA, 150); // 모터 A의 IN1 핀에 150의 PWM 신호를 출력
  analogWrite(A_IB, 0);   // 모터 A의 IN2 핀에 0의 PWM 신호를 출력
  analogWrite(B_IA, 0);   // 모터 B의 IN1 핀에 0의 PWM 신호를 출력
  analogWrite(B_IB, 0);   // 모터 B의 IN2 핀에 0의 PWM 신호를 출력
}

void turnright() {
  analogWrite(A_IA, 0);   // 모터 A의 IN1 핀에 0의 PWM 신호를 출력
  analogWrite(A_IB, 0);   // 모터 A의 IN2 핀에 0의 PWM 신호를 출력
  analogWrite(B_IA, 150); // 모터 B의 IN1 핀에 150의 PWM 신호를 출력
  analogWrite(B_IB, 0);   // 모터 B의 IN2 핀에 0의 PWM 신호를 출력
}
