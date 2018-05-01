#!/usr/bin/env python3
import socket
import pymesh
import pickle
import struct

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 8000

s.bind((host, port))
s.listen(5)  # queue up to 5 requests

# create arbitrary mesh
mesh = pymesh.Mesh()
mesh.vertices = [0.7, 0.5, 0.3]
mesh.indices = [2, 4, 6]

# encode mesh
byte_mesh = pickle.dumps(mesh)

# encode header
mesh_size = len(byte_mesh)
header = struct.pack('!I', mesh_size)

client = 1

while client <= 3:  # allow 3 connections
    client, addr = s.accept()

    print("SERVER: Connection %d from %s" % (client, str(addr)))
    print("SERVER: Sending mesh of size %d bytes" % mesh_size)

    client.send(header)
    client.send(byte_mesh)

    client.close()

    client += 1
