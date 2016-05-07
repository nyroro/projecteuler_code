import copy



#prime = [7,13]
prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43]
arr = []

for t in prime:
    tmp = [1]
    for i in xrange(2, t):
        if i ** 3 % t == 1:
            tmp.append(i)
    arr.append(copy.copy(tmp))
print arr

num = 1
for i in xrange(len(prime)):
    if len(arr[i]) == 1:
        print prime[i]
        num *= prime[i]


ans = 0


def exgcd(a, b):
    if b == 0:
        return (1, 0, a)

    (x, y, d) = exgcd(b, a%b)

    t = x
    x = y
    y = t - (a/b)*y

    return (x, y, d)

def dfs(index,modnum,ansnum):
    global prime
    global arr
    global ans
    if index == len(prime):
        ans += ansnum
        return
    if len(arr[index])==1:
        dfs(index+1,modnum,ansnum)
        return

    for i in arr[index]:
        #CALCULATE t%modnum=ansnum, t%prime[index]=i
        (x, y, d) = exgcd(modnum, prime[index])
        
        x *= i-ansnum
        
        next_ans= x* modnum + ansnum



        if next_ans<0:
            next_ans = modnum*prime[index] -(-next_ans)% (modnum*prime[index])
        
        if next_ans>=modnum*prime[index]:
            next_ans%=modnum*prime[index]


        dfs(index+1, modnum*prime[index], next_ans)
if num==1:
    dfs(0, 1, 0)
else:
    dfs(0,num,1)
print ans-1
        
