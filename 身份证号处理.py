import datetime
y = datetime.datetime.now().year
a = input()
b = eval(a[6:10])
c = y - b
m = a[10:12]
d = a[12:14]
print("你出生于{}年{}月{}日".format(b,m,d))
print("你今年{}周岁".format(c))
if eval(a[16:17]) % 2 != 0 :
	print("你的性别为男")
else :
	print("你的性别为女")