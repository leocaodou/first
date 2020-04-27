package aaa;
import java.sql.*;

import aaa.Conn;
import aaa.Subject;

public class SubjectDB {
	Connection con;
	public SubjectDB(){
		Conn conn= new Conn();
		con = conn.getCon();  
	}
	public Subject Search(String number, String courseName) throws SQLException{
		Subject sub = new Subject();
		PreparedStatement pstmt = 
				con.prepareStatement("select * from scores where number=? and subject=?");
		pstmt.setString(1,number );
		pstmt.setString(2, courseName);
		ResultSet rs = pstmt.executeQuery();  
		if (rs.next()) {
			sub.setName(rs.getString("name"));
			sub.setNumber(number);
			sub.setSubject(courseName);
			sub.setScore(rs.getInt("score"));
		}
		return sub;
	}
	
}
