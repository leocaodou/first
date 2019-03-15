import turtle
x = 0
turtle.penup()
turtle.pensize(15)
turtle.fd(-250)
turtle.color("red")
for i in range(4):
	turtle.fd(50)
	turtle.pendown()
	turtle.fd(100)
	turtle.penup()
	turtle.fd(50)
	x = x - 90
	turtle.seth(x)
turtle.done()