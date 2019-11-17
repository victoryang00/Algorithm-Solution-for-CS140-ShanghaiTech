import random
import os

x = random.randint(0, 500000)

while True:
    p = open("test1.in", "w")
    p.write(str(x)+'\n')

    for i in range(x):
        p.write(str(random.randint(0, 100))+'\n')

    break
