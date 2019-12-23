# OpsForBigInteger.pu
# encoding = UTF-8

# 采用快速求幂的方法，以提供算法效率
def pow_mod(x, y, z):
    number = 1
    while y:
        if y & 1:
            number = number * x % z
        y >>= 1
        x = x * x % z
    return number

def  main():
    pass

if __name__ == "__main__":
    main()