import java.util.Date;
class Account1{
	private int id;
	private double balance;
	private double annualInterestRate;
	private Date dateCreated;
	Account1(){
		id = 0;
		balance = 0;
		dateCreated = new Date();
		annualInterestRate = 0;
	}
	Account1(int id,double balance){
		this.id = id;
		this.balance = balance;
		annualInterestRate = 0;
		dateCreated = new Date();
	}
	public void setId(int id)
	{
		this.id = id; 
	}
	public void setAnnualInterestRate(double annualInterestRate)
	{
		this.annualInterestRate = annualInterestRate; 
	}
	public void setBalance(double balance)
	{
		this.balance = balance;
	}
	public int getId()
	{
		return id; 
	}
	public double getAnnualInterestRate()
	{
		return annualInterestRate; 
	}
	public double getBalance()
	{
		return balance;
	}
	public Date getDateCreated()
	{
		return dateCreated;
	}
	public double getMonthlyInterestRate()
	{
		return annualInterestRate / 12;
	}
	public void withDraw(double d)
	{
		balance = balance - d;
	}
	public void deposit(double d)
	{
		balance = balance + d;
	}
	public String toString()
	{
		return "用户ID" + getId() + '\n' + "用户余额：" + getBalance() + "美元\n" + "用户月利率：" + getMonthlyInterestRate() + '\n' + "开户时间：" + getDateCreated();
	}
}
public class account{
	public static void main(String[] args){
		int x = 1122;
		double y = 20000,z = 0.045;
		Account1 a = new Account1(x,y);
		a.setAnnualInterestRate(z);
		a.withDraw(2500);
		a.deposit(3000);
		System.out.println(a.toString());
	}
}