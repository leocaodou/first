import java.util.Scanner;
class point
{
	private double x = 0;
	private double y = 0;
	public void setx(double a)
	{
		x = a;
	}
	public void sety(double a)
	{
		y = a;
	}
	point(){};
	point(double a, double b)
	{
		x = a;
		y = b;
	}
	double getDistanceToBase()
	{
		return  Math.sqrt(x*x + y*y);
	}
}
public class A{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		point a = new point(3,4);
		point b = new point();
		double x,y;
		x = in.nextDouble();
		y = in.nextDouble();
		b.setx(x);
		b.sety(y);
		System.out.println("p1距离原点的距离为" + String.format("%.2f", a.getDistanceToBase()));
		System.out.println("p2距离原点的距离为" + String.format("%.2f", b.getDistanceToBase()));
	}
}