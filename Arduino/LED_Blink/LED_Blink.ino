// 라이브러리를 불러올때
//#include <라이브러리이름.h>

int pin = 10;

void setup() {
  // 아두이노의 설정이나 채팅등을 하기위해 최초 1번 실행됨
  // GPIO 핀을 출력 or 입력
  pinMode(pin, OUTPUT); // 핀을 출력으로 설정한다. //pinMode는 최초 설정

}

void loop() {
  // 메인 코드는 항상 반복
  digitalWrite(pin, HIGH); //13핀에 연결된 led 켜짐
  delay(1000);          //1000ms(1/000초가 ms) => 1초
  digitalWrite(pin, LOW); //13핀에 연결된 led 꺼짐
  delay(1000);   //1000ms(1/000초가 ms) => 1초

}
