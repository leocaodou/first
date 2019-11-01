package A;
import java.util.Date;
import javafx.application.Application;
class account{
	private int id;
	private double balance;
	private double annualInterestRate;
	private Date dateCreated;
	account(){
		id = 0;
		balance = 0;
		dateCreated = new Date();
		annualInterestRate = 0;
	}
	account(int id,double balance){
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
		return "用户ID" + getId() + '\n' + "�û���" + getBalance() + "��Ԫ\n" + "�û������ʣ�" + getMonthlyInterestRate() + '\n' + "����ʱ�䣺" + getDateCreated();
	}
}
