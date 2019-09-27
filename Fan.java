import java.util.Scanner;
class F
{
	static int SLOW = 1;
	static int MEDIUM = 2;
	static int FAST = 3;
	private int speed = SLOW;
	private double radius = 5;
	private String color = "blue";
	private boolean on = false;
	public int getspeed()
	{
		return speed;
	}
	public double getradius()
	{
		return radius;
	}
	public String getcolor()
	{
		return color;
	}
	public boolean geton()
	{
		return on;
	}
	public void setspeed(int x)
	{
		speed = x;
		return;
	}
	public void setradius(double x)
	{
		radius = x;
		return;
	}
	public void setcolor(String x)
	{
		color = x;
		return;
	}
	public void seton(boolean x)
	{
		on = x;
		return;
	}
	F(){

	};
	F(int x)
	{
		setspeed(x);
	};
	F(double x){setradius(x);};
	F(String x){setcolor(x);};
	F(boolean x){seton(x);};
	public String toString()
	{
		if(on == true)
		{
			return "该风扇的速度为" + speed +"\n颜色是"+color+"\n半径是"+radius + '\n';
		}
		else
			return "风扇没有开启\n" + "该风扇颜色是"+color+"\n半径是"+radius + '\n';
	}
}
public class Fan
{
	public static void main(String[] args)
	{
		F a = new F(F.FAST);
		F b = new F(F.MEDIUM);
		double r1,r2;
		String c1,c2,o1,o2;
		Scanner in = new Scanner(System.in);
		r1 = in.nextDouble();
		c1 = in.next();
		o1 = in.next();
		r2 = in.nextDouble();
		c2 = in.next();
		o2 = in.next();
		a.setradius(r1);
		a.setcolor(c1);
		if(o1.equals("true"))
			a.seton(true);
		else
			a.seton(false);
		b.setradius(r2);
		b.setcolor(c2);
		if(o2.equals("true"))
			b.seton(true);
		else
			b.seton(false);
		System.out.println(a.toString());
		System.out.println(b.toString());
	}
}