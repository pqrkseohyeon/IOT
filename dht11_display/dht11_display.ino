/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h" // 라이브러리 가져오기
#define DHTPIN 8  // DHTPIN 문자열을 2로 변환(컴파일러)
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600); 
  dht.begin();
  lcd.begin(16, 2); 
  
}

void loop() {
  delay(2000); 
 int h = dht.readHumidity(); // 습도 읽기
 int t = dht.readTemperature();  // 온도 읽기

 if (isnan(h) || isnan(t)) { //에러 방지 코드
   Serial.println(F("Failed to read from DHT sensor!"));
   return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  
  lcd.setCursor(0,0);
  lcd.print("humi :  ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp : ");
  lcd.print(t);
  lcd.print("°C ");

}
