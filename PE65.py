def gcd(a,b):
    if a<b: a,b=b,a
    if b==0: return a
    return gcd(b,a%b)

def plus(a,b):
    c=a[0]*b[1]+b[0]*a[1]
    d=a[1]*b[1]
    return [c/gcd(c,d),d/gcd(c,d)]
n=100
def dfs(x):
    if x==n:return [1,0]
    if x==0:
        
        return plus([2,1],dfs(x+1)[::-1])
    if x%3!=2: return plus([1,1],dfs(x+1)[::-1])
    else: return plus([(int(x/3)+1)*2,1],dfs(x+1)[::-1])
e=dfs(0)
print e
f=0
while e[0]>0:
    f+=e[0]%10
    e[0]/=10

print f
