from flask import Flask, render_template
import RPi.GPIO as GPIO
import Adafruit_BMP.BMP085 as BMP085
app = Flask(__name__)

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

pins = {
    10: { 'name':'YELLOW', 'state':GPIO.LOW},
    11: { 'name':'BLUE', 'state':GPIO.LOW},
    12: { 'name':'RED', 'state':GPIO.LOW},
}

sensor = BMP085.BMP085()
bmp = { 'temp' : 0.0, 'humi' : 0.0}

for pin in pins:
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

@app.route("/")
def main():
    for pin in pins:
        pins[pin]['state'] = GPIO.input(pin)
    temp = {
        'pins' : pins,
        'bmp'  : bmp
    }
    return render_template('app.html', **temp)

@app.route("/<changePin>/<action>")
def action(changePin, action):
    pin = int(changePin)

    if action == 'on':
        GPIO.output(pin, GPIO.HIGH)
    if action == 'off':
        GPIO.output(pin, GPIO.LOW)

    for pin in pins:
        pins[pin]['state'] = GPIO.input(pin)
    temp = {
        'pins' : pins,
        'bmp'  : bmp
    }
    return render_template('app.html', **temp)

@app.route("/test")
def readSensor():
    
    # 온도, 압력, 고도 값을 읽어서 변수에 저장 
    temp = sensor.read_temperature()
    pressure = sensor.read_pressure()
    altitude = sensor.read_altitude()
    bmp['temp']=temp
    temp = {
        'pins' : pins,
        'bmp'  : bmp
    }
    return render_template('app.html',**temp)


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)