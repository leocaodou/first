package game;
import java.util.Scanner;
public class game {
	public GameObject Robot()
	{
		double rock = 1;
		double paper = 1;
		double scissors = 1;
		double sum = rock + paper +scissors;
		double d = Math.random() * sum;
		if(d <= rock)
			return new GameObject("布");
		else if(d <= rock + paper)
			return new GameObject("剪刀");
		else
			return new GameObject("石头");
	}
	public void gamestart()
	{
		Scanner in = new Scanner(System.in);
		GameObject yourObject = null;
		Probstrategy p = new Probstrategy();
		Winningstrategy w = new Winningstrategy();
		while(true)
		{
			System.out.println("请输入你按照什么策略出招，策略1输入1，策略2输入2，不玩了输入3");
			int c = in.nextInt();
			if(c == 1)
			{
				yourObject = w.settlewhat();
				if(yourObject == null)
				{
					System.out.println("你还没有出过或者你上把输了你只有使用策略2");
					yourObject = p.settlewhat();
				}
			}
			if(c == 2)
				yourObject = p.settlewhat();
			if(c == 3)
				break;
			GameObject robot = Robot();
			p.add(robot);
			System.out.print("你出的是：");
			yourObject.show();
			System.out.print("对手出的是：");
			robot.show();
			int r = yourObject.Compare(robot);
			if(r == 2)
			{
				System.out.println("你赢了");
				w.setLast(robot);
			}
			if(r == 0)
			{
				System.out.println("你输了");
				w.setLast(null);
			}
			if(r == 1)
			{
				System.out.println("你们平局");
				w.setLast(null);
			}
		}
	}
}
