package dao.impl;

import dao.IUserDao;
import domain.User;
import java.sql.*;
import util.Conn;

/**
 * IUserDao接口的实现类
 * @author hx
 */
public class UserDaoImpl implements IUserDao {

	private Connection con;
	private Statement sql;
	private ResultSet rs;
	
    @Override
    public User find(String userName, String userPwd) {
        try{
        	User user = null;
        	Conn conn = new Conn();
			con = conn.getCon();
			
	 	//	sql = con.createStatement();
			//rs = sql.executeQuery("SELECT * FROM t_user WHERE psw="+userPwd+" 
			//and name='"+userName+"'");
			
			
			PreparedStatement pstmt = con.prepareStatement("select * from t_user where name=? and psw=?");
			pstmt.setString(1, userName );
			pstmt.setString(2, userPwd);
			rs = pstmt.executeQuery();  
			
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

     @Override
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
			con.close();
        }catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}


