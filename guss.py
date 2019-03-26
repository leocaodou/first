i = 1
a = 5
while True :
	x = eval(input("请猜一个1~9的数字\n"))
	if a > x :
		print("遗憾，太小了")
	elif a < x :
		print("遗憾，太大了")
	else :
		print("预计{}次，你猜中了！".format(i))
		break
	i = i + 1