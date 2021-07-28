# Computer Networks CA Lab1 
# Sheerabth OS (19pw33)
# client Program

import socket

TCPClient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
TCPClient.connect(('127.0.0.1', 5005))
while True:
    try:
        option = input('Enter the option: ')
        TCPClient.send(option.encode())
        data = TCPClient.recv(1024)
        print(data.decode('UTF-8'))
    except KeyboardInterrupt:
        break
TCPClient.close()