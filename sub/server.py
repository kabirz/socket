import socket
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--port', '-p', type=int, help = 'port')
args = parser.parse_args()
if args.port == None:
        print("Usage: %s -p port" % __file__)
s = socket.socket()

s.bind((socket.gethostname(), args.port))

s.listen(1000)
print("server is running")

while True:
        c, addr = s.accept()
        print("%s is linked" % addr[0])
        m = bytes.decode(c.recv(1024))
        print("%s: %s" % (addr[0], m))
        print("%s is unlinked" % addr[0])

s.close()
