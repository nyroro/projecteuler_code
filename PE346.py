import math
N=10**12

ans=set()

for i in range(2,int(math.sqrt(N))+1):
    tmp=1+i+i*i
    if i%1000==0:
        print i

    while tmp<N:
        ans.add(tmp)
        tmp=tmp*i+1

ret=sum(list(ans))
print ret+1
