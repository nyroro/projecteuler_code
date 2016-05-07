N=10000000
ans=0

def judge(x):
    while x!=89 and x!=1:
        t=0
        while x>0:
            t+=(x%10)*(x%10)
            x/=10
        x=t
    return x==89

for i in range(1,N+1):
    if judge(i):
        ans+=1
    if i%100000==0:
        print i
        

print ans
