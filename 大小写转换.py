s = input()
for i in s:
	if i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" :
		i = chr(ord(i) + 32)
	else :
		if i in "abcdefghijklmnopqrtsuvwxyz" :
			i = chr(ord(i) - 32)
	print(i,end = '')