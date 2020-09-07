package dao;

import domain.User;
import java.sql.*;
import util.Conn;

/**
 * 操作user表的数据操作
 * @author hx
 */
public class UserDao {

	private Connection con;
	private Statement sql;
	private ResultSet rs;
	
    public User find(String userName, String userPwd) {
        try{
        	User user = null;
        	Conn conn = new Conn();
			con = conn.getCon();
			
	 		sql = con.createStatement();
			rs = sql.executeQuery("SELECT * FROM t_user WHERE psw="+userPwd+" and name='"+userName+"'");
			/*
			PreparedStatement pstmt 
			= con.prepareStatement
			("select * from t_user where name=? and psw=?");
			pstmt.setString(1,userName );
			pstmt.setString(2, userPwd);
			rs = pstmt.executeQuery();  
			*/
			if (rs.next()) {
				user = new User();
				user.setName(userName);
				user.setAge(rs.getInt("age"));
				user.setSex(rs.getString("sex"));
				user.setUserID(rs.getInt("userID"));
				user.setPwd(rs.getString("psw"));
			}
            con.close();
            return user;
        
        }catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void add(User user) {
        try{
        	Conn conn = new Conn();
			con = conn.getCon();
			String strSQL =  "INSERT INTO t_user VALUES ("
							+user.getUserID()+","
							+"'"+user.getName()+"',"
							+"'"+user.getPwd()+"',"
							+"'"+user.getSex()+"',"
							+user.getAge()+")";
			sql = con.createStatement();
			sql.execute(strSQL);
			/*
			String strSQL =  "INSERT INTO t_user VALUES (?,?,?,?,?)";
			PreparedStatement pstmt = con.prepareStatement(strSQL);
			pstmt.setString(1, user.getUserID());
			pstmt.setString(2, user.getName());
			pstmt.setString(3, user.getPwd());
			pstmt.setString(4, user.getSex());
			pstmt.setString(5, user.getAge());
			rs = pstmt.executeUpdate();  
			 */
			con.close();
        }catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}


