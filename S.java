import java.util.Scanner;
public class S{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		double [][]a = new double[][]{{1,2,3} ,{4,5,6} ,{7,8,9}};
		double [][]b = new double[][]{{0,2,4} ,{1,4.5,2.2} ,{1.1,4.3,5.2}};
		double [][]c = addMatrix(a ,b );
		for(int i = 0;i < 3;i++)
		{
			for(int j = 0;j < 3; j++)
			{
				System.out.print(c[i][j]);
				System.out.print(' ');
			}
			System.out.println();
		}
	}
	public static double[][] addMatrix(double[][] a, double[][] b)
	{
		double [][]c = new double[3][3];
		for(int i = 0;i < 3;i++)
		{
			for(int j = 0;j < 3; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		return c;
	}
}