// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int distance = 0;
int red = 3;
int green = 5;
int blue = 6;

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  distance = sonar.ping_cm(); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print(distance);
  Serial.println("cm");
  
  int state= map(distance, 0, MAX_DISTANCE, 1, 3);
//  if (distance > 200)
//  {
//    state = 3;
//  }
//  else if (distance <= 30)
//  {
//    state = 1;
//  }
//  else if ((distance>30) && (distance <= 170))
//  {
//    state = 2;
//  }

  switch (state)
  {
    case 1 : //if (state == 1)
      Serial.println("war");
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
    case 2 : 
      Serial.println("be prepare");
      analogWrite(red, 255);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;
    case 3 :
      Serial.println("relax");
      analogWrite(red, 255);
      analogWrite(green, 255);
      analogWrite(blue, 255);
      break;
    default :
      analogWrite(red,0);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
  }
}