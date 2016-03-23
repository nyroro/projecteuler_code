import string
v=[]
str=raw_input()
while str!='':
    v.append([string.atoi(i) for i in str.split()])
    print v
    str=raw_input()


t=v

for i in range(1,len(v)):
    v[i][0]+=v[i-1][0]
    for j in range(1,len(v[i])-1):
        v[i][j]+=max(v[i-1][j-1],v[i-1][j])
    v[i][len(v[i])-1]+=v[i-1][len(v[i-1])-1]

x=0

for i in range(0,len(v[len(v)-1])):
    x=max(x,v[len(v)-1][i])
print x
