const int led = 16;
const int toucher = 4; //GPIO4 터치핀
int ledState = LOW;
int touchThreshold = 20;
int touchDetected = false;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int touchValue = touchRead(toucher);
  if (touchValue <  touchThreshold && !touchDetected){
    Serial.println("Touch Detected");
    ledState = !ledState;
    digitalWrite(led, ledState);
    touchDetected = true;
    delay(300);
  }//터치됐을 때.
  //터치해서 touchDetected가 true일 때 손을 떼면
  if (touchValue >= touchThreshold && touchDetected){
    touchDetected = false;
  }
  delay(50);
}
  