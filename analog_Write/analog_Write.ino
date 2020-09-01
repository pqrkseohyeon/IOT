
void setup() {
  pinMode(10, OUTPUT); //10번 핀을 출력모드로 설정한다.ㅣ

}

void loop() {  // for 함수.. i=10이며; 255보다 작고;
  for (int i=10; i<255; i=i+10){ // i는 매번 +10을 한다.
    analogWrite(10,i);  // LED (6번 핀)에 i만틈의 아날로그 신호 출력
    delay(100);
  }

}
