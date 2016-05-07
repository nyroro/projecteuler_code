def get_digit(n):
    ret=[0]*10

    while n>0:
        ret[n%10]+=1
        n/=10
    return tuple(ret)

N=7
for i in xrange(125874,10000000):
    tmp = get_digit(i)

    flag = True
    for j in xrange(2,N):
        if get_digit(j*i)!=tmp:
            flag=False
    if flag:
        print i
        break

    
