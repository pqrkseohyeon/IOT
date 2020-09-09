from flask import Flask,render_template
import datetime
import RPi.GPIO as GPIO

app = Flask(__name__)

GPIO.setmode(GPIO.BOARD)

@app.route("/")
def hello():
    now = datetime.datetime.now()
    timeString = now.strftime("%Y-%m-%d %H:%M")
    templateData = { #dict
        'title' : 'Hello!',
        'time' : timeString
        }
    
    return render_template('main.html', **templateData)

@app.route("/<name>") 
def hello2(name):
    templateData = { #dict
        'title' : 'Hello!',
        'name' : name
        }
    
    return render_template('name.html', **templateData)

@app.route("/readPin/<pin>") 
def readPin(pin):
    
    try:
        GPIO.setup(int(pin), GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
        if GPIO.input(int(pin)) == 1:
            response = "High"
        else :
            response = "Low"
    except:
        response = "Error pin number"+pin
        
    
    templateData = { #dict
        'title' : 'Pin Status'+pin,
        'response' : response
        }
    
    return render_template('pin.html', **templateData)

if __name__=="__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)