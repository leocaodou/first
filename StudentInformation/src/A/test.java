package A;

public class test {

	public static void main(String[] args) {
		Address s = new Address("朝阳","北四环东路","北京","111");
		Student a = new Student("刘科宏",'M',s,"2018011252",0);
		Teacher b = new Teacher("Teacher",'M',s,666);
		b.setStudentGrade(a, 100);
		System.out.println(a.getGrade());
		System.out.println(a.toString());
	}

}
