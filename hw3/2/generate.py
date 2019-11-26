import random
n=401
m=800
k=5
print("{} {} {}\n".format(n,m,k))
for i in range(1,n-1):
    print("{} {} {}\n".format(i,i+1,random.randint(0,10000)))
    print("{} {} {}\n".format(i,i+2,random.randint(0,10000)))