#!/usr/bin/env python3

from random import randint as ri
import random
import string    

aph = string.ascii_lowercase

ncase = 5
print(ncase)

for _ in range(ncase):
    n = ri(1,1000)
    print(n)
    x=ri(0,n-1)
    y=ri(0,n-1)
    d=ri(0,n);
    
    for i in range(0,n):
        line = ""
        for j in range(0,n):
            dis = abs(i-x)+abs(j-y)
            if dis>d :
                line += random.choice(aph)
            else :
                line += aph[ (abs(i-x)+1)%len(aph) ]
        print(line)
