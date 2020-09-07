package dao.impl;

import dao.IUserDao;
import domain.User;
import java.sql.*;
import util.Conn;
import MD5.MD5Utils;

public class UserDaoImpl implements IUserDao{
	private Connection con;
	private ResultSet rs;
	private Statement sql;
	@Override
	public User find(String UserName, String UserPaw) {
		try
		{
			User user = null;
			Conn conn = new Conn();
			con = conn.getCon();
			PreparedStatement pstmt = con.prepareStatement("select * from user where userName=? and Password=?");
			pstmt.setString(1, UserName);
			pstmt.setString(2, MD5Utils.md5(UserPaw));
			rs = pstmt.executeQuery();
			if(rs.next())
			{
				user = new User();
				user.setUserID(rs.getInt("UserID"));
				user.setUserName(UserName);
				user.setPassword(UserPaw);
				user.setRealName(rs.getString("realName"));
			}
			con.close();
			return user;
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}

	@Override
	public void add(User user) {
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			String strSQL =  "INSERT user(userName,Password,realName) VALUES ('"
							+user.getUserName()+"',"
							+"'"+MD5Utils.md5(user.getPassword())+"',"
							+"'"+user.getRealName()+"')";
			sql = con.createStatement();
			sql.execute(strSQL);
			con.close();
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}
}
