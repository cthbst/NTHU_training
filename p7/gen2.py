#!/usr/bin/env python3

from random import randint as ri

def ranString():
    re = ""
    len = ri(1,10000)
    for _ in range(len):
        re += str( ri(0,9) )
    return re

ncases = 10
print(ncases)

for _ in range(ncases):
    n = ri(1,10)
    print(n)
    for __ in range(n):
        print( ranString() )
