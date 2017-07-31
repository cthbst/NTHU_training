#!/usr/bin/env python3

from random import randint as ri

MAXN = 30000
N=ri(1,MAXN/100)
M=ri(N,MAXN)
Q=ri(1,MAXN)

print(N,M)
for _ in range(M):
    print( ri(1,N) , ri(1,N) , ri(1,MAXN))

print(Q)
for _ in range(Q):
    print( ri(1,N) , ri(1,N))
