int encoder_pin = 2;
int counter = 0;
int A_IA = 11;
int A_IB = 10;
int B_IA = 6;
int B_IB = 5;
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
  Serial.print("Couter: ");
  Serial.println(counter);
  delay(100);
  turning();
}

void count_encoder()
{
  counter++;
}

void turning()
{
  if (IRsensor == LOW && IR2sensor == HIGH) 
  {
    Serial.println("turn right");
  }
  else if (IRsensor == HIGH && IR2sensor == LOW) 
  {
    Serial.println("turn left");
  }
  delay(500);
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
  analogWrite(B_IB, 150);
}

void turnright(){
  analogWrite(A_IA, 150);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 0);
}
void stop()
{
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 0);
}
  