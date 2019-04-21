a,b = map(int,input().split(' '))
o = 0
for x in range(1, a):
    y = a - x
    if 2 * x + 4 * y == b:
        print(str(x),str(y))
        o = 1  
if o == 0:
    print("Data Error!")