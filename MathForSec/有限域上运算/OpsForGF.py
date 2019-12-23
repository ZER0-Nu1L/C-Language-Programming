# OpsForGF.py
# encoding = UTF-8
from InverseOfModular import *

def FomatStrToValue(str):
    x = [0]*(8+1)
    
    for i in range(len(str)):
        if str[i] == 'x':
            x[int(str[i+2])] = 1
    if "+1" in str:
        x[0] = 1
    return ArrayToNum(x[::-1])

def ValueToFomatStr(x):
    xn = NumToArray(x)[::-1]
    str = ""
    for i in range(len(xn))[::-1]:
        if xn[i] == 1:
            str += "+x^%d"%(i)
    str = str.replace("x^0", "1")
    return str[1:]
# 乘法需要接口，除法不需要
def GF8multi(x, y):
    t =  multi(x, y)
    m, n = div(t, 100000000)
    return n

def SaveToFile(filename):
    pass
        

if __name__ == "__main__":
    str = input('请输入一个多项式(用x^n的形式表示,x也用x^1的形式表示)：')
    x = FomatStrToValue(str)
    # print(ValueToFomatStr(x))
    '''
    str = input('请输入一个多项式(用y^n的形式表示)：')
    y = FomatStrToValue(str)
    print(ValueToFomatStr(y))

    print(multi(x, y))
    print(GF8multi(x, y))
    '''
    fx = "x^8+x^6+x^5+x^1+1"
    # fx = "x^8+x^4+x^3+x^1+1"
    print(ValueToFomatStr(InverseOfModular(x, FomatStrToValue(fx))))

    print("--------------")
    
    # print(x, y)
    # print(multi(x,y))