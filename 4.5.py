import random
i = 1
y=0
a = random.randint( 0, 100)
while True :
	x = input("请猜一个0~100的数字\n")
	for j in x :
		if j not in "1234567890" :
			print("输入内容必须是整数！")
			y=1
			break
	if y != 0:
		break
	x = eval(x)
	if a > x :
		print("遗憾，太小了")
	elif a < x :
		print("遗憾，太大了")
	else :
		print("预计{}次，你猜中了！".format(i))
		break
	i = i + 1