s = input()
a = eval(input())
for i in s:
	if i not in ".,[]{} " :
		i = chr(ord(i) + a)
		if i not in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtsuvwxyz" :
			i = chr(ord(i) - 26)
		print(i,end = '')
	else :
		print(i,end = '')