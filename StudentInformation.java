class Person
{
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
	public void setSex(String sex)
	{
		this.sex = sex;
	}
	public void setAddress(String adr)
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
		return;
	}
}
class Address
{
	private String state;
	private String street;
	private String city;
	private String no;
	Address(String state,String street,String city,String no)
	{
		this.state = state;
		this.street = street;
		this.city = city;
		this.no = no;
	}
	public String toString()
	{
		return;
	}
}
class Student extends Person
{
	private String stNo;
	private int grade;
	Student(){};
	Student(String name,char sex,Address adr,String stNo,int grade)
	{
		super(name,sex,adr);
		this.stNo = stNo;
		this.grade = grade;
	}
	public void setStNo(String stNo)
	{
		this.stNo = stNo;
	}
	public void setGrade(int grade)
	{
		this.grade = grade;
	}
	public String getStNo()
	{
		return stNo;
	}
	public int getGrade(int grade)
	{
		return grade;
	}
}