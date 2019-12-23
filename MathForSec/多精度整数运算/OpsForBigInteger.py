# OpsForBigInteger.py
# encoding = UTF-8
import math
import time

# 把列表转化成为数值
def ArrayToNum(wn):
    wn = [str(i) for i in wn]
    wn = int(''.join(wn))
    return wn

# 把数值按数字逐个分割成数字，组成列表
def NumToArray(w):
    s = str(w)  # 因为整数是不可迭代的，所以要转成字符串处理
    wn = []
    for ch in s:
        wn.append(eval(ch))
    return wn

# 将两个数字列表右对齐，列表长度为n，高位补零
def align(xn, yn, n):    # 高位补零
    if len(xn) > len(yn):
        m = n - len(yn)
        yn.reverse()
        for i in range(m):
            yn.append(0)
        yn.reverse()
    elif len(xn) < len(yn):
        m = n - len(xn)
        xn.reverse()
        for i in range(m):
            xn.append(0)
        xn.reverse()

# 输入两个字符数组，返回一个高位补零的数组，运算为加法；基数为 b
def add(xn, yn, b = 10):
    n = max(len(xn), len(yn))
    align(xn, yn, n)
    # 从低位开始计算
    xn.reverse()
    yn.reverse()    #让列表元素的索引（数组下标）和实际运算的同化
    w = []
    c = 0
    for i in range(n):
        t = xn[i] + yn[i] + c
        if t < b:
            c = 0
            w.append(t)
        else:
            c = 1
            w.append(t - b)
    w.append(c)
    w.reverse()
    # 考虑到 Python 作用域的问题，需要将 xn, yn 重新逆序回来
    xn.reverse()
    yn.reverse()
    return w

# 输入两个字符数组，返回一个高位补零的数组，运算为减法；基数为 b
def sub(xn, yn, b = 10):
    if ArrayToNum(xn) < ArrayToNum(yn): ## 异常处理一定要写在函数以内！
        return [-1] # 返回同类型！
    n = max(len(xn), len(yn))
    align(xn, yn, n)
    # 从低位开始计算
    xn.reverse()
    yn.reverse()     #让列表元素的索引（数组下标）和实际运算的同化
    w = []
    c = 0
    for i in range(n):
        t = xn[i] - yn[i] + c
        if t >= 0:
            c = 0
            w.append(t)
        else:
            c = -1
            w.append(t + b)
    w.reverse()
    xn.reverse()
    yn.reverse()
    return w

# 输入两个字符数组，返回一个高位补零的数组，运算为乘法；基数为 b
def multi(xn, yn, b = 10):
    # 从低位开始计算
    xn.reverse()
    yn.reverse()

    n, t = len(xn)-1, len(yn)-1
    wn = []
    for i in range(n+t+1+1):
        wn.append(0)
    for i in range(t+1): # [0, t]
        c = 0
        for j in range(n+1): # [0, n]
            u = ( wn[i+j] + xn[j]*yn[i] + c) // b
            v = ( wn[i+j] + xn[j]*yn[i] + c) % b
            wn[i+j] = v
            c = u
        wn[i+n+1] = u
    wn.reverse()
    xn.reverse()
    yn.reverse()
    return NumToArray(ArrayToNum(wn))
