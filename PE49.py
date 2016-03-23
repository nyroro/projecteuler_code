import string
N=10000
prime=[1]*(N+10)
plist=[]
ret=[]
cnt=0;

def judge(a,b):
    xa=[0]*10
    xb=[0]*10

    while a>0:
        xa[a%10]+=1
        xb[b%10]+=1
        a/=10
        b/=10
    for i in range(0,10):
        if xa[i]!=xb[i]:
            return 0
    return 1
        
for i in range(2,10000):
    if prime[i]==1:
        for j in range(i*i,N+1,i):
            prime[j]=0
        if i>=1000:
            plist.append(i)

for i in plist:
    for j in plist:
        for k in plist:
            if i!=j and j!=k and i!=k and i-j==j-k and judge(i,j)==1 and judge(j,k)==1:
                print (i*10000+j)*10000+k
