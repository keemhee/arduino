int IR = 3;
int IR2 = 9;
int LED = 13;

void setup() {
  pinMode(IR, INPUT);
  pinMode(IR2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int IRsensor = digitalRead(IR);
  int IR2sensor = digitalRead(IR2);
  Serial.println(IRsensor);
  Serial.println(IR2sensor);
  if (IRsensor == LOW && IR2sensor == HIGH) {
    Serial.println("turn right");
  }
  else if (IRsensor == HIGH && IR2sensor == LOW) {
    Serial.println("turn left");
  }
  delay(500);
}
  
