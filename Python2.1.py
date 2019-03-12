a = eval(input("请输入需要计算的温度大小： "))
b = input("请输入温度的单位： ")
if b in ['F','f']:
	C = (a - 32) / 1.8
	print("转换后的温度是{:.0f}C".format(C))
elif b in ['C','c']:
	F = 1.8 * a + 32
	print("转换后的温度是{:.0f}F".format(F))
else:
	print("抱歉，没有这个单位")