import turtle
turtle.penup()
turtle.pensize(10)
turtle.fd(-200)
turtle.color('orange')
turtle.begin_fill()
turtle.pencolor("yellow")
x=30
turtle.seth(x)
turtle.pendown()
turtle.fd(280)
turtle.pencolor("red")
for i in range(2):
	x=x-120
	turtle.seth(x)
	turtle.fd(420)
turtle.pencolor("pink")
turtle.seth(x-120)
turtle.fd(140)
x=90
turtle.seth(x)
turtle.fd(140)
turtle.pencolor("blue")
for i in range(2):
	x=x-120
	turtle.seth(x)
	turtle.fd(420)
turtle.pencolor("black")
turtle.seth(x-120)
turtle.fd(280)
turtle.end_fill()
turtle.done()