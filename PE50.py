import string
N=1000000
prime=[1]*(N+10)
plist=[]
pn=0
ans=0

        
for i in range(2,N):
    if prime[i]==1:
        for j in range(i*i,N+1,i):
            prime[j]=0
        plist.append(i)
        pn+=1

d=22

while 1:
    sum=0
    for i in range(0,d):
        sum+=plist[i]
    if sum>N:
        break
    for i in range(d,pn):
        sum+=plist[i]-plist[i-d]
        if sum>=N:
            break
        if prime[sum]==1:
            ans=sum
            
    d+=1
print ans
print d

