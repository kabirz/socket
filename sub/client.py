import socket
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--port', '-p', type=int, help = 'port')
parser.add_argument('--address', '-i', type=str, help = 'server ip address')
parser.add_argument('--message', '-m', type=str, help = 'message')
args = parser.parse_args()

if args.port == None or args.address ==None:
        print("Usage: %s -i address -p port -m message" % __file__)
        exit(0)

s = socket.socket()

s.connect((args.address, args.port))

if args.message:
        s.send(bytes(args.message, encoding='utf8'))

s.close()