# 输入两个字符数组，返回一个高位补零的数组，运算为除法；基数为 b
def div(xn, yn, b = 10):
    # 从低位开始计算
    n, t = len(str(ArrayToNum(xn)))-1, len(str(ArrayToNum(yn)))-1
    # [fix] 这里有问题，如果之前对齐过了，所以长度会一致
    # 所以不能直接用 n, t = len(xn)-1, len(yn)-1 

    xn.reverse() # 逆序从右对齐变成左对齐
    yn.reverse()
    if n < t:
        xn.reverse()
        return [0] , xn
    
    qn = []
    for j in range(n-t+1):
        qn.append(0)
    qt = multi(yn[::-1], NumToArray(b**(n-t)), b)   
    # [fix] 由于这里的 xn, yn 都是经过逆序的，
    # 所以调用前面的 add, sub, multi 都需要再逆序[::-1]输入，返回结果再逆序
    while ArrayToNum(sub(xn[::-1], qt, b)) > 0:
        qn[n-t] += 1
        xn = sub(xn[::-1], qt, b)[::-1]
    # [fix] q 不需要逆序,因为一开始程序逻辑和实际逻辑的编号已经一致了
    # 乘法导致不能正常地右对齐
    # qn.reverse()
    for i in range(n, t+1-1, -1):
        if xn[i] == yn[i]:
            qn[i-t-1] = b - 1
        else:
            qn[i-t-1] = math.floor( xn[i] * b + xn[i-1] // yn[t])
        while qn[i-t-1] * (yn[t] * b + yn[t-1]) > xn[i]*b**2 + xn[i-1]*b + xn[i-2]:
            qn[i-t-1] -= 1
        xn = sub(xn[::-1], multi(yn[::-1], NumToArray(qn[i-t-1] * b**(i-t-1)), b))[::-1]
        if ArrayToNum(xn) < 0:
            xn = add(xn[::-1], multi(yn[::-1], NumToArray(b**(i-t-1)), b), b)[::-1]
            qn[i-t-1] -= 1
    rn = xn
    rn.reverse()
    qn.reverse()
    return (qn, rn)

def compare():
    print("由于 Python 标准库中不能直接对二进制进行运算。为了比较运行的效率，这里我们采用十进制。")
    print("======================================")
    x = input("请输入第一个数字:");
    y = input("请输入第二个数字:");
    a, b = x, y

    print("========下面是本程序的运行结果：========")
    xn, yn = [], []
    xn, yn = NumToArray(eval(a)), NumToArray(eval(b))

    mytime_start = time.time()
    print("a + b = %d " %  ArrayToNum(add(xn, yn, 10)))
    w = ArrayToNum(sub(xn, yn, 10))
    if w == -1:
        print("运算结果为负数")
    else:
        print("a - b = %d" % w)

    w = ArrayToNum(multi(xn, yn, 10))
    print("a * b = %d" % w)

    qn, rn = div(xn, yn, 10)
    q = ArrayToNum(qn)
    r = ArrayToNum(rn)
    print("a / b = %d" % q)
    print("a mod b = %d" % r)
    mytime_end = time.time()
    print("程序运行时间为：%fs"%(mytime_end - mytime_start))

    print("========下面是标准库运行结果：========")
    a, b = eval(x), eval(y)
    mytime_start = time.time()
    print("a + b = %d " %  (a + b))
    print("a - b = %d" % (a - b))
    print("a * b = %d" % (a * b))
    print("a / b = %d" % (a // b))
    print("a mod b = %d" % (a %b))
    mytime_end = time.time()
    print("程序运行时间为：%fs"%(mytime_end - mytime_start))


# 函数的封装性！输入和输出数据的格式和类型
# 包括异常处理的    
if __name__ == "__main__":
    # 数据输入部分：
    a = input("请输入第一个数字:");
    b = input("请输入第二个数字:");
    xn, yn = [], []
    xn, yn = NumToArray(eval(a)), NumToArray(eval(b))

    # 数据运算部分
    w = ArrayToNum(add(xn, yn, 2))
    print("a + b = %d " % w)

    '''
    异常处理应该在函数内封装好，不应该在调用的时候额外处理
    if(eval(a) < eval(b)):
        print("无法执行减法")
        return
    '''
    w = ArrayToNum(sub(xn, yn, 2))
    if w == -1:
        print("运算结果为负数")
    else:
        print("a - b = %d" % w)

    w = ArrayToNum(multi(xn, yn, 2))
    print("a * b = %d" % w)

    qn, rn = div(xn, yn, 2)
    q = ArrayToNum(qn)
    r = ArrayToNum(rn)
    print("a / b = %d" % q)
    print("a mod b = %d" % r)

    compare()
