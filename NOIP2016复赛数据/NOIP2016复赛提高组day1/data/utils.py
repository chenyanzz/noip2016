#!/usr/bin/env python3

def write_file(data, path):
    with open(path, "w") as f:
        f.write(data)
