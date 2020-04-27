package aaa;
import java.io.*;

public class Circle { 
	private int radius;
	private int len;
	
	public Circle(){ 
		radius=1;  
	}
	public Circle(int m){ 
		radius=m;
	}
	public int getRadius() {
		return radius;
	}
	public void setRadius(int newRadius)	{
		radius=newRadius;
	}
	public double circleArea()	{
		return Math.PI*radius*radius;
	}
	public double circlLength()	{
		return 2.0*Math.PI*radius;
	}
	public int getLen() {
		return len;
	}
	public void setLen(int len) {
		this.len = len;
	}
}