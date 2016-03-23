arr=['one','two','three','four','five','six','seven','eight','nine']
arr1=['ten','eleven','twelve','thirteen','fourteen','fifteen',\
      'sixteen','seventeen','eighteen','nineteen']

arr2=['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
a=0
for i in arr:
    a+=len(i)

b=0
for i in arr1:
    b+=len(i)

c=0
for i in arr2:
    c+=(len(arr)+1)*len(i)+a

d=0

for i in arr:
    d+=(len(i)+len('hundred'))*100+len('and')*99+(a+b+c);

print a+b+c+d+len('onethousand')


