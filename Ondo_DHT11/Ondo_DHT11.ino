#include "DHT.h" // 라이브러리 가져오기
#define DHTPIN 2  // DHTPIN 문자열을 2로 변환(컴파일러)
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // 시리얼통신 초기화 속도는 9600
  Serial.println(F("DHTxx test!")); // print의 F함수는 메모리 절약을 위해

  dht.begin(); // 시리얼 통신 시작

}

void loop() {
 delay(2000); // 2초 대기(센서의 측정 주기가 보통 1초이상은 되어야 정밀하기 때문에
 float h = dht.readHumidity(); // 습도 읽기
 float t = dht.readTemperature();  // 온도 읽기

 if (isnan(h) || isnan(t)) { //에러 방지 코드
   Serial.println(F("Failed to read from DHT sensor!"));
   return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
 
 
}
