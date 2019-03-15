import turtle
turtle.penup()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(20)
turtle.pencolor("purple")
turtle.seth(60)
x = -60
for i in range( 3 ):
	turtle.fd(250)
	turtle.seth(x)
	x = x - 120
turtle.done()