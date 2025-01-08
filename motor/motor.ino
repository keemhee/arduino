int A_IA = 11;
int A_IB = 10;
int B_IA = 6;
int B_IB = 5;

void setup() {
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  pinMode(B_IA, OUTPUT);
  pinMode(B_IB, OUTPUT);
}

void loop() {
  forward();
  delay(2000);
  backward();
  delay(2000);
}

void forward(){
  analogWrite(A_IA, 150);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 150);
  analogWrite(B_IB, 0);
}

void backward(){
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 150);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 150);
}

void turnleft(){
  analogWrite(A_IA, 150);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 0);
}

void turnright(){
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 150);
  analogWrite(B_IB, 0);
}
