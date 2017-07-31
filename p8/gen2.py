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
    A = ranString(ri(1,25000));
    B = ranString(ri(1,25000));
    C = ranString(ri(1,25000));
    print(A+C)
    print(A+B+C)

for _ in range(2):
    A = ranString(ri(1,25000));
    B = ranString(ri(1,25000));
    C = ranString(ri(1,25000));
    print(A+B)
    print(B+C+A)

for _ in range(2):
    A = ranString(ri(1,250));
    B = ranString(ri(1,250));
    print( A+ repStringN(B+A,3) )
    print( A+ repStringN(B+A,100) )

for _ in range(2):
    A = ranString(ri(1,250));
    B = ranString(ri(1,250));
    print( A+ repStringN(B+A,10) )
    print( A+ repStringN(B+A,15) )

for _ in range(2):
    A = ranString(ri(1,20000));
    B = ranString(ri(1,20000));
    C = ranString(ri(1,20000));
    print(A+B+C+B+A)
    print(C+B+B+C)
