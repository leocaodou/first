a = input()
s = input()
b = 0
for i in range(len(s)):
	if s[i] == a :
		max = i
		b = b + 1
if b == 0 :
	print("Not Found")
else :
    print("index = {}".format(max))