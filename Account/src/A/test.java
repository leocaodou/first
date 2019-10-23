package A;

public class test {
	public static void main(String[] args){
		int x = 1122;
		double y = 20000,z = 0.045;
		account a = new account(x,y);
		a.setAnnualInterestRate(z);
		a.withDraw(2500);
		a.deposit(3000);
		System.out.println(a.toString());
	}
}