a=input("若更换选择输入1，不更换选择输入2：")
import random
n=1000000
b=0.0
if a==1:
    for i in range(1,n+1):
        m=random.randint(1,3)
        if m==2 or m==3:
            b=b+1
            c=((b/n)*100)
    print("更换选择的概率是:{}%".format(c))
if a==2:
    for i in range(1,n+1):
        m=random.randint(1,3)
        if m==1:
               b=b+1
    print("不更换选择的概率是:{}%".format((b/n)*100))
else:
    print("输入错误")