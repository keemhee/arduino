int encoder_pin = 2;
int counter = 0;
int A_IA = 5;
int A_IB = 6;
int B_IA = 11;
int B_IB = 10;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(encoder_pin, INPUT);
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  pinMode(B_IA, OUTPUT);
  pinMode(B_IB, OUTPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoder_pin), count_encoder, RISING);
}

void loop() {
  forward();
  Serial.print("Counter: ");
  Serial.println(counter);
  count_encoder();
  delay(4000);
  turnright();
  delay(800);
  forward();
  delay(4000);
  turnright();
  delay(800);
  forward();
  delay(4000);
  turnright();
  delay(800);
  forward();
  delay(4000);
  turnright();
  delay(800);
  stop();
  delay(10000);
}

void count_encoder()
{
  counter++;
}



void forward(){
  analogWrite(A_IA, 80);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 80);
  analogWrite(B_IB, 0);
}

void backward(){
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 100);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 100);
}


void turnleft(){
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 80);
  analogWrite(B_IA, 80);
  analogWrite(B_IB, 0);
}

void turnright(){
  analogWrite(A_IA, 80);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 80);
}
void stop()
{
  analogWrite(A_IA, 0);
  analogWrite(A_IB, 0);
  analogWrite(B_IA, 0);
  analogWrite(B_IB, 0);
}
  