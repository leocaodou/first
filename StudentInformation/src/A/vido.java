package A;

public class vido {
	private String name;
	private int day;
	private int kinds;
	vido(String n,int d)
	{
		this.name = n;
		this.day = d;
		Setkinds();
	}
	public void Setkinds()
	{
		if(name.equals("普通片"))
			kinds = 1;
		else if(name.equals("儿童片"))
			kinds = 2;
		else if(name.equals("新片"))
			kinds = 3;
	}
	public double getRent()
	{
		if(kinds == 1)
		{
			if(day > 2)
				return (2 + (day - 2) * 1.5);
			else
				return 2.0;
		}
		else if(kinds == 2)
		{
			if(day > 3)
				return (1.5 + (day - 3) * 1.5);
			else
				return 1.5;
		}
		else
		{
			return 3.0 * day;
		}
	}
	public double getAp()
	{
		if(kinds == 1 ||kinds == 2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}
