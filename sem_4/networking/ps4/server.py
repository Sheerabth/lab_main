import socket
import subprocess
from threading import Thread

class TCPServer():
    BUFFER_SIZE = 1024
    def __init__(self, ip_address: str, port: int):
        self.TCP_IP = ip_address
        self.TCP_Port = port
        self.TCPSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.TCPSocket.bind((self.TCP_IP, self.TCP_Port))
        self.TCPSocket.listen(5)

    @staticmethod
    def options(option: str)->str:
        if option == 'R':
            new_process = subprocess.Popen("ip route list", shell=True, stdout=subprocess.PIPE)
            subprocess_return = new_process.stdout.read()
            return subprocess_return
        elif option == 'S':
            new_process = subprocess.Popen("ss -H -A tcp,udp | wc -l", shell=True, stdout=subprocess.PIPE)
            subprocess_return = new_process.stdout.read()
            return subprocess_return
        elif option == 'A':
            new_process = subprocess.Popen("ip neigh show nud reachable", shell=True, stdout=subprocess.PIPE)
            subprocess_return = new_process.stdout.read()
            return subprocess_return
        return 0

    def thread_function(self, client, address):
        while True:
            option = client.recv(1024)
            print('The option recieved is', option.decode('UTF-8'), 'from', address)
            response = TCPServer.options(option.decode('UTF-8'))
            if not response:
                client.send(b'Invalid Response')
                break
            client.send(response)
        client.close()

    def listen(self):
        while True:
            client, address = self.TCPSocket.accept()
            thread = Thread(target=self.thread_function, args=(client, address))
            thread.start()
        self.TCPSocket.close()


if __name__ == '__main__':
    new_Server = TCPServer('127.0.0.1', 5005)
    new_Server.listen()