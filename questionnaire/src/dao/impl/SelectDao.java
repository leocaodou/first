package dao.impl;

import java.sql.*;
import util.Conn;
import domain.Select;

public class SelectDao {
	private Connection con;
	private ResultSet rs;
	public void add(Select select)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			PreparedStatement pstmt = con.prepareStatement("INSERT select_table(selectOrder,questionID,selectContent) VALUES(?,?,?)");
			pstmt.setString(1, select.getSelectOrder());
			pstmt.setInt(2, select.getQuestionID());
			pstmt.setString(3, select.getSelectContent());
			pstmt.executeUpdate();
			con.close();
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
	public int num(int selectID)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			int key = 0;
			PreparedStatement pstmt = con.prepareStatement("select count(*) from answer where selectID=?");
			pstmt.setInt(1, selectID);
			rs = pstmt.executeQuery();
			if(rs.next())
			{
				key = rs.getInt("count(*)");
			}
			con.close();
			return key;
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
}
