# Program to perform traceroute functionality using scapy

from scapy.all import *
import time
# host = "www.google.com"

def traceroute(host):
    dest_reached = False
    ttl = 0
    # Loop until destination reached
    while not dest_reached:
        packet = IP(dst=host, ttl=ttl)/ICMP()/'echo request'
        start_time = time.time()
        resp = sr1(packet, verbose=0, timeout = 4)
        end_time = time.time()

        # No response from node
        if not resp:
            print("Timed Out")
        
        # Response from node
        else:
            RTT = (end_time - start_time) * 1000
            print(f'ttl:{ttl} Packet took : {int(RTT)}ms : {resp[IP].src}')
            
            # Destination reached
            if resp[ICMP].type == 0:
                print("Destination Reached")
                dest_reached = True
            
        ttl = ttl + 1

if __name__ == '__main__':
    if len(sys.argv) < 2 or len(sys.argv) > 2:
        print("Invalid Arguments")
    else:
        host = sys.argv[1]
        traceroute(host)