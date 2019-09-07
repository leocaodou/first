t = input()
a = eval(input())
for i in range (0,a):
	s = input()
	if len(s) < len(t) :
		if s in t :
			print("my child!")
		else :
			print("oh,child!")
	elif len(s) == len(t) :
		if s == t :
			print("jntm!")
		else :
			print("friend!")
	else :
		if t in s :
			print("my teacher!")
		else :
			print("senior!")
