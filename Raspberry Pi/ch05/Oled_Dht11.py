import Adafruit_DHT
import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306
import time
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont


sensor = Adafruit_DHT.DHT11

disp = Adafruit_SSD1306.SSD1306_128_64(rst=24, dc=23, spi=SPI.SpiDev(0, 0, max_speed_hz=8000000))

disp.begin()
disp.clear()
disp.display()

image = Image.new('1', (disp.width, disp.height))

draw = ImageDraw.Draw(image)
font = ImageFont.load_default()

pin = 4



# Note that sometimes you won't get a reading and
# the results will be null (because Linux can't
# guarantee the timing of calls to read the sensor).
# If this happens try again!
while True:
    # 온도, 압력, 고도 값을 읽어서 변수에 저장 

    humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
    # OLED에 화면 표시 내용 
    draw.text((0,0),   'Temp = {0:0.2f}*C'.format(temperature), font=font, fill=255)
    draw.text((0,32), 'Humi = {0:0.2f} %'.format(humidity),font=font, fill=255)

    # 화면 표시 
    disp.image(image)
    disp.display()
    # 딜레이 시간 2초 
    time.sleep(2) 


