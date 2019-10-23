package A;

public class Student extends Person {
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
	public int getGrade()
	{
		return grade;
	}
	public String toString()
	{
		return super.toString() + "Ñ§ºÅ:" + stNo + "\n³É¼¨:" + grade +'\n';
	}
}
