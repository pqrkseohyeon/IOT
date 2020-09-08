from flask import Flask,render_template
import datetime

app = Flask(__name__)

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

if __name__=="__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)