import socket

class UDPServer():
    BUFFER_SIZE = 1024
    def __init__(self, ip_address: str, port: int):
        self.UDP_IP = ip_address;
        self.UDP_Port = port;
        self.UDPSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.UDPSocket.bind((self.UDP_IP, self.UDP_Port))

    def listen(self):
        while True:
            data, address = self.UDPSocket.recvfrom(UDPServer.BUFFER_SIZE)
            print('The data recieved is', data.decode('UTF-8'))
            if not data:
                print('No data Recieved')

            self.UDPSocket.sendto(b'The data sent is ' + data , address)

if __name__ == '__main__':
    new_Server = UDPServer('127.0.0.1', 5005)
    new_Server.listen()