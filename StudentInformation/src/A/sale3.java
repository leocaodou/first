package A;
public class sale3 implements Sale {
	public double Aftersale(spend x)
	{
		if(x.getMoney() >= 1000)
			return (x.getMoney() - 200);
		else
			return x.getMoney();
	}

}
