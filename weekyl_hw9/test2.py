import itertools
a=[10,13,9,10,13,5,2,13,5,10,9,13,10,9,13,10,9,13,2,5,13,2,67,23,1,2,10,1,2,1,10,2,1]

def indexSubsequnce(x, y, z):
    if a.count(x)>0:
        if a.index(x) > -1:
            sub1=a.index(x)+1
            if a[sub1:].count(y)>0:
                if a[sub1:].index(y)> -1:
                    sub2=a[sub1:].index(y)+1
                    sub21=sub1+sub2
                    if a[sub21:].count(z)>0:
                        if a[sub21:].index(z) > -1:
                            return sub21+a[sub21:].index(z)+1
                        else:
                            return -1
                    else:
                        return -1
                else:
                    return -1
            else:
                return -1
        else:
            return -1
    else:
        return -1


def outPutNum(x, y, z):
    out = -1
    if indexSubsequnce(x, y, z) > -1:
        out = indexSubsequnce(x, y, z)
    else:
        return -1
    if indexSubsequnce(x, z, y) > -1:
        if out < indexSubsequnce(x, z, y):
            out = indexSubsequnce(x, z, y)
    else:
        return -1
    if indexSubsequnce(y, x, z) > -1:
        if out < indexSubsequnce(y, x, z):
            out = indexSubsequnce(y, x, z)
    else:
        return -1
    if indexSubsequnce(y, z, x) > -1:
        if out < indexSubsequnce(y, z, x):
            out = indexSubsequnce(y, z, x)
    else:
        return -1
    if indexSubsequnce(z, y, x) > -1:
        if out < indexSubsequnce(z, y, x):
            out = indexSubsequnce(z, y, x)
    else:
        return -1
    if indexSubsequnce(z, x, y) > -1:
        if out < indexSubsequnce(z, x, y):
            out = indexSubsequnce(z, x, y)
    else:
        return -1
    return out



list_in=[]
list_in=list(set(a))
print(list_in)
for i in list(itertools.combinations(a,3)):
    print(i)
    print(outPutNum(i[0],i[1],i[2]))