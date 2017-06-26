#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import shutil
import sys
import make_data as md

from checker import compile_source
from utils import write_file

def make(data, case):
    write_file(data, "running%d.in" % case)
    write_file(data, "running.in")
    if os.system("./std") != 0:
        print("Runtime Error!")
        sys.exit(-1)
    shutil.move("running.out", "running%d.ans" % case)
    

def make_1_to_5():
    make(md.make_si_e_ti(991, 991), 1)
    make(md.make_si_e_ti(991, 991), 2)
    make(md.make_wj_e_0(992, 992),  3)
    make(md.make_wj_e_0(992, 992),  4)
    make(md.make_r(993, 993),       5)
    
def make_6_to_8():
    make(md.make_l(99994, 99994), 6)
    make(md.make_l(99994, 99994), 7)
    make(md.make_l(99994, 99994), 8)
    
def make_9_to_12():
    make(md.make_s_e_1(99995, 99995), 9)
    make(md.make_s_e_1(99995, 99995), 10)
    make(md.make_s_e_1(99995, 99995), 11)
    make(md.make_s_e_1(99995, 99995), 12)

def make_13_to_16():
    make(md.make_t_e_1(99996, 99996), 13)
    make(md.make_t_e_1(99996, 99996), 14)
    make(md.make_t_e_1(99996, 99996), 15)
    make(md.make_t_e_1(99996, 99996), 16)

def make_17_to_19():
    make(md.make_2mum(99997, 99997), 17)
    make(md.make_2mum(99997, 99997), 18)
    make(md.make_2mum(99997, 99997), 19)

def make_20():
    make(md.make_2mum(299998, 299998), 20)
    
if __name__ == "__main__":
    compile_source("../Chenyao2333/std/running.cpp", "./std")
    # make_1_to_5()
    # make_6_to_8()
    # make_9_to_12()
    # make_13_to_16()
    # make_17_to_19()
    make_20()
    # make_13_to_16()
