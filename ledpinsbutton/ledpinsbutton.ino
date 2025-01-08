//array 만들기. list같은 역할
int ledPins[] = {3, 5, 7, 8, 10, 11};
int length = sizeof(ledPins)/sizeof(ledPins[0]); // 0이든 1이든 상관없음.

bool flag = false;
int input = 1;
bool prev_input = true;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < length; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(12, INPUT_PULLUP);
}

void loop() 
{
  input = digitalRead(12);
  if ((input == 0) && (prev_input == true))
  {
    flag = !flag;
    turnOnLeds();
    delay(1000);
    turnOffLeds();
    delay(1000);
  }
  prev_input = input;
}

void turnOnLeds()
{
  for (int i = 0; i < length; i++)
    {
      digitalWrite(ledPins[i], HIGH);
      delay(100);
      //digitalWrite(ledPins[i], LOW);
    }
}

void turnOffLeds()
{
  for (int i = length-1; i>=0; i--)
    {
      digitalWrite(ledPins[i], LOW);
      delay(100);
    }
}