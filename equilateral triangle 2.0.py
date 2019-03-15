import turtle
turtle.penup()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(20)
turtle.pencolor("red")
turtle.seth(-60)
x = 60
for i in range( 3 ):
	turtle.fd(125)
	turtle.seth(x)
	x = x + 120
turtle.pencolor("blue")
turtle.seth(60)
turtle.fd(125)
x = -60
for i in range( 2 ):
	turtle.seth(x)
	turtle.fd(250)
	x = x - 120
turtle.seth(60)
turtle.fd(125)
turtle.done()