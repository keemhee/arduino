int encoder_pin = 2;
int counter = 0;
int A_IA = 5;
int A_IB = 6;
int B_IA = 11;
int B_IB = 10;
int IR = 3;
int IR2 = 9;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(encoder_pin, INPUT);
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  pinMode(B_IA, OUTPUT);
  pinMode(B_IB, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(IR2, INPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoder_pin), count_encoder, RISING);
}

void loop() {
  int IRsensor = digitalRead(IR);
  int IR2sensor = digitalRead(IR2);
  Serial.println(IRsensor);
  Serial.println(IR2sensor);
  forward();
  Serial.print("Counter: ");
  Serial.println(counter);
  delay(4000);
  turnright();
  delay(1000);
  forward();
  delay(4000);
  turnright();
  delay(1000);
  forward();
  delay(4000);
  turnright();
  delay(1000);
  forward();
  delay(4000);
  turnright();
  delay(1000);
  stop();
  delay(100000000);
}

void count_encoder()
{
  counter++;
}

void turning()
{
  if (IR == LOW && IR2 == HIGH) 
  {
    Serial.println("turn right");
  }
  else if (IR == HIGH && IR2 == LOW) 
  {
    Serial.println("turn left");
  }
  delay(500);
}

void forward(){
  analogWrite(A_IA, 100);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 100);
  analogWrite(B_IB, 0);
}

void backward(){
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 100);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 100);
}


void turnleft(){
  analogWrite(A_IA, 100);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 100);
}

void turnright(){
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 100);
  analogWrite(B_IA, 100);
  analogWrite(B_IB, 0);
}
void stop()
{
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 0);
}
  