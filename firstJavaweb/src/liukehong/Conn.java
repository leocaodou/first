package liukehong;
import java.sql.*;
public class Conn {
	private	Connection con=null;
	public Conn() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		try {
			con = DriverManager
					.getConnection("jdbc:mysql://localhost:3306/liukehong2018011252?user=root&password=root");
		}catch (SQLException e1) {
			e1.printStackTrace();
		}
	}
	public Connection getCon(){
		return con;
	}
}