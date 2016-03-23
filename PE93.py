# -*- coding:utf-8 -*-
def cal(a,t,b):
    if t=='+':
        return a+b
    elif t=='-':
        return a-b
    elif t=='*':
        return a*b
    else:
        if b==0:
            return -1000000000
        return 1.0*a/b

def cal_all_possible_in_sequence(num, ope):
    #给定四个数字及齐排列顺序和三个运算符及其顺序
    #计算所有可能的结果
    ret = set()

    #1.((o)o(o))
    ret.add(cal(cal(num[0],ope[0],num[1]),ope[1],cal(num[2],ope[2],num[3])))
    #2.((o)o)o
    ret.add(cal(cal(cal(num[0],ope[0],num[1]),ope[1],num[2]),ope[2],num[3]))
    #3.(o(o))o
    ret.add(cal(cal(num[0],ope[0],cal(num[1],ope[1],num[2])),ope[2],num[3]))
    #4.o((o)o)
    ret.add(cal(num[0],ope[0],cal(cal(num[1],ope[1],num[2]),ope[2],num[3])))
    #5.o(o(o))
    ret.add(cal(num[0],ope[0],cal(num[1],ope[1],cal(num[2],ope[2],num[3]))))
    return ret
import itertools
def cal_all_possible(numList):
    #给定四个数字，求他们可以组合所得答案的全部可能

    opeList=['+','-','*','/']
    result = set()
    for num in list(itertools.permutations(numList)):
        for o1 in opeList:
            for o2 in opeList:
                for o3 in opeList:
                    result.update(cal_all_possible_in_sequence(num,[o1,o2,o3]))

    return result

def find_max_n(numList):
    result = cal_all_possible(numList)
    ret=1

    while True:
        if ret in result:
            ret+=1
        else:
            break
    
    return ret

resList = [1,2,3,4]
resNum = find_max_n(resList)

for i in range(1,10):
    for j in range(i,10):
        for k in range(j,10):
            for l in range(k,10):
                tmpNum=find_max_n([i,j,k,l])
                if tmpNum>resNum:
                    resNum=tmpNum
                    resList=[i,j,k,l]

print resList
print resNum

#import itertools
#print list(itertools.permutations([1,2,3,4]))
