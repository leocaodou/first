x = eval(input())
n = eval(input())
s = 0
for i in range(x,n + 1) :
	t = str(i)
	k = 0
	for j in range(0,len(t) - 1):
		if eval(t[j]) > eval(t[j + 1]):
			k = 1
			break
	if k == 0:
		s = s + 1
print(s)