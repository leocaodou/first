package dao.impl;

import java.sql.*;
import util.Conn;
import domain.Paper;

public class PaperDao {
	private Connection con;
	private ResultSet rs;
	public int add(Paper paper)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			int key = 0;
			PreparedStatement pstmt = con.prepareStatement("INSERT paper(title,adminID,createDate,operateDate,endDate,thanksMsg) VALUES(?,?,?,?,?,?)",Statement.RETURN_GENERATED_KEYS);
			pstmt.setString(1, paper.getTitle());
			pstmt.setInt(2, paper.getAdminID());
			Timestamp t = new Timestamp(paper.getCreateDate().getTime());
			pstmt.setTimestamp(3, t);
			t = new Timestamp(paper.getOperateDate().getTime());
			pstmt.setTimestamp(4, t);
			t = new Timestamp(paper.getEndDate().getTime());
			pstmt.setTimestamp(5, t);
			pstmt.setString(6, paper.getThanks());
			pstmt.executeUpdate();
			rs = pstmt.getGeneratedKeys();
			if (rs.next())
			{
				key = rs.getInt(1) ;
			}
			con.close();
			return key;
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
	public int count(int adminID)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			int s=0;
			PreparedStatement pstmt = con.prepareStatement("select count(*) from paper WHERE adminID=?");
			pstmt.setInt(1, adminID);
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
	public Paper find(int paperID)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			Paper paper=new Paper();
			PreparedStatement pstmt = con.prepareStatement("select * from paper WHERE paperID=?");
			pstmt.setInt(1, paperID);
			rs = pstmt.executeQuery();
			if (rs.next())
			{
				paper.setPaperID(rs.getInt("paperID"));
				paper.setTitle(rs.getString("title"));
				paper.setCreateDate(rs.getDate("createDate"));
				paper.setOperateDate(rs.getDate("operateDate"));
				paper.setEndDate(rs.getDate("endDate"));
				paper.setThanks(rs.getString("thanksMsg"));
			}
			con.close();
			return paper;
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
}
