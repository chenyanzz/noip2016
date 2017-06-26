#!/usr/bin/env python3

import argparse
import math
import sys
from random import randint

def make_random_tree(n):
    res = ""
    for i in range(2, n + 1):
        f = randint(1, i - 1)
        res += "%d %d\n" % (f, i)
    return res


# Si = T1
def make_si_e_ti(n, m):
    res = "%d %d\n" % (n, m)
    res += make_random_tree(n)
    
    for i in range(n):
        if randint(0, 3) is 0:
            res += "0"
        else:
            res += "%d" % randint(0, n)
        if i == n - 1: res += "\n"
        else: res += " "
    
    for i in range(m):
        s = randint(1, n)
        res += "%d %d\n" % (s, s)
    
    return res

# wj = 0
def make_wj_e_0(n, m):
    res = "%d %d\n" % (n, m)
    res += make_random_tree(n)
    
    for i in range(n):
        res += "0"
        if i == n - 1: res += "\n"
        else: res += " "
    
    for i in range(m):
        s = randint(1, n)
        t = randint(1, n)
        res += "%d %d\n" % (s, t)
    
    return res

# All data is randomized
# This method is deprecated, because the most of anwer will be 0 or 1.
def make_r(n, m):
    res = "%d %d\n" % (n, m)
    res += make_random_tree(n)
    
    for i in range(n):
        w = randint(1, n)
        res += "%d" % w
        if i == n - 1: res += "\n"
        else: res += " "
    
    for i in range(m):
        s = randint(1, n)
        t = randint(1, n)
        res += "%d %d\n" % (s, t)
    
    return res
    
def make_link_tree(n):
    res = ""
    for i in range(2, n + 1):
        res += "%d %d\n" % (i - 1, i)
    return res
    
# The tree becomes a link
def make_l(n, m):
    res = "%d %d\n" % (n, m)
    res += make_link_tree(n)
    
    l2r_count = m // 3
    r2l_count = m // 3
    rnd_count = m - l2r_count - r2l_count
    
    W = [0 for i in range(n + 1)]
    paths = []
    
    s = randint(1, n)
    W[s + (n - s) // 2] = (n - s) // 2
    for i in range(l2r_count):
        if randint(0, math.floor(math.sqrt(l2r_count))) == 0:
            s = randint(1, n // 10)
            W[s + (n - s) // 2] = (n - s) // 2
        t = randint(s, n)
        paths.append((s, t))
    
    s = randint(1, n)
    W[n - s // 2] = s // 2
    for i in range(r2l_count):
        if randint(0, math.floor(math.sqrt(r2l_count))) == 0:
            s = randint(n - n // 10, n)
            W[n - s // 2] = s // 2
        t = randint(1, s)
        paths.append((s, t))
    
    for i in range(rnd_count):
        s = randint(1, n)
        t = randint(1, n)
        paths.append((s, t))
    
    for i in range(1, n + 1):
        if W[i] == 0:
            W[i] = randint(0, n)
    
    for i in range(1, n + 1):
        res += "%d" % W[i]
        if i == n: res += "\n"
        else: res += " "
    
    for s, t in paths:
        res += "%d %d\n" % (s, t)
    
    return res

def make_mum_tree(n, start = 0):
    res = ""
    stem_count = n // 2
    leaves_count = n // 2 - n // 10
    
    for i in range(2, stem_count + 1):
        res += "%d %d\n" % (i - 1 + start, i + start)
    
    # f = stem_count
    for i in range(stem_count + 1, stem_count + leaves_count + 1):
        if randint(0, 10000) == 0:
            f = randint(1, n)
        else:
            f = (i - stem_count) // 2 + stem_count
        res += "%d %d\n" % (f + start, i + start)
    
    for i in range(stem_count + leaves_count + 1, n + 1):
        f = randint(1, i - 1)
        res += "%d %d\n" % (f + start, i + start)
    
    return res

def make_2mum_tree(n):
    mum1_count = n // 2
    mum2_count = n - mum1_count
    res = make_mum_tree(mum1_count)
    res += make_mum_tree(mum2_count, start = mum1_count)
    res += "1 %d\n" % (mum1_count + 1,)
    return res
    
def make_2mum(n, m):
    res = "%d %d\n" % (n, m)
    res += make_2mum_tree(n)
    
    leaves_1 = (n // 4, n // 2)
    leaves_2 = (n // 4 * 3, n)
    #print(leaves_1)
    for i in range(1, n + 1):
        w = randint(1, n)
        if i <= n // 2:
            if i not in leaves_1 and randint(0, 10):
                w = n // 4 - i
                if randint(0, 4) == 0:
                    w = i + n // 2
                w += randint(-1, 8)
        else:
            if i not in leaves_2 and randint(0, 10):
                w = n - i - n // 4
                if randint(0, 4) == 0:
                    w = i - n // 4
                w += randint(-1, 8)
        #print("i = %d w = %d\n" % (i, w))
        if w <= 1:
            w = randint(1, n)
        w = min(w, n)
        res += "%d" % w
        if i == n: res += "\n"
        else: res += " "
    
    for i in range(m):
        s = randint(1, n)
        t = randint(1, n)
        if randint(0, 10):
            s = randint(*leaves_1)
            t = randint(*leaves_2)
            if randint(0, 1):
                s, t = t, s
        res += "%d %d\n" % (s, t)
    
    return res

def make_s_e_1(n, m):
    res = "%d %d\n" % (n, m)
    res += make_mum_tree(n)
    for i in range(1, n + 1):
        w = i - 1
        if randint(0, 5) == 0:
            w = randint(1, n)
        res += "%d" % w
        if i == n: res += "\n"
        else: res += " "
    for i in range(n):
        s = 1
        t = 0
        if randint(0, 3):
            t = randint(n // 2, n)
        else:
            t = randint(1, n)
        res += "%d %d\n" % (s, t)
    return res

def make_t_e_1(n, m):
    res = "%d %d\n" % (n, m)
    res += make_mum_tree(n)
    for i in range(1, n + 1):
        w = randint(1, n)
        if randint(0, 10) and i < n // 2:
            w = n // 2 - i
            w += randint(-3, 3)
        w = min(w, n)
        if w < 1:
            w = randint(1, n)
        res += "%d" % w
        if i == n: res += "\n"
        else: res += " "
    for i in range(n):
        s = 0
        t = 1
        if randint(0, 3):
            s = randint(n // 2, n)
        else:
            s = randint(1, n)
        res += "%d %d\n" % (s, t)
    return res

    
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = "Data maker of running.")
    parser.add_argument("type", type = str, help = "Data type.")
    parser.add_argument("N", type = int)
    parser.add_argument("M", type = int)

    args = parser.parse_args()
    
    data = ""
    if args.type == "sieti":
        data = make_si_e_ti(args.N, args.M)
    elif args.type == "wje0":
        data = make_wj_e_0(args.N, args.M)
    elif args.type == "r":
        data = make_r(args.N, args.M)
    elif args.type == "l":
        data = make_l(args.N, args.M)
    elif args.type == "se1":
        data = make_s_e_1(args.N, args.M)
    elif args.type == "te1":
        data = make_t_e_1(args.N, args.M)
    elif args.type == "2mum":
        data = make_2mum(args.N, args.M)
    else:
        print("Please indicate proper data type!")
        sys.exit(-1)
        
    print(data)
    