#!/usr/bin/env python3

from random import randint as ri
import random
import string    


def ranString(len):
    re = ""
    for _ in range(len):
        re += random.choice(string.ascii_lowercase)
    return re

def repStringN(s,n):
    re = ""
    for _ in range(n):
        re += s
    return re

ncase = 10
print(ncase)

for _ in range(2):
    L = ri(1,1000)
    d = ri(1,L)
    A = ranString(d)
    B = ranString(L-d)
    sa = repStringN(A+B,ri(1,100))
    sb = repStringN(B+A,ri(1,100))
    print(sa)
    print(sb)

for _ in range(2):
    L = ri(1,1000)
    d = ri(1,L)
    A = ranString(d)
    B = ranString(d)
    sa = repStringN(A,ri(1,100))
    sb = repStringN(B,ri(1,100))
    print(sa)
    print(sb)

for _ in range(ncase-4):
    d = 1
    r = ri(1,100)
    A = ranString(d)
    sa = repStringN(A,r*ri(1,1000))
    sb = repStringN(A,r*ri(1,1000))
    print(sa)
    print(sb)
