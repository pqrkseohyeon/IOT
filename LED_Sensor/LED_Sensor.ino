int led = 10;
int pir = 2;
int val = 0;

void setup() { 
  pinMode(led, OUTPUT);  
  pinMode(pir, INPUT);
}

void loop() {
  val = digitalRead(pir);
  if(val == HIGH){
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
