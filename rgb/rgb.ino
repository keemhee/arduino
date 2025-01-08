// C++ code
//
int input_data = 0;
int input_pin = A0;
int red = 3;
int green = 6;
int blue = 5;

void setup()
{
  //RGB
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //가변저항
  Serial.begin(9600);
  pinMode(input_pin, INPUT);
}

void loop()
{
  input_data = analogRead(input_pin);
  
  int blue = map(input_data, 0, 1023, 0, 255);
  Serial.println(blue);
  change_color(255, 0, blue);
  delay(1000);
}

void change_color(int red, int green, int blue)
{
  analogWrite(red, red);
  analogWrite(green, green);
  analogWrite(blue, blue);
}

void navy()
{
  analogWrite(3, 153);
  analogWrite(5, 0);
  analogWrite(6, 0);
}

void pink()
{
  analogWrite(3, 229);
  analogWrite(5, 204);
  analogWrite(6, 255);
}
  