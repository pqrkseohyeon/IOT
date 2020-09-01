int trig = 2;
int echo = 3;
int RED = 8;
int YELLOW = 9;
int GREEN = 10;

void setup() {  
  Serial.begin(9600);  // 시리얼 통신 시작, 통신속도는 9600
  pinMode(trig, OUTPUT);  // tirg(2번) 핀을 출력모드로
  pinMode(echo, INPUT);  // echo(3번) 핀을 입력모드로
  pinMode(RED, INPUT);
  pinMode(YELLOW, INPUT);
  pinMode(GREEN, INPUT);
  

}

void loop() {
  digitalWrite(trig, HIGH);  // trig 핀에 HIGH(5V) 신호를 보낸다.
  delayMicroseconds(10);  // 10 마이크로초(1/100,000초) 동안
  digitalWrite(trig, LOW);  // trig 핀에 LOW(0V) 신호를 보낸다.
  int distance = pulseIn(echo, HIGH) * 17/1000;  // 아래에 따라 설명
  Serial.print(distance);  // distance를 시리얼 모니터에 출력한다.
  Serial.println("cm"); // 문자열 cm를 출력한다.
  delay(100);  // 0.1초 지연
  
  if (distance > 20)  //   distance(거리) 가 20보다 크면

  {

    digitalWrite(GREEN, HIGH);     // GREEN이 연결된 핀에 HIGH 신호(5V)를,

    digitalWrite(YELLOW, LOW);    // YELLOW가 연결된 핀에 LOW 신호(0V)를,

    digitalWrite(RED, LOW);       // RED가 연결된 핀에 LOW신호(0V)를.

  }

  if (distance > 10 & distance <= 20)   // distance(거리)가 10초과~20이하 일때

  {

    digitalWrite(GREEN, LOW);   

    digitalWrite(YELLOW, HIGH);

    digitalWrite(RED, LOW);

  }

  if (distance > 0 & distance <= 10)

  {

    digitalWrite(GREEN, LOW);

    digitalWrite(YELLOW, LOW);

    digitalWrite(RED, HIGH);

  }

 

}
