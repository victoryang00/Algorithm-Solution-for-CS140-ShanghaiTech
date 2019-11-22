def getFactorwithoutOverlapping(j):
    list_in=[]
    for x in [477,257,15,169,345,48,81,125,37]:
        x+=j
        for i in range(10):
            num = 1
            print(x)
            while num <= x:
                if x % num == 0:
                    list_in.append(num)
                        # else:
                        #     list_remove.append(num)
                num = num + 1
            x+=10


    # list_in=list(set(list_in))
    # list_remove=list(set(list_remove))
    print(list_in)
    c=list(set(list_in))

    for i in range(len(list_in)-1):
        a=list_in.count(list_in[i])
        if  a>1 & c.count(list_in[i])>0:
            c.remove(list_in[i])
    print(c)
    return (c)

list_out=[]
b=[]

list_out+=getFactorwithoutOverlapping(0)
list_out+=getFactorwithoutOverlapping(1)
list_out+=getFactorwithoutOverlapping(2)
list_out+=getFactorwithoutOverlapping(3)
list_out+=getFactorwithoutOverlapping(5)
list_out+=getFactorwithoutOverlapping(6)
list_out+=getFactorwithoutOverlapping(7)
list_out+=getFactorwithoutOverlapping(8)
list_out+=getFactorwithoutOverlapping(9)
for i in range(len(list_out)-1):
    if list_out.count(list_out[i])>=8:
        b.append(list_out[i])
print(b)