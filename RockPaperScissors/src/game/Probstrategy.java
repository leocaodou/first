package game;
import java.lang.Math;
public class Probstrategy implements Tactics
{
	private double rock = 1;
	private double paper = 1;
	private double scissors = 1;
	public GameObject settlewhat()
	{
		double sum = rock + paper +scissors;
		double d = Math.random() * sum;
		if(d <= rock)
			return new GameObject("布");
		else if(d <= rock + paper)
			return new GameObject("剪刀");
		else
			return new GameObject("石头");
	}
	public void add(GameObject x)
	{
		if(x.getName() == "石头")
			rock++;
		else if(x.getName() == "布")
			paper++;
		else
			scissors++;
	}

}
