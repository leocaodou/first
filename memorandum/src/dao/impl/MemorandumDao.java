package dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Timestamp;

import domain.Memorandum;
import util.Conn;

public class MemorandumDao {
	private Connection con;
	private ResultSet rs;
	public void add(Memorandum mem)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			PreparedStatement pstmt = con.prepareStatement("INSERT memorandum(content,createDate,userID) VALUES(?,?,?)");
			pstmt.setString(1, mem.getContent());
			Timestamp t = new Timestamp(mem.getCreateDate().getTime());
			pstmt.setTimestamp(2, t);
			pstmt.setInt(3, mem.getUserID());
			pstmt.executeUpdate();
			con.close();
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
	public int count(int userID)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			int s=0;
			PreparedStatement pstmt = con.prepareStatement("select count(*) from memorandum WHERE userID=?");
			pstmt.setInt(1, userID);
			rs = pstmt.executeQuery();
			if (rs.next())
			{
				s = rs.getInt("count(*)") ;
			}
			con.close();
			return s;
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
}
