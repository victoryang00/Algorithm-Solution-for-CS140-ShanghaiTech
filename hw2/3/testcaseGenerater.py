from random import randint
import os


n = 300
m = 1000
k = 3000

n = 100
m = 1000
k = 3000

while True:
    p = open("1.in", "w")
    p.write(str(n+1)+' '+str(n//2)+' '+str(n//2*2+1)+'\n')

    for i in range(0, n, 2):
        a = i+2
        b = i+1
        c = i
        if i == 0:
            c = 3000
        p.write(str(a)+' '+str(b)+' '+str(c)+'\n')

    for j in range(2):
        for i in range(0, n, 2):
            p.write(str(i+1)+' '+str(1)+'\n')

    p.write(str(3000)+' '+str(1)+'\n')

    break
