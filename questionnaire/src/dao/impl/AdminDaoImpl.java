package dao.impl;

import dao.IAdminDao;
import domain.Admin;
import java.sql.*;
import util.Conn;
import MD5.MD5Utils;
public class AdminDaoImpl implements IAdminDao {
	private Connection con;
	private ResultSet rs;
	private Statement sql;
	@Override
	public Admin find(String AdminName, String AdminPaw) {
		try
		{
			Admin admin = null;
			Conn conn = new Conn();
			con = conn.getCon();
			PreparedStatement pstmt = con.prepareStatement("select * from administrator where adminName=? and Password=?");
			pstmt.setString(1, AdminName);
			pstmt.setString(2, MD5Utils.md5(AdminPaw));
			rs = pstmt.executeQuery();
			if(rs.next())
			{
				admin = new Admin();
				admin.setAdminID(rs.getInt("AdminID"));
				admin.setAdminName(AdminName);
				admin.setPassword(AdminPaw);
				admin.setRealName(rs.getString("realName"));
			}
			con.close();
			return admin;
		}
		catch(Exception e)
		{
			throw new RuntimeException(e);
		}
	}

	@Override
	public void add(Admin admin) {
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			String strSQL =  "INSERT administrator(adminName,Password,realName) VALUES ('"
							+admin.getAdminName()+"',"
							+"'"+MD5Utils.md5(admin.getPassword())+"',"
							+"'"+admin.getRealName()+"')";
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
