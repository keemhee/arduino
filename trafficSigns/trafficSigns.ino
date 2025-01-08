int h_red = 5;
int h_green = 8;
int c_red = 9;
int c_yellow = 10;
int c_green = 11;

void setup() {
  pinMode(h_red, OUTPUT);
  pinMode(h_green, OUTPUT);
  pinMode(c_red, OUTPUT);
  pinMode(c_yellow, OUTPUT);
  pinMode(c_green, OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(h_red, HIGH);
  digitalWrite(h_green, LOW);
  digitalWrite(c_yellow, LOW);
  digitalWrite(c_green, HIGH);
  digitalWrite(c_red, LOW);
  delay(1000);
  digitalWrite(h_red, LOW);
  digitalWrite(c_green, LOW);
  digitalWrite(c_yellow, HIGH);
  delay(1000);
  digitalWrite(c_yellow, LOW);
  digitalWrite(c_red, HIGH);
  digitalWrite(h_green, HIGH);
  delay(1000);
  // put your main code here, to run repeatedly:

}
