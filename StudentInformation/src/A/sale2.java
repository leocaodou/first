package A;

public class sale2 implements Sale {

	public double Aftersale(spend x) {
		if(x.getMoney() > 200)
		{
			return (x.getMoney() - 200)*0.8 +200;
		}
		return x.getMoney();
	}

}
