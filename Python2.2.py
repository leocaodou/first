str = input("请输入你需要转换的金额：")
if str[-2 : -1] in ['美']:
	M = eval(str[0 : -2])*6
	print("转换为人民币后为{:.2f}人民币".format(M))
elif str[-3 : -1] in ["人民"]:
	M = eval(str[0 : -3])/6
	print("转换为美元后为{:.2f}美元".format(M))
else :
	print("抱歉，目前本程序只支持美元与人民币的转换")