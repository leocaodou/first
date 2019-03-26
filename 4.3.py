a = eval(input("请输入第一个数"))
b = eval(input("请输入第二个数"))
if a < b :
	c = a
else :
	c = b
while True:
	if (a % c == 0) & (b % c == 0) :
		break
	else :
		c = c - 1
print("{}和{}的最大公约数是{}".format(a,b,c))