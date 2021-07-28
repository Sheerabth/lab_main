# Computer Networks CA Lab1 
# Sheerabth OS (19pw33)
# Server Program

import socket
import subprocess
from threading import Thread

# Class for Server
class TCPServer(): 
    table = dict()
    BUFFER_SIZE = 1024
    def __init__(self, ip_address: str, port: int):
        self.TCP_IP = ip_address
        self.TCP_Port = port
        self.TCPSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.TCPSocket.bind((self.TCP_IP, self.TCP_Port))
        self.TCPSocket.listen(5)

    # Functions to handle options
    @staticmethod
    def options(option: str):
        option = option.split()
        if option[0] == 'mput' and len(option) == 3:
            TCPServer.table[option[1]] = option[2] 
            return 'The entry '+ '('+ option[1] + ',' + TCPServer.table[option[1]] + ')' +' added'
        elif option[0] == 'mget' and len(option) == 2:
            if option[1] in TCPServer.table: 
                return 'The value for the key \'' + option[1] + '\' is ' + '\'' + TCPServer.table[option[1]] + '\''
            else:
                return 'Entry not found'
        elif ' '.join(option) == '# of IPC sockets':
            new_process = subprocess.Popen("ss -Hx | wc -l", shell=True, stdout=subprocess.PIPE)
            subprocess_return = new_process.stdout.read()
            return 'The number of IPC sockets are ' + subprocess_return.decode('utf-8')
        return 0

    # Thread Handling Function
    def thread_function(self, client, address):
        while True:
            try:
                option = client.recv(1024)
                if not option: continue
                print('The option recieved is', option.decode('UTF-8'), 'from', address)
                response = TCPServer.options(option.decode('UTF-8'))
                if not response:
                    client.send(b'Invalid command')
                    break
                client.send(response.encode())
            except KeyboardInterrupt:
                break
        client.close()

    # Main Listening Function
    def listen(self):
        try:
            while True:
                client, address = self.TCPSocket.accept()
                thread = Thread(target=self.thread_function, args=(client, address))
                thread.start()
        except KeyboardInterrupt:
            self.TCPSocket.close()
        self.TCPSocket.close()

if __name__ == '__main__':
    new_Server = TCPServer('127.0.0.1', 5005)
    new_Server.listen()