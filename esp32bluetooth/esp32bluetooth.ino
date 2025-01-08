#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("khj");
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(2, OUTPUT);
}

void loop() {
 if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.println(c);
    if(c == 'f'){
      digitalWrite(2, HIGH);
      delay(1000);
    }
    else if( c == 'b'){
      digitalWrite(2, LOW);
      delay(1000);
    }
  }
}

