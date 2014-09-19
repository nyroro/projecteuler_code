n5=0
n2=0

n=1000000000000

t=n

mod=100000
v=1

while t>0:
    r=int(t%mod)
    for i in range(r+1):
        if int(i%2)!=0 and int(i%5)!=0:
            v=(v*i)%mod
    n2+=int(t/2);
    t=int(t/2);

t=int(n/5)
n2-=t
while t>0:
    u=t
    while u>0:
        r=int(u%mod)
        for i in range(r+1):
            if int(i%2)!=0 and int(i%5)!=0:
                v=(v*i)%mod
        u=int(u/2)
    n2-=int(t/5)
    t=int(t/5)

def p2(n):
    n=int(n)
    if n==0:
        return 1
    v1=p2(n/2)
    ret=(v1*v1)%mod
    if n%2==1:
        ret=(ret*2)%mod
    return ret

v2=p2(n2)
ans=(v*v2)%mod

print(ans)



