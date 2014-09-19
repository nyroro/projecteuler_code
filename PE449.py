import math
a=3.0

pi=math.acos(-1)

def f(z):
    r1=(1.0-z*z)
    r2=a+1.0/math.sqrt((a*a-1)*z*z+1)
    r3=1+a/(((a*a-1)*z*z+1)**(1.5))
    #print(r1,r2,r3)
    return r1*r2*r2*r3
ans1=0
ans2=4/3*pi*a*a

r=[[0]*20]*20

r[0][0]=(f(0)+f(1))/2

for i in range(1,20):
    tmp=0
    hn=2**(-i)
    for k in range(1,2**(i-1)+1):
        tmp+=f((2*k-1)*hn)
    r[i][0]=r[i-1][0]/2+(2**(-i))*tmp
    for j in range(1,i+1):
        r[i][j]=(4**j*r[i][j-1]-r[i-1][j-1])/(4**j-1)
print(r[19][19]*2*pi-ans2)
