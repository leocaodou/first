package A;

public class Person {
	private String name;
	private char sex;
	protected Address adr;
	Person(){};
	Person(String name,char sex,Address adr)
	{
		this.name = name;
		this.sex = sex;
		this.adr =adr;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public void setSex(char sex)
	{
		this.sex = sex;
	}
	public void setAddress(Address adr)
	{
		this.adr = adr;
	}
	public String getName()
	{
		return name;
	}
	public char getSex()
	{
		return sex;
	}
	public Address getAddress()
	{
		return adr;
	}
	public String toString()
	{
		return "ĞÕÃû£º" + name + "\nĞÔ±ğ:" + sex + '\n' + adr.toString() + '\n';
	}
}
