# OpsForGF.py
# encoding = UTF-8
from InverseOfModular import *
# 乘法需要接口，除法不需要
def GF8multi(x, y):
    t =  multi(x, y)
    m, n = div(t, 100000000)
    return n

def InverSaveToFile(filename, m):
    for i in range(2**9):
        x = int(bin(i)[2:])
        xrev = InverseOfModular(x, m)
        with open(filename, 'a') as f:
            f.write("%s: %s\n" % (x, xrev))

def MultiSaveToFile(filename, m):
    for i in range(2**9):
        x = int(bin(i)[2:])
        for j in range(2**9):
            y = int(bin(j)[2:])
            z = GF8multi(x, y)
            with open(filename, 'a') as f:
                f.write("%sx%s=%s\n" % (x, y, z))

def FileToInve(filename, x):
    f = open(filename, "r")
    flst = f.readlines()
    newlstRe = []
    for s in flst:
        s = s.strip()
        newlstRe.append(s.split(": "))
    for item in newlstRe:
        if item[0] == str(x):
            return item[1]
    return "Inverse Not Found"

def FileToMul(filename, x, y):
    fstr = str(x) + "x" + str(y)
    flst = f.readlines()
    newlstMu = []
    for s in flst:
        s = s.strip()
        newlstRe.append(s.split(": "))
    for item in newlstRe:
        if item[0] == fstr:
            return item[1]
    return "Multi Not Found"
    
if __name__ == "__main__":
    fx = "x^8+x^6+x^5+x^1+1"
    xstr = input('请输入一个多项式(用x^n的形式表示,x也用x^1的形式表示)：')
    x = FomatStrToValue(xstr)
    ystr = input('请输入一个多项式(用x^n的形式表示,x也用x^1的形式表示)：')
    y = FomatStrToValue(ystr)
    
    print("f(x)和g(x)在 2^8 域上的乘积：")
    print("f(x)×g(x) mod 2^8 = %s" % ValueToFomatStr(GF8multi(x, y)))
    print("f(x) 模 %s 的乘法逆元为：%s"%(fx, ValueToFomatStr(InverseOfModular(x, FomatStrToValue(fx)))))
    print("g(x) 模 %s 的乘法逆元为：%s"%(fx, ValueToFomatStr(InverseOfModular(y, FomatStrToValue(fx)))))

    print("正在构建构造指数对数表，从而通过查表实现")
    print("（其中不可约多项式为%s）"% fx)
    print("由于数据规模比较大，需要等待较长的时间")
    InverSaveToFile("Inv Exponential logarithm table.txt", FomatStrToValue(fx))
    MultiSaveToFile("Mul Exponential logarithm table.txt", FomatStrToValue(fx))
    print("构建完毕，数据已写入%s, %s" %("Exponential logarithm table.txt", "Mul Exponential logarithm table.txt"))

    print("现在可通过查表实现乘法和逆元运算：")    
    xstr = input('请输入一个多项式(用x^n的形式表示,x也用x^1的形式表示)：')
    x = FomatStrToValue(xstr)
    ystr = input('请输入一个多项式(用x^n的形式表示,x也用x^1的形式表示)：')
    y = FomatStrToValue(ystr)
    print("经过查表得到的结果是：")
    print("f(x) 模 %s 的乘法逆元为：%s"%(fx, ValueToFomatStr(FileToInve("Exponential logarithm table.txt", x))))
    print("g(x) 模 %s 的乘法逆元为：%s"%(fx, ValueToFomatStr(FileToMul("Exponential logarithm table.txt", x, y))))
