import socket

def hammingcode_encode(data):
    print('before parity')
    print(data)
    data = data[::-1]
    message = [int(bit) for bit in data]

    m = len(data)

    r = 1

    while (2**r) <= (r + m + 1):
        r = r + 1

    for i in range(r):
        message.insert((2 ** i) - 1,0)

    for i in range(r):
        parity = message[(2 ** i) - 1]
        count = 1
        j = (2**i) - 1
        while j < m+r:
            if count <= (2**i):
                parity = parity ^ message[j]
                count = count + 1
                j += 1
            else:
                count = 1
                j = j + (2**i)
            
        message[(2 ** i) - 1] = parity

    print('adding a random flip')
    message[13] = 1 ^ message[13]
    
    message = ''.join(str(elem) for elem in message)
    print(message[::-1])
    
    return message[::-1] 



HOST = '127.0.0.1' 

PORT = 65431

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    message = '1101001100110101'
    encoded_message = hammingcode_encode(message)
    s.sendall(encoded_message.encode('UTF-8'))  
    response = s.recv(1024)
    if response:
        print('Recieved response - >' , response.decode('UTF-8'), sep='\n')
    else:
        print('Server Closed')

except KeyboardInterrupt:
    s.close()

