package A;
import javafx.application.Application;
public class Address {
	private String state;
	private String street;
	private String city;
	private String no;
	Address(String state,String street,String city,String no)
	{
		this.state = state;
		this.street = street;
		this.city = city;
		this.no = no;
	}
	public String toString()
	{
		return "ס��" + city + "��" +state + "��" + street + "��" + no + "��";
	}
}
