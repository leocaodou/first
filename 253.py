import math as m
a = int(input())
b = int(input())
c = int(input())
if (a == 0) & (b == 0) & (c == 0):
	print("Data error!")
else:
	if b*b - 4*a*c < 0:
		print("该方程无实数解")
	else :
		if a == 0:
			x = -c/b
			print(x)
		else:
			x1 = (-b - m.sqrt(b*b - 4*a*c))/(2 * a)
			x2 = (-b + m.sqrt(b*b - 4*a*c))/(2 * a)
			if x1 == x2:
				print(x1)
			else:
				print(x1,' ',x2)