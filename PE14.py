def dfs(x):
    if x==1:return 1
    if x%2==0: return dfs(x/2)+1
    else: return dfs(3*x+1)+1

ans=0
d=0

for i in range(1,1000000):
    t=dfs(i)
    if t>d:
        d=t
        ans=i
print ans
