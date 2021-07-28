import socket

UDPClient = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
UDPClient.bind(('127.0.0.1', 5000))
UDPClient.sendto(b'Hi', ('127.0.0.1', 5005))
data, address = UDPClient.recvfrom(1024)
print(data.decode('UTF-8'))