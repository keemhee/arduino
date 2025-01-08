// C++ code
//
void setup()
{
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  int red = random(0, 255); // cahange_color의 red와는 다름
  int green = random(0, 255);
  int blue = random(0, 255);
  change_color(red, green, blue);
  delay(1000);
  navy();
  delay(1000);
  pink();
  delay(1000);
}

void change_color(int red, int green, int blue)
{
  analogWrite(7, red);
  analogWrite(6, green);
  analogWrite(5, blue);
}

void navy()
{
  analogWrite(5, 153);
  analogWrite(6, 0);
  analogWrite(7, 0);
}

void pink()
{
  analogWrite(5, 229);
  analogWrite(6, 204);
  analogWrite(7, 255);
}
  