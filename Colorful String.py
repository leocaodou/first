t = input()
s = len(t)
for i in range (0,len(t) - 1) :
	if t[i] == t[i + 1] :
		s = s + 1
		k = 1
		while 1:
			if (i - k < 0) or (i + k >= len(t)) :
				break
			if t[i - k] == t[i + k] :
				s = s + len(set(t[i - k : i + k + 2]))
				k = k + 1
			else :
				break
for i in range (0,len(t) - 2) :
	a = t[i:i+3]
	b = reversed(list(a))
	if list(a) == list(b) :
		s = s + len(set(t[i : i + 3]))
		k = 1
		while 1:
			if (i - k < 0) or (i + k + 2>= len(t)) :
				break
			if t[i - k] == t[i + k + 2] :
				s = s + len(set(t[i - k : i + k + 3]))
				k = k + 1
			else :
				break
print(s)