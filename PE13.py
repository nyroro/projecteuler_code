import string
s=raw_input()
ans=0
while s != '':
    ans+=string.atoi(s)
    s=raw_input()
print ans
