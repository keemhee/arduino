#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo servo1;
//Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  //servo2.attach(10);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  delay(2000);
}

void loop() {
  if (Serial.available() > 0) {
    int angle1 = Serial.parseInt(); 
    //int angle2 = Serial.parseInt();
    
    Serial.print("Received angles: ");
    Serial.print(angle1);
    //Serial.print(", ");
    //Serial.println(angle2);

    angle1 = constrain(angle1, 0, 180); 
    //angle2 = constrain(angle2, 0, 180);

    servo1.write(angle1);
    //servo2.write(angle2);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Angle1:");
    display.setTextSize(1);
    display.println(angle1);
    //display.println("Angle2:");
    //display.setTextSize(1  );
    //display.println(angle2);
    display.display();

    delay(10);
  }
}
