ans=0
n=1000
for i in range(1,n+1):
    t=1
    for j in range(1,i+1):
        t=t*i
    ans = ans + t
print ans
