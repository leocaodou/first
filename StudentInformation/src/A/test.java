package A;

public class test {

	public static void main(String[] args) {
		Address s = new Address("����","���Ļ���·","����","111");
		Student a = new Student("���ƺ�",'M',s,"2018011252",0);
		Teacher b = new Teacher("Teacher",'M',s,666);
		b.setStudentGrade(a, 100);
		System.out.println(a.getGrade());
		System.out.println(a.toString());
	}

}
