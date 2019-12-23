import copy
def popZero(f):
    checkZero=len(f)
    for i in range(checkZero):
        if abs(f[-1])<1e-9:
            f.pop()
        else:
            break
def polyDivision(f1,f2):
    popZero(f1)
    popZero(f2)
    degree1=len(f1)-1
    degree2=len(f2)-1
    if degree1<degree2:
        temp=f1
        f1=f2
        f2=temp
        degree1, degree2 = degree1, degree2
    p=[0 for i in range(degree1-degree2+1)]
    for i in range(degree1-degree2+1):
        p[i-1]=f1[-1]/f2[-1]
        for j in range(len(f2)):
            f1[-j-1]=f1[-j-1]-p[i-1]*f2[-j-1]
        f1.pop()
    r=f1
    popZero(r)
    return p,r

print(polyDivision([1,1,0], [1,0])