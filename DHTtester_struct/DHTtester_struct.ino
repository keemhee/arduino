#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11       // DHT 11 우리가 받은 건 11

DHT dht(DHTPIN, DHTTYPE);   //이거 꼭 알려줘야 사용이 됨.
  
struct SensorData{          //SensorData라는 데이터타입 만듦
  float humidity;
  float temperature;
};

SensorData sensor_data;     //sensor_data의 데이터타입은 SensorData

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));

  dht.begin();
}

SensorData checkSensor()     //SensorData 타입으로 return하는 checkSensor함수
{
  SensorData current_data;
  current_data.humidity = dht.readHumidity();
  current_data.temperature = dht.readTemperature();
  return current_data;
}


void loop() {
  delay(2000);
  sensor_data = checkSensor();

  if (isnan(sensor_data.humidity) || isnan(sensor_data.temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(sensor_data.humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(sensor_data.temperature);
  Serial.println(F("°C "));
}