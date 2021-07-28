import socket
from threading import Thread

def send(TCPClient):
    while True:
        option = input('Enter the message: ')
        if not option:
            break
        TCPClient.send(option.encode())
        if option == 'exit':
            break
    print('Press ctrl+c to exit')

TCPClient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
TCPClient.connect(('127.0.0.1', 5005))
send_thread = Thread(target=send, args=(TCPClient,))
send_thread.start()
try:
    while True:
        message = TCPClient.recv(1024)
        if message: print('\n'+message.decode('utf-8'))
except KeyboardInterrupt:
    TCPClient.close()