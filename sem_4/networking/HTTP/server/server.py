# HTTP Server using Flask

from flask import Flask, render_template, Response, request, jsonify
import os, sys
from pathlib import Path
from email.utils import formatdate

app = Flask(__name__)
current_directory = Path(__file__).parent.absolute()

# Printing request headers before handling the requests
@app.before_request
def log_headers():
    print(f'\nHeaders : \n{request.headers}')

# Default headers added after handling requests
@app.after_request
def set_headers(response):
    response.headers['Access-Control-Allow-Origin'] = '*'
    response.headers['Date'] = formatdate(timeval=None, localtime=False, usegmt=True)
    response.headers['Server'] = 'Sheerabth\'s Server ' + sys.version
    return response

# Default route information
@app.route('/')
def home():
    return 'Add file name as route and perform GET, POST, PUT or DELETE', 200, {"Content-Type": "text/html"}

# Handling GET request
@app.route('/<file_name>', methods=['GET'])
def handle_get(file_name):
    path_to_file = os.path.join(current_directory, f'templates\{file_name}')
    if os.path.exists(path_to_file):
        if os.path.getmtime(path_to_file) > int(request.headers["If-Modified-Since"]):
            response = render_template('file.html'), 200, {"Content-Type": "text/html; charset=utf-8"}
            return response
        else:
            response = render_template('file.html'), 304, {"Content-Type": "text/html; charset=utf-8"}
            return response
    return render_template('error.html'), 404, {"Content-Type": "text/html; charset=urf-8"}

# Hanfling POST request
@app.route('/<file_name>', methods=['POST'])
def handle_post(file_name):
    path_to_file = os.path.join(current_directory, 'data\\', file_name)
    try:
        with open(path_to_file, 'a') as handle:
            handle.write(request.data.decode())
        return {"status": "saved successfully"}, 200, {"Content-Type": "application/json"}
    except IOError:
        return {"status": "failed to save"}, 404, {"Content-Type': 'application/json"}

# Handling PUT request
@app.route('/<file_name>', methods=['PUT'])
def handle_put(file_name):
    path_to_file = os.path.join(current_directory, 'data\\', file_name)
    try:
        with open(path_to_file, 'w') as handle:
            handle.write(request.data.decode())
            # print(handle.read())
        return {"status": "saved successfully"}, 200, {"Content-Type": "application/json"}
    except IOError:
        return {"status": "failed to save"}, 404, {"Content-Type": "application/json"}

# Handlling DELETE request
@app.route('/<file_name>', methods=['DELETE'])
def handle_delete(file_name):
    path_to_file = os.path.join(current_directory, 'data\\', file_name)
    if os.path.exists(path_to_file):
        os.remove(path_to_file)
        return {"status": "delete successfully"}, 200, {"Content-Type": "application/json"}
    return {"status": "failed to save"}, 404, {"Content-Type": "application/json"}

# Starting the server
if __name__ == '__main__':
    app.run()