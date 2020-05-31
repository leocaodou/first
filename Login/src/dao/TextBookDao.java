package dao;

import java.sql.*;

import domain.TextBook;
import util.Conn;

public class TextBookDao {
	private Connection con;
	private Statement sql;
	private ResultSet rs;

	public TextBookDao(){
		Conn conn = new Conn();
		con = conn.getCon();
	}
	public int Insert(TextBook newRecord) {
		try{	
			int count = 0;
			Statement sql =con.createStatement();
			ResultSet rs = sql.executeQuery("select count(*) from t_textbook");
			if ( rs.next() )
				count = rs.getInt(1);
			String strSQL =  
					"INSERT INTO t_textbook VALUES (?,?,?,?,?)";
			PreparedStatement pstmt = con.prepareStatement(strSQL);	
			pstmt.setInt(1, count);
			pstmt.setString(2, newRecord.getClassName());
			pstmt.setString(3, newRecord.getBookName());
			pstmt.setString(4, newRecord.getPublisher());
			pstmt.setInt(5, newRecord.getNum());
			return pstmt.executeUpdate(); 
		}catch (Exception e) {
			throw new RuntimeException(e);
		}
	}
}
