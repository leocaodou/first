import java.util.Scanner;
class Student
{
	int no;
	String name;
	Score score;
	Student(){};
	Student(int no,String name,Score score)
	{
		this.no = no;
		this.name = name;
		this.score = score;
	}
	public String toString()
	{
		return "学号 " + no + "\n姓名 " + name + "\n面试成绩 " + score.mianShi + "\n笔试成绩 " + score.biShi +"\n总成绩" + score.getTotalScore();
	}
}
class Score
{
	double mianShi;
	double biShi;
	Score(){};
	Score(double mianShi,double biShi)
	{
		this.mianShi = mianShi;
		this.biShi = biShi;
	}
	double getTotalScore()
	{
		return mianShi*0.3 + biShi*0.7;
	}
}
public class SS{
	public static void main(String[] args){
		int x;
		Scanner in = new Scanner(System.in);
		x = in.nextInt();
		String y;
		y = in.next();
		Score a = new Score(in.nextDouble(),in.nextDouble());
		Student s = new Student(x,y,a);
		System.out.println(s.toString());
	}
}