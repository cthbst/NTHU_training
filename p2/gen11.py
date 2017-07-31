#!/usr/bin/env python3

from random import randint as ri

MAXN = 30000
N=ri(2,MAXN/10)
M=ri(N,MAXN)
Q=ri(1,MAXN)

print(N,M)
H = ri(N,M)
for _ in range(H):
    u = ri(2,N)
    print( u-1 , u , ri(1,MAXN/10))
for _ in range(M-H):
    print( ri(1,N) , ri(1,N) , ri(MAXN/10+1,MAXN))

print(Q)
for _ in range(Q):
    print( ri(1,N) , ri(1,N))
