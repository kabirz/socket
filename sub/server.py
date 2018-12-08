import socket;
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--port', '-p', type=int, help = 'port')
args = parser.parse_args()
if args.port == None:
        print("Usage: %s -p port" % __file__)
s = socket.socket()

s.bind(socket.gethostname(), args.port)

s.listen(1000)

while True:
        c, addr = s.accept()
        print("%s: %s" % (addr, str(s.recv(1024))))

s.close()