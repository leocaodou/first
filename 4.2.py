x = input("请输入一行字符")
a = 0
b = 0
c = 0
d = 0
for i in x :
	if i in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" :
		a = a + 1
	elif i in "1234567890" :
		b = b + 1
	elif i == ' ' :
		c = c + 1
	else :
		d = d + 1
print("这一段字符中英文字母有{}个，有数字{}个，有空格{}个，有其他字符{}个".format(a,b,c,d))