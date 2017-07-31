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
    print(A)
    print(B)

for _ in range(2):
    A = ranString(ri(1,25000));
    B = ranString(ri(1,25000));
    print(A+B)
    print(B+A)

for _ in range(2):
    A = ranString(ri(1,25000));
    B = ranString(ri(1,25000));
    C = ranString(ri(1,25000));
    print(A+B+C)
    print(A+B+B+C)

for _ in range(2):
    A = ranString(ri(1,25000));
    print(A+A)
    print(A)

for _ in range(2):
    A = ranString(ri(1,25000));
    B = ranString(ri(1,25000));
    C = ranString(ri(1,25000));
    print(A+B+C)
    print(A+C)
