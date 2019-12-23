# InverseOfModular.py
# encoding = UTF-8

# 把列表转化成为数值
def ArrayToNum(wn):
    if wn == []: # 补充
        return None
    wn = [str(i) for i in wn]
    wn = int(''.join(wn))
    return wn
# 把数值按数字逐个分割成数字，组成列表
def NumToArray(w):
    if w == None: # 补充
        return []
    s = str(w)  # 因为整数是不可迭代的，所以要转成字符串处理
    wn = []
    for ch in s:
        wn.append(eval(ch))
    return wn

def add(x, y):
    if x < y:
        x, y = y, x
    xn, yn = NumToArray(x), NumToArray(y)
    lx, ly = len(xn), len(yn)
    temp = [0] * (lx-ly)
    temp[:lx-ly] = xn[:lx-ly]
    for i in range(ly):
        temp.append(xn[lx-ly+i] ^ yn[i])
    return ArrayToNum(temp)
    
def multi(x, y):
    xn, yn = NumToArray(x)[::-1], NumToArray(y)[::-1] # reverse()没有返回值
    lx, ly = len(xn), len(yn)
    temp = [0] * ( lx + ly - 1)
    for i in range(lx):
        for j in range(ly):
            temp[i+j] ^= (xn[i] & yn[j]) # 模运算下不考虑进位的问题 # i+j-1
    return ArrayToNum(temp[::-1]) # & -> *; ^ -> +

def div(x, y):
    if x < y:
        return (x, 0)
    q, b = [], [] # q 表示 除数， b 表示每次的减数
    xn, yn = NumToArray(x), NumToArray(y)
    lx, ly = len(xn), len(yn)
    lq = lx - ly + 1
    
    while ArrayToNum(xn) > y: #len(xn) >= ly and :# 长度大于等于不一定代表能减
        b = []
        q.append(1)
        for i in range(lx):         # 得到最大的减数
            t = yn[i] if i < ly else 0
            b.append(t)
        xn = NumToArray(add(ArrayToNum(xn), ArrayToNum(b))) # 二进制下加法即减法
        
        for i in range(1, lx - len(xn)):    #得到倍数
            if len(q) < lq:
                q.append(0)
        lx = len(xn)

    return (ArrayToNum(q), ArrayToNum(xn))

def gcd(x, y):
    xn, yn = NumToArray(x), NumToArray(y)
    while ArrayToNum(yn) != 0:
        xn, yn = yn, NumToArray(div(ArrayToNum(xn), ArrayToNum(yn))[1])
    return ArrayToNum(xn)

if __name__ == "__main__":
    print(multi(10, 110))
    print(add(101, 110))
    print(div(1100, 100))
    print(div(1011, 100))
    print(div(11, 1))
    print(gcd(1011, 100))
    print(gcd(1010, 100))