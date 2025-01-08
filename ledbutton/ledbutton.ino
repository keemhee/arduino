int button_pin = 7;
int input = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(button_pin, INPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  input = digitalRead(button_pin);
  Serial.println(input);
  if(input == 1)
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5, LOW);
  }
  delay(100);
}