a=int(input())
b=int(input())
su=[]
if a>b:
    smaller=b
else:
    smaller=a
for i in range(1,smaller+1):
    if a%i==0 and b%i==0:
        su.append(i)
l=len(su)
p=su[l-1]
print(p,int(a*b/p))