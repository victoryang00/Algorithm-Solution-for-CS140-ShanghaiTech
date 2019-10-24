import os
 
if __name__ == '__main__':
    while True:
        os.system('python3 gen.py')
        os.system('./std <input.txt >out1.txt')
        os.system('./prog <input.txt >out2.txt')#自己的程序
        if os.system('diff out1.txt out2.txt'):
            print("GG")
            break
        print("Good!")