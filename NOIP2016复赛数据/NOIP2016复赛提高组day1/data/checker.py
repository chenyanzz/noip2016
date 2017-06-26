#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import shutil
import make_data as md

def compile_source(src, dest):
    if os.system("g++ -g %s -o %s" % (src, dest)) != 0:
        print("%s: Compilation Error!\n" % src)
        sys.exit(-1)

def check(prog1, prog2, k, make = md.make_r):
    for i in range(k):
        print("Test %s:" % i)
        data = make(100, 3000)
        with open("running.in", "w") as f:
            f.write(data)
        os.system("%s" % prog1)
        shutil.move("./running.out", "%s.out" % prog1)
        os.system("%s" % prog2)
        shutil.move("./running.out", "%s.out" % prog2)
        
        if os.system("diff %s.out %s.out" % (prog1, prog2)) != 0:
            print("Difference between %s.out and %s.out" % (prog1, prog2))
            sys.exit(-1)
        
def check_std(src):
    compile_source(src, "./std")
    compile_source("../Chenyao2333/1-5.cpp", "./naive")
    check("./std", "./naive", 100)

def check_6_to_8(src):
    compile_source(src, "./6-8")
    compile_source("../Chenyao2333/1-5.cpp", "./naive")
    check("./6-8", "./naive", 100, md.make_l)
    
if __name__ == "__main__":
    # check_std("../Chenyao2333/std.cpp")
    check_6_to_8("../Chenyao2333/6-8.cpp")
