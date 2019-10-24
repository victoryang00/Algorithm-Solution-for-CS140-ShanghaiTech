if __name__ == '__main__':
    with open('input.txt','w') as f:
        n = 100000 #数据规模
        f.write("%d\n"%n)
        totIn = 0 #当前没有删去的股票个数
        totOut = n #当前所有没有加入的股票个数
        for i in range(n*2):
            if totIn==0 or (totOut>0 and randint(0,1)==1): #加一个股票
                f.write('%d %d\n'%(randint(1,100),randint(1,10000)))
                totOut -= 1
                totIn += 1
            else: #删一个股票
                f.write("%d\n"%randint(1,100))
                totIn -= 1