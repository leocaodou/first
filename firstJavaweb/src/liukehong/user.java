package liukehong;
public class user {
	private int Sno;
	private String password;
	public user(int Sno,String password)
	{
		this.Sno = Sno;
		this.password = password;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public int getSno() {
		return Sno;
	}
	public void setSno(int sno) {
		Sno = sno;
	}
}
