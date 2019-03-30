N = eval(input("请输入一个整数"))
n = 0
for x in range (2, N + 1): 
	for i in range (2, x):
		if(x % i == 0):
			break
	else:
		n = n + 1
		print("{:3}".format(x),end =' ')
		if n % 10 == 0:
			print("\n")
				