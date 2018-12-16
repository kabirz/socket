import socket

client = socket.socket()
client.connect(('localhost', 12345))

client.send("Hello, Python".encode())

data = client.recv(512)

print("Server:", data.decode())