import random
n=40
m=n*n/2
k=400
print("{} {} {}".format(n,m,k))
for i in range(1,n+1):
    for j in range(i+1,n+1):
        print("{} {} {}".format(i,j,random.randint(0,10000)))