int trig = 2;
int echo = 3;
void setup() {  
  Serial.begin(9600);  // 시리얼 통신 시작, 통신속도는 9600
  pinMode(trig, OUTPUT);  // tirg(2번) 핀을 출력모드로
  pinMode(echo, INPUT);  // echo(3번) 핀을 입력모드로
  

}

void loop() {
  digitalWrite(trig, HIGH);  // trig 핀에 HIGH(5V) 신호를 보낸다.
  delayMicroseconds(10);  // 10 마이크로초(1/100,000초) 동안
  digitalWrite(trig, LOW);  // trig 핀에 LOW(0V) 신호를 보낸다.
  int distance = pulseIn(echo, HIGH) * 17/1000;  // 아래에 따라 설명
  Serial.print(distance);  // distance를 시리얼 모니터에 출력한다.
  Serial.println("cm"); // 문자열 cm를 출력한다.
  delay(100);  // 0.1초 지연

}
