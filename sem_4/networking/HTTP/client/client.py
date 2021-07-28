# Client code for sending HTTP requests

import os, json, requests
from pathlib import Path
from pprint import pprint
from datetime import datetime

url = 'http://127.0.0.1:5000/'  # server url
current_directory = Path(__file__).parent.absolute()

# Sending GET request
# curl -X GET -H "If-Modified-Since: 367060" localhost:5000/file.html
def get_request(session, file_name, headers):
    headers["If-Modified-Since"] = '367060'
    headers["Accept"] = "text/html"
    response = session.get(url + file_name, headers=headers)
    return response
    
# Sending POST request
# curl -X POST -H "Content-Type: text/html" -d 'some data' localhost:5000/data.txt
def post_request(session, file_name, headers):
    headers["Accept"] = "application/json"
    path_to_file = os.path.join(current_directory, 'data\\', file_name)
    if not os.path.exists(path_to_file):
        print('File does not exists in the directory')
        exit()
    with open(path_to_file, 'r') as handle:
        response = session.post(f'{url}/{file_name}', data = handle.read(), headers=headers)
    return response

# Sending PUT request
# curl -X PUT -H "Content-Type: text/html" -d 'some data' localhost:5000/data.txt
def put_request(session, file_name, headers):
    headers["Accept"] = "applicaiton/json"
    path_to_file = os.path.join(current_directory, 'data\\', file_name)
    if not os.path.exists(path_to_file):
        print('File does not exists in the directory')
        exit()
    with open(path_to_file, 'r') as handle:
        response = session.put(f'{url}/{file_name}', data = handle.read(), headers=headers)
    return response

# Sending DELETE request
# curl -X DELETE -H localhost:5000/data.txt
def delete_request(session, file_name, headers):
    headers["Accept"] = "applicaiton/json"
    path_to_file = os.path.join(current_directory, 'data\\', file_name)
    response = session.delete(f'{url}/{file_name}', headers=headers)
    return response

if __name__ == '__main__':
    headers = { "Content-Type": "text/html",
                "Connection": "keep-alive",
                "Host": "127.0.0.1:5000" }    # Setting default request headers
    session = requests.Session()
    initial_response = session.get(url, headers=headers)
    print(initial_response.content.decode('utf-8'))
    request_type = input('Enter your choice: ')
    file_name = input('Enter file name: ')

    
    if request_type == 'GET':
        response = get_request(session, file_name, headers)
        content = response.content.decode('utf-8')
        print(content)
        pprint(vars(response))
    
    elif request_type == 'POST':
        response = post_request(session, file_name, headers)
        content = json.loads(response.content.decode('utf-8'))
        print(content)
        # pprint(vars(response))
    
    elif request_type == 'PUT':
        response = put_request(session, file_name, headers)
        content = json.loads(response.content.decode('utf-8'))
        print(content)
        # pprint(vars(response))

    elif request_type == 'DELETE':
        response = delete_request(session, file_name, headers)
        content = json.loads(response.content.decode('utf-8'))
        print(content)
        # pprint(vars(response))
    
    else:
        print('Invalid choice')

    session.close()
