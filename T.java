import java.util.Scanner;
class Tank
{
	private double speed = 0;
	private int bulletAmount = 0;
	public void speedUp(double up)
	{
		speed = speed + up;
	}
	public void speedDown(double Down)
	{
		speed = speed - Down;
	}
	void setSpeed(double x)
	{
		speed = x;
	}
	void setBulletAmount(int x)
	{
		bulletAmount = x;
	}
	double getSpeed()
	{
		return speed;
	}
	int getBulletAmount()
	{
		return bulletAmount;
	}
	void fire()
	{
		if(bulletAmount > 0)
		{
			System.out.println("打出一发炮弹");
			bulletAmount--;
		}
		else
			System.out.println("没有炮弹了");
	}
}
public class T{
	public static void main(String[] args){
		Tank a = new Tank();
		Tank b = new Tank();
		Scanner in = new Scanner(System.in);
		a.setBulletAmount(10);
		b.setBulletAmount(1);
		a.speedUp( in.nextDouble());
		b.speedUp( in.nextDouble());
		a.fire();
		b.fire();
		System.out.println("tank1目前的速度是" + a.getSpeed());
		System.out.println("tank2目前的速度是" + b.getSpeed());
		System.out.println("tank1目前的子弹是" + a.getBulletAmount());
		System.out.println("tank2目前的子弹是" + b.getBulletAmount());
		a.speedDown( in.nextDouble());
		b.speedDown( in.nextDouble());
		a.fire();
		b.fire();
		System.out.println("tank1目前的速度是" + a.getSpeed());
		System.out.println("tank2目前的速度是" + b.getSpeed());
		System.out.println("tank1目前的子弹是" + a.getBulletAmount());
		System.out.println("tank2目前的子弹是" + b.getBulletAmount());
	}
}