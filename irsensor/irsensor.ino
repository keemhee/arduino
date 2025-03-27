1| int IR = 3; // IR 센서 핀을 3으로 정의
2| int IR2 = 9; // 두 번째 IR 센서 핀을 9로 정의
3| int LED = 13; // LED 핀을 13으로 정의
4| 
5| void setup() { // 핀을 초기화하는 설정 함수
6|   pinMode(IR, INPUT); // IR 센서 핀을 입력 모드로 설정
7|   pinMode(IR2, INPUT); // 두 번째 IR 센서 핀을 입력 모드로 설정
8|   pinMode(LED, OUTPUT); // LED 핀을 출력 모드로 설정
9|   Serial.begin(9600); // 시리얼 통신을 9600 보드레이트로 시작
10| }
11| 
12| void loop() { // 메인 루프 함수
13|   int IRsensor = digitalRead(IR); // IR 센서에서 값을 읽음
14|   int IR2sensor = digitalRead(IR2); // 두 번째 IR 센서에서 값을 읽음
15|   Serial.println(IRsensor); // 시리얼 모니터에 IR 센서 값을 출력
16|   Serial.println(IR2sensor); // 시리얼 모니터에 두 번째 IR 센서 값을 출력
17|   if (IRsensor == LOW && IR2sensor == HIGH) { // 첫 번째 IR 센서가 감지하고 두 번째가 감지하지 않을 때
18|     Serial.println("turn right"); // "우회전"을 시리얼 모니터에 출력
19|   }
20|   else if (IRsensor == HIGH && IR2sensor == LOW) { // 두 번째 IR 센서가 감지하고 첫 번째가 감지하지 않을 때
21|     Serial.println("turn left"); // "좌회전"을 시리얼 모니터에 출력
22|   }
23|   delay(500); // 루프를 반복하기 전에 500밀리초 대기
24| }
25|   
26| 
