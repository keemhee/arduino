#include "DHT.h" // DHT 라이브러리 포함

#define DHTPIN 2 // DHT 센서가 연결된 핀 번호
#define DHTTYPE DHT11 // DHT11 센서 타입 지정

DHT dht(DHTPIN, DHTTYPE); // DHT 객체 생성

struct SensorData { // SensorData라는 구조체 타입 정의
  float humidity; // 습도 값을 저장할 변수
  float temperature; // 온도 값을 저장할 변수
};

SensorData sensor_data; // SensorData 구조체의 인스턴스 생성

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작 (보드레이트 9600)
  Serial.println(F("DHTxx test!")); // 초기화 메시지 출력

  dht.begin(); // DHT 센서 초기화
}

void loop() {
  delay(2000); // 2초 대기
  sensor_data.humidity = dht.readHumidity(); // 습도 값 읽기

  sensor_data.temperature = dht.readTemperature(); // 온도 값 읽기

  if (isnan(sensor_data.humidity) || isnan(sensor_data.temperature)) {
    Serial.println(F("Failed to read from DHT sensor!")); // 센서 읽기 실패 시 메시지 출력
    return; // 함수 종료
  }

  Serial.print(F("Humidity: ")); // 습도 출력 메시지
  Serial.print(sensor_data.humidity); // 습도 값 출력
  Serial.print(F("%  Temperature: ")); // 온도 출력 메시지
  Serial.print(sensor_data.temperature); // 온도 값 출력
  Serial.println(F("°C ")); // 온도 단위 출력
}
