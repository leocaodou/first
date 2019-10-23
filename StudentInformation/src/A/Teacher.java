package A;

public class Teacher extends Person{
	private int gongHao;
	Teacher(){};
	Teacher(String name,char sex,Address adr,int gongHao)
	{
		super(name,sex,adr);
		this.gongHao = gongHao;
	}
	public void setStudentGrade(Student s,int grade)
	{
		s.setGrade(grade);
	}
	public String toString()
	{
		return super.toString() + "¹¤ºÅ" + gongHao +'\n';
	}
}
