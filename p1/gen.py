#!/usr/bin/env python3

from random import randint as ri

N = ri(1,1000);

def ranID():
    return str(ri(0,1)) + str(ri(1111,9999))

ncases = 10
print(ncases)

for _ in range(ncases):
    n = ri(1,1000)
    print(n)
    for __ in range(n):
        print( ranID() )
