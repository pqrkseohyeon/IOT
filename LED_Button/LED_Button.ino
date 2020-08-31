int led = 10;
int button = 2;

void setup() {
  //led는 출력핀으로 설정
  pinMode(led, OUTPUT);
  //button은 입력으로 설정
  pinMode(button, INPUT);
  //시리얼 통신 추가
  Serial.begin(9600); // 속도는 9600

}

void loop() {
  if(digitalRead(button)==HIGH){
    digitalWrite(led,HIGH);
    Serial.println("button ON!");
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("button OFF!");
  }
  delay(100); //0.1초

}
