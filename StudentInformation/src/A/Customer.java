package A;
public class Customer {
	public String name;
	private double SumRent = 0;
	private double ap = 0;
	public Customer next = null;
	Customer(String n)
	{
		this.name = n;
	}
	public void addVido(vido x)
	{
		SumRent = SumRent + x.getRent();
		ap = ap + x.getAp();
	}
	public double getSumRent()
	{
		return SumRent;
	}
	public double getAp()
	{
		return ap;
	}
}
