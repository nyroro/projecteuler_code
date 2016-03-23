def d(x):
    ret=0
    for i in range(1,x):
        if x%i==0:
            ret+=i
    return ret

ans=0
dic={}
dic[284]=220
for i in range(1,10000):
    t=d(i)
    if t>i:
        dic[i]=t
    elif t<i:
        if i==284:print t,dic[t]
        if dic.get(t)!=None and dic[t]==i :
            print i,t
            ans+=i+t
print ans
