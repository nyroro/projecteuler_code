
import math
N=100000000

prime = [True]*(N+1)

ans=1
MOD=1000000009
def count_prime(n,i):
    ret=0
    while n>0:
        ret+=n//i
        n//=i
    return ret

def power(x,n):
    global MOD
    if n==0:
        return 1
    if n==1:
        return x
    tmp=power(x,n/2)
    tmp=tmp*tmp%MOD
    if n%2==1:
        tmp=tmp*x%MOD
    return tmp


for i in xrange(2,int(math.sqrt(N))+1):
    if prime[i]:
        print i
        m=count_prime(N,i)
        tmp=power(i,m)
        ans*=(1+tmp**2)
        ans%=MOD
        for j in xrange(i*i,N+1,i):
            prime[j]=False
for i in xrange(int(math.sqrt(N))+1,N+1):
    if prime[i]:
        tmp=power(i,count_prime(N,i))
        ans*=(1+tmp**2)
        ans%=MOD
print ans
"""
N=10
MOD=1000000009
def gcd(a,b):
    if a<b:[a,b]=[b,a]
    if b==0:return a
    return gcd(b,a%b)
t=1
for i in xrange(1,N+1):
    t*=i
ans=0
for i in xrange(1,t+1):
    if t%i == 0:
        if gcd(i,t/i)==1:
            print i
            ans+=i*i
            ans%=MOD

print ans
"""
