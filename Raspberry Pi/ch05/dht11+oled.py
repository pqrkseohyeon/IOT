import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306
import Adafruit_DHT
import time

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

sensor = Adafruit_DHT.DHT11

disp = Adafruit_SSD1306.SSD1306_128_64(rst=24, dc=23, spi=SPI.SpiDev(0, 0, max_speed_hz=8000000))

disp.begin()
disp.clear()
disp.display()

pin = 4

image = Image.new('1', (disp.width, disp.height))

draw = ImageDraw.Draw(image)
#draw.rectangle((0,0,disp.width-1,disp.height-1), outline=1, fill=0)

font = ImageFont.load_default()


while True:   
    humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
    
    # 측정값을 출력 (터미널) 
    print('Temp={0:0.1f}*C'.format(temperature))
    print('Hum={0:0.1f}*%'.format(humidity))
    
    # OLED에 화면 표시 내용     
    draw.text((0, 0),'Temp={0:0.1f}*C '.format(temperature),  font=font, fill=255)
    draw.text((0, 32),'Humidity={0:0.1f}%'.format(humidity),  font=font, fill=255)

    # 화면 표시 
    disp.image(image)
    disp.display()
    
    # 딜레이 시간 2초 
    time.sleep(2)

