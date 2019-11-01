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
		return "住在" + city + "市" +state + "区" + street + "街" + no + "号";
	}
}
