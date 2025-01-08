int encoder_pin = 2;
int counter = 0;
int A_IA = 11;
int A_IB = 10;
int B_IA = 6;
int B_IB = 5;

void setup() {
  Serial.begin(9600);
  pinMode(encoder_pin, INPUT);
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  pinMode(B_IA, OUTPUT);
  pinMode(B_IB, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoder_pin), count_encoder, RISING);
}

void loop() {
  forward();
  Serial.print("Couter: ");
  Serial.println(counter);
  delay(100);
  if (counter > 210)
  {
    turnright();
    delay(2000);
    counter = 0;
    stop();
  }
  delay(1000);
}

void count_encoder()
{
  counter++;
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
  