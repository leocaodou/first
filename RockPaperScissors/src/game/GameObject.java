package game;
public class GameObject {
	private String name;
	private int Value;
	GameObject(String name)
	{
		this.name = name;
		setValue();
	}
	public String getName()
	{
		return name;
	}
	public void setValue()
	{
		if(name.equals("石头"))
		{
			Value = 3;
		}
		if(name.equals("剪刀"))
		{
			Value = 2;
		}
		if(name.equals("布"))
		{
			Value = 1;
		}
	}
	public int getValue()
	{
		return Value;
	}
	public int Compare(GameObject x)
	{
		if(this.Value - x.getValue() == 1 ||this.Value - x.getValue() == -2 )
			return 2;
		else if(this.Value == x.getValue() )
			return 1;
		else
			return 0;
	}
	public void show()
	{
		System.out.println(name);
	}
}
