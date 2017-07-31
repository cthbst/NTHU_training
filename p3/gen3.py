#!/usr/bin/env python3

from random import randint as ri

MAXN = 100000
MAXW = 10000

ncase = 10
print(ncase)

for __ in range(ncase):
    N=ri(1,MAXN/100)
    M=ri(N,MAXN)
    
    print(N,M)
    for _ in range(M):
        print( ri(1,N) , ri(1,N) , ri(1,4))
