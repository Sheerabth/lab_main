# Program to perform ping functionality using scapy

from scapy.all import *
from threading import Thread
import time
import json
import sys

# no_of_requests = 10
# host = "www.google.com"

# Payload Class
class Payload:
    message = "MY_PING"
    def __init__(self, seq_no):
        self.seq_no = seq_no
        self.timestamp = time.time()

    def __str__(self):
        return f'MY_PING,{self.seq_no},{self.timestamp},'

# Sending packets
def send_packet(host, no_of_requests):
    for i in range(no_of_requests):
        payload = Payload(i)
        packet = IP(dst=host)/ICMP()/str(payload)
        send(packet)
        next_time = time.time()
        if next_time - payload.timestamp < 1:
            time.sleep(1 - next_time + payload.timestamp)

# Adding end time to each packet
def sniffed_packet(packet):
    print(packet.summary())
    packet[Raw].load += str(time.time()).encode()

# Generating report
def sniff_report(resp):
    report = list()
    print("Report: ")
    for i in range(no_of_requests):
        packet = resp[i]
        payload = packet[Raw].load.decode('utf-8').split(',')
        report.append({
                        "seq_no": int(payload[1]),
                        "message": payload[0],
                        "start_time": float(payload[2]),
                        "end_time": float(payload[3]),
                        "RTT": (float(payload[3]) - float(payload[2]))*1000,
        })
        if report[i]["RTT"] < 1:
            print(report[i]["seq_no"], "Timed_Out")
        
        elif i != report[i]["seq_no"]:
            print(report[i]["seq_no"], report[i]["message"], "Recieved_out_of_order")

        else:
            print(report[i]["seq_no"], report[i]["end_time"], report[i]["message"], "Successfully_Recieved", report[i]["RTT"], "ms")

    print("Average RTT", sum([packet_report["RTT"] for packet_report in report])/no_of_requests, "ms")
    print("Error_rate", sum([1 for packet_report in report if packet_report["message"] == "Timed_Out"])*100/no_of_requests, "%")

# Generate thread and sniff packets
def sniff_packets(host, no_of_requests):
    thread = Thread(target=send_packet, args=(host, no_of_requests))
    thread.start()
    resp = sniff(filter="src " + host + " and icmp", prn=sniffed_packet, timeout=no_of_requests)
    sniff_report(resp)

# Run like "sudo python3 ping.py hostname no_of_requests"
if __name__ == '__main__':
    if len(sys.argv) < 3 or len(sys.argv) > 3:
        print("Invalid Arguments")
    else:
        host = sys.argv[1]
        no_of_requests = int(sys.argv[2])
        sniff_packets(host, no_of_requests)