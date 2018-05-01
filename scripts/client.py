#!/usr/bin/env python3

import socket
import struct
import pickle

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()  # localhost
port = 8000

s.connect((host, port))

# Receive header
header = s.recv(4)
mesh_size = struct.unpack('!I', header)[0]

# Receive mesh
byte_mesh = s.recv(mesh_size)
mesh = pickle.loads(byte_mesh)

s.close()  # done with the socket

print('CLIENT: Receiving mesh of size %d bytes' % mesh_size)
print('CLIENT: ', mesh)
