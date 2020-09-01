int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT); 

}

void loop() { 
  val=analogRead(A0);
    analogWrite(10,(val/4));  
    delay(100);     //0.1초 딜레이
  

}
