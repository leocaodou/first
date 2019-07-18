import sys 
for line in sys.stdin:
	a = line.split()
	if eval(a[0])/eval(a[1]) > eval(a[2])/eval(a[3]) :
		print(">")
	elif eval(a[0])/eval(a[1]) == eval(a[2])/eval(a[3]):
		print("=")
	else:
		print("<")