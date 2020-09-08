from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

@app.route("/abc")
def abc():
    return "Hello ABC!"

if __name__=="__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
    