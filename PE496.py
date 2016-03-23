from math import *
from time import clock
N=1000000000

x=[1,2]
l=[[1,1]]
st=clock()
ans=0
while len(l)>0:
    t=[a+b for a,b in zip(x,l[-1])]
    if t[0]*t[1]<=N:
        count = N//(t[0]*t[1])
        ans+= t[0]*t[1]*(1+count)*count//2
        l.append(t)
    else:
        x=l[-1]
        l.pop()

print(ans)
ed=clock()
print(ed-st)
