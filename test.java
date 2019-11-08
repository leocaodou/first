import java.util.Scanner;
import java.lang.*;
abstract class GeometricObject
{
	String color;
	boolean fild;
	abstract String getcolor();
	abstract void setcolor(String color);
	abstract boolean getFild();
	abstract void setFild(boolean fild);
	abstract double getArea();
	abstract double getPerimeter();
}
class Triangle extends GeometricObject{
	double s1;
	double s2;
	double s3;
	Triangle(double s1,double s2,double s3,String color,boolean filde)
	{
		this.s1 = s1;
		this.s2 = s2;
		this.s3 = s3;
		setcolor(color);
		setFild(filde);
	}
	public String toString()
	{
		return "颜色" + getcolor() + '\n' + "是否填充" + getFild() + '\n'+ "面积" + getArea() + '\n' + "周长" + getPerimeter();
	}
	String getcolor()
	{
		return color;
	}
	void setcolor(String color)
	{
		this.color = color;
	}
	public boolean getFild()
	{
		return fild;
	}
	public void setFild(boolean fild)
	{
		this.fild = fild;
	}
	double getArea()
	{
		double p;
		p = (s1 + s2 + s3) / 2;
		return Math.sqrt(p*(p - s1) * (p - s2) * (p - s3));
	}
	double getPerimeter()
	{
		return s1 + s2 + s3;
	}
}
public class test{
	public static void main(String[] args){
		double s1,s2,s3;
		String c,f;
		boolean fild;
		Scanner in = new Scanner(System.in);
		s1 = in.nextDouble();
		s2 = in.nextDouble();
		s3 = in.nextDouble();
		c = in.next();
		f = in.next();
		if(f.equals("true"))
			fild = true;
		else
			fild = false;
		Triangle a = new Triangle(s1,s2,s3,c,fild);
		System.out.println(a.toString());
	}
}