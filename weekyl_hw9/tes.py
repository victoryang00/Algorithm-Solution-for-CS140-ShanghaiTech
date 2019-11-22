list_in=[]
num = 1
x=477
while num <= x:
    if x % num == 0:
        list_in.append(num)
    num = num + 1
print (list_in)