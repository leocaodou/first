import java.util.Scanner;
public class test{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		double a,b,c,d;
		a = in.nextDouble();
		b = in.nextDouble();
		c = in.nextDouble();
		b = b / 1200;
		d = a * Math.\pow((1 + b),(c * 12));
		System.out.println(d);
	}
}