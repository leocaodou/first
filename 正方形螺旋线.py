import turtle
turtle.colormode(255)
turtle.pencolor((51, 204, 12))
turtle.penup()
turtle.fd(-250)
turtle.seth(-90)
turtle.fd(100)
turtle.seth(90)
turtle.pendown()
turtle.pensize(10)
x=400
y=90
a=51
b=204
c=12
for i in range(20):
	for j in range(2):
		turtle.fd(x)
		y=y-90
		turtle.seth(y)
		turtle.pencolor((a, b, c))
		a=a+5
		b=b-5
		c=c+6
	x=x-20
turtle.done()