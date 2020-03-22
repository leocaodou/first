class Dice
{
	private int faceValue;
	public void roll()
	{
		faceValue = (int)(Math.random()*6 + 1);
	}
	public int getFaceValue()
	{
		return faceValue;
	}
}
class Dicegame
{
	private Dice dice1 = new Dice();
	private Dice dice2 = new Dice();
	public boolean play()
	{
		dice1.roll();
		dice2.roll();
		if(dice1.getFaceValue() + dice2.getFaceValue() == 7)
			return true;
		else
			return false;
	}
}
public class test {
	public static void main(String[] args)
	{
		Dicegame a = new Dicegame();
		if(a.play())
		{
			System.out.println("Win");
		}
		else
		{
			System.out.println("Lose");
		}
	}
}