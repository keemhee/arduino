#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11   // DHT 11 우리가 받은 건 11

DHT dht(DHTPIN, DHTTYPE); //이거 꼭 알려줘야 사용이 됨.

struct SensorData{     //sensordata라는 데이터타입 만듦
  float humidity;
  float temperature;
};

SensorData sensor_data;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  delay(2000);
  sensor_data.humidity = dht.readHumidity();

  sensor_data.temperature = dht.readTemperature();

  if (isnan(sensor_data.humidity) || isnan(sensor_data.temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }


  Serial.print(F("Humidity: ")); //''은 letter 하나일때, ""여러문자
  Serial.print(sensor_data.humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(sensor_data.temperature);
  Serial.println(F("°C ")); //특수문자 쓰는 법: 한글로 바꾸고 ㄹ한자
}
