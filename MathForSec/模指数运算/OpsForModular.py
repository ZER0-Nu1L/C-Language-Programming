# OpsForBigInteger.pu
# encoding = UTF-8

import random

# 采用快速求幂的方法，以提供算法效率
def pow_mod(x, y, z):
    number = 1
    while y:
        if y & 1:
            number = number * x % z
        y >>= 1
        x = x * x % z
    return number

if __name__ == "__main__":
    print("随机生成 m, a, e:")
    m = random.getrandbits(1024)
    a = random.randint(1,1000)
    e = random.randint(1,1000)
    print("m = %d" % m)
    print("= %s" % bin(m))
    print("a = %d" % a)
    print("= %s" % bin(a))
    print("e = %d" % e)
    print("= %s" % bin(e))
    print("a^e mod m = %d" % pow_mod(a, e, m))
    print("= %s" % bin(pow_mod(a, e, m)))
    