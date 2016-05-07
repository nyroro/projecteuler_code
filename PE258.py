arr = [1]*2000

k=2000
while True:
    t=arr[0]+arr[1]
    arr.pop(0)
    arr.append(t)
    print k,t
    k+=1
