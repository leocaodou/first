package dao.impl;
import java.sql.*;
import util.Conn;
import domain.Question;
public class QuestionDao {
	private Connection con;
	private ResultSet rs;
	public int add(Question question)
	{
		try
		{
			Conn conn = new Conn();
			con = conn.getCon();
			int key = 0;
			PreparedStatement pstmt = con.prepareStatement("INSERT question(questionOrder,title,questionType,paperID) VALUES(?,?,?,?)",Statement.RETURN_GENERATED_KEYS);
			pstmt.setInt(1, question.getQuestionOrder());
			pstmt.setString(2, question.getTitle());
			pstmt.setString(3, question.getQuestionType());
			pstmt.setInt(4, question.getPaperID());
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
}
