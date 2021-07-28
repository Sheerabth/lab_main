import socket
from threading import Thread

class ChatServer:

    def __init__(self, ip_address, port):
        self.users = dict()
        self.IP = ip_address
        self.PORT = port
        self.TCPSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.TCPSocket.bind((self.IP, self.PORT))
        self.TCPSocket.listen(5)

    def broadcast(self, client, address):
        while True:
            message = client.recv(1024)
            message = message.decode('utf-8')
            if not message: continue
            if message == 'exit': break
            print('The message recieved is', message, 'from', address)
            # send to other users
            for user_address in self.users.keys():
                if user_address != address:
                    print(user_address)
                    response = f'from {address}: {message}'
                    self.users[user_address].send(response.encode()) 
        client.close()
        del self.users[address]

    def listen(self):
        try:
            while True:
                client, address = self.TCPSocket.accept()
                self.users[address] = client
                thread = Thread(target=self.broadcast, args=(client, address))
                thread.start()
        except KeyboardInterrupt:
            self.TCPSocket.close()

if __name__ == '__main__':
    new_server = ChatServer('127.0.0.1', 5005)
    new_server.listen()